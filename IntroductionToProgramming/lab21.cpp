// ******************************************************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 21:		Arrays of structures
// Date:		June 18, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-------------------------------------------------------------------------------------------------------
//
// This lab exercise is to show how to process an array of structures.
// The problem is to define a structure type to represent a students in class CSCI 1370
// and use an array of the structure to represent all students in the class. 
// 
// The structure studentType consists of the following members( or fields): 
// (1) studentFirstName, (2) studentLastName, (3) studentID, (4) a double array to 
// store value of attendance, hw1, hw2, hw3, hw4, hw5, hw6, quiz, test1, test2, test3, 
// (5) score for the class, and (6)  letter grade. 
//
// Once the studentTpye has been defined, we shall declare an array of studentType to represent all 
// students in the class. 
//
// The data is stored in file "lab_20_data.txt", and shall be loaded into the array.
//
// The formula to calculate the scores of attendance 5%, quiz 5%, homework 30%, tests 60%. 
// The grade is decided as follows: A if score >= 90, B if 80<= score <90, C if 70<= score < 80, 
// D if 60 <= score <70, and F otherwise.
//
// Compile and run your program. When everything is fine,
// print your .cpp and .h files and turn them to me or to the TA
// ********************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

//define a const array size
const int SIZE = 35;				//class size				
const int COLUMN = 11;				//column size

#include "lab21.h" 

using namespace std; 

int main( )
{
	

	//declare an array of studentType to class CSCI 1370
	studentType csci1370[SIZE];		//for att, quiz, hw, tests and score

	//file var
	ifstream inFile;				//input file


	//open file
	inFile.open("lab_20_data.txt"); 
	if(!inFile)
	{
		cout<<"Fail to open lab_20_data.txt, and stop ."<<endl;
		return 1; 
	}

	//initialize array letterStata
	loadData(inFile, csci1370, SIZE, COLUMN);

	//close inFile
	inFile.close(); 

	//compute score and grades
	grading(csci1370, SIZE, COLUMN); 

	//show grades
	showGrades(csci1370, SIZE, COLUMN); 
	
	//well done and exit
	return 0; 
}