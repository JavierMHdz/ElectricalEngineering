#include <vector>
#include <string>
#include <ostream>
#include "net.h"
#include "gates.h"

using namespace std;
//Empty Constructor
Gate::Gate(){
   inputs = new vector <Net *>;
   inst_name = " ";
   delay = 1;
}

//Constructor
Gate::Gate(string n){
   inputs = new vector<Net *>;
   inst_name = n;
   delay = 1;
}

//Overloaded constructor
Gate::Gate(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Gate::~Gate(){
   delete inputs;
}

//Return string
string Gate::name() const{
   return inst_name;
}

//Return delay
int Gate::getDelay() const{
   return delay;
}

//Adds an input net to this gate
void Gate::addInput(Net *n){
   inputs->push_back(n);
}

//Returns the inputs
vector<Net *>* Gate::getInputs(){
   vector<Net *> *temp = new vector <Net *>;
   for(unsigned int i = 0; i < inputs->size(); i++){
      Net* netPointer = (*inputs)[i];//new Net(((*inputs)[i])->name());
      //add 
      //TODO
      temp->push_back(netPointer);
   }
   return temp;
}

//Set the output net
void Gate::addOutput(Net *n){
   output = n;
}

//Return the output net
Net* Gate::getOutput() const{
   return output;
}

//Returns the number of inputs
int Gate::getNumInputs() const{
   return inputs->size();
}

//And class
//Constructor
And::And(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
And::~And(){

}

//Evaluates and returns a char
char And::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = ' ';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(zero == true){
      output = '0';
   }
   else if(uncertain == true){
      output = 'X';
   }
   else{
      output = '1';
   }
   return output;
}

//Dump function
void And::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"and ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}

//Or class
//Constructor
Or::Or(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Or::~Or(){

}

//Evaluates and returns a char
char Or::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = ' ';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(one == true){
      output = '1';
   }
   else if(uncertain == true){
      output = 'X';
   }
   else{
      output = '0';
   }
   return output;
}

//Dump function
void Or::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"or ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}

//Nor class
//Constructor
Nor::Nor(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Nor::~Nor(){

}

//Evaluates and returns a char
char Nor::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = ' ';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(one == true){
      output = '0';
   }
   else if(uncertain == true){
      output = 'X';
   }
   else{
      output = '1';
   }
   return output;
}

//Dump function
void Nor::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"nor ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}

//Nand class
//Constructor
Nand::Nand(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Nand::~Nand(){

}

//Evaluates and returns a char
char Nand::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = ' ';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(zero == true){
      output = '1';
   }
   else if(uncertain == true){
      output = 'X';
   }
   else{
      output = '0';
   }
   return output;
}

//Dump function
void Nand::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"nand ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}

//Xor class
//Constructor
Xor::Xor(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Xor::~Xor(){

}

//Evaluates and returns a char
char Xor::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = ' ';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(uncertain == true){
      output = 'X';
   }
   else if(zero == true && one == true){
      output = '1';
   }
   else{
      output = '0';
   }
   return output;
}

//Dump function
void Xor::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"xor ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}

//Not class
//Constructor
Not::Not(string n, int d){
   inst_name = n;
   delay = d;
}

//Destructor
Not::~Not(){

}

//Evaluates and returns a char
char Not::eval(){
   bool zero = false;
   bool uncertain = false;
   bool one = false;
   char output = 'X';
   for(unsigned int i = 0; i < inputs->size(); i++){
      if(((*inputs)[i])->getVal() == '0'){
         zero = true;
      }
      if(((*inputs)[i])->getVal() == 'X'){
         uncertain = true;
      }
      if(((*inputs)[i])->getVal() == '1'){
         one = true;
      }
   }
   
   if(uncertain == true){
      output = 'X';
   }
   else if(zero == true){
      output = '1';
   }
   else{
      output = '0';
   }
   return output;
}

//Dump function
void Not::dump(ostream &os){
   //if delay is equal to 1, don't show delay
   os<<"not ";
   if(delay != 1){
      os<<"#"<<delay<<" ";
   }
   os<<inst_name<<"("<<output->name()<<", ";
   for(unsigned int i = 0; i < inputs->size(); i++){
      os<<((*inputs)[i])->name();
      if(i != inputs->size()-1){
         os<<", ";
      }
   }
   os<<");"<<endl;
}
