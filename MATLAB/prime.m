%{
%PRIME Calculates the nth prime number.
%This function takes in a scalar input (PRIMENUM)
%and returns the nth prime number as NPRIME
Javier Macossay
ITP 168 - Fall 2015
Lab 13
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/15/2015        Original            Javier Macossay
%}

function nprime = prime(primeNum)
%Validate input (not using a loop)
%scalar
if length(primeNum) ~= 1
    error('Input must be scalar');
end;
%greater than or equal to one
if primeNum < 1
    error('Input must be greater than or equal to 1');
end;
%Valid input

%Calculate primes
numPrimes = 1;
start = 2;
while (numPrimes < primeNum)
    %look for next prime
    maybeprime = true;
    for index = start-1:-1:2;
        if (mod(start,index ) == 0)
            maybeprime = false;
        end;
    end;
    
    if maybeprime == true
        numPrimes =  numPrimes+1;
    end;
    start = start +1;
end;
%Output nth prime
nprime = start-1
end