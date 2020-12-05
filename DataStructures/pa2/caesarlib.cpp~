/* 
caesarlib.cpp

Author: Javier Jesus Macossay-Hernandez

Short description of this file:
*/

#include <fstream>
#include <iostream>
//I included this library because strlen function will be used
#include <cstring>
#include "caesarlib.h"

using namespace std;

// is this char an English letter?
bool is_letter(char ch) {

   //Checking if the char is a letter
   if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
      return true;
   }
   else{
      return false; 
   }
}

// return shifted image of ch (if ch not letter, don't shift)
// assumes 0 <= steps < 26
char image(char ch, int steps) {

   //calling the function that I already built
   bool check = is_letter(ch);
   
   
   if (check == true){
      //check if the letter is uppercase and setting the alphabet as a
      //cycle
      if (ch >= 'A' && ch <= 'Z'){
         for (int i = 0; i < steps; i++){
            ch++;
            //if it's not a letter, replace it with an 'A'
            if(ch > 'Z'){
               ch = 'A';
            }
         }
      
      }
      //check if the letter is lowercase and setting the alphabet as a
      //cycle
      if(ch >= 'a' && ch <= 'z'){
         for (int i = 0; i < steps; i++){
            ch++;
            //if it's not a letter, replace it with an 'a'
            if(ch > 'z'){
               ch = 'a';
            }
         }
      
      }
   }
   return ch;
}

// shift all characters in this file and print it to cout
// return 1 if error (file couldn't be opened), 0 if no error
int print_file_image(const char filename[], int steps) {
   //declaring the variables and creating the object ifile
   char line [80];
   ifstream ifile(filename);
   
   //check if ifile worked
   if (!ifile.fail()){
   ifile.getline(line, 80);   //copy the line in my char array
      
      //loop it until it stops working
      while (!ifile.fail()){
         
         //send all the char's to image function and print it out.
         for (int i = 0; i < strlen(line); i++){
            cout<<image(line[i], steps);
         }
                     
         cout<<endl;  
         ifile.getline(line,80);
      }
      
      //close the file
      ifile.close();
      return 0;   
   }
   else{
      return 1;
   }
}

