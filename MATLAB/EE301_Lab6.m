%% EE301 Lab6
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%%Question 1
%sinsum(1);

%%Question 2
kk = -20:20;
CC = -(2./(pi*kk)).^2;
CC(1:2:length(kk)) = 0;

T = 0.1;
periods = 5;

[ss,tt] = fourier_synthesis(CC,T,periods);
%This figure corresponds to the Stem Plot
figure
stem(kk,CC)
title('Fourier Coefficients Stem Plot');

%This figure corresponds to the triangle wave
figure
plot(tt,ss);
title('Fourier Synthesis Plot');

%%Question 3
%load data from lab6_data.mat
load('lab6_data.mat');

%part a
figure
plot(step_time,step_signal)
title('Step signal from Question 3');

%Get one period
t0 = step_time(1:length(step_time)/5);
x = step_signal(1:length(step_signal)/5);

figure
plot(t0,x);
title('Plot of one period of the signal');

dt = min(diff(t0));
T = (max(t0)-min(t0));
MS = dt*sum(x.^2)/T;
disp('The mean square value is the following:')
disp(MS)

%part b
[CC50,ww50] = fourier_analysis(x,T,50);

figure
subplot(2,1,1);
stem(ww50,abs(CC50));
title('Magnitude');
subplot(2,1,2);
stem(ww50,angle(CC50));
title('Phase');

%part c
%The vectors I will create will have coefficients with values that range
%from N=25 to N=200. In the case of N=25, it creates 51 coefficients
periods = 1;

[CC25, ww25] = fourier_analysis(x,T,25);
[ss25,tt25] = fourier_synthesis(CC25, T, periods, 16384);

[ss50,tt50] = fourier_synthesis(CC50,T,periods, 16384);

[CC100,ww100] = fourier_analysis(x,max(t0)-min(t0),100);
[ss100,tt100] = fourier_synthesis(CC100,1,periods,16384);

[CC200,ww200] = fourier_analysis(x,max(t0)-min(t0),200);
[ss200,tt200] = fourier_synthesis(CC200,1,periods,16384);

figure
subplot(2,2,1);
plot(tt25,ss25);
title('25 coefficients');
xlim([0 1]);

subplot(2,2,2);
plot(tt50,ss50);
title('50 coefficients');
xlim([0 1]);

subplot(2,2,3);
plot(tt100,ss100);
title('100 coefficients');

subplot(2,2,4);
plot(tt200,ss200);
title('200 coefficients');

MSE25 = dt*sum((ss25-x).^2)/(max(tt)-min(tt));
MSE50 = dt*sum((ss50-x).^2)/(max(tt)-min(tt));
MSE100 = dt*sum((ss100-x).^2)/(max(tt)-min(tt));
MSE200 = dt*sum((ss200-x).^2)/(max(tt)-min(tt));

disp('The mean squared error with N = 25 is')
disp(MSE25)

disp('The mean squared error with N = 50 is')
disp(MSE50)

disp('The mean squared error with N = 100 is')
disp(MSE100)

disp('The mean squared error with N = 200 is')
disp(MSE200)

Ecc25 = sum(abs(CC25).^2);
Ecc50 = sum(abs(CC50).^2);
Ecc100 = sum(abs(CC100).^2);
Ecc200 = sum(abs(CC200).^2);

%MSE = (MStrue - Energy)*2

%These are equivalent to half of the MSEs
error25 = MS - Ecc25;
error50 = MS - Ecc50;
error100 = MS - Ecc100;
error200 = MS - Ecc200;