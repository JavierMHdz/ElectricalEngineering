#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include "puzzle_heur.h"
#include "board.h"
using namespace std;

int PuzzleBFSHeuristic::compute(const Board& b){
   return 0;
}

int PuzzleOutOfPlaceHeuristic::compute(const Board& b){
   int counter = 0;
   for(int i = 0; i < b.getSize(); i++){
         //check if the value inside the tile
         //is not a in it's right place or blank
         if(b.getTile(i) != i && b.getTile(i) != 0){
            counter++;
         }
   }
   return counter;
}

int PuzzleManhattanHeuristic::compute(const Board& b){
   int counter = 0;
   int dim = b.getDim();
   for(int i = 0; i < b.getSize(); i++){
      //as long as it's not the white space
      if(b.getTile(i) != 0){
         //finding the coordinates of the actual value
         int actualVal = b.getTile(i);
         int actualRow = actualVal/dim;
         int actualCol = actualVal%dim;
         
         //finding the right place for the actual value
         int rightRow = i/dim;
         int rightCol = i%dim;
         
         //I will check how far is the actualCol from the right place
         while(rightCol != actualCol){
            if(rightCol > actualCol){
               actualCol++;
            }
            else{
               actualCol--;
            }
            counter++;
         }
         
         while(rightRow != actualRow){
            if(rightRow > actualRow){
               actualRow++;
            }
            else{
               actualRow--;
            }
            counter++;
         }
      }
   }
   return counter;
}
