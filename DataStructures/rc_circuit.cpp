#include <iostream> //including inputs and outputs
#include <iomanip> //inlcuding tabular output, setw, and floating point precision, setprecision
#include <cmath> //including exp function

using namespace std;

int main ()
{
   double Vc, Vs, R, C, T, t, t10, t90; //declaring variables
   t = t10 = t90 = 0;
   bool done = false;
   bool flag10 = false;
   bool flag90 = false;
   
   cout<<"Enter Vs, R, C, and T separated by spaces: "<<endl; //asking for input
   cin>> Vs >> R >> C >> T;
 
   cout<<setw(15)<<"Time"<<setw(15)<<"Vc"<<endl; //printing the header of the table

   while (!done)
   {
         Vc = Vs*(1-exp(-t/(R*C))); //calculating the voltage of capacitor
         
         cout<<setw(15)<<fixed<<setprecision(2)<<t<<setw(15)<<Vc<<endl;
         
         if (Vc > (Vs*0.1) && flag10 == false) //checking if the capacitor is charged 10%
         {
            t10 = t;
            flag10 = true;
         }
         
         if (Vc > (Vs*0.9) && flag90 == false) //checking if the capacitor is charged 90%
         {
            t90 = t;
            flag90 = true;
         }
        
         if (t > T) //checking if we are done comparing
         {
            done = true;
         } 
         
         t += T/25; //updating the condition
   }
   
   if (t10 != 0 && t90 != 0)
   {
      cout<<"Rise time is: "<<t90-t10<<" seconds"<<endl;
   }
   else
   {
      cout<<"No rise-time available"<<endl;
   }
   
   return 0;
}
