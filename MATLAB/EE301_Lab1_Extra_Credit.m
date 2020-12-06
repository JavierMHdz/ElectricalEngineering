%% EE301 Lab1 Extra Credit
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc
clear all
close all

%Change vector
dtau = 0.01;

%Time vector
t=0:dtau:10;

%Part One - Calculating the energy of the f(t) signal
f=inline('log(t+1).*sin((t.^2)/3).*exp(-cos(2*pi*sqrt(t)))');
EnergyOfF= sum(f(t).^2*dtau)

%Plotting f(t) with pulse signal
figure
plot(t,f(t),'b--');
hold all
p = sqrt(3.0160)*(heaviside(t)-heaviside(t-10));
plot(t,p,'r-');
grid

EnergyOfP = sum(p.^2*dtau)

xlabel('Time (t)');
ylabel('Amplitude of Signal');
title('Amplitude of Signal vs. Time');
legend('f(t)','p(t)');