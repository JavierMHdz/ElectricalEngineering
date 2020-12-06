%{
Javier Macossay
ITP 168 - Fall 2015
Lab 6
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
9/17/2015        Original            Javier Macossay
%}

%Ask their birth month
month = input('Please enter your birth month: ');

if ((month <= 12)&&(month >= 1))
    day = input('Enter your birth day: ');
    switch month
        case 1
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on January %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 2
            if ((day <= 28)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on February %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 3
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on March %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 4
            if ((day <= 30)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on April %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 5
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on May %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 6
            if ((day <= 30)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on June %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 7
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on July %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 8
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on August %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 9
            if ((day <= 30)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on September %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 10
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on October %.0f,%.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 11
            if ((day <= 30)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on November %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
        case 12
            if ((day <= 31)&&(day >= 1))
                year = input('Enter your birth year: ');
                if (year>0)
                fprintf('Your birthday is on December %.0f, %.0f\n\n',day,year); 
                else
                    fprintf('Invalid birth year. Now quitting!\n\n');
                end;
            else
                fprintf('Invalid birth day. Now quitting!\n\n');
            end;
    end;
else
    fprintf('Invalid birth month. Now quitting!\n\n');
end;