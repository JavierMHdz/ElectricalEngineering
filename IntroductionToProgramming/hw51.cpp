// *****************************************************************
// Author:		Jesus Alberto Hernandez
// Class:		CSCI 1380.01, Summer 2013
// Lab 26:		Insertion sort 
// Date:		July 3, 2013
//
// Write a C++ program which will generate a list of signed random numbers, 
// find the average of all the numbers, the average of the positive and negative numbers, 
// and the largest e number. In addition, you r program shall perform bubble sorting, 
// linear searching and binary searching of the list.
// *****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

#include "hw51.h" 

using namespace std; 

int main( )
{
	ofstream outFile; 
	const int SIZE = 1000; 
	int list[SIZE];
	int list2[SIZE]; 
	int count, largest; 
	double avg, avgP, avgN; 
	string tag; 
	int num, position;  


	//generate the random int list of positive and negative values
	randomList(list, SIZE); 

	//call avgs to find respective averages 
	avg = avgP = avgN = 0; 
	avgs (list, SIZE, avg, avgP, avgN); 

	//find the largest int in the list
	largest =  max (list, SIZE); 

	//output the list and the statistical info
	outFile.open("hw5.txt"); 
	printList(outFile, list, SIZE, avg, avgP, avgN, largest); 
	outFile.close(); 


	//do bubble sort
	//copy list list 2
	for (int i=0; i<SIZE; i++)
		list2[i] = list[i]; 
	
	//sort list 2
	bubbleSort(list2, count, SIZE); 
	cout<<" completed buble in " << count <<" comparisons " <<endl; 
	
	while (true)
	{	
		//test linear search
		cout<<" give me an int for linear serach "; 
		cin>>num; 
		count = 0; 
		if (linearSearch(list, SIZE, count, num))
		{
			cout<< " found " << num <<" in the list  in " << count << " comparisons" <<endl; 
		}
		else 
		{
			cout<< " failed to find " << num <<" in the list  in " << count << " comparisons" <<endl; 
		}


		cout<<" give me an int for binary serach "; 
		cin>>num; 
		count = 0; 
		position = binarySearch(list2, num, count, SIZE);  
		if (position >= 0)
		{
			cout<< " found " << num <<" in the list  at position "
				<<position<<" in " << count << " comparisons" <<endl; 
		}
		else 
		{
			cout<< " failed to find " << num <<" in the list  in " << count << " comparisons" <<endl; 
		}
		
		cout<<" want to try another search test (yes/no)? "; 
		cin>>tag; 
		if (tag != "yes")
		{
			cout<<" got enough, see you later! " <<endl; 
			break; 
		}	
	}

	//well done and exit
	return 0; 
}