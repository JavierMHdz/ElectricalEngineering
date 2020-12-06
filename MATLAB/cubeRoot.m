%Homework 2
function [cubeRootOut] = cubeRoot(val)

x = 10; %initial guess
count = 0;
error = 10;
while abs(error) > 1e-9
    f_x = x^3 - val;
    f_x_1stderiv = 3*x^2;
    xnew = x - f_x/f_x_1stderiv;
    error = x - xnew;
    x = xnew;
    count = count +1; %number of iterations
end

cubeRootOut = x;