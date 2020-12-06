function [out1, out2]=ludecomp(matrixA)
%getting the size of rows and columns
[rows,col] = size(matrixA);

if (rows > col)
    error('The rows of the input matrix needs to be less than or equal to the number of columns of the input matrix.');
end;

    %Part 1: Setting up my Lower and Upper
    upperTrig = matrixA;
    
    lowTrig = eye(rows);
    
    %Part 2: Decompose
    for i = 1:rows-1
        for j = i + 1:rows
            
            temporaryMatrix = eye(rows);
            
            factor = -(upperTrig(j,i)./upperTrig(i,i));
            
            upperTrig(j,:) = upperTrig(j,:)+factor*upperTrig(i,:);
            
            temporaryMatrix(j,:) = temporaryMatrix(j,:)+factor*temporaryMatrix(i,:);
            
            lowTrig = lowTrig*temporaryMatrix^-1;
        end;
    end;
    out1 = lowTrig;
    out2 = upperTrig;
end