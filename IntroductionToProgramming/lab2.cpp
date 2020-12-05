// ****************************************************************
// Author:		Javier Jesus Macossay-Hernandez 20228488
// Class:		CSCI 1380-01, Summer 2013
// Lab 2:		cin, getline(), cin.get(), cin.ignore()
// Date:		June 4, 2013
// Revised on:  06/26/2009 by sirisha surisetty
// Comment:		The code here is meant to be revised.
//
//----------------------------------------------------------------
//
// Practice cin, getline(), cin.get, cin.ignore
//
// Compile and run your program. When everything is fine,
// print your .cpp file and turn it to me or the TA.
// ****************************************************************

#include <iostream>
#include <string>
using namespace std; 

int main( )
{
	//variable declarations
	string firstName, lastName;		//vars to store names and answer
	string name;					//var to store a full name with space
	string line;					//var to store a string of characters with spaces
	char ch;						//var to store one character
	int x, y;						//vars to store integers
	string str;						//var to a string

	//cin cannot get blanks (or white spaces)
	//That is, a blank in the input stop cin
	cout << "What is your first name? "; 
	cin >> firstName;
	
	cout << "What is your last name? "; 
	cin >> lastName; 
	cout<<endl<<"The name is " <<firstName <<" " <<lastName<<endl; 

	//try it again
	cout << "enter first name and last in one line with spaces in between => \n"; 
	cin >> firstName >> lastName; 
	cout << "The name is " << firstName << " " <<lastName<<endl<<endl; 

	//try it again
	cout << "enter first name and last in one line with spaces in between => \n"; 
	cin >> name; 
	cout << "The name is " << name <<endl; 

	//try it again
	cin>> name; 
	cout<< "\nSee what another cin gets is ==> " <<name <<endl<<endl; 

	//try getline
	cin.get(ch); 					//This clears the buffer 
	cout<<"Enter \'I like C++ very much\' =>\n"; 
	getline(cin, line); 
	cout<<"\nSee what getline gets ==> " <<line<<endl<<endl; 

	//try cin.get and cin.ignore
	cout<<"Enter \'I do not like C++ very much\' =>"; 
	cin.get(ch); 
	cin.ignore(20, 't'); 
	getline(cin, line); 
    
	/*********************************************************************
	This part is for you to complete
	Ask user to enter a line "123TDog and cat W346 abc defg are good."
	Use cin, cin.get,getline and store "123" in x, "346" in y, 
	"Dog and cat " in str, and "are good." in line 
	*********************************************************************/
	
	// enter the line "123TDog and cat W346 abc defg are good."
	cout<< "Enter \'123TDog and cat W346 abc defg are good.\' =>\n";
	cin >> x;
	cin >> ch; //cin.get(ch);
	getline (cin, str, 'W');
	cin >> y;
	cin.ignore (1000, 'g');
	getline (cin, line); //getline (cin,line,'\n');

	cout<<"x = "<<x<< endl;
	cout<<"y = "<<y<< endl;
	cout<<"str = "<<str<< endl;
	cout<<"line = "<<line<< endl;



	//complete the work
	return 0;

}



