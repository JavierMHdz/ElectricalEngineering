%{
Javier Macossay
ITP 168 - Fall 2015
Homework 3: Conversion
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/22/2015        Original            Javier Macossay
%}

%Part 1: Create a menu
fprintf('Unit Converter\n********************\n');
fprintf('Please select and option:\n1. Meter-Foot Converter\n');
fprintf('2. Kilogram-LB Converter\n3. Celsius-Fahrenheit Converter\n');
option = input('Option: ');

switch (option)
    case 1
    %Part 2: Converting Lengths
    fprintf('Meter-Foot Converter:\n');
    value = input('Enter a value: ');
    unit = input('Enter a unit (m or ft): ','s');

    meter = strcmpi(unit,'m');
    feet = strcmpi(unit,'ft');

    if (meter == 1 && feet == 0)
        answer = value*3.28084;
        fprintf('%0.6f m = %0.6f ft\n',value, answer);

    elseif (meter == 0 && feet == 1)
        answer = value/3.28084;
        fprintf('%0.6f ft = %0.6f m\n',value, answer);
    else
        fprintf('Invalid unit!\n');
    end;

    case 2
    %Part 3: Converting Weights
    fprintf('Kilogram-LB Converter:\n');
    value = input('Enter a value: ');
    unit = input('Enter a unit (kg or lb): ','s');

    kilogram = strcmpi(unit,'kg');
    pound = strcmpi(unit,'lb');

    if (kilogram == 1 && pound == 0)
        answer = value*2.204620;
        fprintf('%0.6f kg = %0.6f lbs\n',value, answer);

    elseif (kilogram == 0 && pound == 1)
        answer = value/2.204620;
        fprintf('%0.6f lbs = %0.6f kg\n',value, answer);
    else
        fprintf('Invalid unit!\n');
    end;

    case 3
    %Part 4: Converting Temperatures
    fprintf('Celsius-Fahrenheit Converter:\n');
    value = input('Enter a value: ');
    unit = input('Enter a temp scale (C or F): ','s');


    celsius = strcmpi(unit,'c');
    fahrenheit = strcmpi(unit,'f');

    if (celsius == 1 && fahrenheit == 0)
        answer = (1.8)*value+32;
        fprintf('%0.6f C = %0.6f F\n',value, answer);

    elseif (celsius == 0 && fahrenheit == 1)
        answer = value(1.8)-32;
        fprintf('%0.6f F = %0.6f C\n',value, answer);
    else
        fprintf('Invalid temperature scale!\n');
    end;
    
    otherwise
        fprintf('Invalid option!\n');
end;