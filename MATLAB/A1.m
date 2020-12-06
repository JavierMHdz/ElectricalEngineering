%{
Javier Macossay
ITP 168 - Fall 2015
Homework 1: Payment Calculator
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/4/2015        Original            Javier Macossay
9/5/2015        Added Part 1        Javier Macossay
9/6/2015        Added Part 2        Javier Macossay
%}

%Welcome
fprintf('Auto Loan Calculator\n');

%Asking the user for the purchase price of the car
purchasePrice = input('\nPlease enter the purchase price of the car: $');
downPayment = input('Please enter your down payment as a percentage of the purchase price \nEg 10% is 10: ');

%Calculating Principle
if downPayment == 0
    principle = purchasePrice;
else
    principle = purchasePrice-(purchasePrice*(downPayment/100));
end

%Display the principle to the user
fprintf('Your principle is: ');
fprintf('$%0.2f\n', principle);

%Ask the user for the Annual Percentage Rate
annualPercentageRate = input('Please enter the APR \nEg 3% is 3: ');

%Ask the user for the length of their loan in years
lengthOfLoan = input('Please enter the length of the loan in years: ');

%Calculate how much the car will cost per month
monthly = (principle*(annualPercentageRate/100)/12)/(1-(1+(annualPercentageRate/100)/12)^(-lengthOfLoan*12));

%Output the monthly payments to the user
fprintf('Your payments will be: ');
fprintf('$%0.2f', monthly);
fprintf('/month\n');