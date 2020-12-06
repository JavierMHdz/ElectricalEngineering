%{
Javier Macossay
ITP 168 - Fall 2015
Lab 11
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/6/2015        Original            Javier Macossay
%}

A = csvread('matrix.txt');
vector = size(A);

numEl = vector(1)*vector(2);

rowVec = zeros(1,numEl);
for index = 1:numEl
    rowVec(index) = A(index);
end;

swap = true;
while (swap)
swap = false;
for index = 1:99
    if (rowVec(index)>rowVec(index+1))
        variable = rowVec(index+1);
        rowVec(index+1)=rowVec(index);
        rowVec(index) = variable;
        swap = true;
    end;
end;

end;

for index = 1:numEl
    A(index) = rowVec(index);
end;

csvwrite('sorted.txt',A);
