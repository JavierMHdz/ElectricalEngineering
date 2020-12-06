%{
Javier Macossay
ITP 168 - Fall 2015
Lab 7
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/22/2015        Original            Javier Macossay
%}

%Loop Flag
validInput = false;

while(~validInput)
    %Ask the user for input
    userIn = input('Enter a number >= 0 to calculate the factorial: ');
    if (userIn >= 0)
        validInput = true;
    else
        fprintf('Invalid input!\n\n');
    end;
end;

%Calculate factorial
if (userIn == 0)
    factorial = 1;
else
    counter = userIn;
    factorial = 1;
    while (counter ~= 0)
        factorial = counter*factorial;
        counter = counter-1;
    end;
end;
    

%Print out answer to user
fprintf('%.0f! = %.0f\n\n',userIn, factorial)