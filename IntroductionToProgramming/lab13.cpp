// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 13:		Nested loops 
// Date:		June 13, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------- 
//
// This lab exercise is to practice two nested loops.
// The problem is to read integers from an input file line by line. 
// find simple stats for each line. 
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// *****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>
#include <limits.h>

using namespace std; 

int main( )
{
	//input file objects
	ofstream outFile;			//output file 
	ifstream inFile;			//input file

	//variable declarations
	int number;					//var to store an int value
	int sum, min, max, avg;		//vars to store simple statistical info
	int counter;				//a counter for controling the loop
	int size;					//another counter
	int row, col;				//loop variable for rows and columns

	/************************************************************
	Part A. Create a data file data.txt in range of 0 to 9999
	As assume 10 lines, each line with 8 random numbers 
	in the range
	************************************************************/
	//use two nested for-loops to create the data file 
	//open data.txt
	/*
	outFile.open("data.txt"); 
	
	if (outFile.fail())
	{
		cout<<"failed to open data.txt so break ...... "<<endl; 
		return 1; 
	}
	for (row = 0; row < 10; row++)						//outer loop for rows/lines
	{
		srand(row);										//set random seed
		
		for (col = 0; col < 8; col++)					//inner loop for columns/number per row
		{
			outFile <<setw(10)<<right<< rand()%10000;	//generate a random number between 0 and 9999
		}
		if (row != 9)									//move to next line
			outFile <<endl;								//but do not move at the last line
	}
	//close outFile
	outFile.close(); 
	*/

	/************************************************************
	Part B. Use two nested for-loops to process data.txt
	************************************************************/
	/*
	cout<<" Use two nested for-loops to process data.txt "<<endl; 
	
	//open data.txt for input
	inFile.open("data.txt");
	inFile.seekg(ios::beg);

	for (row = 0; row < 10; row++)			//outer loop to process rows/lines
	{
		//initialization
		sum=counter=max=avg =0;
		min=INT_MAX;						//min has the maximum integer valued assigned//changed by sirisha						
		max=INT_MIN;
		size = 8; 

		for (col = 0; col < 8; col++)		//inner loop to process column/numbers in a row
		{
			inFile>>number;					//get next number		
			sum += number;			
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
		}
		
		//show stats for each row
		cout<<" \nStatistical info about row " << row +1 <<" is "<<endl
		<<" \t The sum is " << setw(10)<<right<<sum << endl 
		<<" \t The min is " << setw(10)<<right<<min << endl
		<<" \t The max is " << setw(10)<<right<<max << endl
		<<" \t The Avg is " << setw(10)<<right
		<<setprecision(4)<<fixed<<showpoint
		<<static_cast<double> (sum) / static_cast<double> (size) << endl; 
	} 
	inFile.close(); 
	*/

	
	/*******************************************************************
	 Part C. This is for you: Re-do Part B with two nested while-loops
	 *******************************************************************/
	
	cout<<" Use two nested while-loops to process data.txt "<<endl; 
	
	//open data.txt for input
	inFile.open("data.txt");
	inFile.seekg(ios::beg);


	row = 0; //row value
	while (row < 10)			//outer loop to process rows/lines
	{
		//initialization
		sum=counter=max=avg =0;
		min=INT_MAX;						//min has the maximum integer valued assigned//changed by sirisha						
		max=INT_MIN;
		size = 8; 
		col=0;
		while (col < 8)		//inner loop to process column/numbers in a row
		{
			inFile>>number;					//get next number		
			sum += number;			
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
			col++;
		}
		
		//show stats for each row
		cout<<" \nStatistical info about row " << row +1 <<" is "<<endl
		<<" \t The sum is " << setw(10)<<right<<sum << endl 
		<<" \t The min is " << setw(10)<<right<<min << endl
		<<" \t The max is " << setw(10)<<right<<max << endl
		<<" \t The Avg is " << setw(10)<<right
		<<setprecision(4)<<fixed<<showpoint
		<<static_cast<double> (sum) / static_cast<double> (size) << endl; 

		row++;
	} 
	inFile.close(); 

	/*********************************************************************
	 Part D. This is for you: Re-do Part B  with two nested do-while-loops
	 *********************************************************************/
	cout<<" Use two nested do-while-loops to process data.txt "<<endl; 
	
	//open data.txt for input
	inFile.open("data.txt");
	inFile.seekg(ios::beg);

	row = 0; //row value
	do										//outer loop to process rows/lines
	{
		//initialization
		sum=counter=max=avg =0;
		min=INT_MAX;						//min has the maximum integer valued assigned//changed by sirisha						
		max = INT_MIN;
		size = 8; 
		col = 0; 
		do									//inner loop to process column/numbers in a row
		{
			inFile>>number;					//get next number		
			sum += number;			
			if (number > max)
				max = number; 
			if (number < min)
				min = number;	
			col = col +1;
		} while (col < 8);
		
		//show stats for each row
		cout<<" \nStatistical info about row " << row +1 <<" is "<<endl
		<<" \t The sum is " << setw(10)<<right<<sum << endl 
		<<" \t The min is " << setw(10)<<right<<min << endl
		<<" \t The max is " << setw(10)<<right<<max << endl
		<<" \t The Avg is " << setw(10)<<right
		<<setprecision(4)<<fixed<<showpoint
		<<static_cast<double> (sum) / static_cast<double> (size) << endl; 

		row = row + 1;

	} while (row < 10);
	inFile.close(); 
	
	//well done and exit
	return 0; 
}