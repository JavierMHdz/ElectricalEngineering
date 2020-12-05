#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>
#include <limits.h>		

using namespace std; 

#ifndef	HW3H		
#define HW3H

//welcome
void welcome()
{
	cout<<" Welcome to the Rio Grande Bank!"<<endl; 
}

//this function tries to received loan info
void getLoanInfo(double & loanAmt, double & annualIntRate, int & numMonths)
{
	cout<<"How much do you want to borrow? "; 
	cin>>loanAmt; 
	cout<<"What is the annual int rate? "; 
	cin>>annualIntRate; 
	cout<<"In how many months do you want to pay off the loan? "; 
	cin>>numMonths; 
}

//to calculate the month int rate, given the annual int rate
double monthIntRateCal(const double cat)
{
	return (cat /100) /12; 
}

//to calculate the month payment, given loan amount, month int rate and numMonths
double monthPaymentCal(const double loanAmt, const double monthIntRate, const int numMonths)
{
	double pay; 
	pay = loanAmt * monthIntRate * pow(1+monthIntRate, numMonths) 
		 /  (pow(1+monthIntRate, numMonths) -1 ); 
	return pay; 
}


#endif
