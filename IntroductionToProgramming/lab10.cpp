// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 10:		Simple for-loops
// Date:		June 13, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------- 
//
// This lab exercise is to play with simple for-loops to process 
// a list of integers and find simple statistical information
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
	//variable declarations
	int number;				//var to store an int value
	int sum, min, max, avg; //vars to store simple statistical info
	int size ,counter;		// a counter

	/************************************************************************
	Part A. A counter controlled for-loop
	************************************************************************/
	cout<<"************** Play Counter Controled For-Loop************/"<<endl; 
	cout<<"How many integers do you want to play with? => "<<endl; 
	cin>>counter;
	size=counter;
	min=INT_MAX;			//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;

	//start the loop
	for ( sum= max=avg =0; counter > 0; counter-- )	
    //loop control: initialization, condition, update
	{	
		cout<<"Enter an integer ==> "<<endl;				
		cin>>number; 
		sum += number;								//changed by sirisha
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
	}

	cout<<" You entered "<< size << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size)) <<endl<<endl;	//changed by sirisha

	/************************************************************
	Part B. Sentinel/Event controlled for loop
	************************************************************/
	cout<<"************** Play Sentinel/Event controled While Loop************/"<<endl; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum= max=avg =0;
	min=INT_MAX;									//changed by sirisha
	max=INT_MIN;

	//start the loop
	for (cout<<"Enter an integer ==> ", cin>>number; 	//loop initialization
		 number != -99;									//loop condition
		 cout<<"Enter an integer ==> ", cin>>number)	//loop update
	{
		counter += 1; 
		sum += number;								//changed by sirisha 
		if (number > max)
			max = number; 
		if (number < min)
			min = number; 
	}
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size))<<endl<<endl; 

	/****************************************************************************
	 Part C. Sentinel/Event controlled for loop -- break out within the loop 
	***************************************************************************/
	cout<<"************** Play Sentinel/Event controlled While Loop************\n"
		<<"************** Break out within the loop**************************\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl; 
	//initialization
	counter=sum= max=avg =0;
	min=INT_MAX;									//changed by sirisha
	max=INT_MIN;

	//start the loop
	for (cout<<"Enter an integer ==> ", cin>>number; 	//loop initialization
		 true;											//loop foever but break out within 
		 cout<<"Enter an integer ==> ", cin>>number)	//loop update
	{
		if (number == -99) 
		{
			cout<<" Event -99 happened, so break out......... "<<endl; 
			break; 
		}
		counter += 1; 
		sum += number;								//changed by sirisha 
		if (number > max)
			max = number; 
		if (number < min)
			min = number; 
		
	}
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size)) <<endl<<endl; 



    /****************************************************************************
	The following three parts are for you to complete.
	****************************************************************************/

    /****************************************************************************
    Part D. Write a counter-controled for-loop to process only even numbers
	****************************************************************************/
	//Write your code here:

	cout<<" Play Counter Controled For-Loop to process only even numbers/"<<endl; 
	cout<<"How many integers do you want to play with? => "<<endl; 
	cin>>counter;
	size=counter;
	min=INT_MAX;			//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;

	//start the loop
	for ( sum= max=avg =0; counter > 0; counter-- )	
    //loop control: initialization, condition, update
	{	
		cout<<"Enter an integer ==> "<<endl;				
		cin>>number; 
		
		if (number%2==0)
		{
			sum += number;								//changed by sirisha
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
		}
	}

	cout<<" You entered "<< size << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size)) <<endl<<endl;	//changed by sirisha

	/****************************************************************************
	Part E. Write an event-controled for-loop to process only even numbers
	****************************************************************************/
	//Write your code here:

	cout<<"Play Sentinel/Event controled While Loop to process only even numbers/"<<endl; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum= max=avg =0;
	min=INT_MAX;									//changed by sirisha
	max=INT_MIN;

	//start the loop
	for (cout<<"Enter an integer ==> ", cin>>number; 	//loop initialization
		 number != -99;									//loop condition
		 cout<<"Enter an integer ==> ", cin>>number)	//loop update
	{
		if (number%2==0)
		{
			counter += 1; 
			sum += number;								//changed by sirisha 
			if (number > max)
				max = number; 
			if (number < min)
				min = number;
		}
	}
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size)) <<endl<<endl; 

	/****************************************************************************
	Part F. Write an event-controled for-loop to process only even numbers that 
	breaks within the loop
	****************************************************************************/
	//Write your code here:

	cout<<"Play Sentinel/Event controlled While Loop to process only even numbers\n"
		<<"************** Break out within the loop**************************\n"; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl; 
	//initialization
	counter=sum= max=avg =0;
	min=INT_MAX;									//changed by sirisha
	max=INT_MIN;

	//start the loop
	for (cout<<"Enter an integer ==> ", cin>>number; 	//loop initialization
		 true;											//loop foever but break out within 
		 cout<<"Enter an integer ==> ", cin>>number)	//loop update
	{
		if (number == -99) 
		{
			cout<<" Event -99 happened, so break out......... "<<endl; 
			break; 
		}

		if (number%2==0)
		{
			counter += 1; 
			sum += number;								//changed by sirisha 
			if (number > max)
				max = number; 
			if (number < min)
				min = number; 
		}
		
	}
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size))<<endl<<endl; 

	//well done and exit
	return 0; 
}
