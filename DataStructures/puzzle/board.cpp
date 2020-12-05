#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


Board::Board(int dim, int numInitMoves, int seed )
{
  _size = dim*dim;
  _tiles = new int[_size];
  srand(seed);
  for(int i=0; i < _size; i++){
    _tiles[i] = i;
  }
  int blankLoc = 0;
  while(numInitMoves > 0){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < _size){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      _tiles[blankLoc] = _tiles[randNeighbor];
      _tiles[randNeighbor] = 0;
      blankLoc = randNeighbor;
      numInitMoves--;
    }
  }
}



void Board::move(int tile)
{
  int dim = static_cast<int>(sqrt(_size));
  int tr, tc, br, bc;

  // find the tile
  int i=-1;
  while(_tiles[++i] != tile);

  tr = i / dim; 
  tc = i % dim;

  // find the blank
  int j=-1;
  while(_tiles[++j] != 0);
  br = j / dim;
  bc = j % dim;

  // if they aren't next to each other just return
  if( abs(static_cast<double>(tr-br)) + abs(static_cast<double>(tc-bc)) != 1){
    cout << "Invalid move of tile " << tile << " at ";
    cout << tr << "," << tc << " and blank spot at ";
    cout << br << "," << bc << endl;
    return;
  }
  // Swap tile and blank spot
  _tiles[j] = tile;
  _tiles[i] = 0;
}



// Write the other member functions for this class
//Constructs a solved board of given dimension
Board::Board(int dim){
  _size = dim*dim;
  _tiles = new int[_size];
  for(int i=0; i < _size; i++){
    _tiles[i] = i;
  } 
}

//Destructor
Board::~Board(){
   delete [] _tiles;
  
   
   //Not sure about this
  /* map<int, Board*> deleteMap = potentialMoves();
   map<int, Board*>::iterator it;
   for(it = deleteMap.begin(); it != deleteMap.end(); ++it){
      delete (it->second);
   }*/
}

//getSize()
int Board::getSize() const{
   return _size;
}

//getTile(int loc)
int Board::getTile(int loc) const{
   return _tiles[loc];
}

//getDim()
int Board::getDim() const{
   return static_cast<int>(sqrt(_size));
}

//solved()
bool Board::solved() const{
   bool check = true;
   cout<<_tiles[0]<<endl; 
   for (int i = 0; i < _size; i++){
      if(_tiles[i] != i){
         check = false;
      }
   }
   
   return check;
 
}

//copy constructor
Board::Board(const Board &b){
   _size = b.getSize();
   _tiles = new int[b.getSize()];
   for(int i = 0; i <_size; i++){
      _tiles[i] = b.getTile(i);
   }
}

//potentialMoves()
map<int, Board*> Board::potentialMoves() const{
   int index;
   bool north, south, west, east;
   north = south = west = east = true;
   int dim = getDim();
   Board* b = new Board(*this);   
   
   //creating the map
   map<int, Board*> neighbors;
   
   for(int i = 0; i<_size; i++){
      if(_tiles[i] == 0){
         index = i;
      }
   }
   if(index-dim < 0){
      north = false;
   }
   if(index+dim >= _size){
      south = false;
   }
   if(index+1 >= _size){
      east = false;
   }
   if(index-1 < 0){
      west = false;
   }
   //generate three boards
   //no north neighbor
   if(!north && south && east && west){
      Board s = Board(*b); 
      Board e = Board(*b);
      Board w = Board(*b);
      s.move(index+dim);
      e.move(index+1);
      w.move(index-1);
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index+1),&e));
      neighbors.insert(make_pair((index-1),&w));
   }
   //no east neighbor
   else if(north && south && !east && west){
      Board s = Board(*b); 
      Board n = Board(*b);
      Board w = Board(*b);
      s.move(index+dim);
      n.move(index-dim);
      w.move(index-1);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index-1),&w));
   }
   //no south neighbor
   else if(north && !south && east && west){
      Board e = Board(*b); 
      Board n = Board(*b);
      Board w = Board(*b);
      e.move(index+1);
      n.move(index-dim);
      w.move(index-1);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index+1),&e));
      neighbors.insert(make_pair((index-1),&w));
   }
   //no west neighbor
   else if(north && south && east && !west){
      Board s = Board(*b); 
      Board n = Board(*b);
      Board e = Board(*b);
      s.move(index+dim);
      n.move(index-dim);
      e.move(index+1);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index+1),&e));
   }
   //generate two boards
   //northwest corner
   else if(!north && !west && south && east){
      Board s = Board(*b);
      Board e = Board(*b);
      s.move(index+dim);
      e.move(index+1);
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index+1),&e));
   }
   //northeast corner
   else if(!north && !east && south && west){
      Board s = Board(*b);
      Board w = Board(*b);
      s.move(index+dim);
      w.move(index-1);
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index-1),&w));
   }
   //southeast corner
   else if(north && west && !south && !east){
      Board n = Board(*b);
      Board w = Board(*b);
      n.move(index-dim);
      w.move(index-1);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index-1),&w));
   }
   //southwest corner
   else if(!south && !west && east && north){
      Board e = Board(*b);
      Board n = Board(*b);
      e.move(index+1);
      n.move(index-dim);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index+1),&e));
   }
   //generate four boards
   //in the center or all neighbors exist
   else{
      Board n = Board(*b);
      Board s = Board(*b);
      Board e = Board(*b);
      Board w = Board(*b);
      n.move(index-dim);
      s.move(index+dim);
      e.move(index+1);
      w.move(index-1);
      neighbors.insert(make_pair((index-dim),&n));
      neighbors.insert(make_pair((index+dim),&s));
      neighbors.insert(make_pair((index+1),&e));
      neighbors.insert(make_pair((index-1),&w));
   }
   delete b;
   return neighbors;
}

ostream& operator<<(ostream &os, const Board &b){
   int dim = b.getDim();
   int index = 0;
   os<<setw(3);
   for(int i = 0; i < dim; i++){
      for(int j = 0; j < dim; j++){
         if(b._tiles[index] != 0){
            os<<b._tiles[index]<<setw(3);
         }
         else{
            os<<" "<<setw(3);
         }
         index++;  
      }
      os<<endl;
   }
   return os;
}

bool Board::operator<(const Board& rhs) const{
   bool check = true;
   for(int i = 0; i < (_size-1); i++){
      if(_tiles[i] > rhs.getTile(i)){
         check = false;
         //if it's a big board, use break
         break;
      }
   }
   return check;
}
