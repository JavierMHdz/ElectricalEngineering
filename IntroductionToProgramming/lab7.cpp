// **********************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer I 2013
// Lab 7:		Switch statement vs. if-else statement
// Date:		June 11, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//-----------------------------------------------------------------------
//
// This lab exercise is to play with switch statements and to understand
// their equivalence to if-else statements
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// **********************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath> 
#include <cstdlib>
#include <iomanip>

using namespace std;
const 

int main( )
{
	//variable declarations
	char choice, choice1, choice3; 			//choice1 for switch and choice for replay//changed by sirisha
	int choice2; 
	unsigned seed;							//random seed
	int test;								//random number test
	char a, b, c, d, A, B, C, D;

	//a loop to play forever until the user chooses to stop
	/*
	while  (true)
	{
		//get the choice
		cout<<"What is your choice? ('a' to 'd', or 'A' to 'D') =>"<<endl; 
		cin>>choice1;
		//switch to deal with four cases
		switch (choice1)					//changed by sirisha
		{
			case 'a':	
			case 'A':
				cout<<"I see a rat "<<endl;	//no break here
			case 'b':
			case 'B':	
				cout<<"I have a cat "<<endl; 
				break; 
			case 'c':
			case 'C':  
				cout<< "Cat hates rat "<<endl; 
				cout<<"Rate chases cat "<<endl; 
				break; 
			case 'd':
			case 'D':	
				//complex statement can be added any where as you wish
				cout<<"Give me a random seed => "; 
				cin>>seed; 
									
				srand(seed);				//set the random seed
				test = rand(); 
								
				if (test%100 >= 70)
					cout<<" With 30% of chance, cat hits rat with a bat" <<endl; 
				else 
					cout<<" With 70 % of chance, rat catches cat with a hat" <<endl; 
						
				break; 
			default: 
				cout<<"The choice is not valid" <<endl; 
		}
					
		//repeat or not 
		cout<<"Want to play again? (y/n) => "; 
		cin>>choice;				
		if (choice != 'y' && choice != 'Y')
		{
			// stop if the choice is not 'y' or not 'Y'
			cout<<"Byebye now ........ "<<endl; 
			break;					
		}
		
		cout<<"Okay, one more time >>>>>>>>>>>>>>>> "<<endl; 
	}
	*/
	/*************************************************************************************
	The following two parts are for you to complete.
	*************************************************************************************/

	/**************************************************************************************
	Part A. Rewrite the above given switch statememt with an int type selction variable.
	**************************************************************************************/
	//Write your code here:
	
	while  (true)
	{
		//get the choice
		cout<<"What is your choice? (1 to 10)=>"<<endl; 
		cin>> choice2;
		//switch to deal with four cases
		switch (choice2)					//changed by sirisha
		{
			case 1:	
			case 2:
				cout<<"I want a pizza."<<endl;	//no break here
			case 3:
			case 4:	
			case 5:
				cout<<"I love dancing."<<endl; 
				break; 
			case 6:
			case 7:
			case 8:
				cout<< "I enjoy watching movies,"<<endl; 
				cout<<"but I enjoy more playing soccer."<<endl; 
				break; 
			case 9:
			case 10:	
				//complex statement can be added any where as you wish
				cout<<"Give me a random seed =>"; 
				cin>>seed; 
									
				srand(seed);				//set the random seed
				test = rand(); 
								
				if (test%100 >= 70)
					cout<<" With 30% of chance, I will buy you pizza." <<endl; 
				else 
					cout<<" With 70 % of chance, I will buy you a chewing gum." <<endl; 
						
				break; 
			default: 
				cout<<"The choice is not valid" <<endl; 
		}
					
		//repeat or not 
		cout<<"Want to play again? (y/n) => "; 
		cin>>choice;				
		if (choice != 'y' && choice != 'Y')
		{
			// stop if the choice is not 'y' or not 'Y'
			cout<<"Au revoir, mon ami."<<endl; 
			break;					
		}
		
		cout<<"Okay, one more time >>>>>>>>>>>>>>>> "<<endl; 
	}
	

	/**************************************************************************************
	Part B. Rewrite the above given switch statement using if-else statements
	**************************************************************************************/
	//Write your code here:


	//a loop to play forever until the user chooses to stop

	while  (true)
	{
		//get the choice
		cout<<"What is your choice? ('a' to 'd', or 'A' to 'D') =>"<<endl; 
		cin>>choice3;
		choice3 = toupper(choice3); 
		//switch to deal with four cases
		if (choice3 == 'A')
		{
			cout<<"I will go to Turkey."<<endl;
		}
		else if (choice3 == 'B')
		{
			cout<<"I will go to France."<<endl;
		}
		else if (choice3 == 'C')
		{
			cout<<"I will go to Jamaica."<<endl;
			cout<<"I will go to Argentina."<<endl;
		}
		else if (choice3 == 'D')
		{
			cout<<"Give me a random seed => "<<endl; 
			cin>>seed; 				
			srand(seed);				//set the random seed
			test = rand(); 
	
			if (test%100 >= 70)
					cout<<" With 30% of chance, I will go to Iceland next summer." <<endl; 
			else 
					cout<<" With 70 % of chance, I will go to Italy next summer." <<endl;
		}
		else  
			cout<<"The choice is not valid" <<endl; 
		
					
		//repeat or not 
		cout<<"Want to play again? (y/n) => "; 
		cin>>choice;				
		if (choice != 'y' && choice != 'Y')
		{
			// stop if the choice is not 'y' or not 'Y'
			cout<<"Bye........ "<<endl; 
			break;					
		}
		
		cout<<"Okay, one more time >>>>>>>>>>>>>>>> "<<endl; 
	}

	//well done and exit
	return 0; 
}


