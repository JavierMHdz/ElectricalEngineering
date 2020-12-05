// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Homework 4:		Header file for Homework 4
// Date:		June 18, 2013
// HW Assignment: Four
// *****************************************************************

#include <iostream>
#include <cstring>

using namespace std; 

#ifndef	HW_4_HEAD_H		
#define HW_4_HEAD_H

void welcome()
{
	cout<<"Welcome to Fractional Arithmetic Program"<<endl;
	return;
}
void instructions()
{
	cout<<"This program will perform arithmetic on fractions."<<endl;
	cout<<"Problems should be entered like this: 2/5 - 4/7"<<endl;
	cout<<"The allowed operations are addition (+), subtraction (-), multiplication (*), and division (/)."<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"There must be at least one space around these operators."<<endl;
	cout<<"*********************************************************"<<endl;
	return;
}
void addition (const int A, const int B, const int C, const int D)
{
	int E, F, r, gcf, a, b;
	E = (A*D)+(C*B);
	F = (B*D);
	r = E % F;
	if ( r != 0)
	{
		do
		{
			a = F;
			b = r;
			r = a % b;
		} while ( r !=0);

		gcf = b;
	}
	int n = E/ gcf;
	int d = F/ gcf;
	cout<<"The answer is "<<n<<" / "<<d<<endl;
	return;
}
void subtraction (const int A, const int B, const int C, const int D)
{
	int E, F, r, gcf, a, b;
	E = (A*D)-(C*B);
	F = (B*D);
	r = E % F;
	if ( r != 0)
	{
		do
		{
			a = F;
			b = r;
			r = a % b;
		} while ( r !=0);

		gcf = b;
	}
	int n = E/ gcf;
	int d = F/ gcf;
	cout<<"The answer is "<<n<<" / "<<d<<endl;

	return;
}
void multiplication (const int A, const int B, const int C, const int D)
{
	int E, F, r, gcf, a, b;
	E = (A*C);
	F = (B*D);
	r = E % F;
	if ( r != 0)
	{
		do
		{
			a = F;
			b = r;
			r = a % b;
		} while ( r !=0);

		gcf = b;
	}
	int n = E/ gcf;
	int d = F/ gcf;
	cout<<"The answer is "<<n<<" / "<<d<<endl;
	return;
}
void division (const int A, const int B, const int C, const int D)
{
	int E, F, r, gcf, a, b;
	E = (A*D);
	F = (B*C);
	r = E % F;
	if ( r != 0)
	{
		do
		{
			a = F;
			b = r;
			r = a % b;
		} while ( r !=0);

		gcf = b;
	}
	int n = E/ gcf;
	int d = F/ gcf;
	cout<<"The answer is "<<n<<" / "<<d<<endl;
	return;
}
#endif
