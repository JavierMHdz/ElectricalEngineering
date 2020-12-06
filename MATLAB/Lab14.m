function x = approx(value,string,iterations)
%{
APPROX this function calculates the approximation
using the equations from Homework 4 (sine, cosine,
exponent).

Javier Macossay
ITP 168 - Fall 2015
Lab 14
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/20/2015        Original            Javier Macossay
%}

    
    if nargin == 2
        iterations = 10;
    end;
    
    if (iterations < 1)
        error('Number of iterations must be greater than 0');
    end;
    
    if (numel(value) ~= 1)
        error('X must be scalar');
    end;
        
    if (strcmpi('exp', string))

        sum = 0;
        for index = 1: iterations
            answer = (power(value,(index-1)))/factorial(index-1);
            sum = answer + sum;
        end;
        x = sum;

    elseif (strcmpi('sin',string))

        sum = 0;
        for index = 1: iterations
            answer = ((power(-1,index-1))*power(value,(2*index)-1))/factorial((2*index)-1);
            sum = answer + sum;
        end;
        x = sum;


    elseif (strcmpi('cos',string))

        sum = 0;
        for index = 1: iterations
            answer = ((power(-1,index-1))*power(value,(2*index)-2))/factorial((2*index)-2);
            sum = answer + sum;
        end;
        x = sum;

    else
        error('Invalid function name');
    end;
end