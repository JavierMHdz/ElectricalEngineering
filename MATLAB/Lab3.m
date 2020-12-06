%{
Javier Macossay
ITP 168 - Fall 2015
Lab 3
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/8/2015        Original            Javier Macossay
%}

%Create the array
newArray = 1:10;

%Ask the user for input
newArray(1) = input('Trial 1: ');
newArray(2) = input('Trial 2: ');
newArray(3) = input('Trial 3: ');
newArray(4) = input('Trial 4: ');
newArray(5) = input('Trial 5: ');
newArray(6) = input('Trial 6: ');
newArray(7) = input('Trial 7: ');
newArray(8) = input('Trial 8: ');
newArray(9) = input('Trial 9: ');
newArray(10) = input('Trial 10: ');

%Getting the average of the distance traveled
total = sum(newArray);
averageDistance = total/10;

%Display the average to the user
fprintf('The average distance traveled was ');
fprintf('%0.2f', averageDistance);
fprintf(' inches\n');