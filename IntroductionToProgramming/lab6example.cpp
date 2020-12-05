// **********************************************************************
// Author:		Javier Jesus Macossay-Hernandez
// Class:		CSCI 1380-01, Summer I 2013
// Lab 6:		Logical expressions and if statement
// Date:		June 7, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//------------------------------------------------------------------------
//
// This lab exercise is to play with logical expressions compised of 
// relational and logical operators, if-statements, if-else-statements,
// chained if-else-statements, nested if-statements
//
// The problem here is to compute the letter grade for the user when 
// the score is entered. The formula to do the calculation is as follows: 
// A if 90<=score; B is 80<=score <90; C if 70<=score<80; D if 
// 60 <=score <70; F if otherwise.
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// ************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

using namespace std; 

int main( )
{
	//variable declaration
	double score;           //var to store score for the class
	char choice;			// variable of the answer if you
							// want to repeat the program

	do
	{

	//ask for score from the user
	cout<<"What is your score for the class? ==> "; 
	cin>>score;

	
	/*************************************************************************
	Part A. Use if-statements only.	I did two statements and you do the rest.
	*************************************************************************/
	if (score >= 90)
		cout<< "Your grade is A." <<endl; 
	if (80 <= score && score < 90)
		cout<<"Your grade is B." <<endl;
	if (70 <= score && score <80)
		cout<<"Your grade is C."<<endl;
	if (60 <= score && score <70)
		cout<<"Your grade is D."<<endl;
	if (score <= 59)
		cout<<"Your grade is F."<<endl;


	/****************************************************************************
	Part B. Use if-else-statements only.I did two statements and you do the rest.
	*****************************************************************************/
	if (score >=90)
		cout<< "Your grade is A." <<endl; 
	else if (80 <= score)
		cout<<"Your grade is B." <<endl; 
	else if (70 <= score)
		cout<<"Your grade is C."<<endl;
	else if (60 <= score)
		cout<<"Your grade is D."<<endl;
	else if (score <= 59)
		cout<<"Your grade is F."<<endl;

	/****************************************************************************
	Part C. Use if-else-statements only.I did two statements and you do the rest.
	*****************************************************************************/
	if (score >70)
	{
		cout<< "You passed the class. And, your grade is " <<endl; 
		if (score >= 90)
			cout<<" A " <<endl; 
		//else if 
		/***** finish this part ******/ 
		else if (80 <= score)
			cout<<" B " <<endl;
		else if (70 <= score)
			cout<<" C " <<endl;
		else if (60 <= score)
			cout<<" D " <<endl;


	} 
	//else if 
	/***** finish this part *****/
	else if (score <= 59)

		cout<< "You did not pass the class. And, you grade is F" <<endl;

	//Run again the program

	cout<<"Do you want to play again? (y/n)"<<endl;
	cin>>choice;
	} while ( choice == 'y' );

	//well done and exit
	return 0; 
}
