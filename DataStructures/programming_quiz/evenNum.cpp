#include <iostream>
#include <climits>
using namespace std;

   int main (){
   int numOne, numTwo, numCheck, currentLength, maxLength, minLength, achievedMax, achievedMin;

   maxLength = -1;
   minLength = INT_MAX;
 cout<<"Enter two numbers: ";
cin>>numOne>>numTwo;
 for(int i = numOne; i <= numTwo; i++){

         numCheck = i;
         currentLength = 0;
         
         while(true){
         
            if(numCheck == 1){
               break;
            }
            
            if(numCheck%2 == 0){
               numCheck = numCheck/2;
            }
            else{
               numCheck = numCheck*3+1;
            }
            
            currentLength++;
         }
         
         if(currentLength > maxLength){
            maxLength = currentLength;
            achievedMax = i;
         }
         
         if(currentLength < minLength){
            minLength = currentLength;
            achievedMin = i;
         }
         

      }
      
      cout<<"Minimum length: "<<minLength<<endl;
      cout<<"Achieved by: "<<achievedMin<<endl;
      cout<<"Maximum length: "<<maxLength<<endl;
      cout<<"Achieved by: "<<achievedMax<<endl;
return 0;
}
