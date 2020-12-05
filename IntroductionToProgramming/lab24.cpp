// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 24:		Bubble sort 
// Date:		July 3, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-----------------------------------------------------------------
//
// This lab exercise is to show how to do bubble sort.
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

#include "lab24.h" 

using namespace std; 

int main( )
{
	/*const int SIZE=1000;		//list or array size
	int list[SIZE];				//list or array
	int count;					//comparisons of performance metric

	//load list with random numbers
	loadList(list, SIZE); 
		
	//show list
	cout<<"Before sorting, the list is ....." <<endl; 
	showList(list, SIZE); 

	//linear search 
	bubbleSort(list, count, SIZE); 
	
	//show list
	cout<<"After sorting, the list is ......" <<endl; 
	showList(list, SIZE); 
	
	//show count
	cout<<"The number of comparisons for bubble sort is "<<count<<endl; */

	/******************************************************************
	 This part is for you: Write a bubble sort to sort a list of words.
	 You need to implement the dollowing functions: 
	 (1) loadWordList(...) //this function loads words from data file 
		 "lab_24_data.txt"
	 (2) BubbleWordSort(...)
	 (3) showWordList(...)
	 and have a similar driver to test your implementation.
	 ******************************************************************/
	const int SIZE=1000;		//list or array size
	string list[SIZE];				//list or array
	int count;					//comparisons of performance metric

	//load list with random numbers
	loadWordList(list, SIZE); 
		
	//show list
	cout<<"Before sorting, the list is ....." <<endl; 
	showWordList(list, SIZE); 

	//linear search 
	bubbleWordSort(list, count, SIZE); 
	
	//show list
	cout<<"After sorting, the list is ......" <<endl; 
	showWordList(list, SIZE); 
	
	//show count
	cout<<"The number of comparisons for bubble sort is "<<count<<endl;


	//well done and exit
	return 0; 
}