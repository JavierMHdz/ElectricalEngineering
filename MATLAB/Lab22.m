%{
Javier Macossay
ITP 168 - Fall 2015
Lab 22
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/17/2015        Original            Javier Macossay
%}

A = [1 2 0; 3 2 4; -2 1 -2];
B = [1;7;-1];
C = [A B];

[row,col] = size(A);

%consistent or inconsistent
if (rank(A) == rank(C))
    %1 or infinite
    if rank(A) == col
        %1 solution
        X = pinv(A)*B;
        fprintf('One solution\n');
        disp(X);
    else
        %infinite solutions
        %homogenous solution
        xH = null(A,'r');
        %particular solution
        xP = pinv(A)*B;
        %number of free parameters
        nFree = col - rank(A);
        %trivial parameter solution
        xTP = xP - Xh*xP((end-nFree+1):end); %grabs all free parameter values
        
        X = [xTP xH];
        fprintf('Infinite number of solutions:\n');
        fprintf('Number of free parameters: %0.0f\n',nFree);
        disp(X);
    end;
else
    %no solution
    fprintf('No solution exists\n');
end;