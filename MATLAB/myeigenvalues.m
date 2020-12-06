%Exercise 6: the output gives the eigenvalues of the matrix.
function [eigenval] = myeigenvalues(A)

a = A(1,1);
b = A(1,2);
c = A(2,1);
d = A(2,2);
eigenval (1,1) = ((a+d)+sqrt((a+d)^2-4*(a*d-b*c)))/2;
eigenval (2,1) = ((a+d)-sqrt((a+d)^2-4*(a*d-b*c)))/2;

