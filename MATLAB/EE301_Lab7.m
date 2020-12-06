%% EE301 Lab7
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%Q1
signal = dtmf_dial([1 2 3 4 5 6 7 8 9 10 11 12],1);

%Q2
%Part A) A vector was used instead of a command
M = 50;
fs = 8192;
k=0:M;

h697 = sin(2*pi*697.*k/fs); %first impulse response filter
h770 = sin(2*pi*770.*k/fs);
h852 = sin(2*pi*852.*k/fs);
h941 = sin(2*pi*941.*k/fs);
h1209 = sin(2*pi*1209.*k/fs);
h1336 = sin(2*pi*1336.*k/fs);
h1477 = sin(2*pi*1477.*k/fs);

figure
stem(h697); title('impulse response of 697'); xlabel('Frequency'); ylabel('H697');

figure
stem(h770); title('impulse response of 770'); xlabel('Frequency'); ylabel('H770');

figure
stem(h852); title('impulse response of 852'); xlabel('Frequency'); ylabel('H852');

figure
stem(h941); title('impulse response of 941'); xlabel('Frequency'); ylabel('H941');

figure
stem(h1209); title('impulse response of 1209'); xlabel('Frequency'); ylabel('H1209');

figure
stem(h1336); title('impulse response of 1336'); xlabel('Frequency'); ylabel('H1336');

figure
stem(h1477); title('impulse response of 1477'); xlabel('Frequency'); ylabel('H1477');
%
% [H697,w] = freqz(h697,M);
% figure
% plot(w/2/pi*fs,abs(H697));

%c
for M=1:1000;
    gain = dtmf_filt_char(M,697,0);
    g1=sort(gain);
    g0(M)=g1(7)/g1(6);
end

M=1:1000;
figure;
plot(M,g0);

% As the value of M increases, the peaks increase.
% As a result, there are more delays.
% The resulting gain of the frequency is 107, 104, 98, 95, 66, 62, 59

%Q3
figure
numbers = dtmf_decode(signal)
soundsc(signal, fs);

%Q4
success_rate = dtmf_attack(0.9)