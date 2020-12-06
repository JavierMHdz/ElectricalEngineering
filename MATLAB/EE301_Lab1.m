%% EE301 Lab1
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%%Q1 Scalars
z=35000;
y=4;
y
y=z;
y

%%Q2a Vectors
i = [9 8 7 6 5 4 3];
j = [9:-1:3];
m = i-j;

%The result of the operation i-j is 0. All the value of the vectors are
%equal to 0.
%The fifth element of vector m i equal to zero.

%%Q2b Vectors
%Yes, there is a similar command which can create a vector of ones
z=ones(1,3);

%%Q3a Matrices
M=[1 4 5; 4 6 9; 5 9 3];
ThirdRow_FirstColumn=M(3,1)
SecondColumn=M(:,2)

%%Q3b Matrices
u=[0.2996; 0.5361; -0.7892];
r=M*u;
s=(-5.0125)*u;

%When comparing r and s, both results are pretty much the same. They differ
%a little bit and that is due to rounding errors.

%%Q3c Matrices
%The command in MATLAB which can create an identity matrix of a desired
%size is eye
I = eye(4,4);

%%Q4a Sampling
Ts = pi/2;
t = [0:Ts:2*pi];
figure
plot(t,sin(t));
xlabel('Time');
ylabel('Amplitude');
axis([0 6.3 -1.25 1.25]);
title('Not Enough Sampling Points');

t1 = [0:0.01:2*pi];
figure
plot(t1,sin(t1));

xlabel('Time');
ylabel('Amplitude');
axis([0 6.3 -1.25 1.25]);
title('Enough Sampling Points');

%%Q4b Sampling
%There is a way to obtain the two plots on the same figure.
figure
Ts = pi/2;
t = [0:Ts:2*pi];
t1 = [0:0.01:2*pi];
plot(t,sin(t),'b--o',t1,sin(t1),'r');

xlabel('Time');
ylabel('Amplitude');
axis([0 6.3 -1.25 1.25]);
legend('Not Enough Sampling Points','Enough Sampling Points');
title('Two graphs on the same figure');

%%Q4c Amplitude Effects
fs = 8000;
tstart = 0;
tend = 2;
t = [tstart: 1/fs: tend];
f = 3;
w = 2*pi*f;

astart = 1;
aend = 6;
da = (aend-astart)/(length(t)-1);
A = [astart: da : aend];
figure
plot(t, A.*sin(w*t));

xlabel('Time');
ylabel('Amplitude');
axis([0 2 -6 6]);
title('Amplitude Effects');

%%Q5 Loops
%1)
fs = 8000;
dt = 1/fs;
t = [0: 1/fs: 3];
f = 1;
X1 = sin(2*pi*f*t);
X3 = sin(2*pi*3*f*t)/3;
X5 = sin(2*pi*5*f*t)/5;
X7 = sin(2*pi*7*f*t)/7;

%2) Plot the sine wave of frequency f=1Hz
figure
plot(t,X1);
xlabel('Time');
ylabel('Amplitude');
axis([0 3 -1.1 1.1]);
title('Sine Wave with Fundamental Frequency');

%3) Composite Signal Z
Z = X1+X3+X5+X7;
figure
plot(t,Z);
xlabel('Time');
ylabel('Amplitude');
axis([0 3 -1 1]);
title('Composite Signal Plot = Z vs. t');

%4) f will take on values 1, 3, 5,..., 31 during the loop
Z1 = zeros(1,length(t));
for f = 1:2:31
    Z1 = Z1 + sin(2*pi*f*t)/f;
end

%5) Z1 vs. t plot
%My guess was correct, the signal seems more like a square and it seems
%like a digital signal (ON and OFF signal).
figure
plot(t,Z1);
xlabel('Time');
ylabel('Amplitude');
axis([0 3 -1 1]);
title('Z1 vs. t');

%%Q6 Unit Step Function
t = -5:0.01:10;
xt = heaviside(t+1)-heaviside(t-2)+heaviside(t-4);
figure
plot(t,xt);
ylim([-0.1 1.1]);
xlabel('Time');
ylabel('Amplitude');
title('Unit Step Function');

%%Q7 Even and Odd Functions
t = [0:0.1:5];

%Original signal
xt = t.*exp(-t);

%Even decomposition
xe = (0.5)*(xt+fliplr(xt));

%Odd decomposition
xo = (0.5)*(xt-fliplr(xt));

%The signal y(t) = xe+xo
y = xe+xo;

figure
subplot(4,1,1);
plot(t,xt);
xlabel('t');
ylabel('X(t)');
title('X(t) vs. t');

subplot(4,1,2);
plot(t,xe);
xlabel('t');
ylabel('Xe(t)');
title('Xe(t) vs. t');

subplot(4,1,3);
plot(t,xo);
xlabel('t');
ylabel('Xo(t)');
title('Xo(t) vs. t');

subplot(4,1,4);
plot(t,y);
xlabel('t');
ylabel('Y(t)');
title('Y(t) vs. t');

%%Q8 Numerical Integration
%By increasing the number of rectangles to 10, the number is closer to 39.
%The number is 35.895. E(10) = 39 - 35.895 = 3.105

%When calculating and plotting E(N) for N = 10 to 100 I observe that the
%value of E(N) gets closer to 39.

Tstart = 2;
Tend = 5;
for Nr = 10:100
    Dx = (Tend-Tstart)/(Nr);
    t = Tstart:Dx:(Tend-Dx); %sample points
    fs = t.^2;
    A = zeros(1,Nr);
    A = sum(Dx*fs);
    if A > 38.5
        Nr
        break
    end
end

%63 rectangles are required to achieve a relative error less than 0.5