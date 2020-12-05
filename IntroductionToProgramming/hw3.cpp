// *****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Assignment:	Homework 3 
// Date:		June 19, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
// *****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>
#include <limits.h>			
#include "hw3.h"

using namespace std; 

int main( )
{
	ofstream outFile;
	outFile.open("hw3Output.txt", ios::app);
	double loanAmount, annualIntRate; 
	int numMonths; 
	double monthIntRate;
	double monthPayment; 
	double balance, monthPaidPrincipal, monthPaidInt, totalPayment, totalInt; 
	int i; 

	//show welcome msg
	welcome(); 
	//get loan info
	getLoanInfo(loanAmount, annualIntRate, numMonths);
	//cal month int rate
	monthIntRate = monthIntRateCal(annualIntRate); 
	//cal month payment
	monthPayment = monthPaymentCal(loanAmount, monthIntRate, numMonths); 

	//loop to show table
	cout<<"                Amortized Payment Table " <<endl;
	outFile<<"                Amortized Payment Table " <<endl;
	cout<<setw(6)<<"month"<<setw(10)<<"Paid Prin" <<setw(10) 
		<<"paid Int" <<setw(10) <<"balance" <<endl; 
	outFile<<setw(6)<<"month"<<setw(10)<<"Paid Prin" <<setw(10) 
		<<"paid Int" <<setw(10) <<"balance" <<endl; 
	balance = loanAmount; 
	cout<<setprecision(2)<<fixed<<showpoint; 
	outFile<<setprecision(2)<<fixed<<showpoint; 
	for (i=1; i<=numMonths; i++)
	{
		monthPaidInt = balance * monthIntRate; 
		monthPaidPrincipal = monthPayment - monthPaidInt; 
		balance = balance - monthPaidPrincipal; 
		cout<<setw(6)<<i<<setw(10)<<monthPaidPrincipal <<setw(10) 
			<<monthPaidInt <<setw(10) <<(balance<0? 0: balance) <<endl; 
		outFile<<setw(6)<<i<<setw(10)<<monthPaidPrincipal <<setw(10) 
			<<monthPaidInt <<setw(10) <<(balance<0? 0: balance) <<endl; 
	}
	outFile.close();

	//show summmary table

	//well done and exit
	return 0; 
}
