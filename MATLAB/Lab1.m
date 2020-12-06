%{
Javier Macossay
ITP 168 - Fall 2015
Lab 1
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/1/2015        Original            Javier Macossay
%}

%Welcome
fprintf('\nAverage Calculator\n');

%Creating variables
firstNumber = input('Please enter first number: ');
secondNumber = input('Please enter second number: ');
thirdNumber = input('Please enter third number: ');
fourthNumber = input('Please enter fourth number: ');
fifthNumber = input('Please enter fifth number: ');

%Calculating average
average = (firstNumber + secondNumber + thirdNumber + fourthNumber + fifthNumber)/5;

%Output
fprintf('The average is: %d\n', average);

