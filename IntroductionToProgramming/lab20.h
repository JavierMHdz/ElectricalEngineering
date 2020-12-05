// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 20:		Header file for Lab 20
// Date:		June 18, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
// *****************************************************************

#include <iostream>
#include <cstring>
#include <string>

using namespace std; 

#ifndef		LAB_20_HEAD_H		
#define		LAB_20_HEAD_H



/********************************************************************
 This function gets class information from the input file and store
 the info to three parallel array and one two dim array.
 inFile: input file
 firstNames, lastNames, IDs: three output parallel arrays
 csci1370: two dim output array
 SIZE, COLUMN: two input parameters
 *********************************************************************/
void loadData(ifstream & inFile, 
			  string firstNames[], string lastNames[ ], string IDs[ ], 
			  double csci1370[][11], const int SIZE, const int COLUMN)
{
	
	char  str[1024]; 
	//skip the first three lines
	inFile.getline(str, 1080, '\n'); 
	cout<<str<<endl; 
	inFile.getline(str, 1080, '\n'); 
	cout<<str <<endl;
	inFile.getline(str, 1080, '\n'); 
	cout<< str<<endl; 

	for (int row = 0; row < SIZE; row++)
	{
		inFile	>> firstNames[row]					//get first name
				>> lastNames[row]					//get last name
				>> IDs[row];						//get ID

		for (int col = 0; col <COLUMN; col++)
		{
			inFile >> csci1370[row][col];			//get a row for csci1370
		}
	}
}

/*********************************************************************
 This function computes scores for each student and decides
 his/her grade. The formula to calculate the scores of attendance 5%, 
 quiz 5%, homework 30%, tests 60%. The grade is decided as follows:
 A if score >= 90, B if 80<= score <90, C if 70<= score < 80, 
 D if 60 <= score <70, and F otherwise.
 *********************************************************************/
void grading(const double csci1370[][11],			//input array
			 double scores[],						//output array for scores
			 char grades[],							//output array for grades
			 const int SIZE, const int COLUMN)		//input parameters
{
	double a,b,c,d;
	int att, hw1, hw2, hw3, hw4, hw5, hw6, t1, t2, t3, quiz;
	char  str[1024]; 
	//skip the first three lines
	inFile.getline(str, 1080, '\n'); 
	cout<<str<<endl; 
	inFile.getline(str, 1080, '\n'); 
	cout<<str <<endl;
	inFile.getline(str, 1080, '\n'); 
	cout<< str<<endl; 

	for (int row = 0; row < SIZE; row++)
	{
		inFile	>> csci1370[row].att					
				>> csci1370[row].hw1
				>> csci1370[row].hw2
				>> csci1370[row].hw3
				>> csci1370[row].hw4
				>> csci1370[row].hw5
				>> csci1370[row].hw6
				>> csci1370[row].t1
				>> csci1370[row].t2
				>> csci1370[row].t3
				>> csci1370[row].quiz;

		for (int col = 0; col <COLUMN; col++)
		{
			inFile >> csci1370[row][col];			//get a row for csci1370
		}
	}

	for (int row = 0; row < SIZE; row++)
	{
	a = csci1370[row].att * .05;
	b = csci1370[row].quiz * .05;
	c = ((csci1370[row].hw1+csci1370[row].hw2+csci1370[row].hw3+csci1370[row].hw4+csci1370[row].hw5+csci1370[row].hw6)/6) * .3;
	d = ((csci1370[row].t1 + csci1370[row].t2 + csci1370[row].t3 + csci1370[row].t4)/4) * .6;
	grades[] = a + b + c + d;
	}
	if (grades [] <= 90)
	{
		cout<<"Your grade is A" <<endl;
	}
	else if (grades[] <= 80)
	{
		cout<<"Your grade is B"<<endl;
	}
	else if (grades[] <= 70)
	{
		cout<<"Your grade is C"<<endl;
	}
	else if (grades[] <= 60)
	{
		cout<<"Your grade is D"<<endl;
	}
	else
	{
		cout<<"Your grade is F"<<endl;
	}
}

/****************************************************************
 This function displays class information for CSCI 1370 
 in some nice format.
 ****************************************************************/
void showGrades(const string firstNames[], 
				const string lastNames[], 
				const string IDs[], 
				const double csci1370[][11], 
				const double scores[], 
				const char grades[], 
				const int SIZE, const int COLUMN)
{
	for (int row=0; row<SIZE; row++)
	{
		//print name and ID the i-th student
		cout<<setw(7)<<left<<csci1370[row].firstName
			<<setw(7)<<left<<csci1370[row].lastName
			<<setw(7)<<left<<csci1370[row].ID;
	
		//print record of the i-th student
		for (int col=0; col<COLUMN; col++)
			cout<<setw(5)<<right<<setprecision(1)<<showpoint<<fixed<<csci1370[row].record[col]; 
		
		//print score and grdae
		cout<<setw(5)<<setprecision(1)<<showpoint<<fixed<<csci1370[row].score 
			<<setw(3)<<csci1370[row].grade;

		cout<<endl; 
	}
}


#endif