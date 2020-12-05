/* 
shift.cpp

Author: Javier Jesus Macossay-Hernandez

Short description of this file:
*/

#include "caesarlib.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
   if (argc != 3) {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: shift message.txt shift_number" << endl;
      return 1;
   }
   
   // read the arguments and print the shifted output
   //convert argv[2] argument into an integer
   int result = print_file_image(argv[1],atoi(argv[2]));
   
   // return sensible error if the filename is wrong
   if (result != 0) {
      cout << "Couldn't open the input file." << endl;
      return 1;
   }
   
   return 0;
}
