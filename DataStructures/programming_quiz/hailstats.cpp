#include <iostream>
#include <climits>   //to use INT_MAX
using namespace std;

int main(){
   int numOne, numTwo, numCheck, minLength;
   int maxLength, achievedMax, achievedMin, length;
   
   //setting my initial max and min lengths
   maxLength = -1;
   minLength = INT_MAX;

   //ask the user for the range
   cout<<"Enter the range you want to search: ";
   cin>>numOne>>numTwo;
   
   //check if the range is valid
   if(numOne > numTwo){
      cout<<"Invalid range"<<endl;
   }
   //if the range is valid, run the program
   else{
      
      //run the program for all the range (inclusive)
      for(int i = numOne; i <= numTwo; i++){
         numCheck = i;
         length = 0;
         
         while(true){
            
            //checking if num is equal to one
            if(numCheck == 1){
               break;
            }
            
            //check if it's even and do proper calculations
            if(numCheck%2 == 0){
               numCheck = numCheck/2;
            }
            //if it's odd, then do proper calculations
            else{
               numCheck = numCheck*3+1;
            }
            
            //add 1 to length variable
            length++;
         }
         
         //check if length is bigger than maxLength and store values
         if(length > maxLength){
            maxLength = length;
            achievedMax = i;
         }
         
         //check if length is smaller than minLength and sotre values
         if(length < minLength){
            minLength = length;
            achievedMin = i;
         }

      }
      
      //display length to the user
      cout<<"Minimum length: "<<minLength<<endl;
      cout<<"Achieved by: "<<achievedMin<<endl;
      cout<<"Maximum length: "<<maxLength<<endl;
      cout<<"Achieved by: "<<achievedMax<<endl;
   }
   return 0;
}
