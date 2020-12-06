%{
Javier Macossay
ITP 168 - Fall 2015
Lab 8
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/24/2015        Original            Javier Macossay
%}

%Welcome the user
fprintf('Enter a series of numbers >= 0 or a negative number to quit.\n');

%Max value variable
maxValue = 0;

%Counter of loops
counter = 0;

while (true)
     choice = input('Enter a number of -1 to quit: ');
    if (choice < 0)
        break;
    else
        if (maxValue < choice)
            maxValue = choice;
        end;
    end;
    
    counter = counter+1;
end;

if (counter == 0)
    fprintf('You did not enter any values!\n');
else
    fprintf('The largest number was %0.3f\n', maxValue);
end;

fprintf('\n');