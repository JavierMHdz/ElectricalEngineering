// **************************************************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 20:		Parrallell arrays and two dimensional arrays
// Date:		June 18, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------------------------------------------
//
// This lab exercise is to show how to process two dimensional arrays. 
// The problem is use to a 2-D array to store and process the following 
// class inform for CSCI 1370:
// 
// studentName	studentID attendance hw1 hw2 hw3 hw4 hw5 hw6 quiz test1 test2 test3 score grade
// 
// The data is stored in file "lab_20_data.txt". 
//
// You need to use five parallel arrays to store student firstName, lastName, ID, score, and grade. 
// In addition, you need a two dimensional array to store attendance, homework points, quizes, tests. 
// The formula to calculate the scores of attendance 5%, quiz 5%, homework 30%, tests 60%. 
// The grade is decided as follows: A if score >= 90, B if 80<= score <90, C if 70<= score < 80, 
// D if 60 <= score <70, and F otherwise.
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// ***************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

#include "lab20.h" 

using namespace std; 

int main( )
{
	//define a const array size
	const int SIZE = 35;				//class size				
	const int COLUMN = 11;				//column size

	//declare five parallel arrays for firstName, lastName, and ID
	string firstNames[SIZE],			//firstnames for students
		   lastNames[SIZE],				//last names for students
		   IDs[SIZE];					//IDs for students
	double scores[SIZE];				//scores for students
	char   grades[SIZE];				//letter grades

	//declare two dim array for class info
	double csci1370[SIZE][COLUMN];		//for att, quiz, hw, tests and score

	//file var
	ifstream inFile;					//input file

	int row, col;						//loop var

	//open file
	inFile.open("lab_20_data.txt"); 
	if(!inFile)
	{
		cout<<"Fail to open lab_20_data.txt, and stop ."<<endl;
		return 1; 
	}

	//initialize array letterStata
	loadData(inFile, firstNames, lastNames, IDs, csci1370, SIZE, COLUMN);

	//close inFile
	inFile.close(); 

	//compute score and grades
	grading(csci1370, scores, grades, SIZE, COLUMN); 

	//show grades
	showGrades(firstNames, lastNames, IDs, csci1370, scores, grades, SIZE, COLUMN); 
	
	//well done and exit
	return 0; 
}