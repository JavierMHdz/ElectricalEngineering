%EE301 HW2

clc
clear all
close all

%Change in time vector
dtau = 0.0001;

%Time vector
t=-2e-3:dtau:2e-3;

%Function
x=inline('20*sin(2*pi*1000*t-pi/3).*exp(-500*t)');

%Plotting x(t)
figure
plot(t,x(t));
hold all
grid

xlabel('Time (t)');
ylabel('x(t)');
title('a = 500');