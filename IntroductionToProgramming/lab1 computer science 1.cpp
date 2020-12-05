// **********************************************************************
// Author:		Javier Jesus Macossay-Hernandez
// Class:		CSCI 1380-01, Summer I 2013
// Lab 1:		Hello There! Play characters, strings, and numbers
// Date:		June 3, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//------------------------------------------------------------------------ 
//
// Write a program to ask the user whether he/she like C++.
// ask his/her score for this class and then decide the grade for him/her.
// Do some arithmetic operations.
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// ************************************************************************

#include <iostream>
#include <string>
using namespace std; 

int main( )
{
	//variable declarations
	string firstName, lastName, answer;	//vars to store names and answer
	float score;						//var to store score
	char grade;							//var to store grade
	int number1, number2, result;		//vars to store two numbers and the result

	//Prompt user to enter names
	cout<<"What is your first name? "; 
	cin>>firstName; 
	cout<<"What is your last name? "; 
	cin>>lastName; 

	cout << "Hello, "<< firstName << " " << lastName <<"!\n"; 

	//get answer
	cout<<" Do you like C++? (yes/no)"; 
	cin>>answer;

	//get the score
	cout<<" What is your score for this class? "; 
	cin>>score; 

	//display greeting
	cout<<endl<<endl<<firstName <<"  "<<lastName <<"  "; 
	if (answer=="yes")
		cout<< "likes C++." <<endl; 
	else
		cout<< "does not likes C++." <<endl;
	if (score >= 90 )
		grade = 'A'; 
	else if (score >= 80)
		grade = 'B'; 
	else if (score >= 70)
		grade = 'C'; 
	else
		grade = 'F'; 
	cout<< " And, your grade is " <<grade <<".\n\n"; 



	//play with arithmetic operations
	cout<<" Let do some math operations.\n"; 
	cout<< " Give me one integer => "; 
	cin>>number1; 
	cout<<" Give another integer => "; 
	cin>> number2; 

	//do addition
	cout<< number1 <<"  +  " <<number2 <<"  =  ? "; 
	cin>>result; 
	if (number1 + number2 == result )
		cout<< "Very good, you are right!\n"; 
	else 
		cout<<" Too bad, you are wrong. \n\n"; 

	//do subtraction

	cout<< number1 <<"  -  " <<number2 <<"  =  ? "; 
	cin>>result; 
	if (number1 - number2 == result )
		cout<< "Very good, you are right!\n"; 
	else 
		cout<<" Too bad, you are wrong. \n\n"; 

	//do multiplication

	cout<< number1 <<"  *  " <<number2 <<"  =  ? "; 
	cin>>result; 
	if (number1 * number2 == result )
		cout<< "Very good, you are right!\n"; 
	else 
		cout<<" Too bad, you are wrong. \n\n"; 

	//do division

	cout<< number1 <<"  /  " <<number2 <<"  =  ? "; 
	cin>>result; 
	if (number1 / number2 == result )
		cout<< "Very good, you are right!\n"; 
	else 
		cout<<" Too bad, you are wrong. \n\n"; 

	//complete the work
	return 0;

}
