//********************************************************************
// Program Name: hw4.cpp
// Author: Javier Jesus Macossay Hernandez
// UTPA Student ID: 20228488
// Due Date: 06/18/2013
// Course: 1380.01
// HW Assignment: Four
//
// Description: This is a program is to do fractional arithmetic.
//              The program should handle  the operations of addition,
//              subtraction, multiplication, and division. It should
//				also reduce the answer to its lowest form.
//*********************************************************************


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

//include my own header file
#include "hw4.h"

using namespace std; 

int main( )
{
	//declaration of variables
	char choice, sign;

	welcome();
	instructions();

	do
	{	
		char operation;
		int A, B, C, D;
		cout<<"Please enter a problem =>"<<endl;
		cin>>A>>sign>>B>> operation >>C>>sign>>D;
		{
				switch (operation)
				{
					case '+':
						addition (A, B, C, D);
						break;
					case '-':
						subtraction (A, B, C, D);
						break;
					case '*':
						multiplication (A, B, C, D);
						break;
					case '/':
						division (A, B, C, D);
						break;
					default:
						cout<<"This is not a right operation"<<endl;
				}
		}
		cout<<"Do you want to use the program again? (y/n)"<<endl;
		cin>>choice;
	} while (choice == 'y' || choice == 'Y');
	cout<<"Goodbye"<<endl;
	
	//well done and exit
	return 0; 
}
