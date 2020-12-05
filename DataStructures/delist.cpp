#include "delist.h"
#include <cstddef>
#include <iostream>

using namespace std;

//constructor
DEList::DEList(){
   //display a message to the user
   cout<<"Creating DEList object"<<endl;
   //set pointers to NULL
   head = NULL;
   tail = NULL;
}
//destructor (free all memory for each item
DEList::~DEList(){
   //display a message to the user
   cout<<"Deleting DEList object"<<endl;
   while(!empty()){
      //emptying the list and errasing the data
      pop_front();
   }
}

//Returns true if the list is empty
bool DEList::empty(){
   return (head == NULL);
}

//Returns the number of items in the list
int DEList::size(){
   int cnt = 0;
   DEItem* curr = head;
   //coun the number of structs in the list
   while(curr!=NULL){
      cnt++;
      curr = curr->next;
   }
   return cnt;
}

//return the front value of the list
int DEList::front(){
   if(!empty()){
      return head->val;
   }
   return -1;
}

//return the last value of the list
int DEList::back(){
   if(!empty()){
      return tail->val;
   }
   return -1;
}

//adding a struct at the beginning of the list
void DEList::push_front(int new_val){
   DEItem* dummy = new DEItem;
   dummy->val = new_val;
   dummy->next = head;
   //prev is pointing anywhere
   dummy->prev = NULL;
   if(!empty()){
      dummy->next->prev = dummy;
   }
   else{
      //if the list is empty
      tail = dummy;
   }
   head = dummy;
}

//Add a new integer, new_val, to th back of the list
void DEList::push_back(int new_val){
   DEItem* dummy = new DEItem;
   dummy->val = new_val;
   //next is pointing anywhere
   dummy->next = NULL;
   if(empty()){
      dummy->prev = NULL;
      head = dummy;
      tail = dummy;
   }
   else{
      //List already has some items
      dummy->prev = tail;
      tail->next = dummy;
      tail = dummy;
   }
}

//deleting the first struct of the list
void DEList::pop_front(){
   int counter = size();
   //if there is more than one struct
   if(counter>1){
      DEItem* temp = head;
      head = head->next;
      head->prev = NULL;
      delete temp;
   }
   //only one struct
   else if (counter == 1){
      delete head;
      //setting both pointers to NULL
      head = NULL;
      tail = NULL;
   }
   //if the list is empty
   else{
      cout<<"The DEList object is empty"<<endl;
   }
}

//deleting the last struct of the list
void DEList::pop_back(){
   int counter = size();
   //if there is more than one struct
   if(counter>1){
      DEItem* temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete temp;
   }
   //only one struct
   else if(counter == 1){
      delete tail;
      //setting both pointers to NULL
      head = NULL;
      tail = NULL;
   }
   //if the list is empty
   else{
      cout<<"The DEList object is empty"<<endl;
   }
}
