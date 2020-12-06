%% EE301 Lab3
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

% Demonstration of music convolved with various impulse responses.
% R Kozick modified by Satsuki Takahashi
fs = 44100; % Sampling freq, in Hz
T = 1/fs;
fc = 500; % Desired cutoff freq, in Hz
wc = 2*pi*fc;

% Make impulse response length equal to 2.30259 time constants
t = 0:T:(2.30259/wc);
g = wc*T*exp(-t*wc);

% Read the original audio sample
f = wavread('IMDR1.wav');

fprintf('This is the original music . . . ');
sound(f,44100)
pause(16)

figure(1)
plot(t, g);
title('Impulse response g(t)');
xlabel('Time (sec.)');
ylabel('Amplitude');

fprintf('\nComputing -- please wait . . . ');
y = conv(f(:,1), g);
fprintf('\nThis is after convolution with g(t) . . . ');
sound(y,44100);
pause(16)

fprintf('\nComputing -- please wait . . . ');
h = [g, zeros(size(0:T:1)), .5*g];

figure(2)
th = (1:length(h))*T;
plot(th, h)
title('Impulse response h(t)');
xlabel('Time (sec.)');
ylabel('Amplitude');

z = conv(f(:,1), h);
fprintf('\nThis is after convolution with h(t) . . . ');
sound(z,44100);
fprintf('\n');

fprintf('To repeat the sounds:\n')
fprintf('sound(f,44100) is the original\n')
fprintf('sound(y,44100) is convolved with g(t)\n')
fprintf('sound(z,44100) is convolved with h(t)\n')

%%Question 4)
%The first impulse function g(t) looks like a decaying exponential
%function. An acceptable value for the missing time constant value is
%2.30259 because at that specific value of the time constant, 90% of the graph is
%being shown.

%%Question 5)
%The effect of the first convolution with the impulse function g(t)
%decreased the amplitude of the signal. Therefore, the volume of audio
%sample was decreased.

%%Question 6)
%The effect of the second convolution with the impulse function h(t)
%created an echo on the audio sample. A physical mechanism that does the
%second peak of h(t) is the bouncing of the wave on a rigid material. A
%porous material will absorb the wave and the echo would not be heard.