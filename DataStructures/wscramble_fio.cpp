char*// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Prototype
void permute(char items[], int len);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s

int main(int argc, char* argv[])
{
   //check if the right amount of input arguments were given
   if (argc != 2) {
      cout << "Wrong number of arguments." << endl;
      return 1;
   }
   
  srand(time(0));
  char guess[80];
  ifstream ifile(argv[1]);
  int numWords;
  char buffer[41];
  bool wordGuessed = false;
  int numTurns = 10;
  
  //check if the file opened
  if (ifile.fail()){
      cout<<"The text file could not be opened."<<endl;
      return 1;
  }
  //check if there is an integer in the file
  ifile >> numWords;
  if(ifile.fail()){
      cout<<"The text does not contain an integer in the beginning of the file."<<endl;
      ifile.close();
      return 1;
  }
  
  //initializing the temp[i] into new char's
  char** temp = new char*[numWords];
  for(int i = 0; i < numWords; ++i){
   temp[i] = new char;
  }
  
  //dynamically allocate array for wordBank
  char* wordBank[numWords];
  ifile >> buffer;
  for (int i = 0; i < numWords; i++){
      strcpy(temp[i],buffer);
      wordBank[i] = temp[i];
      ifile >> buffer;
  }

  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // More initialization code
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while ( !wordGuessed && numTurns > 0 ){
    cout << "\nCurrent word:  " << word << endl;
    cin >> guess;
    wordGuessed = (strncmp(guess, wordBank[target], targetLen+1) == 0);
    numTurns--;
  }
  if(wordGuessed){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  //delete all the dynamic allocated variables
  delete [] word;
  for (int i = 0; i < numWords; i++){
      delete wordBank[i];
  }
  delete [] temp;
  //close the file
  ifile.close();
  return 0;
}

// Scramble the letters
void permute(char items[], int len)
{
  for(int i=len-1; i > 0; --i){
    int r =  rand() % i;
    int temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }

}

