//***************************************************************
// Program Name: hwOneMain.cpp
// Author: Javier Jesus Macossay Hernandez
// UTPA Student ID: 20228488
// Due Date: 06/06/2013
// Course: 1380.01
// HW Assignment: One
//
// Description: This is a program where the area of a triangle
//              can be calculated when the user inputs the
//              three sides of a triangle.
//****************************************************************

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()

{
	// declaration of variables 
	double a,b,c; // variables for three sides
	double s; // varieble for the semiperimeter
	double area; // variable for the area
	ofstream outfile; //for output file

	// open an output file
	outFile.open("hw1.txt", ios:app);
	
	while (true)
	{

		// prompt for and read the lengths of the sides
		cout<< "Please enter side a";
		cin>> a;
		cout<< "Please enter side b";
		cin>> b;
		cout<< "Please enter side c";
		cin>> c;

		// check to see whether the three sides form a triangle or not

		if (a+b < c || a+c < b || b+c <a)
		{
			cout<<"The three sides do not form a triangle!" <<endl
				<< "I quit." <<endl;
			break;
			
		}


		// compute the semiperimeter and area
		s = (a + b + c) / 2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));

		
		// setup output format 
		cout<<fixed<<showpoint<<setprecision(2);

		// display the input values and the resulting area
		cout<< "The area of the triangle with the sides" <<endl
			<< setw(6)<< a << "," << setw(6)<< b << ",and" << setw(6)<< c
			<< "is" <<setw(10)<< area <<endl
			<< "Bye" <<endl;

		outFile<< "The area of the triangle with the sides" <<endl
			<< setw(6)<< a << "," << setw(6)<< b << ",and" << setw(6)<< c
			<< "is" <<setw(10)<< area <<endl
			<< "Bye" <<endl;


		// Extra Bonus Part A
		cout<< "Do you want to calculate the area of another triangle (yes/no)?";
		cin>>answer;

		if (answer != "yes")
			break;

	}

	// close the output file
	outFile.close();








 

	return 0;


}