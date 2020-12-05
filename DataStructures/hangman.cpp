// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char *wordBank[] = {"computer","president","trojan","program","coffee",
			  "library","football","popcorn","science","engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand()%10];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  
  //calculate the length of the targetWord
  int sizeLen = strlen(targetWord);
  
  //initialize counter
  int count = 0;
  
  //initialize the c-string with *'s and end it with a null character
  for(int i = 0; i < sizeLen; i++)
  {
      word[i]='*';
  }
  word[sizeLen] = '\0';
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (numTurns != 0)
  {
     
     //print out message to the user
     cout<<"Current word: "<<word<<endl<<numTurns<<" remain...Enter a letter to guess:"<<endl;
     cin>>guess;
     
     //call processGuess and get as return how many times the guess letter is in the word
     count = processGuess(word,targetWord, guess);

     //reduce the amount of tries if the guess is not part of the word
     if (count == 0)
     {
         //reduce the numTurns by one
         numTurns--;
     }
     cout<<endl;
     
     //compare if the word is the same as the targetWord to see if the user guessed the word
     if(strcmp(word, targetWord) == 0)
     {
         //check if the user checked the word
         wordGuessed = true;
         break;
     }
     
  }
  
  // Print out end of game status
  if(wordGuessed == true)
  {
      //print out if the user won
      cout<<"The word was: "<<word<<". You win!"<<endl;
  }
  else
  {
      //print out if the user lost
      cout<<"Too many turns...You lose!"<<endl;
  }
   
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
   //check if the guess letter matches
   int found = 0;
   
   //calculate the length of the targetWord
   int sizeLen = strlen(targetWord);
   
   //check every single letter of the word
   for(int i = 0; i < sizeLen; i++)
   {
      if(targetWord[i] == guess)
      {
         
         //change the * for the letter guessed
         word[i] = guess;
         found++;
      }
   }
   
   if (found > 0)
   {
      //the user guessed a letter that appears
      return found;
   }
   else
   {
      return 0;   //the user guessed a letter that did not appear
   }
}

