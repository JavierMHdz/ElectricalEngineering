%{
Javier Macossay
ITP 168 - Fall 2015
Lab 4
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/10/2015        Original            Javier Macossay
%}

%Get all the values of X and Y
valuesX = valArray(1,:);
valuesY = valArray(2,:);

%Calculate the average of X and Y
averageX = sum(valuesX)/8;
averageY = sum(valuesY)/8;

%Calculate the correlation coefficient
numerator = sum((valuesX-averageX).*(valuesY-averageY));
denominator = sqrt(sum((valuesX-averageX).^2).*sum((valuesY-averageY).^2));
correlationCoefficient = numerator/denominator;

%Print out the correlation coefficient to the user
fprintf('\nThe product-moment correlation coefficient is ');
fprintf('%0.2f\n', correlationCoefficient);