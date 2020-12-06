%% EE301 Lab4
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%1a)Using subplot and stairs to plot the three code signals

code1 = code_signal(75,10);
code2 = code_signal(50,10);
code3 = code_signal(204,10);

figure(1)
subplot(3,1,1)
stairs(code1)
axis([1 100 -1.5 1.5]);
xlabel('Time');
ylabel('Amplitude of Signal');
title('Figure 1,in = 75, chips = 10');

subplot(3,1,2)
stairs(code2)
axis([1 100 -1.5 1.5]);
xlabel('Time');
ylabel('Amplitude of Signal');
title('Figure 2, in = 50, chips = 10');

subplot(3,1,3)
stairs(code3)
axis([1 100 -1.5 1.5]);
xlabel('Time');
ylabel('Amplitude of Signal');
title('Figure 3, in = 204, chips = 10');

%1b)

%Means
code1Mean = mean(code1)
code2Mean = mean(code2)
code3Mean = mean(code3)

%Energies
E01 = sum(code1.^2)
E02 = sum(code2.^2)
E03 = sum(code3.^2)

%1c)
c_code12 = sum(code1.*code2)/sqrt(E01*E02)
c_code13 = sum(code1.*code3)/sqrt(E01*E03)
c_code23 = sum(code2.*code3)/sqrt(E02*E03)

%1d)
%Positively correlated: c_code13 (code 1 and code 3)
%Uncorrelated: c_code12 (code 1 and code 2)
%Anticorrelated: c_code23 (code 2 and code 3)

%2b)
corr01=run_corr(code1,code2)/sqrt(E01*E02);
figure(2)
subplot(2,1,1)
plot(corr01);
xlabel('Time');
ylabel('y(t)*x(t)');
title('Code 1 and Code 2 Correlation Signals');

corr03=run_corr(code3,code3)/sqrt(E03*E03);
subplot(2,1,2)
plot(corr03);
xlabel('Time');
ylabel('y(t)*x(t)');
title('Code 3 and Code 3 Correlation Signals');

%2c)
%Yes, according to the graph the correlation signal is symmetric.
%The maximum value of the correlation signal is 100.
%The energy of the code 3 correlated to itself give the maximum value of
%100

%3a)
load('lab4_data.mat')

cs1=code_signal(170,10);
cs2=code_signal(25,6);

figure
subplot(3,1,1)
stairs(dsss)
axis([1, 1000, -2.5, 2.5])
xlabel('Time');
ylabel('Amplitude of Signal');
title('dsss');


subplot(3,1,2)
stairs(cs1)
axis([1, 1000, -2.5, 2.5])
xlabel('Time');
ylabel('Amplitude of Signal');
title('cs1, in = 170, chips = 10');

subplot(3,1,3)
stairs(cs2)
axis([1, 1000, -2.5, 2.5])
xlabel('Time');
ylabel('Amplitude of Signal');
title('cs2, in = 25, chips = 6');

%3b)
%normalize the energy for each sequence
Enorm1=sum(dsss.^2);
Enorm2=sum(cs1.^2);
Enorm3=sum(cs2.^2);

cor1=run_corr(cs1,dsss)/sqrt(Enorm1*Enorm2);
figure
plot(cor1)
xlabel('x(t)');
ylabel('Amplitude');
title('cor1');

sub_cor1 = cor1(length(cs1):length(cs1):length(cor1));
figure
stem(sub_cor1)
xlabel('x(t)');
ylabel('Amplitude');
title('sub_cor1');

figure
subplot(2,1,1)
plot(cor1)
xlabel('x(t)');
ylabel('Amplitude');
title('cor1');
subplot(2,1,2)
stem(sub_cor1)
xlabel('x(t)');
ylabel('Amplitude');
title('sub_cor1');


output=zeros(length(sub_cor1));
I=find(sub_cor1>0);
output(I)=1;
figure
stem(output)
xlabel('x(t)');
ylabel('y(t)');
title('Output (Decode)');
%0111110000

%3c)
cor2=run_corr(cs2,dsss)/sqrt(Enorm1*Enorm3);
figure
plot(cor2)
xlabel('x(t)');
ylabel('Amplitude');
title('cor2');
sub_cor2=cor2(length(cs2):length(cs2):length(cor2));

figure
subplot(2,1,1)
plot(cor2)
xlabel('x(t)');
ylabel('Amplitude');
title('cor2');
subplot(2,1,2)
stem(sub_cor2)
xlabel('x(t)');
ylabel('Amplitude');
title('sub_cor2');

output2=zeros(1,length(sub_cor2));
I=find(sub_cor2>0);
output2(I)=1;
figure
stem(output2)
xlabel('x(t)');
ylabel('y(t)');
title('Output(Decode)');
%01101000001011110

%The decoded bits that I suspect might be incorrect are the ones too close
%to 0. This means that the points that are very close to the x-axis might
%be incorrect. This is due to the fact that they are close to the threshold
%and the spacing is shorter than the first one. In other words, the code
%that I am correlating it with is shorter. As a result, the shorter the
%code, the more error prone.

%4a)

Ex=sum(radar_pulse.^2);
figure
subplot(2,1,1)
plot(radar_pulse)
axis([0 5000 -10 10])
xlabel('x(t)');
ylabel('y(t)');
title('Figure1)');
subplot(2,1,2)
plot(radar_received)
axis([0 5000 -10 10])
xlabel('x(t)');
ylabel('y(t)');
title('Figure2');

%No, I cannot identify the reflected pulses in the received signal by
%visual inspection alone because it is not easy to do that. Visual
%inspection will not yield to the right answer.

%4b)
cor3=run_corr(radar_pulse,radar_received);
duration=1e-6;

%Finding the Actual Time Increments
T=duration/length(radar_pulse)
xaxis01=0:T:(length(cor3)-1)*T;
figure
plot(xaxis01,cor3);
xlabel('xaxis01');
ylabel('cor3');
title('Figure');

%The received pulses are at the peaks and in the plot 4 peaks can be found.
%Furthermore, reflections are at the peaks.
%The locations of the peaks are:
%Peak 1(6.707e-06, 59.53)
%Peak 2(1.041-05, 50.93)
%Peak 3(1.937e-05, 62.19)
%Peak 4(4.333e-05, 39.13)

I=find(cor3>30);
time0=xaxis01(I);
distance0=3e8*time0;

%Find the distance to each object
distance01=(3e8*6.7e-6)/2
distance02=(3e8*1.041e-5)/2
distance03=(3e8*1.937e-5)/2
distance04=(3e8*4.333e-5)/2