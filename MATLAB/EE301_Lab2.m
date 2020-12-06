%% EE301 Lab2
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

%Q1. Exercising graphical convolution

figure(1)

x=inline('1.5*sin(pi*t).*(t>=0 & t<1)');
h=inline('1.5*(t>=0 & t<1.5)-(t>=2 & t<2.5)');
dtau = 0.005;
tau = -1:dtau:4;
ti=0;
tvec = -1:0.1:4;

% Pre-allocate memory
y=NaN*zeros(1,length(tvec));

for t=tvec
    %Time index
    ti=ti+1;
    xh=x(t-tau).*h(tau);
    lxh=length(xh);
    
    %Trapezoidal approximation of integral
    y(ti)=sum(xh.*dtau);
    
    subplot(2,1,1),plot(tau,h(tau),'r-',tau,x(t-tau),'b--',t,0,'ok');
    
    axis([tau(1) tau(end) -2.0 2.5]);
    
    %Patch command is used to create the gray-shaded area of convolution
    patch([tau(1:end-1); tau(1:end-1); tau(2:end); tau(2:end)],[zeros(1,lxh-1); xh(1:end-1); xh(2:end); zeros(1,lxh-1)], [0.8 0.8 0.8], 'edgecolor','none');
    
    xlabel('\tau');
    legend('h(\tau)', 'x(t-\tau)','t','h(\tau)x(t-\tau)',3);
    
    c = get(gca, 'children');
    set(gca,'children', [c(2);c(3);c(4);c(1)]);
    
    subplot(2,1,2), plot(tvec,y,'k',tvec(ti),y(ti),'ok');
    xlabel('t');
    ylabel('y(t)');
    title('y(t) = \int h(\tau)x(t-\tau) d\tau');
    axis([tau(1) tau(end) -1.0 2.0]);
    grid;

    drawnow;
    
end

%Q4. Obtain ys(t):
figure(2)

x=inline('t>=0');
%R and C are equal to 1
h=inline('exp(-t).*(t>=0)');
dtau = 0.005;
tau = -1:dtau:4;
ti=0;
tvec = -1:0.1:4;

% Pre-allocate memory
y=NaN*zeros(1,length(tvec));

for t=tvec
    %Time index
    ti=ti+1;
    xh=x(t-tau).*h(tau);
    lxh=length(xh);
    
    %Trapezoidal approximation of integral
    y(ti)=sum(xh.*dtau);
    
    subplot(2,1,1),plot(tau,h(tau),'r-',tau,x(t-tau),'b--',t,0,'ok');
    
    axis([tau(1) tau(end) -2.0 2.5]);
    
    %Patch command is used to create the gray-shaded area of convolution
    patch([tau(1:end-1); tau(1:end-1); tau(2:end); tau(2:end)],[zeros(1,lxh-1); xh(1:end-1); xh(2:end); zeros(1,lxh-1)], [0.8 0.8 0.8], 'edgecolor','none');
    
    xlabel('\tau');
    legend('h(\tau)', 'x(t-\tau)','t','h(\tau)x(t-\tau)',3);
    
    c = get(gca, 'children');
    set(gca,'children', [c(2);c(3);c(4);c(1)]);
    
    subplot(2,1,2), plot(tvec,y,'k',tvec(ti),y(ti),'ok');
    xlabel('t');
    ylabel('y(t)');
    title('y(t) = \int h(\tau)x(t-\tau) d\tau');
    axis([tau(1) tau(end) -1.0 2.0]);
    grid;

    drawnow;
    
end

%Q5. Obtain h(t):
figure(3)
plot(tvec(2:end),diff(y)/dtau);
xlabel('t');
ylabel('h(t)');
title('Impulse Response [h(t)] vs Time (t)');

%Q6. Obtain pulse response part 1:

%First plot
figure(4)

x=inline('(t>=0 & t<=0.1)');
h=inline('exp(-t).*(t>=0)');
dtau = 0.005;
tau = -1:dtau:4;
ti=0;
tvec = -1:0.1:4;

% Pre-allocate memory
y=NaN*zeros(1,length(tvec));

