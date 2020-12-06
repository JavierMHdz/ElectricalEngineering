%{
Javier Macossay
ITP 168 - Fall 2015
Homework 4: Lots of Loops
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/2/2015        Original            Javier Macossay
%}

while (true)
    %Part 1: Create a menu
    fprintf('Series Approximations\n********************\n');
    fprintf('Please select an option:\n\t1. Exponent: e^(x)\n\t2. Sine: sin(x)\n\t3. Cosine: cos(x)\n');
    option = input('Option: ');
    
    flag = false;
    
    if (option == 1 || option == 2 || option == 3)
        flag = true;
    else
        while (flag == false)
            fprintf('Invalid! Choose again!');
            option = input('\nOption: ');
            if (option == 1 || option == 2 || option == 3)
                flag = true;
            end;
        end;
    end;
    
    while(flag == true)
            switch option
                case 1 %Part 2: Exponent Approximation
                    value = input('Enter an X value: ');
                    iterations = input('Enter number of iterations: ');
                    
                    if (iterations > 0)
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = (power(value,(index-1)))/factorial(index-1);
                            sum = answer + sum;
                        end;
                        fprintf('Exponent Approximation:\ne^(%0.2f) = %0.2f',value, sum);
                    else
                        while (true)
                        fprintf('Iterations must be greater than 0');
                        iterations = input('\nEnter number of iterations: ');
                            if (iterations > 0)
                                break;
                            end;
                        end;
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = (power(value,(index-1)))/factorial(index-1);
                            sum = answer + sum;
                        end;
                        fprintf('Exponent Approximation:\ne^(%0.2f) = %0.2f',value, sum);
                    end;
                case 2 %sine approximation
                    value = input('Enter an X value: ');
                    iterations = input('Enter number of iterations: ');
                    
                    if (iterations > 0)
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = ((power(-1,index-1))*power(value,(2*index)-1))/factorial((2*index)-1);
                            sum = answer + sum;
                        end;
                        fprintf('Sine Approximation:\nsin(%0.2f) = %0.2f',value, sum);
                    else
                        while (true)
                        fprintf('Iterations must be greater than 0');
                        iterations = input('\nEnter number of iterations: ');
                            if (iterations > 0)
                                break;
                            end;
                        end;
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = ((power(-1,index-1))*power(value,(2*index)-1))/factorial((2*index)-1);
                            sum = answer + sum;
                        end;
                        fprintf('Sine Approximation:\nsin(%0.2f) = %0.2f',value, sum);
                    end;
                case 3 %cosine approximation
                    value = input('Enter an X value: ');
                    iterations = input('Enter number of iterations: ');
                    
                    if (iterations > 0)
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = ((power(-1,index-1))*power(value,(2*index)-2))/factorial((2*index)-2);
                            sum = answer + sum;
                        end;
                        fprintf('Cosine Approximation:\ncos(%0.2f) = %0.2f',value, sum);
                    else
                        while (true)
                        fprintf('Iterations must be greater than 0');
                        iterations = input('\nEnter number of iterations: ');
                            if (iterations > 0)
                                break;
                            end;
                        end;
                        
                        sum = 0;
                        
                        for index = 1: iterations
                            answer = ((power(-1,index-1))*power(value,(2*index)-2))/factorial((2*index)-2);
                            sum = answer + sum;
                        end;
                        fprintf('Cosine Approximation:\ncos(%0.2f) = %0.2f',value, sum);
                    end;
            end;
        break;
    end;
    
    choice = input('\nWould you like to run again? (Y/N): ','s');
    
    if (strcmpi(choice, 'N'))
        break;
    end;
    
end;

