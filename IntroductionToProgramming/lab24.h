// *****************************************************************
// Author:		Zhixiang Chen
// Class:		CSCI/CMPE 1170, Spring 2009
// Lab 24:		Bubble sort
// Date:		January 12, 2009
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
// *****************************************************************

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std; 

#ifndef		LAB_24_HEAD_H		
#define		LAB_24_HEAD_H

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
 This function does bubble sort. The output paramter count reports
 the number of comparisons to show the time performance.
 ***********************************************************************/
/*void bubbleSort(int list[], int & count, const int SIZE) 	
{
	//local vars
	int temp;							//local var to help swap two numbers
	bool swap;							//flag to see if there is one swap in a pass
	int i, j;							//loop vars

	//set initial value for count
	count = 0; 

	for (i = 0; i < SIZE; i++)			//outer loop controls the bubbling passes 
	{
		swap = false;					//no swap at the beginning for the current pass
		for (j = 0; j < SIZE - i - 1; j++)		//inner loop does the bubbling for the current pass
		{
			if (list[j] > list [j+1])	//list[j] and list[j+1] are in wrong order
			{
				swap = true;			//one swap happened

				temp = list[j];			//the three statements do swaping
				list[j] = list[j+1]; 
				list[j+1] = temp; 

				count++;				//record the comparisons
			}
		}

		if(!swap)						//no swap in the current pass
			break;						//means the list is sorted so break out
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

/*****************
This is my part
*****************/
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
void bubbleWordSort(string list[], int & count, const int SIZE) 	
{
	//local vars
	string temp;							//local var to help swap two numbers
	bool swap;							//flag to see if there is one swap in a pass
	int i, j;							//loop vars

	//set initial value for count
	count = 0; 

	for (i = 0; i < SIZE; i++)			//outer loop controls the bubbling passes 
	{
		swap = false;					//no swap at the beginning for the current pass
		for (j = 0; j < SIZE - i - 1; j++)		//inner loop does the bubbling for the current pass
		{
			if (list[j] > list [j+1])	//list[j] and list[j+1] are in wrong order
			{
				swap = true;			//one swap happened

				temp = list[j];			//the three statements do swaping
				list[j] = list[j+1]; 
				list[j+1] = temp; 

				count++;				//record the comparisons
			}
		}

		if(!swap)						//no swap in the current pass
			break;						//means the list is sorted so break out
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