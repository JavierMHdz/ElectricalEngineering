/*
character.cpp

Author: Javier Jesus Macossay-Hernandez
*/
#include <iostream>
#include <cstddef>
#include "character.h"

using namespace std;

//constructor
Character::Character(){
  //set all the values equal to 0
  ul_r = ul_c = height = width = euler = 0;
  q0 = q1 = q2 = q3 = q4 = qd = 0;
  area = perimeter = 0;
  ratio = ver_centroid =  hor_centroid = 0;
  ver_numerator = ver_denominator = 0;
  hor_numerator = hor_denominator = 0;
  ver_sym = hor_sym = 0;
  shift_ver_cen = shift_hor_cen =0;
}

//overloaded constructor
Character::Character(unsigned char(*myimage)[256], int ulr, int ulc, int h, int w){
   image = myimage;
   ul_r = ulr;
   ul_c = ulc;
   height = h;
   width = w;

}

Character::~Character(){

}

//perform tests
void Character::perform_tests(){
   
   //Perform tests
   calc_bit_quads();
   euler = calc_euler_number();
   area = calc_area();
   perimeter = calc_perimeter();
   ratio = calc_aspect_ratio();
   calc_spatial_moment();
   calc_sym();
}

void Character::calc_bit_quads(){
   q0 = q1 = q2 = q3 = q4 =qd = 0;
   for(int i = ul_r-1; i <= ul_r + height + 1; i++){
      for(int j = ul_c-1; j <= ul_c + width + 1; j++){
         unsigned char positionOne = image[i][j];
         unsigned char positionTwo = image[i][j+1];
         unsigned char positionThree = image[i+1][j];
         unsigned char positionFour = image[i+1][j+1];

         //all white
         if(positionOne == 255 && positionTwo == 255 && positionThree == 255 && positionFour == 255){
            q0++;
            //cout<<"q0 "<<q0<<endl;
         }
         //one black 
         else if((positionOne+positionTwo+positionThree+positionFour) == 255*3){
            q1++;
            //cout<<"q1 "<<q1<<endl;
         }
         //three blacks
         else if((positionOne+positionTwo+positionThree+positionFour) == 255){
            q3++;
            //cout<<"q3 "<<q3<<endl;
         }
         //four blacks
         else if((positionOne+positionTwo+positionThree+positionFour) == 0){
            q4++;
            //cout<<"q4 "<<q4<<endl;
         }
         //diagonal
         else if((positionOne != 255 && positionFour != 255) != (positionTwo !=255 && positionThree != 255)){
            qd++;
            //cout<<"qd "<<qd<<endl;
         }
         //two blacks
         else{
            q2++;
            //cout<<"q2 "<<q2<<endl;
         }
         
      }
   }
}

int Character::calc_area(){
   return 0.25*(q1+2*q2+2*qd+3*q3+4*q4);
}

int Character::calc_perimeter(){
   return q1+q2+2*qd+q3;
}

int Character::calc_euler_number(){
   return 0.25*(q1-q3-(2*qd));
}

void Character::calc_spatial_moment(){
   int isblack;

   for(int i = ul_r; i < ul_r+height; i++){
      for(int j = ul_c; j < ul_c+width; j++){
         if (image[i][j] == 0){
            isblack = 1;
         }
         else{
            isblack = 0;
         }
         ver_numerator += i*isblack;
         ver_denominator += isblack;
         hor_numerator += j*isblack;
         hor_denominator = ver_denominator;
      }
   }
   
   ver_centroid = ((double)ver_numerator/ver_denominator)-ul_r;
   hor_centroid = ((double)hor_numerator/hor_denominator)-ul_c;
   
   shift_ver_cen = (ver_centroid - (0.5*height))*-1;
   shift_hor_cen = hor_centroid - (0.5*width);
   
}

void Character::calc_sym(){
   //check vertical symmetry
   int ver_cnt = 0;
   int check_ver = 0;
   for(int i = 0; i < width; i++){
      for(int j = 0; j < (height*0.5); j++){
         if(image[ul_r+j][ul_c+i] == image[ul_r+height-j][ul_c+i]){
            ver_cnt++;
         }
         check_ver++;
      }
   }
   
   //check horizontal symmetry
   int hor_cnt = 0;
   int check_hor = 0;
   for(int i = 0; i < height; i++){
      for(int j = 0; j < (width*0.5); j++){
         if(image[ul_r+i][ul_c+j]==image[ul_r+i][ul_c+width-j]){
            hor_cnt++;
         }
         check_hor++;
      }
   }
   ver_sym = (double)ver_cnt/check_ver;
   hor_sym = (double)hor_cnt/check_hor;
   
}

double Character::calc_aspect_ratio(){
   return (double)height/width;
} 

//classify
void Character::classify(){
   //perform classification tests something();
   perform_tests();
   
   //determine the character and set it as a private data member
   //first compare euler number
   if (euler == -1){
      recognized_char = '8';
   }
   else if (euler == 1){
      //7, 3, 1, 2, 5
      if(shift_ver_cen < 0 && shift_hor_cen < 0){
         recognized_char = '1';
      }
      else if(shift_ver_cen < 0 && shift_hor_cen > 0 && ver_sym > 0.58){
         recognized_char = '2';
      }
      else if(shift_ver_cen > shift_hor_cen && shift_hor_cen > 0){
         recognized_char = '7';
      }
      else if(shift_hor_cen > shift_ver_cen && shift_ver_cen >0 && shift_hor_cen > 0 && shift_hor_cen > 2.2){
         recognized_char = '3';
      }
      else{
         recognized_char = '5';
      }
   }
   else{
      //4, 6, 9, 0
      if(shift_ver_cen < 0){
         recognized_char = '6';
      }
      else if(shift_ver_cen > 1.99){
         recognized_char = '9';
      }
      else if(ver_sym > 0.9 && hor_sym > 0.85){
         recognized_char = '0';
      }
      else{
         recognized_char = '4';
      }
   }
}

//get classification
char Character::get_classification(){
   //call the classify function
   classify();
   return recognized_char;
}

//get bounding box
void Character::get_bounding_box(int &sr, int &sc, int &er, int &ec){
   sr = ul_r;
   sc = ul_c;
   er = ul_r+height;
   ec = ul_c+width;
}

//print calculations
void Character::print_calculations(){
   //call the classification function
   get_classification();
   
   cout<<"Character in bounding box: ";
   cout<<ul_r<<","<<ul_c<<" to "<<ul_r+height<<","<<ul_c+width<<endl;
   cout<<"=============================================="<<endl;
   cout<<"BQ0="<<q0<<" ";
   cout<<"BQ1="<<q1<<" ";
   cout<<"BQ2="<<q2<<" ";
   cout<<"BQ3="<<q3<<" ";
   cout<<"BQ4="<<q4<<" ";
   cout<<"BQD="<<qd<<" ";
   
   cout<<"Euler number="<<euler<<endl;
   cout<<"Area="<<area<<endl;
   cout<<"Perimeter="<<perimeter<<endl;
   cout<<"VCentroid="<<ver_centroid<<" / HCentroid="<<hor_centroid<<endl;
   cout<<"Shifted VCentroid="<<shift_ver_cen<<" / Shifted HCentroid="<<shift_hor_cen<<endl;
   cout<<"VSym="<<ver_sym<<" / HSym="<<hor_sym<<endl;
   cout<<"Aspect ratio="<<ratio<<endl;
   cout<<"Character is classified as "<<recognized_char<<endl;
  cout<<endl;
}
