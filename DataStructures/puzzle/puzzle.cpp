#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

int main(int argc, char *argv[])
{
  if(argc < 5){
    cerr << "Usage: ./puzzle size initMoves seed heur" << endl;
    return 1;
  }

  int size, initMoves, seed, heur;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);
  heur = atoi(argv[4]);

  Board b(size,initMoves,seed);

  PuzzleHeuristic* ph;
  if(heur == 0){
    ph = new PuzzleBFSHeuristic;
  }
  else if(heur == 1){
    ph = new PuzzleOutOfPlaceHeuristic;
  }
  else {
    ph = new PuzzleManhattanHeuristic;
  }

  //*********** Implement the gameplay here
  int option;
  while(true){
      cout<<b<<endl;
      cout<<"Enter a tile number to move or -1 for a cheat: ";
      cin >> option;
      if(option < -1 || option >= b.getSize()){
         cout<<"Invalid option. "<<endl;
         cout<<endl;
      }
      else if(option == 0){
         cout<<"Thank you for playing."<<endl;
         break;
      }
      else if (option == -1){
         deque<int> solved;
         PuzzleSolver answer(b, ph);
         solved = answer.getSolution();
         //print the values out
         cout<<"Try this sequence: "<<endl;
         int counter = 0;
         while(0 < counter){
            cout<<solved.back()<<" ";
            solved.pop_back();
            counter--;
         }
         cout<<endl;
         cout<<"(Expansions = "<<answer.getNumExpansions()<<")"<<endl;
         cout<<endl;
      }
      else{
         //move the tile
         b.move(option);
      }
      //solved returns a boolean
      if(b.solved()){
         cout<<b<<endl;
         cout<<"Congrats! You have solved the puzzle."<<endl;
         break;
      }
  }

  delete ph;
  return 0;
}
