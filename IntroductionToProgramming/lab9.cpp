// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 9:		Simple while-loops
// Date:		June 13, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-----------------------------------------------------------------
//
// This lab exercise is to play with simple while loops to process 
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
#include <limits.h>			//changed by sirisha
using namespace std; 

int main()
{
	//file variables
	ifstream inFile;
	ofstream outFile;

	//variable declarations
	int number;				//var to store an int value
	int sum, min, max, avg;	//vars to store simple statistical info
	int counter;			//a counter for controling the loop
	int size;				//another counter


	/*create a data file
	outFile.open("lab9.txt");
	counter = 0;
	srand(time(0));
	while (counter<100)
	{
		outFile<<1 +rand()%100<<endl;
		counter++;
	}
	
	outFile.close();
	*/

	inFile.open("lab9.txt");
	sum = 0;
	while (inFile)
	{
		inFile>>number;
		sum +=number;
	}

	inFile.close();
	cout<<"The sum is"<<sum<<endl;

	system("pause");

	/************************************************************
	Part A. A counter controled while loop
	************************************************************/
	cout<<"************** Play Counter Controled while-Loop**********\n"; 
	
	//initialization
	sum= max=avg =0;
	min=INT_MAX;			//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;
	cout<<" Enter How many integers do you want to play with? => "<<endl; 
	cin>>counter;			//get the counter
	size = counter;			//memory the counter
	
	//start the loop
	while (counter > 0)
	{		
		cout<<"Enter an integer ==> "<<endl;				
		cin>>number;		//get a number
		sum += number;						//changed by sirisha			
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
		
		counter--; 
	} 

	cout<<" You entered "<< size << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl		//changed by sirisha
		<<" The min is " << min <<endl
		<<" The Avg is " << sum/size <<endl<<endl; 

	/************************************************************
	Part B. Sentinel/Even controled while loop loop
	************************************************************/

	cout<<"************** Play Sentinel/Event controled while-Loop************/"<<endl; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum= max=avg =0;
	min=INT_MAX;							//changed by sirisha
	max=INT_MIN;
	cout<<"Enter an integer ==> "<<endl;				
	cin>>number;	
	
	//start the loop
	while (number != -99)
	{
		counter++;			//count numbers
		sum += number;						//changed by sirisha			
		if (number > max)
			max = number; 
		if (number < min)
			min = number;
		
		cout<<"Enter an integer ==> "<<endl;				
		cin>>number;	
	}
	
	cout<<" You entered "<< counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl		//changed by sirisha
		<<" The min is " << min <<endl
		<<" The Avg is " << sum/counter <<endl<<endl; 


	/************************************************************
	 Part C. Sentinel/Event controled while loop-break out 
	 within theloop 
	************************************************************/

	cout<<"************** PLay Sentinel/Event controled while-loop************/"<<endl;
	cout<<"************** Break out within the loop **************************/"<<endl; 
    cout<<" Compute simple stats of integers. Stop -99 is entered." <<endl ; 
	//initialization
	counter=sum= max=avg =0;
	min=INT_MAX;							//changed by sirisha
	max=INT_MIN;

	//start the loop
	while (true)			//loop forever but break from within
	{ 
		//get a number
		cout<<"Enter an integer ==> "<<endl; 
		cin>>number; 

		if (number == -99)	//check for event -99. If happened  break 
		{
			cout<<" Event -99 happened, so break out......... "<<endl; 
			break; 
		}
		counter += 1; 
		sum += number;						//changed by sirisha
		if (number > max)
			max = number; 
		if (number < min)
			min = number; 
		
	}
	cout<<" You entered " << counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl		//changed by sirisha
		<<" The min is " << min <<endl
		<<" The Avg is " << sum/counter<<endl<<endl;



	 /****************************************************************************
	 The following three parts are for you to complete.
	 ***************************************************************************/

	/****************************************************************************
	 Part D. Write a counter-controled while-loop to process only even numbers
	 ****************************************************************************/
	 //Write your code here:

	cout<<"************** Play Counter Controled While-Loop for even numbers**********\n"; 
	
	//initialization
	sum= max=avg =0;
	min=INT_MAX;			//min has the maximum integer valued assigned//changed by sirisha
	max=INT_MIN;
	cout<<"How many integers do you want to play with? => "<<endl; 
	cin>>counter;			//get the counter
	size = counter;			//memory the counter

		while (counter > 0)
		{		
			cout<<"Enter an integer ==> "<<endl;				
			cin>>number;		//get a number

			if(number%2==0)
			{
				sum += number;						//changed by sirisha			
				if (number > max)
					max = number; 
				if (number < min)
					min = number;
		
				counter--; 
			}
		} 

		cout<<" You entered "<< size << " many integers. " <<endl
			<<" The sum is " << sum <<endl 
			<<" The max is " << max <<endl		//changed by sirisha
			<<" The min is " << min <<endl
			<<" The Avg is " << sum/size <<endl<<endl;


	/****************************************************************************
	 Part E. Write an event-controled while-loop to process only even numbers
	 ****************************************************************************/
	 //Write your code here:

	cout<<"************** Play Sentinel/Event controled while-loop for even numbers************/"<<endl; 
	cout<<" Compute simple stats of integers. Stop -99 is entered."<<endl;	
	//intitialization
	counter=sum= max=avg =0;
	min=INT_MAX;							//changed by sirisha
	max=INT_MIN;
	cout<<"Enter an intenger ==> "<<endl;				
	cin>>number;	
	
		//start the loop
		while (number != -99)
		{
			if(number%2==0)
			{
				counter++;			//count numbers
				sum += number;						//changed by sirisha			
				if (number > max)
					max = number; 
				if (number < min)
					min = number;
			}
		
			cout<<"Enter an integer ==> "<<endl;				
			cin>>number;	
		}
	
		cout<<" You entered "<< counter << " many integers. " <<endl
			<<" The sum is " << sum <<endl 
			<<" The max is " << max <<endl		//changed by sirisha
			<<" The min is " << min <<endl
			<<" The Avg is " << sum/counter <<endl<<endl; 

	/****************************************************************************
	 Part F. Write an event-controled while-loop to process only even numbers
	 that breaks within the loop
	 ****************************************************************************/
	 //Write your code here:

	cout<<" PLay Sentinel/Event controled while-loop to process even numbers"<<endl;
	cout<<"************** Break out within the loop **************************/"<<endl; 
    cout<<" Compute simple stats of integers. Stop -99 is entered." <<endl ; 
	//initialization
	counter=sum= max=avg =0;
	min=INT_MAX;							//changed by sirisha
	max=INT_MIN;

	//start the loop
	while (true)			//loop forever but break from within
	{ 
		//get a number
		cout<<"Enter an integer ==> "<<endl; 
		cin>>number; 

		if (number == -99)	//check for event -99. If happened  break 
		{
			cout<<" Event -99 happened, so break out......... "<<endl; 
			break; 
		}
		if(number%2==0)
		{
			counter += 1; 
			sum += number;						//changed by sirisha
			if (number > max)
				max = number; 
			if (number < min)
				min = number; 
		}
		
	}
	cout<<" You entered " << counter << " many integers. " <<endl
		<<" The sum is " << sum <<endl 
		<<" The max is " << max <<endl		//changed by sirisha
		<<" The min is " << min <<endl
		<<" The Avg is " << sum/counter<<endl<<endl;
	

	//well done and exit
	return 0; 
}


