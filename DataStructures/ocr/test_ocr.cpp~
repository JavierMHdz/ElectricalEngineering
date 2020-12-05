#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include "character.h"
#include "point.h"
#include "bmplib.h"

using namespace std;

#define THRESH 127

unsigned char image[SIZE][SIZE];		// Input Image Data Array
unsigned char explored[SIZE][SIZE];		// Explored

//Prototype for bfs_function
void bfs_function(Point startPoint, int &ulr, int &ulc, int &h, int &w);
Point search_character(Point startPoint);

int main(int argc, char *argv[])
{
   //check if the user entered the correct amount of input arguments
   //if not, return 1
   if(argc < 2 || argc > 3){
      cout<<"You entered the incorrect amount of input arguments"<<endl;
      return 1;
   }
   
   int checkRead = readGSBMP(argv[1], image);
   int ulr, ulc, h, w;
   
   //initialize all the variables to 0
   ulr = ulc = h = w = 0;
   Point startPoint(0,0);
   
   //if the file is not read properly, return 1
   if(checkRead == 1){
      return 1;
   }
   
   //Initiliaze the explored matrix to -1 default value
   for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
         explored[i][j] = 0;
      }
   }
   
   //change all the gray to white or black
   for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
         if(image[i][j] < 127){
            image[i][j] = 0; //black
         }
         else{
            image[i][j] = 255; //white
         }
      }
   }
   
   //I need to make this run until all the characters are read
   startPoint = search_character(startPoint);
   
   if (startPoint.r != 0 && startPoint.c != 0){
   
   //Now, I will create a vector of Characters
   vector<Character> my_vec(0);

      while(startPoint.r != 0 && startPoint.c != 0){
         
         //call the bfs function
         bfs_function(startPoint, ulr, ulc, h, w);
         
         //create the character and call the functions
         Character number(image, ulr, ulc, h, w);

         //add it to the vector
         my_vec.push_back(number);
                   
         //set values back to 0 to see if there is another character                 
         startPoint.r = 0;
         startPoint.c = 0;
         
         //check if there is another character
         startPoint = search_character(startPoint);
      
      }
      
      //printing each character's classification
      //if the debug mode is off just print the recognized characters
      if(argc == 2){
         for (unsigned int i = 0; i < my_vec.size(); i++){
            //call the print function
            cout<<my_vec[i].get_classification()<<" ";
         }
         cout<<endl;
      }
      else{
         //debug mode is on and it is being asked to print the calculations
         if (atoi(argv[2]) == 1){
            for (unsigned int i = 0; i < my_vec.size(); i++){
                  //call the print function
                  my_vec[i].print_calculations();

            }
         }
      }
      
   }
   else{
      cout<<"No character was found in the image"<<endl;
   }
  return 0;
}

Point search_character(Point startPoint){
   bool boolBreak = false;
   //look for the first character
   for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
         if(image[i][j] == 0 && explored[i][j] != 1){
            startPoint.r = i;
            startPoint.c = j;
            //to keep track if we find the first black pixel
            boolBreak = true;
            break;
         }
      }
      if(boolBreak ==  true){
         break;
      }  
   }
 
   return startPoint;
}

void bfs_function(Point startPoint, int &ulr, int &ulc, int &h, int &w){
   //BFS Algorithm
   //I will create a deque
   deque<Point> my_deque;
   
   //adding it at the end of the code
   my_deque.push_back(startPoint);
   
   //Creating the minimum and maximum point
   Point min(SIZE, SIZE);
   Point max(0,0);
   
   while(!my_deque.empty()){
      //set loc equal to the next one of the Queue
      Point loc = my_deque.front();
      my_deque.pop_front();
      
      if(loc.r < min.r){
         min.r = loc.r;
      }
      if(loc.r > max.r){
         max.r = loc.r;
      }
      if(loc.c < min.c){
         min.c = loc.c;
      }
      if(loc.c > max.c){
         max.c = loc.c;
      }
   
      //setting the location of the neighboars relative to startPoint
      Point north, west, east, south, nw, ne, sw, se;
      north.r = loc.r-1;
      north.c = loc.c;
      west.r = loc.r;
      west.c = loc.c-1;
      south.r = loc.r+1;
      south.c = loc.c;
      east.r = loc.r;
      east.c = loc.c+1;
      
      //North West Direction
      nw.r = north.r;
      nw.c = west.c;
      
      //North East Direction
      ne.r = north.r;
      ne.c = east.c;
      
      //South West Direction
      sw.r = south.r;
      sw.c = west.c;
      
      //South East Direction
      se.r = south.r;
      se.c = east.c;
      
      //check for the neighbor in north
      if(north.r >= 0 && north.r < SIZE && north.c >= 0 && north.c < SIZE && explored[north.r][north.c] == 0 && image[north.r][north.c] == 0){
      my_deque.push_back(north);
      explored[north.r][north.c] = 1;
      }
      
      //check for the neighbor in south
      if(south.r >= 0 && south.r < SIZE && south.c >= 0 && south.c < SIZE && explored[south.r][south.c] == 0 && image[south.r][south.c] == 0){
      my_deque.push_back(south);
      explored[south.r][south.c] = 1;
      }
      
      //check for the neighbor in east
      if(east.r >= 0  && east.r < SIZE && east.c >= 0 && east.c < SIZE && explored[east.r][east.c] == 0 && image[east.r][east.c] == 0){
      my_deque.push_back(east);
      explored[east.r][east.c] = 1;
      }
      
      //check for the neighbor in west
      if(west.r >= 0 && west.r < SIZE && west.c >= 0 && west.c < SIZE && explored[west.r][west.c] == 0 && image[west.r][west.c] == 0){
      my_deque.push_back(west);
      explored[west.r][west.c] = 1;
      }
      
      //check for the neighbor in nw
      if(nw.r >= 0 && nw.r < SIZE && nw.c >= 0 && nw.c < SIZE && explored[nw.r][nw.c] == 0 && image[nw.r][nw.c] == 0){
      my_deque.push_back(nw);
      explored[nw.r][nw.c] = 1;
      }
      
      //check for the neighbot in sw
      if(sw.r >= 0 && sw.r < SIZE && sw.c >= 0 && sw.c < SIZE && explored[sw.r][sw.c] == 0 && image[sw.r][sw.c] == 0){
      my_deque.push_back(sw);
      explored[sw.r][sw.c] = 1;
      }
      
      //check for the neighbot in se
      if(se.r >= 0 && se.r < SIZE && se.c >= 0 && se.c < SIZE && explored[se.r][se.c] == 0 && image[se.r][se.c] == 0){
      my_deque.push_back(se);
      explored[se.r][se.c] = 1;
      }
      
      //check for the neighbot in ne
      if(ne.r >= 0 && ne.r < SIZE && ne.c >= 0 && ne.c < SIZE && explored[ne.r][ne.c] == 0 && image[ne.r][ne.c] == 0){
      my_deque.push_back(ne);
      explored[ne.r][ne.c] = 1;
      }
   }
   
   //calculate the bounding box
   ulr = min.r;
   ulc = min.c;
   h = max.r - min.r;
   w = max.c - min.c; 
}
