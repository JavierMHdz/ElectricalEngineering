#include <iostream> //input and output
using namespace std;

int main (){
   
   int num, countTwo, countThree, flag;
   bool done = false;
   countTwo = countThree = flag = 0;
   cout<<"Enter a number: ";
   cin>>num;
   
   while (!done)
   {
      if (num%2==0)
      {
         num=num/2;
         countTwo++;
         
         if (num == 1)
         {
            done = true;
         }
      }
      else if (num%3==0)
      {
         num=num/3;
         countThree++;
         
         if(num == 1)
         {
            done = true;
         }
      }
      else
      {
         flag = 1;
         done = true;
      }
   }
   if (flag == 1)
   {
      cout<<"No"<<endl;
   }
   else
   {
      cout<<"Yes"<<endl<<"Twos="<<countTwo<<" Threes="<<countThree<<endl;
   }
   return 0;
}
