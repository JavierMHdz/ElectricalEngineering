// ************************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 5:		Strings, C-strings, and string operations
// Date:		June 7, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-------------------------------------------------------------------------
//
// This lab exercise is to play with strings, C-strings, and simple string 
// operations such as copying and concatenation.
//
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// *************************************************************************

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
	//declare string variables
	string line1, line2, line3;			//three string objects
	char str1[50], str2[50], str3[50],	//three arrays of 100 charaters
		 str4[50], str5[50],ch;			//two arrays of 5 characters

	/*
	//get string inputs
	cout<<"Enter one string without spaces => "; 
	cin>> line1;                        //cin cannot get spaces
        cin.get(ch);					//this clears out the buffer i.e., takes out the "enter" character out of buffer//changed by sirisha.			
	cout<<"Enter a line with spaces => "; 
	getline(cin, line2, '\n');			//getline can get spaces

	//string concatenation
	line3 = line1 + line2;				//+ symbol is to concatenate two strings
	cout << "line1 is " <<line1 <<endl
		<<"line2 is " << line2 <<endl
		<<"line3 is " << line3 <<endl; 
	
	line1 += line3;						// += symbol is to concatenate two strings and assigns the value
	cout<<"Now, line1 becomes " <<line1 <<endl; 

	//get strings
	cout<<"Enter one word => "; 
	cin>>str1;							//cin cannot get spaces
	cout<<"Enter 'I like C++ very much.' =>"; 
	cin.getline(str2, 50, 'v');			//getline can get spaces
	
	//string copy
	strcpy_s(str3, str1);					//copy str1 to str3
	
	//string concatenation
	strcat_s(str3, str2);					//concatenate str2 to str3

	getline(cin,line1);					//takes out “ery much.”out of bbuffer ad clears it.	//changed by sirisha
	cout<<"str1 is " <<str1 <<endl
		<<"str2 is " <<str2<<endl
		<<"str3 is " <<str3<<endl; 

	//control the input string size
	cout<<"Enter 'CatandDogarefriends.' =>"; 
	cin.width(5);						//set input upto 4characters
	cin>>str3; 
	cin>>setw(5)>>str4;					//set input upto 4characters

	cout<<"str3 is " <<str3 <<endl
		<<"str4 is " <<str4<<endl;
 

	/******************************************************************
	This is for you to complete: 
	Get three lines from the keyboards. Play with string copying, 
	concatenation, and input size controling.
	******************************************************************/
	//Write your code here

	/***************************
	I am doing C ++ strings
	****************************/

	//get string inputs
	cout<<"Enter one string without spaces => "; 
	cin>> line1;                        //cin cannot get spaces
    cin.get(ch);					//this clears out the buffer i.e., takes out the "enter" character out of buffer//changed by sirisha.			
	cout<<"Enter a line with spaces => "; 
	getline(cin, line2, '\n');			//getline can get spaces

	//string concatenation
	line3 += line1 + line2;				//+ symbol is to concatenate two strings
	cout << "line1 is " <<line1 <<endl
		<<"line2 is " << line2 <<endl
		<<"line3 is " << line3 <<endl; 
	
	line1 = line3 + line2;						// += symbol is to concatenate two strings and assigns the value
	cout<<"Now, line1 becomes " <<line1 <<endl; 
	
	/*************************
	I am doing C strings
	*************************/
	//get strings
	cout<<"Enter one word => "; 
	cin>>str1;							//cin cannot get spaces
	cout<<"Enter 'I love Math and Physics.' =>"; 
	cin.getline(str2, 50, 'n');			//getline can get spaces
	
	//string copy
	strcpy_s(str3, str1);					//copy str1 to str3
	
	//string concatenation
	strcat_s(str3, str2);					//concatenate str2 to str3

	getline(cin,line1);					//takes out “ery much.”out of bbuffer ad clears it.	//changed by sirisha
	cout<<"str1 is " <<str1 <<endl
		<<"str2 is " <<str2<<endl
		<<"str3 is " <<str3<<endl; 

	//control the input string size
	cout<<"Enter 'RunandSwimisfun!.12345678' =>"; 
	cin.width(9);					             	//set input upto 9characters
	cin>>str3; 
	cin>>str4;					

	cout<<"str3 is " <<str3 <<endl
		<<"str4 is " <<str4<<endl;


	//well done and exit
	return 0; 
}