%ee301_forloop.m

%fs = 8000;
%dt = 1/fs;
%t = [0:dt:2];
%X = sin(w*t);

%for i = i:length(X)-1
%    deriv(i) = (X(i+1) - X(i))/dt;
%end

%deriv(length(X)) = deriv(length(X)-1);
%plot(t,deriv);

%fs = 8000;
%dt = 1/fs;
%t = [0: 1/fs: 3];
%f = 1;
%X1 = sin(2*pi*f*t);
%X3 = sin(2*pi*3*f*t)/3;
%X5 = sin(2*pi*5*f*t)/5;
%X7 = sin(2*pi*7*f*t)/7;

%Plot the sine wave of frequency f=1Hz
%figure
%plot(t,X1);
%xlabel('Time');
%ylabel('Amplitude');
%axis([0 3 -1.1 1.1]);
%title('Sine Wave with Fundamental Frequency');

%Composite Signal Z
%Z = X1+X3+X5+X7;
%figure
%plot(t,Z);
%xlabel('Time');
%ylabel('Amplitude');
%axis([0 3 -1 1]);
%title('Composite Signal Plot = Z vs. t');

%f will take on values 1, 3, 5,..., 31 during the loop
%Z1 = zeros(1,length(t))
%for f = 1:2:31
%    Z1 = Z1 + sin(2*pi*f*t)/f;
%end

%Z1 vs. t plot
%My guess was correct, the signal seems more like a square and it seems
%like a digital signal (ON and OFF signal).
%figure
%plot(t,Z1);
%xlabel('Time');
%ylabel('Amplitude');
%axis([0 3 -1 1]);
%title('Z1 vs. t');

%t = -5:0.01:5;
%xt = heaviside(t+1)-heaviside(t-2)+heaviside(t-4);
%figure
%plot(t,xt);
%ylim([-0.1 1.1]);
%xlabel('Time');
%ylabel('Amplitude');
%title('Unit Step Function');
%{
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
plot(t,xe);
xlabel('t');
ylabel('Xo(t)');
title('Xo(t) vs. t');

subplot(4,1,4);
plot(t,y);
xlabel('t');
ylabel('Y(t)');
title('Y(t) vs. t');
%}

%vector = zeros(1,90);
%Tstart = 2;
%Tend = 5;
%for Nr = 10:100
 %   Dx = (Tend-Tstart)/(Nr);
  %  t = Tstart:Dx:(Tend-Dx); %sample points
   % fs = t.^2;
    %A = zeros(1,Nr);
%    A = sum(Dx*fs);
 %   if A > 38.5
  %      Nr
 %       break
 %   end
%end
dtau = 0.01;
t = 0:dtau:10;
p = sqrt(3)*(heaviside(t)-heaviside(t-10));
figure

 plot(t,p,'r');
 %axis([-1 11 0 3]);