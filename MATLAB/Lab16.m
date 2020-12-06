%{
Javier Macossay
ITP 168 - Fall 2015
Lab 16
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/6/2015        Original            Javier Macossay
%}

x = dlmread('stats.txt')

[rows,columns] = size(x);

rowVec = zeros(1,rows);
for index = 1:rows
    rowVec(index) = x(index);
end;

swap = true;
while (swap)
swap = false;
for index = 1:rows-1
    if (rowVec(index)>rowVec(index+1))
        variable = rowVec(index+1);
        rowVec(index+1)=rowVec(index);
        rowVec(index) = variable;
        swap = true;
    end;
end;


end;

plot(rowVec,'b+');
figure
hist(x);