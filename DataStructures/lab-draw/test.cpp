#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];

void draw_rectangle(int ulr, int ulc, int h, int w);

int main()
{
  // initialize the image to all white pixels
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      image[i][j] = 255;
    }
  }
  int choice, posRow, posCol, sizeOne, sizeTwo;
  cout<<"To draw a rectangle, enter: 0 upper-left-row upper left-col height width"<< endl;
  cin>> choice >> posRow >> posCol >> sizeOne >> sizeTwo;
  
  draw_rectangle(posRow, posCol, sizeOne, sizeTwo);
  
   writeGSBMP("testoutput.bmp", image);
   return 0;
}

void draw_rectangle(int ulr, int ulc, int h, int w)
{
   for(int i=0; i < w; i++){
      image[ulc+i][ulr] = 0;
      image[ulc+i][ulr+h] = 0;
   }
    for(int j=0; j < h; j++){
      image[ulc][ulr+j] = 0;
      image[ulc+w][ulr+j] = 0;
    }
  
}
