salaries = [3.79 2.99 2.77 2.91 3.1 1.84 2.52 3.22 2.45 2.14 2.67 2.52 2.71 2.75 3.57 3.85 3.36 2.05 2.89 2.83 3.13 2.44 2.1 3.71 3.14 3.54 2.37 2.68 3.51 3.37];

%Part A
%Calculate the sample mean
M = mean(salaries);

%Calculate the sample variance

%Step 1 - Get the size of the array
[x,y] = size(salaries);

%Step 2 - Initialize the variable
sum = 0;

%Step 3 - Get the sample variance
for i = 1:y
    sum = sum + (salaries(i)-M).^2/(y-1);
end

%Step 4 - Get the square root to get the standard deviation
standardDeviation = sqrt(sum);

fprintf('The sample mean is %f and the sample standard deviation is %f \n',M, standardDeviation);