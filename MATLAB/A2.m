%{
Javier Macossay
ITP 168 - Fall 2015
Homework 2: Inversion
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/12/2015        Original            Javier Macossay
9/13/2015        Added Part 1,2,3,4  Javier Macossay
9/14/2015        Output to the user  Javier Macossay
%}

%Ask the user for input
A = input('Enter a 3x3 matrix using bracket notation: ');

%Calculate the Determinant
determinant = (A(1,1)*(A(2,2)*A(3,3)-A(3,2)*A(2,3)))-(A(1,2)*(A(2,1)*A(3,3)-A(3,1)*A(2,3)))+(A(1,3)*(A(2,1)*A(3,2)-A(3,1)*A(2,2)));

%Calculate the Cofactor
cofactor = [(A(2,2)*A(3,3)-A(2,3)*A(3,2)) -(A(2,1)*A(3,3)-A(2,3)*A(3,1)) (A(2,1)*A(3,2)-A(2,2)*A(3,1)); -(A(1,2)*A(3,3)-A(1,3)*A(3,2)) (A(1,1)*A(3,3)-A(1,3)*A(3,1)) -(A(1,1)*A(3,2)-A(1,2)*A(3,1)); (A(1,2)*A(2,3)-A(1,3)*A(2,2)) -(A(1,1)*A(2,3)-A(1,3)*A(2,1)) (A(1,1)*A(2,2)-A(1,2)*A(2,1))];

%Calculate the Transpose of the Cofactor
cofactorTranpose = [cofactor(1,1) cofactor(2,1) cofactor(3,1); cofactor(1,2) cofactor(2,2) cofactor(3,2); cofactor(1,3) cofactor(2,3) cofactor(3,3)];

%Calculate the Inverse
inverseA = (1/determinant).*cofactorTranpose;

%Output the results to the user
disp(inverseA);