//
//  main.cpp
//  Hilo
//
//  Created by Javier Jesus Macossay Hernandez on 11/10/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void)

{
    int max=100; //max number for guessing
    
    //get a somewhat random number between zero and max;
    std::srand(std::time(0));
    int target=rand()%(max+1);
    
    cout<<"Guess a number between 0 and "<< max<< ":>";
    int guess;
    cin>>guess;
    while(guess!=target)
    {
        cout<<guess<<" <target is "<< (guess<target)
        <<endl;
        cout<<guess<<" >target is "<< (guess>target)
        <<endl;

        cout<<"Guess a number between 0 and "<< max<<":>";
        cin>>guess;
        
    }
    cout<<"Congratulations. "
    <<"You've just wasted a few minutes of your life";
    cout<<endl;
    return 0;
}
