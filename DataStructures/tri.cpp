#include <iostream>
#include <cmath>
using namespace std;

int main (){
   int n = 31;
   int degrees, opposite;
   
   cout<<"Enter the angle theta in degrees:"<<endl;
   cin>>degrees;

   for (int i = 0; i < n; i++)
   {
      opposite = floor(tan(degrees*M_PI/180)*i);
      
      if(opposite >= 20 && opposite <= 30)
      {
         for (int k = 0; k < 20; k++)
         {
            cout<<"*";
         }
         cout<<endl;
      }
      else
      {
         for (int j = 0; j < opposite; j++)
         {
            cout<<"*";
         }
         cout<<endl;
      }
   } 
   
   return 0;
}
