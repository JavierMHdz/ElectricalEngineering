#include <iostream>

using namespace std;

int main (){
   int length = 0;
   int num;
   
   //asking user for input
   cout<<"Enter a number: ";
   cin>>num;
   
   while (true)
   {
      //checking if num is equal to one
      if (num == 1){
         break;
      }
      
      //check if it's even and do proper calculations
      if(num%2 == 0){
         num = num/2;
      }
      //if it's odd, then do proper calculations
      else{
         num = num*3+1;
      }
      
      //add 1 to length variable
      length++;
      
      //display num to the user
      cout<<num<<" ";
   }
   cout<<endl;
   
   //display length to the user
   cout<<"Length: "<<length<<endl;
   
   return 0;
}
