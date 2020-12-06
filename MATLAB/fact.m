%{
FACT this function calculates the factorial
It asks the user to a single scalar value,
not arrays. If the user gives arrays, it's
going to print out an error.
If it's a scalar value, I will calculate
the factorial.

Javier Macossay
ITP 168 - Fall 2015
Lab 12
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/8/2015        Original            Javier Macossay
%}

function answer = fact(number)
    condition = size(number);

    if condition(1) == 1 && condition(2) == 1
            if number == 0
                answer = 1;
            else
                answer =1;
                for i = number:-1:1;
                    answer = answer*i;
                end;
            end;
    else
        fprintf('Error! Input value must be scalar!\n');
    end;