//
//  main.cpp
//  Remainder
//
//  Created by Javier Jesus Macossay Hernandez on 11/17/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include <iostream>

int main()

{
    int first_number;
    int second_number;
    int gcd;
    std::cout<<"Enter First Number:";
    std::cin>>first_number;
    std::cout<<"Enter Second Number:";
    std::cin>>second_number;
    
    for(int i=1;i<=first_number&&i<=second_number;i++)
    {
        if(first_number%i==0&&second_number%i==0)
        {
            gcd=i;
        }
    }
    std::cout<<"Greatest Common Division (GCD):"<<gcd<<std::endl;
    return 0;
}
