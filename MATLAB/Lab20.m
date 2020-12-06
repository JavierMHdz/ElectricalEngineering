%{
Javier Macossay
ITP 168 - Fall 2015
Lab 20
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
11/10/2015        Original            Javier Macossay
%}

%read in the data
Y = load('traj.txt');

t = linspace(0,length(Y)*10,52)';

figure
subplot(3,1,1)
plot(t,Y,'b-');
xlabel('Altitude (ft)');
ylabel('Time(s)')
title('Space Shuttle Atlantis Launch Data');

%calculating velocity
deltaY = diff(Y);
deltaT = 10;

velocity = deltaY./deltaT;
subplot(3,1,2)
plot(t(1:end-1),velocity,'b-');
xlabel('Velocity (ft/s)');
ylabel('Time(s)');

%calculating acceleration
deltaY2 = diff(deltaY);

acceleration = deltaY2./deltaT;
subplot(3,1,3)
plot(t(1:end-2),acceleration,'b-');
xlabel('Acceleration (ft/s*s)');
ylabel('Time(s)');