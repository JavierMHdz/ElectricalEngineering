// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez
// Class:		CSCI 1380-01, Summer I 2013
// Lab 8:		Enumerated data types and string comparisons
// Date:		June 10, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------- 
//
// This lab exercise is to play with enumerated data types and 
// string object comparisons and C-string comparisions. 
// Please pay attention to the fact that one cannot do direct 
// input/ouput for any enumerated data types.
// The main advantage of having enumerate data types is for readability.
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

using namespace std; 

int main( )
{
	//enumerate type definition
	enum weekDays {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};   //changed by sirisha
	
	//variable declarations
	weekDays myDays;		//to deal with weekDays datatype
	string day;				//C++ string object, to get the day
	char anotherDay[200];	//C-string var, to get the day as a C-string

	char choice,			//for choice of C++ strings or C-string; 
		 option;			//a flag to stop the loop

	//loop forever to play the program until the user stops
	while (true)
	{
		//play with C++ strings or C-strings	
		cout<<"Want to play C++ strings or C-strings (y for C++ strings /n for C strings)? => "<<endl; 
		cin>>choice; 

		if (choice == 'y' || choice == 'Y')		//for C++ strings
		{
			//get a day via C++ string object
			cout<<"Enter a week day => "; 
			cin>>day; 

			//covert string week day to enumerated weekDays value
			if (day == "Monday")
				myDays = Monday;				//changed by sirisha
			else if (day == "Tuesday")
				myDays = Tuesday;				//changed by sirisha
			//For you: finish the rest of conversion
			/**********  Write Your Code here *************/
			
			else if (day == "Wednesday")
				myDays = Wednesday;
			else if (day == "Thursday")
				myDays = Thursday;
			else if (day == "Friday")
				myDays = Friday;
			else if (day == "Saturday")
				myDays = Saturday;
			else if (day == "Sunday")
				myDays = Sunday;
			else
			{
				cout<< "not a valid day. "<<endl; 
				continue; 
			}
		}
		//this part is to play with C-strings 	
		else								
		{
			//get a day via C string object
			cout<<"Enter a week day => "; 
			cin>>anotherDay; 

			//covert string week day to enumerated weekDays value
			if (strcmp(anotherDay, "Monday") == 0)
				myDays = Monday;				//changed by sirisha 
			else if (strcmp(anotherDay, "Tuesday") == 0)
				myDays = Tuesday;				//changed by sirisha
			//For you: finish the rest of conversion
		    /********** Write Your Code here *************/
			else if (strcmp(anotherDay, "Wednesday") == 0)
				myDays = Wednesday;
			else if (strcmp(anotherDay, "Thursday") == 0)
				myDays = Thursday;
			else if (strcmp(anotherDay, "Friday") == 0)
				myDays = Friday;
			else if (strcmp(anotherDay, "Saturday") == 0)
				myDays = Saturday;
			else if (strcmp(anotherDay, "Sunday") == 0)
				myDays = Sunday;
			else 
			{
				cout<< "not a valid day. "<<endl; 
				continue; 
			}
		}

		//now play with enumerated type value
		switch (myDays)
		{
		case Monday: 
			cout<<"Monday is not a study day,"<<endl;
			cout<<"coz I am still sleepy." <<endl; 
			break; 
		case Tuesday:
			cout<<"Oh, Geez, Tuesday IS a studyday."<<endl; 
			break; 
		
		//This is for you: Complete the rest of the cases, including the default case.
		/************  Write Your Code here ***********************************/

		case Wednesday:
			cout<<"Oh, I feel like sleeping all day."<<endl; 
			break;
		case Thursday:
			cout<<"Feel like going to study a little bit."<<endl;
			cout<<"tomorrow is Friday!"<<endl;
			break; 
		case Friday:
			cout<<"Friday at last, I am free!"<<endl;
			break; 
		case Saturday:
			cout<<"Spend some time watching T.V. and sleeping."<<endl;
			break; 
		case Sunday:
			cout<<"Awesome day to spend with my family,"<<endl;
			cout<<"sadly tomorrow is Monday."<<endl;
			break; 
		default: 
			cout<<"You entered a wrong day. " <<endl; 
		}

		//This part is for you: Ask the user whether to continue the play or not
		/************  Write Your Code here *********************************/

		cout<<"Do you want to play again? (y/n)"<<endl;
		cin>>option;

		if (option != 'y' && option != 'Y')
		{
			cout<<"Bye Bye"<<endl;
			break;
		}

	}



	//well done and exit
	return 0; 
}
