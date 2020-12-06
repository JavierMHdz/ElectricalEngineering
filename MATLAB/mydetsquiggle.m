%Exercise done in class.
function [myvalues] = mydetsquiggle(A)

a = A(1,1);
b = A(1,2);
c = A(2,1);
d = A(2,2);
myvalues (1,1) = a*d-b*c;
myvalues (2,1) = a*d+b*c;