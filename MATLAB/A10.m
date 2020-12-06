%{
Javier Macossay
ITP 168 - Fall 2015
Homework 10: Skydiving
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/20/2015        Original            Javier Macossay
%}

%Part 1
initialGravity = 32.17;
drag = 0.1;

%anonymous function
VPrime = @(initialGravity,drag,time,velocity) initialGravity - drag*velocity;

%Part 2
tSpan = [0 0.5];
yZero = 0;
[time,velocity] = ode45(@(time,velocity) VPrime(initialGravity,drag,time,velocity), tSpan, yZero);

distance = trapz(time,velocity);

while distance < 13000
    tSpan(end) = tSpan(end) + 0.5;
    [time,velocity] = ode45(@(time,velocity) VPrime(initialGravity,drag,time,velocity), tSpan, yZero);
    distance = trapz(time,velocity);
end;

%Part 3
%cumulative trapezoidal function
distanceVec = cumtrapz(time,velocity);
actualPosition = 13000-distanceVec;

%plot
plotHandle = plotyy(time,velocity,time,actualPosition);
xlabel('Time (seconds)');
ylabel(plotHandle(1), 'Velocity (ft/s)');
ylabel(plotHandle(2), 'Position (ft)');
title('Velocity and Altitude with Air Resistance');

