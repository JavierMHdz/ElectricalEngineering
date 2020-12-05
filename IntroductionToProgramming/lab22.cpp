// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 22:		Linear search 
// Date:		July 2, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-----------------------------------------------------------------
//
// This lab exercise is to show how to do linear search. 
//
// Compile and run your program. When everything is fine,
// print your .cpp and .h files and turn them to me or the TA.
// *****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

#include "lab22.h" 

using namespace std; 

int main( )
{
/*	const int SIZE=100;			//list or array size
	int list[SIZE];				//list or array
	int value;					//tagert value 
	int count;					//comparisons of performance metric
	int pos;					//position of the target if found or -1
	char choice;				//flag for yes or no choice

	//load list with random numbers
	loadList(list, SIZE); 
		
	//show list
	showList(list, SIZE); 
	
	//loop to play search again and again 
	do 
	{
		//get a target value
		cout<<"Enter a target value to for linear search: "; 
		cin>>value; 

		//linear search 
		pos = linearSearch(list, value, count, SIZE); 
	
		if (pos == -1)
			cout<< "The target "<<value <<" is not in the list"<<endl; 
		else
		cout<< "The target "<<value <<" is in the list at position "<<pos<<endl; 
		cout<<" The number of comparions is " <<count <<endl; 

		//get a choice
		cout<<"Want to play again (y/n)? => "; 
		cin>>choice; 
	}while (toupper(choice) == 'Y'); 
	*/

	/******************************************************************
	 This part is for you: You shall follow the above approaches to
	 implement linear search for a list of words. That is, you need to 
	 implement the following three functions: 
	 (1) loadWordList(...)
	 (2) linearWordSearch(...)
	 (3) showWordList(...)
	 and have a similar loop to test your implementation.
	 ******************************************************************/
	const int SIZE=1000;			//list or array size
	string list[SIZE];				//list or array
	string name;					//tagert value 
	int count;					//comparisons of performance metric
	int pos;					//position of the target if found or -1
	char choice;				//flag for yes or no choice

	//load list with random numbers
	loadWordList(list, SIZE); 
		
	//show list
	showWordList(list, SIZE); 
	
	//loop to play search again and again 
	do 
	{
		//get a target value
		cout<<"Enter a target value to for linear search: "; 
		cin>>name; 

		//linear search 
		pos = linearWordSearch(list, name, count, SIZE); 
	
		if (pos == -1)
		{
			cout<< "The target "<<name <<" is not in the list"<<endl;
		}
		else
		{
			cout<< "The target "<<name <<" is in the list at position "<<pos<<endl; 
			cout<<" The number of comparions is " <<count <<endl; 
		}
		//get a choice
		cout<<"Want to play again (y/n)? => "; 
		cin>>choice; 
	}while (toupper(choice) == 'Y');


	//well done and exit
	return 0; 
}