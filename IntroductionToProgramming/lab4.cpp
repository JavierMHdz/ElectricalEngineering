// *********************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 4:		File input/ouput, 
//				random number generators and output formating
// Date:		June 6, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------------
//
// This lab exercise is to practice rand(), srand() and 
// output formating with help of <iomanip>. It also practices 
// file input and output.
//
// You need to create an input file, named with "lab_4_data.txt" with 
// the following integers "23   456    3000    578   9876".
//
// You do not need to create an output file, because the file open call
// will do this for you. 
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// **********************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

using namespace std; 

void showMenu(); 

int main( )
{

	//file declaration
	ifstream inputSeedsFile;	//input file with random seeds
	ofstream outTableFile,	    //output file to store square root and logarithm table
	outCalendarFile;            //output file to store the calendar

	//variable declarations
	unsigned seed;				//random seed
	int x, totalNumber;			//x holds int values, totalNumbers holds the number of int values
	double  sqrtResult,			//store square roots
			logResult;			//store base-10 logrithmic values
	int choice;					//store choice value (1, 2, 0r 3)
	char option; 				//store option value (y/n)
	int dice1, dice2,			//dice numbers
		sum, guess;				//the sum of two dices and the guessed sum
	

	//open the input file
	inputSeedsFile.open("lab_4_data.txt"); 
	//open the output files 
	outTableFile.open("lab_4_output.txt"); 
	outCalendarFile.open("Lab_4_outputCalendar.txt"); 

	while ( true )
	{
		showMenu();				//show menu
		cin>>choice;			//get the user's choice
		
		//build a log and base-10 logrithmic table
		if (choice == 1) 
		{
			cout<<"How many numbers do you want to play?  "<<endl;
			cin>>totalNumber; 

			//totalNumber shall be >= 1
			if (totalNumber < 1)
			{
				cout<<"The total number must be greater or equal to 1. "<<endl;
			}
			//build the table when totalNumber >= 1
			else 
			{
				//prepare the outfile format
				//set decimal format with 4 decimal digits
				outTableFile<<setprecision(4)<<fixed<<showpoint; 

				//output the table to the output file
				//print table head with three column of width 10 each
				outTableFile<<setw(10)<<right<<"input"<<setw(20)<<right<<"square root"
					        <<setw(20)<<right<<"base-10 logarithm"<<endl;
				outTableFile<<"---------------------------------------------------------------"<<endl;

				
			//use a for-loop to build a table, one row at a time/iteration
			for (int i=1; i<= totalNumber; i++)
			{
				//output one row to the output file
				outTableFile<< setw(10)<<right<<i							        //print column 1
							<<setw(20)<<right<<sqrt(static_cast<double>(i))	        //print column 2
							<<setw(20)<<right<<log10(static_cast<double>(i))<<endl;	//print column 3
			}
			
		cout<<"The table is finished ..................."<<endl<<endl; 
		outTableFile<<"The table is finished .................."<<endl<<endl;
			}

		}
	
		//The program rolls two dices, yielding two integers between 1 and 6. 
		//Ask the user to guess the sum of the two dices.
		if (choice == 2) 
		{
			//ask for a random seed
			cout<<"Get me a random seed from the input file ....."<<endl; 
			inputSeedsFile>>seed; 
			
			//set the random seed
			srand(seed); 

			//roll the first dice
			dice1 = 1 + rand()%6; 
			cout<<"Rolled dice one ........................"<<endl;
			//roll the second dice
			dice2 = 1 + rand()%6; 
			cout<<"Rolled dice two ........................"<<endl;

			//calculate the sum of two dices
			sum = dice1 + dice2; 

			//Ask the user to guess the sum
			cout<<"Guess the sum of the two dice ==> "<<endl;
			cin>>guess; 
		
			if (guess == sum)
			{
				cout<<"You are a winner!" <<endl
				    <<"Dice one  "<<dice1 <<" + dice two  " <<dice2 <<"  is " 
				    << "you guessed " <<guess<<endl; 
			}
			else
			{
				cout<<"You are a loser!"<<endl
				    <<"Dice one  "<<dice1 <<" + dice two  " <<dice2 <<"  is not " 
				    << "you guessed " <<guess<<endl;
			}

			
		}
		
		/*******************************************************************************************
		This part is for you to complete. You need to print into the output file "outCalendar.txt" 
		a calendar of June, July and August 2008.	
		You shall format the result for month well so that it looks like a real calendar table.
		You must use <iomanip>
		********************************************************************************************/
		if (choice == 3 ) 
		{

			cout<<" This part is for you to complete. "
				<<"You need to print into the output file (outCalendar.txt) a calendar of June," 
				<<"July and August 2013."<<endl;	

					cout<<endl<<endl;
					cout<<" July 2013" <<endl
						<<"--------------------------------------------"<<endl;
					cout<<setw(4)<<' '<<setw(4)<<'1'<<setw(4)<<2<<setw(4)<<3
						<<setw(4)<<4<<setw(4)<<5<<setw(4)<<6<<endl;
					for (int j = 7; j<=31; j++)
					{
						cout<<setw(4)<<j;
						if(j==13 || j==20 || j==27)
							cout<<endl;
					}
					cout<<endl;
					
					cout<<endl<<endl;
					cout<< "August 2013"<<endl
					    <<"-----------------------------------"<<endl;
					cout<<setw(20)<<1<<setw(4)<<2<<setw(4)<<3<<endl;

					for (int j=4; j<=31; j++)
					{
						cout<<setw(4)<<j;
						if (j == 10 || j == 17 || j == 24 || j == 31)
							cout<<endl;
					}
					cout<<endl;

		}

		cout<<"Do you want to play again (y/n)? "; 
		cin>>option; 
		
		if (option !='y')
		{
			cout<<"Bye bye!"<<endl<<endl; 		
			break; 
		}
	}
	
	//close files
	inputSeedsFile.close( );				//close randomSeeds.txt 
	outTableFile.close( );					//close outTable.txt
	outCalendarFile.close( );				//close outputCalendat.txt 




	//complete the work
	return 0;

}
void showMenu()
{
	cout<<"************************************************\n"
		<<"Enter 1 to build a square root, log10 table     \n"
		<<"Enter 2 to play rolling two dices               \n"
		<<"Enter 3 to print a calendar for 2008            \n"
		<<"What is your choice  ==>	"; 

	return; 
}


