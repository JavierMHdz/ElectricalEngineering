%{
STDEV this function calculates the corrected or
uncorrected standard deviation for a scalar, vector,
or matrix.

Javier Macossay
ITP 168 - Fall 2015
Lab 15
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/22/2015        Original            Javier Macossay
%}
function out = stdev(firstParameter, secondParameter)
%1 equals the corrected and 0 equals the uncorrected
if (nargin == 1)
    secondParameter = 1;
elseif (nargin > 2)
    error('Too many input arguments');
elseif (nargin < 1)
    error('Too few input arguments');
end;

if (secondParameter ~= 1 && secondParameter ~= 0)
    error('Invalid value for second input argument');
end;

[row,col] = size(firstParameter);

if (row == 1 && col == 1)
    out = 0;
    
else
    helper(firstParameter, secondParameter)
end;

end

function out = helper(firstParameter, secondParameter)

[row,col] = size(firstParameter);

if ((row == 1 && col > 1) || (row > 1 && col == 1))
    numEl = numel(firstParameter);
    avg = mean(firstParameter);
    numer = sum((firstParameter-avg).^2);
    if (secondParameter == 1)
        out = sqrt(numer/(numEl - 1));
    else
        out = sqrt(numer/numEl);
    end;
    
else
    [rows,columns] = size(firstParameter);
    rowVec = zeros(1,columns);
    
    for counter = 1:columns
        numEl = numel(firstParameter(rows,:));
        avg = mean(firstParameter(:,counter));
        numer = sum((firstParameter(:,counter)-avg).^2);
        if (secondParameter == 1)
            rowVec(counter) = sqrt(numer/(numEl - 1));
        else
            rowVec(counter) = sqrt(numer/numEl);
        end;
    end;
    
    out = rowVec;
   
end;
end