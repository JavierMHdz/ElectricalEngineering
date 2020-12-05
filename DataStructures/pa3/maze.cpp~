/* 
maze.cpp

Author: Javier Jesus Macossay-Hernandez

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main() {
   int rows, cols, result;
   char** mymaze;
   
   mymaze = read_maze(&rows, &cols); // FILL THIS IN

   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
   for (int i = 0; i < rows; i++){
      delete [] mymaze[i];
   }
   delete [] mymaze;
   
   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) {
   //declaring all the variables
   bool pathFound = false;
   int countS = 0;
   int countF = 0;
   //create starting location, loc, and neighbors
   Location start, loc, north, west, east, south;
   //create queue with max int
   Queue q(rows*cols);
   
   //search for S and F in the maze
   for(int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
  
        if(maze[i][j] == 'S'){
            countS++;
            start.row = i;
            start.col = j;         
        }
        if(maze[i][j] == 'F'){
            countF++;
        }
      }
   }
   
   //check and return -1 if it is an invalid maze
   if(countS != 1 || countF != 1){
      return -1;
   }
   
   //2D array of bools and initializing it to false
   bool** visitedCells = new bool*[rows];
   for (int i = 0; i < rows; i++){
      visitedCells[i] = new bool[cols];
   }
       
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         visitedCells [i][j] = false;
         }
   }
   
   //2D array of Location and initializing it to -1,-1
   Location** predecessor = new Location*[rows];
   for (int i = 0; i < rows; i++){
      predecessor[i] = new Location[cols];
   }
       
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
         predecessor[i][j].row = -1;
         predecessor[i][j].col = -1;
      }
   }
   
   //send start to queue
   q.add_to_back(start);
   //set start visitedCells as true
   visitedCells[start.row][start.col] = true;
   //set it on the predecessor array as NULL
   predecessor[start.row][start.col].row = (int)NULL;
   predecessor[start.row][start.col].col = (int)NULL;
   
   //BFS algorithm
   while(!q.is_empty()){
      //set loc equal to the next one of the Queue
      loc = q.remove_from_front();
      //look if the path was found
      if(maze[loc.row][loc.col] == 'F'){
         pathFound = true;
         break;
      }
      
      //setting the location of the neighbors relative to loc
      north.row = loc.row-1;
      north.col = loc.col;
      west.row = loc.row;
      west.col = loc.col-1;
      south.row = loc.row+1;
      south.col = loc.col;
      east.row = loc.row;
      east.col = loc.col+1;
      
      //check for the neighbor in north
      if(north.row >= 0 && north.row < rows && north.col >= 0 && north.col < cols){
         if(visitedCells[north.row][north.col] == false && maze[north.row][north.col] != '#'){
               q.add_to_back(north);
               predecessor[north.row][north.col].row = loc.row;
               predecessor[north.row][north.col].col = loc.col;
               visitedCells[north.row][north.col] = true;
         }
      }
      
      //check for the neighbor in west
      if(west.row >= 0 && west.row < rows && west.col >= 0 && west.col < cols){
         if(visitedCells[west.row][west.col] == false && maze[west.row][west.col] != '#'){
               q.add_to_back(west);
               predecessor[west.row][west.col].row = loc.row;
               predecessor[west.row][west.col].col = loc.col;
               visitedCells[west.row][west.col] = true;
         }
      }
      
      //check for the neighbor in south
      if(south.row >= 0 && south.row < rows && south.col >= 0 && south.col < cols){
         if(visitedCells[south.row][south.col] == false && maze[south.row][south.col] != '#'){
               q.add_to_back(south);
               predecessor[south.row][south.col].row = loc.row;
               predecessor[south.row][south.col].col = loc.col;
               visitedCells[south.row][south.col] = true;
         }
      }
      
      //check for the neighbor in east
      if(east.row >= 0 && east.row < rows && east.col >= 0 && east.col < cols){     
         if(visitedCells[east.row][east.col] == false && maze[east.row][east.col] != '#'){
               q.add_to_back(east);
               predecessor[east.row][east.col].row = loc.row;
               predecessor[east.row][east.col].col = loc.col;
               visitedCells[east.row][east.col] = true;
         }
      }
      

   }
   
   //walk back the maze and put a start in the shortest path
   while(true){
      loc = predecessor[loc.row][loc.col];
      if(maze[loc.row][loc.col] == 'S'){
         break;
      }
      maze[loc.row][loc.col] = '*';
   }
         
   //delete all the data allocated in the heap
   for (int i = 0; i < rows; i++){
      delete [] visitedCells [i];
   }
   delete [] visitedCells;
   
   for (int j = 0; j < rows; j++){
      delete [] predecessor[j];
   }
   delete [] predecessor;

   //return 1 if path was found or 0 if it was not found
   if(pathFound == true){
      return 1;
   }
   else{
      return 0;
   }
}
