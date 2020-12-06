%{
Javier Macossay
ITP 168 - Fall 2015
Lab 19
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/5/2015        Original            Javier Macossay
%}
n = input('Please enter the order of the polynomial fit: ');
data = csvread('Lab19.txt');

BHP = data(:,1);
MPG = data(:,2);
plot(BHP,MPG,'bo');

x = linspace(min(BHP),max(BHP));
p = polyfit(BHP,MPG,n);
y = polyval(p,x);

hold on
plot(x,y,'r');
hold off

%calculate fit
yFit = polyval(p,BHP);
yBar = mean(MPG);
%calculate sums
ssRes = sum((MPG-yFit).^2);
ssTot = sum((MPG-yBar).^2);
%calculate R-Squared
rSq = 1 - (ssRes/ssTot);

fprintf('R-Squared: %0.2f\n',rSq);