for t=tvec
    %Time index
    ti=ti+1;
    xh=x(t-tau).*h(tau);
    lxh=length(xh);
    
    %Trapezoidal approximation of integral
    y(ti)=sum(xh.*dtau);
    
    subplot(2,1,1),plot(tau,h(tau),'r-',tau,x(t-tau),'b--',t,0,'ok');
    
    axis([tau(1) tau(end) -2.0 2.5]);
    
    %Patch command is used to create the gray-shaded area of convolution
    patch([tau(1:end-1); tau(1:end-1); tau(2:end); tau(2:end)],[zeros(1,lxh-1); xh(1:end-1); xh(2:end); zeros(1,lxh-1)], [0.8 0.8 0.8], 'edgecolor','none');
    
    xlabel('\tau');
    legend('h(\tau)', 'x(t-\tau)','t','h(\tau)x(t-\tau)',3);
    
    c = get(gca, 'children');
    set(gca,'children', [c(2);c(3);c(4);c(1)]);
    
    subplot(2,1,2), plot(tvec,y,'k',tvec(ti),y(ti),'ok');
    xlabel('t');
    ylabel('y(t)');
    title('y(t) = \int h(\tau)x(t-\tau) d\tau');
    axis([tau(1) tau(end) -1.0 2.0]);
    grid;

    drawnow;
    
end

%Second plot
figure(5)

x=inline('1/0.01*(t>=0 & t<=0.1)');
h=inline('exp(-t).*(t>=0)');
dtau = 0.005;
tau = -1:dtau:4;
ti=0;
tvec = -1:0.1:4;

% Pre-allocate memory
y=NaN*zeros(1,length(tvec));

for t=tvec
    %Time index
    ti=ti+1;
    xh=x(t-tau).*h(tau);
    lxh=length(xh);
    
    %Trapezoidal approximation of integral
    y(ti)=sum(xh.*dtau);
    
    subplot(2,1,1),plot(tau,h(tau),'r-',tau,x(t-tau),'b--',t,0,'ok');
    
    axis([tau(1) tau(end) -2.0 2.5]);
    
    %Patch command is used to create the gray-shaded area of convolution
    patch([tau(1:end-1); tau(1:end-1); tau(2:end); tau(2:end)],[zeros(1,lxh-1); xh(1:end-1); xh(2:end); zeros(1,lxh-1)], [0.8 0.8 0.8], 'edgecolor','none');
    
    xlabel('\tau');
    legend('h(\tau)', 'x(t-\tau)','t','h(\tau)x(t-\tau)',3);
    
    c = get(gca, 'children');
    set(gca,'children', [c(2);c(3);c(4);c(1)]);
    
    subplot(2,1,2), plot(tvec,y,'k',tvec(ti),y(ti),'ok');
    xlabel('t');
    ylabel('y(t)');
    title('y(t) = \int h(\tau)x(t-\tau) d\tau');
    axis([tau(1) tau(end) -1.0 2.0]);
    grid;

    drawnow;
    
end

%Third plot
figure(6)

x=inline('1/0.001*(t>=0 & t<=0.1)');
h=inline('exp(-t).*(t>=0)');
dtau = 0.005;
tau = -1:dtau:4;
ti=0;
tvec = -1:0.1:4;

% Pre-allocate memory
y=NaN*zeros(1,length(tvec));

for t=tvec
    %Time index
    ti=ti+1;
    xh=x(t-tau).*h(tau);
    lxh=length(xh);
    
    %Trapezoidal approximation of integral
    y(ti)=sum(xh.*dtau);
    
    subplot(2,1,1),plot(tau,h(tau),'r-',tau,x(t-tau),'b--',t,0,'ok');
    
    axis([tau(1) tau(end) -2.0 2.5]);
    
    %Patch command is used to create the gray-shaded area of convolution
    patch([tau(1:end-1); tau(1:end-1); tau(2:end); tau(2:end)],[zeros(1,lxh-1); xh(1:end-1); xh(2:end); zeros(1,lxh-1)], [0.8 0.8 0.8], 'edgecolor','none');
    
    xlabel('\tau');
    legend('h(\tau)', 'x(t-\tau)','t','h(\tau)x(t-\tau)',3);
    
    c = get(gca, 'children');
    set(gca,'children', [c(2);c(3);c(4);c(1)]);
    
    subplot(2,1,2), plot(tvec,y,'k',tvec(ti),y(ti),'ok');
    xlabel('t');
    ylabel('y(t)');
    title('y(t) = \int h(\tau)x(t-\tau) d\tau');
    axis([tau(1) tau(end) -1.0 2.0]);
    grid;

    drawnow;
    
end