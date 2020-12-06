function tumor(m,n)
%TUMOR plots the tumor model for values of N and M
%based on the problem in 'Essential Calculus' by Stewart

%{
Javier Macossay
ITP 168 - Fall 2015
Lab 18
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/3/2015        Original            Javier Macossay
%}

%check inputs
if length (m) ~= 1 || length (n) ~= 1
    error('Inputs must be scalar');
end;

if m < 0 || n < 0
    error('Inputs must be positive');
end;

phi = linspace(0,pi);
theta = linspace(0,2*pi);

[thetaGrid, phiGrid] = meshgrid(theta,phi); 

rho = 1 + (.2)*sin(m*thetaGrid).*sin(n*phiGrid);

X = rho.*sin(phiGrid).*cos(thetaGrid);
Y = rho.*sin(phiGrid).*sin(thetaGrid);
Z = rho.*cos(phiGrid);

surf(X,Y,Z);

end