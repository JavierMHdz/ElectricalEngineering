#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"

using namespace std;

//Constructor
PuzzleSolver::PuzzleSolver(const Board& b, PuzzleHeuristic *ph) : _b(b){
   //_b = b;
   _ph = ph;
   _expansions = 0;
}

PuzzleSolver::~PuzzleSolver(){

}

void PuzzleSolver::run(){
     _expansions = 0;
     PuzzleMoveHeap open_list;
     PuzzleMoveSet closed_list;
     PuzzleMove* start = new PuzzleMove(&_b);
     open_list.push(start);
     closed_list.insert(start);
     while(!open_list.empty()){
         PuzzleMove* current = open_list.top();
         
         //if the board is solved
         if(current->b->solved()){
            //set the solution in the deque
            while(current->tileMove != 0){
               _solution.push_back(current->tileMove);
               current = current->prev;
            }
            //remove all members of closelist
            PuzzleMoveSet::iterator it_close;
            for(it_close = closed_list.begin(); it_close != closed_list.end(); ++it_close){
               delete *it_close;
            }
            
            //remove all members of openlist
            for (unsigned int i = 0; i < open_list.size(); i++){
               open_list.pop();
            }
            return;
         }
         //if the board is not solved
         else{
            open_list.pop();
            map<int, Board*> moves = current->b->potentialMoves();
            map<int, Board*>::iterator it;
            for(it = moves.begin(); it != moves.end(); ++it){
                PuzzleMove* current = new PuzzleMove(it->first, it->second, current);
                PuzzleMoveSet::iterator itTwo = closed_list.find(current);
                if(itTwo == closed_list.end()){
                  current->h = _ph->compute(*(it->second));
                  open_list.push(current);
                  closed_list.insert(current);
                  _expansions++;
                }
                else{
                  //delete current;
                }
            }
         }
     }
     
     //just to check that all the memory has been freed
     //the open_list can get empty without finding a solution
     PuzzleMoveSet::iterator it_close;
     for(it_close = closed_list.begin(); it_close != closed_list.end(); ++it_close){
         delete *it_close;
     }
}

std::deque<int> PuzzleSolver::getSolution(){
   run();
   return _solution;
}

int PuzzleSolver::getNumExpansions()
{
  return _expansions;
}



