// *******************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 11:		Simple do-while loops
// Date:		June 13, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//--------------------------------------------------------------------
//
// This lab exercise is to play with simple do-while loops to process 
// a list of integers and find simple statistical information
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// ********************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>
#include <limits.h>				//changed by sirisha
using namespace std; 

int main( )
{
	//variable declarations
	int number;					//var to store an int value
	int sum, min, max, avg;		//vars to store simple statistical info
	int counter;				//a counter for controling the loop
	int size;					//another counter

	/************************************************************************
	Part A. A counter controlled do-while loop
	************************************************************************/
	cout<<"************** PLay Counter Controled do-while-Loop************\n"; 
	
	//initialization
	sum=max=avg =0;
	min=INT_MAX;				//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;
	cout<<" Enter How many integers do you want to play with? => "; 
	cin>>counter;				//get the counter
	size = counter;				//memory the counter
	//The control condition is at the end. This means that we enter the loop first regardless the condition
	do {
		cout<<"Enter an integer ==> ";				
		cin>>number;			//get a number
		sum += number;			//changed by sirisha			
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
	}while (counter-- > 1); 

	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size))<<endl; 

	/*******************************************************************************
	Part B. Sentinel/Event controlled do-while loop 
	*******************************************************************************/
	cout<<"************** PLay Sentinel/Event controled do-while Loop************\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum=max=avg =0;
	min=INT_MAX;				//changed by sirisha
	max=INT_MIN;
	
	//The control condition is at the end. This means that we enter the loop first regardless the condition
	do {
		cout<<"Enter an integer ==> ";				
		cin>>number;			//get a number
		
		if (number != -99)		//check for event but cannot break in for practice
		{
			counter++;			//count numbers
			sum += number;		//changed by sirisha			
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
		}
	}while ( number != -99);	//use event -99 to control the loop

	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter))<<endl; 


	/*******************************************************************************
	Part C. Sentinel/Event controled do-while loop,	break out within the loop 
	******************************************************************************/
	cout<<"************** PLay Sentinel/Event controled do-while Loop************\n"
		<<"************** Break out within the loop **************************\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl; 
	//initialization
	counter=sum=max=avg =0;
	min=INT_MAX;				//changed by sirisha
	max=INT_MIN;

	//start the loop
	do { 
		//get a number
		cout<<"Enter an integer ==> "; 
		cin>>number; 

		if (number == -99)		//check for event -99. If happened, then break 
		{
			cout<<" Event -99 happened, so break out......... "; 
			break; 
		}
		counter += 1; 
		sum += number;			//changed by sirisha 
		if (number > max)
			max = number; 
		if (number < min)
			min = number; 
		
	   }while ( true);
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter)) <<endl; 


	/*********************************************************************************
	The following three parts are for you to complete.
	*********************************************************************************/

	/*********************************************************************************
	Part D. Write a counter-controled do-while-loop to process only even numbers
	*********************************************************************************/
	//Write your code here:

	cout<<"Play Counter Controled do-while-Loop to process only even numbers\n"; 
	
	//initialization
	sum=max=avg =0;
	min=INT_MAX;				//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;
	cout<<" Enter How many integers do you want to play with? => "; 
	cin>>counter;				//get the counter
	size = counter;				//memory the counter
	//The control condition is at the end. This means that we enter the loop first regardless the condition
	do {
		cout<<"Enter an integer ==> ";				
		cin>>number;			//get a number
		
		if (number%2==0)
		{
			sum += number;						
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
		}

	}while (counter-- > 1); 

	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size))<<endl; 

	/*********************************************************************************
	Part E. Write an event-controled do-while-loop to process only even numbers
	*********************************************************************************/
	//Write your code here:

	cout<<"Play Sentinel/Event controled do-while Loop to process only even numbers\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum=max=avg =0;
	min=INT_MAX;				//changed by sirisha
	max=INT_MIN;
	
	//The control condition is at the end. This means that we enter the loop first regardless the condition
	do {
		cout<<"Enter an integer ==> ";				
		cin>>number;			//get a number
		
		if (number != -99)		//check for event but cannot break in for practice
		{
			if (number%2==0)
			{
				counter++;			//count numbers
				sum += number;		//changed by sirisha			
				if (number > max)
					max = number; 
				if (number < min)
					min = number;
			}
		}
	}while ( number != -99);	//use event -99 to control the loop

	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter))<<endl; 


	/*********************************************************************************
	Part F. Write an event-controled do-while-loop to process only even numbers
	that breaks within the loop
	*********************************************************************************/
	//Write your code here:

	cout<<"Play Sentinel/Event controled do-while Loop to process only even numbers\n"
		<<"************** Break out within the loop **************************\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl; 
	//initialization
	counter=sum=max=avg =0;
	min=INT_MAX;				//changed by sirisha
	max=INT_MIN;

	//start the loop
	do { 
		//get a number
		cout<<"Enter an integer ==> "; 
		cin>>number; 

		if (number == -99)		//check for event -99. If happened, then break 
		{
			cout<<" Event -99 happened, so break out......... "; 
			break; 
		}

		if(number%2==0)
		{
			counter += 1; 
			sum += number;			//changed by sirisha 
			if (number > max)
				max = number; 
			if (number < min)
				min = number; 
		}
		
	   }while ( true);
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter))<<endl; 

	//well done and exit
	return 0; 
}