// *****************************************************************
// Author:		Jesus Alberto Hernandez
// Class:		CSCI 1380.01, Summer 2013
// Lab 26:		Header file for homework 5
// Date:		July 3, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
// *****************************************************************

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std; 

#ifndef		HW5_HEAD_H		
#define		HW5_HEAD_H


//This will generate a list of n integer values between 1 and 1000 and save these values in the list, 
//where n is already known
void randomList(int list[ ], const int n)
{
	int coin; 

	//reset random seed
	srand(time(0)); 
	for (int i=0; i<n; i++)
	{
		coin = rand()%100; 
		list[i] = 1 + rand()%999; 
		if (coin >50)
			list[i] = - list[i]; 
	}
}

//list is a one-dimensional array of integers and n is the number of elements 
//in that array. Both of these are input parameters to the function. 
//The function must calculate: 1) the average of the n integers in list 
//and return the result in avg, 2) the average of the positive numbers (> 0) 
//and return the result in avgP, and 3) the average of the negative numbers (< 0) 
//and return the result in avgN.
void avgs (const int list[ ], const int n, double &avg, double &avgP, double &avgN)
{
	double sum, pSum, nSum;
	int pNum, nNum; 
	sum = pSum = nSum = pNum = nNum = 0; 

	for (int i =0; i<n; i++)
	{
		sum += list[i]; 
		if (list[i] >0)
		{
			pSum += list[i]; 
			pNum++; 
		}
		if (list[i] <0)
		{
			nSum += list[i]; 
			nNum++; 
		}
	}
	avg = static_cast<double>(sum) / n; 
	avgP = static_cast<double>(pSum) / pNum;
	avgN = static_cast<double>(nSum) / nNum;
}


//list is a one-dimensional array of signed integers and 
//n is the number of elements in that array. 
//The function returns the value of the largest element in the array.
int max (const int list[ ], const int n)
{
	int largest; 
	largest = INT_MIN; 
	for (int i =0; i<n; i++)
	{
		if (list[i]> largest)
			largest = list[i]; 
	}
	return largest; 
}

//This will display, to both the display of the computer and 
//the output file, the list of values (nicely formatted) together 
//with the averages and the largest value
void printList(ofstream & outFile, const int list[ ], const int n, const double avg,
				const double avgP, const double avgN, const int largest)
{
	int i; 
	cout<<setprecision(4)<<showpoint<<fixed; 
	outFile<<setprecision(4)<<showpoint<<fixed; 

	for (i=0; i<n; i++)
	{
		cout<<setw(10)<<list[i]; 
		outFile<<setw(10)<<list[i]; 
		if ((i+1)%5 == 0)
		{
			cout<<endl; 
			outFile<<endl; 
		}
	}

	cout<<"\n\n the statistical info about the data list is " <<endl
		<<" the largest element is " << setw(10)<<largest<<endl
		<<" the avg is " << setw(10) << avg<<endl
		<<" the postive avg is " << setw(10) <<avgP<<endl
		<<" the negative avg is " << setw(10) <<avgN <<endl; 

	outFile<<"\n\n the statistical info about the data list is " <<endl
		<<" the largest element is " << setw(10)<<largest<<endl
		<<" the avg is " << setw(10) << avg<<endl
		<<" the postive avg is " << setw(10) <<avgP<<endl
		<<" the negative avg is " << setw(10) <<avgN <<endl; 
}


//This function searches for the given value in the list 
//using the linear search algorithm. It returns true if
//it finds the value in the list or false otherwise.
bool linearSearch(const int list[ ], const int n, int & count, const int value)
{
	for (int i=0; i<n; i++)
	{
		count++; 
		if (list[i] == value)
			return true; 
	}
	return false; 
}

//This function sorts the given list in increasing order using the bubble sort algorithm. It also returns
//the number of comparisons that were done during the sorting process to the output parameter counts.
void bubbleSort(int list[], int & count, const int N) 	
{
	//local vars
	int temp;							//local var to help swap two numbers
	bool swap;							//flag to see if there is one swap in a pass
	int i, j;							//loop vars

	//set initial value for count
	count = 0; 

	for (i = 0; i < N; i++)			//outer loop controls the bubbling passes 
	{
		swap = false;					//no swap at the beginning for the current pass
		for (j = 0; j < N - i - 1; j++)		//inner loop does the bubbling for the current pass
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


//This function searches for the given value in the list 
//using the binary search algorithm. It returns true if
//it finds the value in the list or false otherwise.
int binarySearch(const int list[], const int value, int & count, const int SIZE) 	
{
	//working vars
	int first =0,					//beginning of the search range
		last = SIZE-1,				//end of the search range; 
		middle,						//middle of the search range
		pos = -1;					//position for the target or -1 if not in the list
	bool found =false;				//flag for being found 

	//set initial value for count
	count = 0; 

	while (!found && first <=last) 
	{
		count++;					//count comparisons

		middle =(first + last)/2;	//middle range for binary division
		if(list[middle]==value)		//found
		{
			found = true; 
			pos = middle; 
		}
		else if (list[middle] > value)		//search the left half
			last = middle - 1;	
		else								//search the right half		
			first = middle + 1; 
	}

	return pos; 
}



#endif