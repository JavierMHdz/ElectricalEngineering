//
//  main.cpp
//  C++ Gravity
//
//  Created by Javier Jesus Macossay Hernandez on 10/29/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include <iostream>
using namespace std;

int main ()
{
    double g=9.81;// acceleration due to gravity
    double t; //time in seconds
              //I declared all the variables at the beginning of the program
    
    cout<<"Input the initial velocity (m/s):>";
    double v0;
    cin>>v0;
    
    cout<<"Input the time (s):>";
    cin>>t;
    
    cout<<"================"
    <<endl;
    
    cout<<"The velocity at time "<<t<<" is "<<v0-g*t<<endl;
    return 0;
}