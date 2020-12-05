//
//  main.cpp
//  Fibonacci Number
//
//  Created by Javier Jesus Macossay Hernandez on 12/3/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include<iostream>

using namespace std;

int main()
{
    int n, c, first = 0, second = 1, next;
    
    cout << "Enter the number of terms of Fibonacci series you want" << endl;
    cin >> n;
    
    cout << "First " << n << " terms of Fibonacci series are :- " << endl;
    
    for ( c = 1 ; c < n ; c++ )
    {
        if ( c <= 1 )
            next = c;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << endl;
    }
    
    return 0;
}