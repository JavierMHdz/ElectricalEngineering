%{
Javier Macossay
ITP 168 - Fall 2015
Lab 21
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/12/2015        Original            Javier Macossay
%}

%time
tFinal = 0.01;

flag = true;
while (flag)
    %time vector
    t = 0:0.01:tFinal;
    
    %velocity profile
    v=  -3*t.^2+30*t;
    area = trapz(t,v);
    
    if (area <= 0)
        time = t;
        flag = false;
    end;
    tFinal = tFinal + 0.01;
end;
plot(time,v);
seconds = time(length(time));
xlabel('Time');
ylabel('Velocity');
title ('Velocity vs. Time Graph');
fprintf('Time before object reaches the ground : %0.2f seconds \n',seconds);
