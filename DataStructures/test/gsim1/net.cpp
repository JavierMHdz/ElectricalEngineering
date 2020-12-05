#include <vector>
#include <string>
#include "net.h"
#include "gates.h"
#include <iostream>
using namespace std;

//Constructor
Net::Net(){
   drivers = new vector <Gate *>;
   loads = new vector <Gate *>;
   netname = " ";
   delay = 0;
   val = 'X';
   color = ' ';
   
}

Net::Net(string n){
   drivers = new vector <Gate *>;
   loads = new vector <Gate *>;
   netname = n;
   delay = 0;
   val = 'X';
   color = 'w';
}

//Destructor
Net::~Net(){
   delete drivers;
   delete loads;
}

//Returns the name
string Net::name() const{
   return netname;
}

//Adds the given gate to the list of drivers
void Net::addDriver(Gate *g){
   drivers->push_back(g);
}

//Adds the given gate to the list of loads
void Net::addLoad(Gate *g){
   loads->push_back(g);
}

//Returns the loads of this net
vector<Gate *>* Net::getLoads(){
   vector<Gate *> *temp = new vector<Gate *>;
   for(unsigned int i = 0; i < loads->size(); i++){
      //Gate* gatePointer = new Gate(((*loads)[i])->name(), ((*loads)[i])->getDelay());
      //temp->push_back(gatePointer);
      temp->push_back((*loads)[i]);
   }
   return temp;
}

//Returns the drivers of this net
vector<Gate *>* Net::getDrivers(){
   vector<Gate *> *temp = new vector<Gate *>;
   for(unsigned int i = 0; i < drivers->size(); i++){
      //Gate* gatePointer = new Gate(((*drivers)[i])->name(), ((*drivers)[i])->getDelay());
      //temp->push_back(gatePointer);
      temp->push_back((*drivers)[i]);
   }
   return temp;
}

//Value of net
char Net::computeVal(){
   bool on = false;
   bool off =  false;
   bool uncertain = false;
   for(unsigned int i = 0; i < drivers->size(); ++i){
      if(((*drivers)[i])->eval() == 'X'){
         uncertain = true;
      }
      if(((*drivers)[i])->eval() == '1'){
         on = true;
      }
      if(((*drivers)[i])->eval() == '0'){
         off = true;
      }
   }

   if(uncertain == true){
      val = 'X';
      return 'X';
   }
   else if(on == true && off == true){
      val = 'X';
      return 'X';
   }
   else if(on == true && off == false){
      val = '1';
      return '1';
   }
   else{
      val = '0';
      return '0';
   }
}

//Time it will take to be resolved
int Net::computeDelay(){
   int max_inputs = 0;
   int gateDelay = 0;
   int delay = 0;

   for(unsigned int i = 0; i < drivers->size(); ++i){
      for(unsigned int j = 0; j < ((*drivers)[i])->getInputs()->size(); ++j){
         //Check syntax later for dereferencing
         if(max_inputs < (((*(((*drivers)[i])->getInputs()))[i]))->getDelay()){
            max_inputs = (((*(((*drivers)[i])->getInputs()))[i]))->getDelay();
         }
      }
      gateDelay = ((*drivers)[i])->getDelay();
      if(delay < (max_inputs + gateDelay)){
         delay = max_inputs + gateDelay;
      }

      //Initializing the values for the next iteration in the loop
      max_inputs = 0;
      gateDelay = 0;
   }
   return delay;
}

//Print function
void Net::printDriversLoads(){
   //Prints the drivers
   for(unsigned int i = 0; i < drivers->size(); i++){
      cout<<"Name: "<<((*drivers)[i])->name()<<endl;
   }
   
   //Prints the loads
   for(unsigned int i = 0; i < loads->size(); i++){
      cout<<"Name: "<<((*loads)[i])->name()<<endl;
   }
   
}
