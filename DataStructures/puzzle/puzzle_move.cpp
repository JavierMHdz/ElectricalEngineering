#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include "puzzle_move.h"
using namespace std;

PuzzleMove::PuzzleMove(Board* board){
   tileMove = g = h = 0;
   b = board;
   prev = NULL;
}

PuzzleMove::PuzzleMove(int tile, Board *board, PuzzleMove *parent){
   g = parent->g + 1;
   h = 0; 
   tileMove = tile;
   b = board;
   prev = parent;
}

PuzzleMove::~PuzzleMove(){
   //PuzzleMove* end = NULL;
   if(prev != NULL){
      
      delete b;
   }
}

bool PuzzleMove::operator<(const PuzzleMove& p) const{
   if(g+h < p.g+p.h){
      return true;
   }
   return false;
}

void PuzzleMove::score(PuzzleHeuristic* ph){
   h = ph->compute(*b);
}


