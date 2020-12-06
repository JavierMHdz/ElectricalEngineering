%{
Javier Macossay
ITP 168 - Fall 2015
Lab 2
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/2/2015        Original            Javier Macossay
%}

%Welcome
fprintf('\nRunning Total and Average Calculator\n');

%Creating variables
firstNumber = input('Enter a number: ');
fprintf('Running Total      Running Average\n');
fprintf('%13.2f%21.2f\n',firstNumber, firstNumber);

secondNumber = input('Enter a number: ');
runningTotal1 = firstNumber + secondNumber;
runningAverage1 = (firstNumber + secondNumber)/2;
fprintf('Running Total      Running Average\n');
fprintf('%13.2f%21.2f\n',runningTotal1, runningAverage1);

thirdNumber = input('Enter a number: ');
runningTotal2 = runningTotal1 + thirdNumber;
runningAverage2 = (firstNumber + secondNumber +thirdNumber)/3;
fprintf('Running Total      Running Average\n');
fprintf('%13.2f%21.2f\n',runningTotal2, runningAverage2);

fourthNumber = input('Enter a number: ');
runningTotal3 = runningTotal2 + fourthNumber;
runningAverage3 = (firstNumber + secondNumber +thirdNumber +fourthNumber)/4;
fprintf('Running Total      Running Average\n');
fprintf('%13.2f%21.2f\n',runningTotal3, runningAverage3);

fifthNumber = input('Enter a number: ');
runningTotal4 = runningTotal3 + fifthNumber;
runningAverage4 = (firstNumber + secondNumber +thirdNumber +fourthNumber + fifthNumber)/5;
fprintf('Running Total      Running Average\n');
fprintf('%13.2f%21.2f\n',runningTotal4, runningAverage4);