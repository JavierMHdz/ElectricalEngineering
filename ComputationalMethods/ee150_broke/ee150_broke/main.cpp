//
//  main.cpp
//  ee150_broke
//
//  Created by Javier Jesus Macossay Hernandez on 11/17/14.
//  Copyright (c) 2014 Javier Jesus Macossay Hernandez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double p;
    double totalflips;
    srand(1000);
    
    int seedintP1; int seedintP2; int seedintP3;
    printf("What is the intial value for Player 1?\n");
    scanf("%d", &seedintP1);
    printf("What is the intial value for Player 2?\n");
    scanf("%d", &seedintP2);
    printf("What is the intial value for Player 3?\n");
    scanf("%d", &seedintP3);
    
    printf("What is the fairness of the coin?\n");
    scanf("%lf", &p);
    
    
    for (int t = 0; t < 100000; t++)
    {
        int intP1 = seedintP1;
        int intP2 = seedintP2;
        int intP3 = seedintP3;
        
        while ((intP1 >0) && (intP2 > 0) && (intP3))
        {
            
            int heads[3] = {0};
            int tails[3] = {0};
            
            double flip1 = (double)rand()/ (double) RAND_MAX;
            double flip2 = (double)rand()/ (double) RAND_MAX;
            double flip3 = (double)rand()/ (double) RAND_MAX;
            
            
            if (flip1 < p)
                heads[0] = heads[0] + 1;
            else
                tails[0] = tails [0] + 1;
            
            if (flip2 < p)
                heads[1] = heads[1] + 1;
            else
                tails[1] = tails [1] + 1;
            
            if (flip3 < p)
                heads[2] = heads[2] + 1;
            else
                tails[2] = tails [2] + 1;
            
            // Player 1
            
            if ((heads[0] == 1 && heads[1] == 0 && heads[2] == 0 ) || (tails[0] == 1 && tails[1] == 0 && tails[2] == 0))
            {
                intP1 = intP1 + 2;
                intP2 = intP2 - 1;
                intP3 = intP3 - 1;
            }
            
            // Player 2
            else if ((heads[0] == 0 && heads[1] == 1 && heads[2] == 0 ) || (tails[0] == 0 && tails[1] == 1 && tails[2] == 0))
            {
                intP1 = intP1 - 1;
                intP2 = intP2 + 2;
                intP3 = intP3 - 1;
            }
            
            // Player 3
            else if ((heads[0] == 0 && heads[1] == 0 && heads[2] == 1 ) || (tails[0] == 0 && tails[1] == 0 && tails[2] == 1))
            {
                intP1 = intP1 - 1;
                intP2 = intP2 - 1;
                intP3 = intP3 + 2;
            }
            
            
             totalflips = totalflips + 1;
        }
    }
    
    totalflips = totalflips / 100000;
    printf("Average flips for 100,000 runs: %6.3lf\n", totalflips);
}
