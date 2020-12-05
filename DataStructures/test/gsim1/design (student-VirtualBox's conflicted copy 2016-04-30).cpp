#include <ostream>
#include <vector>
#include <map>
#include <string>
#include "gates.h"
#include "net.h"
#include "design.h"
#include <iostream>

using namespace std;

//Constructor
Design::Design(){
   desname = " ";
}
Design::Design(string n){
   desname = n;
}

//Destructor
Design::~Design(){

}

//Returns the name of the Design
string Design::name(){
   return desname;
}

//Adds the primary input
void Design::addPI(string n){
   pis.push_back(n);
}

//Adds the primary output
void Design::addPO(string n){
   pos.push_back(n);
}

//Returns a pointer to the net
Net* Design::findNet(string net_name){
   if(designNets.find(net_name) != designNets.end()){
      return designNets[net_name];
      //designNets.find(net_name)->second;
   }
   else{
      return NULL;
   }
}

//Returns a pointer to the gate
Gate* Design::findGate(string inst_name){
   if(designGates.find(inst_name) != designGates.end()){
      return designGates[inst_name];
   }
   else{
      return NULL;
   }
}

//Add a Net
Net* Design::addFindNet(string n){
   if(designNets.find(n) != designNets.end()){
      return designNets[n];
   }
   else{
      designNets.insert(make_pair(n,new Net(n)));
      return designNets[n];
   }
}

//Add a Gate with default delay
Gate* Design::addFindGate(int gtype, string g){
   if(designGates.find(g) != designGates.end()){
      return designGates[g];
   }
   else{
      Gate* temp;
      if(gtype == AND){
         temp = new And(g,1);
      }
      else if(gtype == OR){
         temp = new Or(g,1);
      }
      else if(gtype == NAND){
         temp = new Nand(g,1);
      }
      else if(gtype == NOR){
         temp = new Nor(g,1);
      }
      else if(gtype == XOR){
         temp = new Xor(g,1);
      }
      else{
         temp = new Not(g,1);
      }
      designGates.insert(make_pair(g,temp));
      return designGates[g];
   }
}

//Add a Gate with default value given by the user
Gate* Design::addFindGate(int gtype, string g, int d){
   if(designGates.find(g) != designGates.end()){
      return designGates[g];
   }
   else{
      Gate* temp;
      if(gtype == AND){
         temp = new And(g,d);
      }
      else if(gtype == OR){
         temp = new Or(g,d);
      }
      else if(gtype == NAND){
         temp = new Nand(g,d);
      }
      else if(gtype == NOR){
         temp = new Nor(g,d);
      }
      else if(gtype == XOR){
         temp = new Xor(g,d);
      }
      else{
         temp = new Not(g,d);
      }
      designGates.insert(make_pair(g,temp));
      return designGates[g];
   }
}

//Returns a pointer to the primary inputs
vector<Net *>* Design::getPINets(){
   vector<Net *> *temp = new vector<Net*>;
   for(unsigned int i = 0; i < pis.size(); i++){
      temp->push_back(new Net(pis[i]));
   }
   return temp;
}

//Returns a pointer to the primary outputs
vector<Net *>* Design::getPONets(){
   vector<Net *> *temp = new vector<Net*>;
   for(unsigned int i = 0; i < pos.size(); i++){
      temp->push_back(new Net(pos[i]));
   }
   return temp;
}

//Returns a pointer to the wires
vector<Net *>* Design::getWireNets(){
   vector<Net *> *temp = new vector<Net*>;
   map<string, Net*>::iterator it;
   for(it = designNets.begin(); it != designNets.end(); ++it){
      temp->push_back(it->second);
   }
   return temp;
}

//Returns a pointer to all nets
vector<Net *>* Design::allNets(){
   vector<Net *> *temp = new vector<Net*>;
   
   //PI
   for(unsigned int i = 0; i < pis.size(); i++){
      temp->push_back(new Net(pis[i]));
   }
   
   //PO
   for(unsigned int i = 0; i < pos.size(); i++){
      temp->push_back(new Net(pos[i]));
   }
   
   //Internal Wire
   map<string, Net*>::iterator it;
   for(it = designNets.begin(); it != designNets.end(); ++it){
      temp->push_back(it->second);
   }
   
   return temp;
}

//Returns a pointer to all gates
vector<Gate *>* Design::allGates(){
   vector<Gate *> *temp = new vector<Gate *>;
   map<string, Gate*>::iterator it;
   for(it = designGates.begin(); it != designGates.end(); ++it){
      temp->push_back(it->second);
   }
   return temp;
}

//Performs a topological sorting
vector<Net *>* Design::toposort(){
   
   //Creating the empy list
   vector<Net *> *temp = new vector<Net *>;
   
   //Initializing colormap to white
   map<string,int> colormap;
   map<string, Net*>::iterator it;
   for(it = designNets.begin(); it != designNets.end(); ++it){
      colormap.insert(make_pair(it->second->name(), 0));
   }
   
   //Calling the DFS
   for(unsigned int i = 0; i < pos.size(); ++i){
     if(colormap[pos[i]] == 0){
         dfs_visit(it->second, temp, colormap);
     }
   }
   
   return temp;
}

//Dump function
void Design::dump(ostream &os){
   //first line
   os<<"module "<<desname<<"(";
   for(unsigned int i = 0; i < pis.size(); i++){
      os<<pis[i];
      if(i != pis.size()){
         os<<", ";
      }
   }
   for(unsigned int i = 0; i < pos.size(); i++){
      os<<pos[i];
      if(i != pos.size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
   
   //inputs
   for(unsigned int i = 0; i < pis.size(); i++){
      os<<" input "<<pis[i]<<";"<<endl;
   }
   
   //outputs
   for(unsigned int i = 0; i < pos.size(); i++){
      os<<" output "<<pos[i]<<";"<<endl;
   }
   os<<endl;
   //Wires
   map<string, Net*>::iterator it;
   for(it = designNets.begin(); it != designNets.end(); ++it){
      bool found = false;
      for(unsigned int i = 0; i < pis.size(); ++i){
         if((it->first).compare(pis[i]) == 0){
            found = true;
         }
      }
      for(unsigned int i = 0; i < pos.size(); ++i){
         if((it->first).compare(pos[i]) == 0){
            found = true;
         }
      }
      if(found == false){
         os<<" wire "<<it->first<<";"<<endl;
      }
   }
   os<<endl;
   
   //Gates
   map<string, Gate*>::iterator kt;
   for(kt = designGates.begin(); kt != designGates.end(); ++kt){
      os<<" ";
      kt->second->dump(os);
   }
   os<<endl;
   //end of file
   os<<"endmodule"<<endl;
}

//check if the object is a primary input
bool Design::isPI(Net *n){
   bool check = false;
   for(unsigned int i = 0; i < pis.size(); i++){
      if(pis[i].compare(n->name()) == 0){
         check = true;
      }
   }
   return check;
}

//check if the object is primary output
bool Design::isPO(Net *n){
   bool check = false;
   for(unsigned int i = 0; i < pos.size(); i++){
      if(pos[i].compare(n->name()) == 0){
         check = true;
      }
   }
   return check;
}

void Design::dfs_visit(Net *n, vector<Net *> *flist, map<string, int> &colormap){
   //Grey
   colormap[n->name()] = 1;
   map<string, int>::iterator it;
   for(it = colormap.begin(); it != colormap.end(); ++it){
      if(colormap[it->first] == 0){
         dfs_visit(it->second, flist, colormap);
      }
   }

   //black
   colormap[n->name()] = 2;
   flist->push_back(n);
   n->computeDelay();
}
