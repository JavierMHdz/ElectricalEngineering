%% EE301 Lab5
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;


%Q1 (a)
t = linspace(-0.5, 2, 1000);
plot(t,cos(linspace(-7.5,27,1000)),'k:');

grid on;

% The amplitude is equal to 1
% s(t)=A*cos(2*pi*f*t+phi) when t is equal to 0
% s(t)=Acos(phi)
% s(0)=0.7209=A*cos(phi) 
% phi=cos^-1(0.7209)=0.7657
% rad = 43.8 degrees

phi=acosd(0.7209)

% t1=0.043
% t2=0.4985
% Period = T = 0.4985-0.043 = 0.4555 s
% f = 1/T = 1/0.4555 = 2.1954 Hz

% A*exp(j*phi), where the value of A=1
% phi=0.7657 rad
% s= 1*exp(j*0.7657), which is polar form
% s= cos(0.7657)+j*sin(0.7657) = 0.721+j*0.693

Rectangual= 1*exp(j*0.7657)

%Q1 (b)
A = 1;
phi = 0.7657;
frq = 2.1954;
new = A*cos(2*pi*frq.*t-phi);

hold on
plot(t, new)
title('Graph1'); 
xlabel('Time');
ylabel('Amplitude');
legend('Plot a','Plot b');

%Q2 (a)
t_test = 0:99;
s_test = 1.3*cos(t_test*pi/10 + 2.8);

% Amplitude is equal to 1.3
% A*cos(w*t+phi) = -1.225 when t equals to 0
% A*cos(phi) = -1.225
% phi = cos^-1(-1.225/1.3) = 2.8 rad = 160.44 degrees

phi=acosd(-1.225/1.3)

% 2*pi*f*t = t_test*pi*1/10
% -> 1/10 = 2*f -> f = 1/20

%Q2 (b)
t_test = 0:99;
s_test = 1.3*cos(t_test*pi/10 + 2.8);
figure
plot(t_test,s_test)
title('Graph2'); 
xlabel('Time');
ylabel('Amplitude');
grid on

[A,phi]=apc(s_test, t_test, 1/20);

%Q2 (c)

% w = 200*pi = 2*pi*f where f is equal to 100

load('lab5_data.mat')
figure
plot(t_samp,s_samp)
xlabel('Time');
ylabel('Amplitude');
title('samp signal');
[A,phi] = apc(s_samp, t_samp, 100);
hold on
new = A*cos(2*pi.*t_samp*100+phi);
plot(t_samp,new,'r')

%Q2 (d)

apc_support = 0:80;
apc_test = cos(apc_support*pi/15+0);

% The amplitude is equal to 1
% The phase is equal to 0
% The frequency is equal to 1/30

[A,phi]=apc(apc_test, apc_support, 1/30);
figure
plot(apc_support, apc_test)
hold on
new=A*cos(2*pi.*apc_support*1/30+phi);
plot(apc_support,new,'r')
title('Graph4'); 
xlabel('Time');
ylabel('Amplitude');
legend('Plot a(apc_test)','Plot b(new)');

% The fundamental period, in this case,
% is 30 seconds.
% There are 2.75 periods included in apc_test

abs(new - apc_test)
sum(abs(new - apc_test))

%Q2 (e)

A = ones(1,500);
phi = (zeros(1,500));

for i = 10:500

apc_support = 0:i;
apc_test = cos(apc_support*pi/15+0);
[A(i),phi(i)] = apc(apc_test, apc_support, 1/30);
end

i = 1:500;
figure
amplitude_error=abs(A-1);
subplot(2,1,1)
plot(i,amplitude_error)
xlabel('Time');
ylabel('amplitude error');
title('amplitude error');
subplot(2,1,2)
plot(i,phi)
xlabel('Time');
ylabel('phase error');
title('phase error');

% For this particular case the amplitude estimates to the value of zero
% always.
% This will result in the amplitude never becoming one.

%Q3 (a)

[frq,A,phi,X]=fape(s_test,t_test)
new = real(A*exp(j*(2*pi*frq.*t_test+phi)));

figure
plot(t_test,s_test)
grid
hold on
plot(t_test, new,'r');

% f = 1/20 = 0.05 Hz
% Amplitude is equal to 1.3
% s(t) = A*cos(2*pi*f*t+phi) where t is equal to 0
% s(t) = A*cos(phi)
% s(0) = -1.225 = A*cos(phi)
% phi = cos^-1(-1.225) = undefined. The angle is approximately pi/2 because
% that is the value where cosine is undefined.
% Yes, the estimates are correct.

%Q3 (b)


[frq,A,phi,X]=fape(fape_test_s,fape_test_t)
new = real(A*exp(j*(2*pi*frq.*fape_test_t+phi)));

figure
plot(fape_test_t,fape_test_s)
grid
hold on
plot(fape_test_t, new,'r');


% The accuracy of estimates is not accurate. The phase is different in the
% actual signal.