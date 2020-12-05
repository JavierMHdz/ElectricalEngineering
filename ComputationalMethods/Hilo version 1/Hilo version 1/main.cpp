//
//  main.cpp
//  Hilo version 1
//
//  Created by Javier Jesus Macossay Hernandez on 11/13/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{ 	cout << "High Low Number" << endl;
    std::srand(std::time(0));
    double randomNo = rand() % 100 + 1;
   
    bool game = true;
    while (game)
    {
        cout << "Enter a number between 0-100: ";
        int num = 1;
        cin >> num;
        if ((num >= 0) && (num <= 100))
        {
            if (num < randomNo)
            {
                cout << "Your Guess is Too Low!" << endl;
            }
            else if (num> randomNo)
            {
                cout << "Your Guess is Too High!" << endl;
                
            }
            else if (num == randomNo)
            {
                cout << "You Win!!" << endl;
                game = false;
                return 0;
            }
        }
    }
    
    return 0;
}