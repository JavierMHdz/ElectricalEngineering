%% EE301 Lab9
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%%Exercise #1: Warm-up
[rec fs] = audioread('omg.mp4'); %load the audio file
sound(rec, fs); %playback

rec = rec(1:fs,:); %trim
rec(:,2) = rec(:,1); %convert to mono

%%Exercise #2: Artificial Stereo

speed = 300;
d = 0.1651;
time = d/speed;

T = 1/44.1e3;
shift = time / T;

shift02 = round(shift);

%coming from the center
pause(2)
new = rec; %copy
rec(:,2) = circshift(new(:,1),0); %shift right channel
sound(rec,fs); %playback

%coming from the right
pause(2)
rec(:,2) = circshift(new(:,1), shift02); %shift right channel
sound(rec,fs); %playback

%coming from the left
pause(2)
rec(:,2) = circshift(new(:,1), -shift02); %shift right channel
sound(rec,fs); %playback

%%Exercise #3: Even Better Stereo
rec(:,2) = 0.2*circshift(new(:,1),0); %the right is attenuated
sound(rec,fs); %playback

rec(:,2) = 5*circshift(new(:,1),0); %the right is attenuated
sound(rec,fs); %playback

rec(:,2) = 3*circshift(new(:,1),0); %the right is attenuated
sound(rec,fs); %playback

fourier = fft(rec);
x=((0:1:length(rec)-1)./length(rec)-0.5)*44.1e3/2;
figure
plot(x,abs(fftshift(fourier(:,1))));

fourier02 = circshift(fourier,[2e3 0]);
figure
plot(x,abs(fftshift(fourier02(:,1))));
rec02 = ifft(fourier02);
sound (real(rec02),fs);

figure
fourier03 = fftshift(fourier);
plot(abs(fourier03(:,1)));

fourier03(21875:22227,:)=0; %kill some frequencies
figure
plot(abs(fourier03(:,1)));
rec03=ifft(fourier03);
sound(10*real(rec03),fs);

%autotune
timev = 0:T:1-T; %generate time support
timev02 =([timev;timev]); %time support for left and right channels
shifter = cos(2*pi*400*timev02);
sound(new.*shifter',fs);