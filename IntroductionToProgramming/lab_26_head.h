// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez
// Class:		CSCI 1380-01, Summer I 2013
// Lab 26:		Header file for Lab 26
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

#ifndef		LAB_26_HEAD_H		
#define		LAB_26_HEAD_H

/***********************************************************************
 This function generates SIZE many integers in the range of 0 and 99 
 and loads these random integer to the list
 ***********************************************************************/
void loadList(int list[], const int SIZE) 
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
}

/***********************************************************************
 This function does insertion sort. The output paramter count reports
 the number of comparisons to show the time performance.
 ***********************************************************************/
void insertionSort(int list[], int & count, const int SIZE) 	
{
	//local vars
	int temp;								//to help swap to elements
	int i, j;								//loop vars
	bool stop;		

	//set initial value for count
	count = 0; 

	for (i = 0; i < SIZE-1; i++)			//outer loop controls the bubbling passes 
	{
		stop = false;
		for (j = i+1; !stop && j >=1; j--)	//inner loop inserts list[i+1] to the right position
		{
			count++;						//record the comparisons
			if (list [j]<list[j-1])			//list[j] is in wrong place so need to be swaped with list[j-1]
			{			
				temp = list[j-1];			//swap list[j] and list[j-1]
				list[j-1] = list[j]; 
				list[j] = temp; 
			}
			else 
				stop=true;					//stop
		}
	}

	//finish and stop
	return; 

}

/************************************************************************
 This function print all numbers in the list. 
 ************************************************************************/
void showList(const int list[], const int SIZE)
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