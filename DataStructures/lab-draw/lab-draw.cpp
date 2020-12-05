#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];

// Prototypes
void draw_rectangle(int ulr, int ulc, int h, int w);
void draw_ellipse(int cr, int cc, int a, int b);


int main()
{

  // initialize the image to all white pixels
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      image[i][j] = 255;
    }
  }

  // Main program loop here
   int numArray[5];
   bool breakOccurred = false;
   while (true){
      //creating the menu to ask the user the input
      cout<<"To draw a rectangle, enter: 0 upper-left-row upper left-col height width"<< endl;
      cout<<"To draw an ellipse, enter: 1 center_pt_row ceter_pt_col major-len minor-len"<< endl;
      cout<< "To save your drawing as \"output.bmp\" and quit, enter: 2"<<endl;
      
      //accepting all the inputs
      for (int i = 0; i < 5; i++){
         cin>>numArray[i];
         
         //check when the user wants to quit the program
         if(numArray[0] == 2){
            breakOccurred = true;
            break;
         }
      }
      
      //break out of the while loop when the user enters a 2
      if (breakOccurred == true){
         break;
      }
      
      //if numArray[1] or numArray[2] are bigger then size,
      //then the rectangle cannot be drawn.
      if (numArray[1] > SIZE || numArray[2] > SIZE){
         cout<<"You entered invalid numbers."<<endl;
      }
      else{
         if(numArray[0] == 0){
            //calling the function to create a rectangle
            draw_rectangle(numArray[1], numArray[2], numArray[3], numArray[4]);
         }
         else if(numArray[0] == 1){
         //calling the function to create an ellipse
            draw_ellipse(numArray[1], numArray[2], numArray[3], numArray[4]);
         }
         else{
         //check if the user didn't enter a 0 or 1 for the drawing options
            cout<<"You entered an incorrect option."<<endl;
         }
      }
   }


  // Write the resulting image to the .bmp file
  writeGSBMP("output.bmp", image);

  return 0;
}

void draw_rectangle(int ulr, int ulc, int h, int w)
{  
   //if rows are less than 0
   if(ulr < 0){
      h = h+ulr;
      ulr = 0;
      for (int i = 0; i < w; i++){
         image[ulr+h][ulc+i]=0;
      }
      for (int j = 0; j < h; j++){
         image[ulr+j][ulc] = 0;
         image[ulr+j][ulc+w] = 0;
      }
   }
   //if columns are less than 0
   else if(ulc < 0){
      w = w+ulc;
      ulc = 0;
      for (int i = 0; i < w; i++){
         image[ulr][ulc+i] = 0;
         image[ulr+h][ulc+i] = 0;
      }
      for(int j =0; j < h; j++){
         image[ulr+j][ulc+w] = 0;
      }
   }
   //if the addition of rows is really big
   else if((ulr+h) > SIZE){
      h = SIZE -ulr;
      for (int i = 0; i < w; i++){
         image[ulr][ulc+i] = 0;
      }
      for (int j = 0; j < h; j++){
         image[ulr+j][ulc] = 0;
         image[ulr+j][ulc+w] = 0;
      }
   }
   //if the addition of columns is really big
   else if((ulc+w) > SIZE){
      w = SIZE-ulc;
      for (int i = 0; i < w; i++){
         image[ulr][ulc+i] = 0;
         image[ulr+h][ulc+i] = 0;
      }
      for (int j = 0; j < h; j++){
         image[ulr+j][ulc] = 0;
      }
   }
   //when the rectangle fits inside the image
   else{
      for(int i=0; i < w; i++){
         image[ulr][ulc+i]= 0;
         image[ulr+h][ulc+i]= 0;
      }
       for(int j=0; j < h; j++){
         image[ulr+j][ulc] = 0;
         image[ulr+j][ulc+w] = 0;
       }
    }
}

void draw_ellipse(int cr, int cc, int a, int b)
{
   for(double theta=0.0; theta < 2*M_PI; theta += .01){
      //casting the values to double and then calculating the coordinates
      int x = static_cast<double>(a)*0.5*cos(theta);
      int y = static_cast<double>(b)*0.5*sin(theta);
      x += cr;
      y += cc;
      
      //only changing the pixels to black if the image is in the range
      if((x > 0) && (x < SIZE) && (y > 0) && (y < SIZE)){ 
         image[y][x] = 0;
      }
   }
}
