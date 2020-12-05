// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 25:		Header files for Lab 25
// Date:		July 4, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
// *****************************************************************

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std; 

#ifndef		LAB_25_HEAD_H		
#define		LAB_25_HEAD_H

/***********************************************************************
 This function generates SIZE many integers in the range of 0 and 99 
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
		list[i] = rand()%100;
	}
	
	return;
}*/

/***********************************************************************
 This function does selection sort. The output paramter count reports
 the number of comparisons to show the time performance.
 ***********************************************************************/
/*void selectionSort(int list[], int & count, const int SIZE) 	
{
	//local vars
	int smallestPos;				//local var to record the postion of the smallest element in the current pass
	int temp;						//to help swap to elements
	int i, j;						//loop vars

	//set initial value for count
	count = 0; 

	for (i = 0; i < SIZE; i++)					//outer loop controls the bubbling passes 
	{
		smallestPos=i;							//initialize largePos to i
		for (j = i+1; j < SIZE; j++)			//inner loop does the bubbling for the current pass
		{
			count++;							//record the comparisons
			if (list[j] < list [smallestPos])	//find a smaller element
			{
				smallestPos = j;				//record the pos of the smaller element				
			}
		}
		if (list[i] > list[smallestPos])		//do swap
		{
			temp = list[i];						//the three statements do swaping
			list[i] = list[smallestPos]; 
			list[smallestPos] = temp; 
		}
	}

	//finish and stop
	return; 

}*/

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

}*/
/*********************
This is my part
*********************/
void loadWordList (string list [], const int SIZE)
{
	ifstream inFile;
	list [SIZE]; 
	inFile.open("lab_24_txt.txt"); 
	inFile.seekg(ios::beg);
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
void selectionWordSort(string list[], int & count, const int SIZE) 	
{
	//local vars
	int smallestPos;				//local var to record the postion of the smallest element in the current pass
	string temp;						//to help swap to elements
	int i, j;						//loop vars

	//set initial value for count
	count = 0; 

	for (i = 0; i < SIZE; i++)					//outer loop controls the bubbling passes 
	{
		smallestPos=i;							//initialize largePos to i
		for (j = i+1; j < SIZE; j++)			//inner loop does the bubbling for the current pass
		{
			count++;							//record the comparisons
			if (list[j] < list [smallestPos])	//find a smaller element
			{
				smallestPos = j;				//record the pos of the smaller element				
			}
		}
		if (list[i] > list[smallestPos])		//do swap
		{
			temp = list[i];						//the three statements do swaping
			list[i] = list[smallestPos]; 
			list[smallestPos] = temp; 
		}
	}

	//finish and stop
	return; 

}
void showWordList(string list[], const int SIZE)
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