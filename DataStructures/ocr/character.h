#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
 public:
  Character();
  // the first parameter should just be passed in and saved to 
  //  the 'image' data member as in ( image = myimage; )
  Character(unsigned char (*myimage)[256], int ulr, int ulc, int h, int w );
  ~Character();

  void perform_tests();
  void classify();
  char get_classification();
  
  // returns upper-left point and lower-right point of bounding box
  //  DOES NOT compute bounding box...it's already in your data members
  //  just returns the bounding box if a user wants the bounds
  void get_bounding_box(int &ulr, int &ulc, int &lrr, int &lrc);
  void print_calculations();

 private:
  //==============
  // Helper Functions
  //==============

  void calc_bit_quads();
  int calc_area();
  int calc_perimeter();
  int calc_euler_number();
  void calc_spatial_moment(); // calcs the horizontal & vertical centroids
  void calc_sym();            // calcs horizontal and vertical symmetry
  double calc_aspect_ratio();

  //==============
  // Data Members
  //==============
 private: 
  int ul_r, ul_c;          //Upper-left most row, column
  int height, width;       //height and width of character
  int euler;               //Euler number

  // feel free to add functions here.
  int q0, q1, q2, q3, q4, qd;
  int area;
  int perimeter;
  double ratio;
  double ver_centroid, hor_centroid;
  int ver_numerator, ver_denominator;
  int hor_numerator, hor_denominator;
  double ver_sym, hor_sym;
  double shift_ver_cen, shift_hor_cen;
  
  char recognized_char; //probably the same as char classified on character.cpp
  unsigned char (*image)[256];


};

#endif

