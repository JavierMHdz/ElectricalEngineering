%{
Javier Macossay
ITP 168 - Fall 2015
Lab 5
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/15/2015        Original            Javier Macossay
%}

%Create two random integer values max = 20
firstOp = randi(20);
secondOp = randi(20);

%Create a random mathematical operator (+ - *)
oper = randi(3);
fprintf('Perform the following calculations as quickly as possible! Good luck!\n');
pause (3); %pause the timer

%Ask the question
switch oper
    case 1
        fprintf('%.0f + %.0f = ',firstOp, secondOp);
        correct = firstOp + secondOp;
    case 2
        fprintf('%.0f - %.0f = ',firstOp, secondOp);
        correct = firstOp - secondOp;
    case 3
        fprintf('%.0f * %.0f = ',firstOp, secondOp);
        correct = firstOp * secondOp;
end;

%Start the timer
startTime = tic;

%Get input
userIn = input('');

%End time
elapsedTime = toc(startTime);

%Correct? and display time
if (correct == userIn)
    fprintf('Correct! It took you %.2f seconds.\n', elapsedTime);
else
    fprintf('Incorrect! It took you %.2f seconds.\n', elapsedTime);
end;
