// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 22:		Header file for Lab 22
// Date:		July 2, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
// *****************************************************************

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std; 

#ifndef		LAB_22_HEAD_H		
#define		LAB_22_HEAD_H



/***********************************************************************
 This function generates SIZE many integers in the range of 0 and 9999 
 and loads these random integer to the list
 ***********************************************************************/
/*void loadList(int list[], const int SIZE) 
{
	unsigned seed; 
	
	//get a random seed
	cout<<"Enter a random seed => "; 
	cin>>seed; 
	srand(seed); 
	
	//generate random numbers and load them to the list
	for (int i=0; i<SIZE; i++)
	{
		list[i] = rand()%10000;
	}
	
	return;
}
*/
/***********************************************************************
 This function does linear search to see if the target vaule is in the
 list or not. If yes, it returns the position of the target in the list
 otherwise it returns -1.
 Note: count is an output paramter to record the number of comparisons
 during the search
 ***********************************************************************/
/*int linearSearch(const int list[], const int value, int & count, const int SIZE) 	
{
	//set initial value for count
	count = 0; 

	for (int i=0; i<SIZE; i++)
	{
		count++; 
		if (list[i]==value)		//found the target
		{
			return i; 
		}

	}

	//if not return is done in the for-loop, then target is not in the list
	return -1; 

}
*/
/************************************************************************
 This function print all numbers in the list. 
 ************************************************************************/
/*void showList(const int list[], const int SIZE)
{
	cout<<"The list is ..... " <<endl; 
	for (int i=0; i<SIZE; i++)
	{
		cout<<setw(8)<<right<<list[i]; 
		if ((i+1)%10==0)
			cout<<endl; 
	}
	cout<<endl; 

}/*

/*********************************************************************
This is my part
**********************************************************************/
void loadWordList (string list [], const int SIZE)
{
	ifstream inFile;
	list [SIZE]; 
	inFile.open("lab_24_txt.txt"); 
	if(!inFile)
	{
		cout<<"Fail to open lab_24_txt.txt, and stop ."<<endl; 
	}
	for (int i = 0; i<SIZE; i++)
	{
		inFile >> list [i];

	}
	inFile.close();
}
int linearWordSearch(string list[], string name, int & count, const int SIZE) 	
{
	//set initial value for count
	count = 0; 

	for (int i=0; i<SIZE; i++)
	{
		count++; 
		if (list[i]==name)		//found the target
		{
			return i; 
		}

	}

	//if not return is done in the for-loop, then target is not in the list
	return -1; 

}
void showWordList (string list[], const int SIZE)
{
	cout<<"The list is ..... " <<endl; 
	for (int i=0; i<SIZE; i++)
	{
		cout<<setw(8)<<right<<list[i]; 
		if ((i+1)%10==0)
			cout<<endl; 
	}
	cout<<endl; 

}
#endif