/* 
crack.cpp

Author:

Short description of this file:
*/

#include "caesarlib.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

// frequencies of letters in a large sample of English
const double enfreq[26] = {0.0793, 0.0191, 0.0392, 0.0351, 0.1093,
   0.0131, 0.0279, 0.0238, 0.0824, 0.0024, 0.0103, 0.0506, 0.0277,
   0.0703, 0.0602, 0.0274, 0.0019, 0.0705, 0.1109, 0.0652, 0.0321,
   0.0098, 0.0093, 0.0026, 0.0156, 0.0040};

// return score when ch is shifted (if ch not letter, return 0)
double char_score(char ch, int shift) {
   //check if it's a letter
   bool check = is_letter(ch);
   
   //process the char if it's a letter
   if(check == true){
      //call the image function
      ch = image(ch, shift);
      
      //convert the char into a integer to later use it as a subscript for
      //the array and return the score
      if(ch >= 'A' && ch <= 'Z'){
         ch = ch-'A';
      }
      else{
         ch = ch-'a';
      }
      return enfreq[(int)ch];
   }
   else{
      return 0;
   }
}

// return score when contents of entire file are shifted
double file_score(const char filename[], int shift) {
   //declaring the variables and creating the ifile object
   double totalScore = 0;
   char line [80];
   ifstream ifile(filename);
   
   if(ifile.good()){
   //copying the line into the line array
    ifile.getline(line, 80);
    
      while(ifile.good()){
         
         //adding the total scores of the whole line and later of the text
         for(int i = 0; i < strlen(line); i++){
            totalScore += char_score(line[i], shift);
         }
         ifile.getline(line,80);
      } 
      
   }
   
   //copying the ifile object
   ifile.close();
   return totalScore;
}

/*
// crack.cpp test main
int main() { 
   cout << char_score('A', 3) << " ";
   cout << char_score('x', 10) << " ";
   cout << char_score('?', 3) << endl;
   cout << file_score("secret.txt", 0) << " ";
   cout << file_score("secret.txt", 1) << endl;
   return 0;
}
*/

// actual main
int main(int argc, char* argv[]) {
   if (argc != 2) {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: crack ciphertext.txt" << endl;
      return 1;
   }
   
   //declare the variables
   int shiftMaxScore = 0;
   double score = 0;
   double maxScore = 0;
   
   //do 25 shifts and find the maximum score
   for (int i = 0; i <= 25; i++){
      
      score = file_score(argv[1], i);
      
      //save the maximum score and the i value for that maximum score
      if(maxScore < score){
         maxScore = score;
         shiftMaxScore = i;
      }
   }
   
   //call the print_file_image function to shift the text
   print_file_image(argv[1], shiftMaxScore);
   
   return 0;
}
