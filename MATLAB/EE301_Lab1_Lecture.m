clc
clear all
close all

dtau = 0.01;
t = -10:dtau:10;
g=inline('t.*(t.^2+3)');

figure
plot(t,g(t));
grid

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
x=inline('4*exp(-t/10).*(t>=2.5&t<=5.5)');
figure
plot(t,x(t));
grid

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

x=inline('-3*t.*(t>=-5&t<=5)');
x(t)
figure
plot(t,x(t));
display('power');
P=1/10*(sum(x(t).^2)*dtau)
grid

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
n=-50:1:50;
g=inline('10*0.8.^n.*sin(2*pi.*n/16).*(n>=0)');
figure
stem(n,g(n));
grid