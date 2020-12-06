%{
Javier Macossay
ITP 168 - Fall 2015
Lab 9
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/29/2015        Original            Javier Macossay
%}

%Ask the user for the input
while (true)
firstGenes = input ('Enter the first parents genes in a 2 character pair: ','s');
if (length(firstGenes) ==2)
    break;
end;
fprintf('Error! Try again!\n');
end;
while (true)
secondGenes = input ('Enter the second parents genes in a 2 character pair: ','s');
if (length(secondGenes) == 2)
    break;
end;
fprintf('Error! Try again!\n');
end;

%I will create my cell array
punnetSquare = cell(3,3);

%Input the values of the parents
punnetSquare {1,2} = firstGenes(1);
punnetSquare {1,3} = firstGenes(2);
punnetSquare {2,1} = secondGenes(1);
punnetSquare {3,1} = secondGenes(2);

punnetSquare {2,2} = [firstGenes(1),secondGenes(1)];
punnetSquare {3,2} = [firstGenes(1),secondGenes(2)];
punnetSquare {2,3} = [firstGenes(2),secondGenes(1)];
punnetSquare {3,3} = [firstGenes(2),secondGenes(2)];

%Diplay Punnet Square to the user
for y = 1:3
    fprintf(' %s ',punnetSquare{1,y});
end;
fprintf('\n');
for x = 2:3
    for y = 1:3
    fprintf('%s ',punnetSquare{x,y});
    end;
    fprintf('\n');
end;
    