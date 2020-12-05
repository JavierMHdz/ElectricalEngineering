#include <map>
#include <vector>
#include "student.h"
#include <iostream>

using namespace std;

int main(){
   int option, index, score, totalSize;
   double average;
   string student;
   map<string, Student> stumap;
   
   //asking the user for input
   
   do{
      cout<<"Please enter a command number"<<endl;
      cout<<"1 =  Add new student"<<endl;
      cout<<"2 = Remove student"<<endl;
      cout<<"3 = Add a new score to all student objects"<<endl;
      cout<<"4 = Update score: i for student, s to the provided value"<<endl;
      cout<<"5 = Calculate average"<<endl;
      cout<<"6 = Print student names and scores"<<endl;
      cout<<"7 = Exit program"<<endl;
      
      cin>>option;
      cout<<endl;
      
      if(option == 1){
         //ask the user for a student's first name
         cout<<"Please enter the student's first name: ";
         cin>>student;
         
         //adding them to the map;
         Student s(student);
         stumap.insert(make_pair(student, s));
      }
      else if (option == 2){
         //ask the user for a student's first name
         cout<<"Please enter the student's first name: ";
         cin>>student;
         cout<<endl;
         
         //check if the student exists
         map<string, Student>::iterator it;
         bool check = false;
         for (it = stumap.begin(); it != stumap.end(); ++it){
            if(it->first == student){
               check = true;
            }
         }
         
         //remove the student object from the map
         if(check == true){
            stumap.erase(student);
         }
         else{
            cout<<"That student does not exist."<<endl;
         }
      }
      else if (option == 3){
         //calling the function add_grade
         map<string, Student>::iterator it;
         for (it = stumap.begin(); it != stumap.end(); ++it){
            (it->second).add_grade(0);
         }
      }
      else if (option == 4){
         //ask the user for a student's first name
         cout<<"Please enter the student's first name: ";
         cin>>student;
         
         //index into the grades vector
         cout<<"Please enter an index into the grades vector starting in 0: ";
         cin>>index;
         
         //updated score
         cout<<"Please enter an updated score: ";
         cin>>score;
         cout<<endl;
         //check if the student exists
         map<string, Student>::iterator it;
         bool check = false;
         for (it = stumap.begin(); it != stumap.end(); ++it){
            if(it->first == student){
               check = true;
            }
         }
         
         //update the score at that index for the given student
         if(check == true){
            vector<int> grades = stumap[student].get_grades();
            //this if statement is to avoid segmentation fault
            if(index >= 0 && index < grades.size()){
               stumap[student].update_grade(index, score);
            }
            else{
               cout<<"The index is incorrect. Please check your information."<<endl;
            }
         }
         else{
            cout<<"The student does not exist in the list. Please check your information."<<endl;
         }

      }
      else if(option == 5){
         average = 0;
         totalSize = 0;
         //ask the user for an index into the grades vector
         cout<<"Please enter an index into the grades vector: ";
         cin>>index;
         cout<<endl;
         
         map<string, Student>::iterator it;
         for (it = stumap.begin(); it != stumap.end(); ++it){
            //this if statement is to avoid segmentation fault
            vector<int> grades = (it->second).get_grades();
            if(index >= 0 && index < grades.size()){
               average += (double)(it->second).get_grade(index);
            }
            totalSize++;
         }
         
         average = average/(double)totalSize;

         cout<<"The average is "<<average<<endl;

      }
      else if (option == 6){
         //printing each students' name and all of his/her scores in order
         map<string, Student>::iterator it;
         for (it = stumap.begin(); it != stumap.end(); ++it){
            vector<int> vecCheck = (it->second).get_grades();
            cout<<"Name of student: " <<(it->first)<<endl;
            cout<<"Grades: ";
            
            //printint out the values in the vector
            for(int i = 0; i < vecCheck.size(); i++){
               cout<<vecCheck[i]<<" ";
            }
            cout<<endl;
         }

      }
      else{
         cout<<"Goodbye!"<<endl;
      }
      cout<<endl;
   }while(option!=7 && option >= 1 && option <= 6);
   
   
   return 0;
}
