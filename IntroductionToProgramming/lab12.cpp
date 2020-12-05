// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 12:		Continue and more about break
// Date:		June 13, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-----------------------------------------------------------------
//
// This lab exercise is to practice the continue and break statements.
// It's a little tricky to understand continue well
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
#include <limits.h>				//changed by sirisha
using namespace std; 

int main( )
{
	//variable declarations
	int number;					//var to store an int value
	int sum, min, max, avg;		//vars to store simple statistical info
	int counter;				//a counter for controling the loop
	int size;					//another counter

	/*****************************************************************************
	Part A. continue in a while loop
	*****************************************************************************/
	//cout<<"************** Play Counter Controled do-while-Loop************/"<<endl; 
	/*
	//initialization
	sum=max=avg =0;
	min=INT_MAX;				//min has the maximum integer valued assigned
	max=INT_MIN;
	cout<<"How many integers do you want to play with? => "; 
	cin>>counter;				//get the counter
	size = counter;				//memory the counter
	
	//start the loop
	while (counter > 0)
	{		
		cout<<"Enter an integer ==> ";				
		cin>>number;			//get a number
		
		//here we use a continue to skip odd numbers
		if (number % 2 ==1)
		{
			cout<<"This is an odd number"<<endl;
			continue;								//to skip all statement from here to the end of the while loop, 
		}											//and start the next iteration of the loop.

		sum += number;			//changed by sirisha			
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
		
		counter--; 
	} 
	cout<<" You entered "<< size << " many integers. " <<endl
		<<" The sum is " << sum << endl 
		<<" The min is " << min << endl
		<<" The max is " << max << endl
		<<" The Avg is " << (size == 0 ? 0 : static_cast<double>(sum)/double(size)) << endl; 

	*/

	/***************************************************************
	Part B. This part is for you to complete. 
	Re-do Part A using continue in an event controlled for-loop.
	***************************************************************/
	//cout<<"********Play event controlled for-loop with -99******** "<<endl;
	/*
	//initialization
	sum=max=avg =0;
	min=INT_MAX;				//min has the maximum integer valued assigned
	max=INT_MIN;
	cout<<"How many integers do you want to play with? => "; 
	cin>>counter;				//get the counter
	size = counter;				//memory the counter
				//get a number
	//start the loop
	for (counter = 0; counter < size;  )			//initialization
	{
		cout<<"Enter an integer ==> ";				
		cin>>number;	
		if (number == -99)
		{
			cout<<" Event -99 happened, so break out......... "; 
			break; 
		}
		else if (number%2==1)
		{
			cout<<"This is an odd number"<<endl;
			continue;								//to skip all statement from here to the end of the while loop, 
								//and start the next iteration of the loop.
		}
		sum += number;						
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
		counter++;
	}

	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl
		<<" The max is " << max << endl
		<<" The min is " << min <<endl
		<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter)) <<endl; 

	*/
	/**************************************************************
	 Part C. This part is for you to complete. 
	 Re-do Part A using continue in an event controlled do-while-loop
	 **************************************************************/
	cout<<"********Play event controled do-while-Loop with event -99******** "<<endl; 
	
	counter=sum=max=avg =0;		//initialization
	min=INT_MAX;				//changed by sirisha
	max=INT_MIN;
	//cout<<"How many integers do you want to play with? => "; 
	//cin>>counter;				//get the counter
	//size = counter;				//memory the counter

	//start the loop
	counter = 0; 
	do{
		cout<<"Enter an integer or -99 to stop ==> ";				
		cin>>number;				//get a number
		
		if (number == -99 || number%2==1 || number == -1)
		{
			cout<<"This is an odd number"<<endl;
			continue;							//to skip all statement from here to the end of the while loop, 
		}										//and start the next iteration of the loop.

		sum += number;						
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
		
		counter++; 

	} while (number != -99);  

	if (counter >0)
	{
		cout<<" You entered "<< counter << " many integers. " <<endl
			<<" The sum is " << sum <<endl 
			<<" The min is " << min <<endl
			<<" The max is " << max <<endl
			<<" The Avg is " << (counter == 0 ? 0 : static_cast<double>(sum)/double(counter)) <<endl; 
	}
	else 
	{
		cout<<" zero even numbers are entered. " <<endl; 
	}




	//well done and exit
	return 0; 
}