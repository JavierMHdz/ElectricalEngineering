%simulation forced response of 2nd order ODE
tspan = [0 80];
init = [0,0];
[t,y]=ode45(@odefun1,tspan, init);

%plot y(t)
figure
subplot(2,1,1)
plot(t,y(:,1))
xlabel('t');
ylabel('y');

%plot phase portray
subplot(2,1,2)
plot (y(:,1),y(:,2))
xlabel('y');
ylabel('dy/dt');
