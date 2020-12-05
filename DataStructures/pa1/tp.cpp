/*********************************************************
 * File name : tp.cpp
 * Author    : Javier Jesus Macossay-Hernandez
 * Date      : January 29, 2016
 * Purpose   : Simulates the toilet-paper problem
 * Notes     : None
 *********************************************************/

#include <iostream>   // Basic I/O => cin, cout, etc.
#include <cstdlib>    // Other helpful functions => rand(), RANDMAX
#include <iomanip>    //setprecision function used for output

using namespace std;

// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();

// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
int single_roll_sim(int N, double p);

int main(int argc, char *argv[])
{
  srand(time(0));   //changes the pattern to create the random number

  const int num_sims = 100000;  // number of trials for our simulation

  int N;                // initial number of squares on each roll

  double p;             // probability of a big-chooser

  int total_squares; // for each trial we'll keeping a running sum
                        // of the squares lef t on the non-empty roll
                        
  // Do some error checking to make sure the user
  // entered the correct number of arguments to the program
  if(argc < 3){
    cout << "Usage: " << argv[0] << " N p" << endl;
    cout << "\tN = number of squares on each roll to start" << endl;
    cout << "\tp = probability of a big-chooser" << endl;
    return 1;
  }
  
  N = atoi(argv[1]);   // convert the argument to an integer
  p = atof(argv[2]);   // convert the argument to a floating point

  // Add your code here
  total_squares = 0; //assigning the value of zero to total_squares

  for (int i = 0; i < num_sims; i++)   //calling single_roll_sim 100,000 times
  {
      total_squares += single_roll_sim(N,p); //adding all the remaining squares
  }
  
  //calculating the average of the remaining squares 
  double avg = static_cast<double>(total_squares)/num_sims;
  
  //displaying the average to the user with three values after the decimal point
  cout<<"Average: "<<fixed<<setprecision(3)<<avg<<endl;
  
  return 0; //return to operating system
}

// return the number of squares on the non-empty roll
int single_roll_sim(int N, double p)
{
   int rollOne, rollTwo, person; //declaring variables
   rollOne = rollTwo = N;  //setting the two variables equal to the value of N
   bool done = false;   //keep track if a roll is empty

   
   while (!done)
   {
      //creating a person with the rand_uniform function
      double randNum = rand_uniform();
      if (randNum <= p)
      {
         person = 1; //big chooser
      }
      else
      {
         person = 0; //small chooser
      }
      
      if (person == 1)  //big chooser
      {
         if (rollOne == rollTwo) //always check rollOne first
         {
            rollOne--;
         }
         else if (rollOne > rollTwo)
         {
            rollOne--;
         }
         else
         {
            rollTwo--;
         }
      }
      else  //small chooser
      {
         if (rollOne == rollTwo)
         {
            rollOne--;
         }
         else if (rollOne > rollTwo) //small chooser likes to use small rolls
         {
            rollTwo--;
         }
         else
         {
            rollOne--;
         }
      }
      
      if (rollOne == 0 || rollTwo == 0) //check if a roll is empty
      {
         //the simulation is done and it will take us outside the while loop
         done = true;
      }
   }
   //out of the while loop
   if (rollOne != 0) //if rollOne is not empty, then return that value
   {
      return rollOne;
   }
   else  //if rollTwo is not empty, then return that value
   {
      return rollTwo;
   }
}

// returns a uniformly-distributed number in the range [0,1]
double rand_uniform()
{
   //create a random number from 0 to 1 (inclusive)
   double randNum = static_cast<double>(rand())/RAND_MAX;
   return randNum;
}
