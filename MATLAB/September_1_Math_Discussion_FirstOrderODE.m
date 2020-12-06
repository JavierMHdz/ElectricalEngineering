% solve 1st order ODE
% set up argument variables
tspan = [0 6]; %interval
y0 = 1; %intial value (initial condition)

% solve ODE
[t,y] = ode45(@odefun, tspan, y0);

%plot results
plot(t,y);
xlabel('t');
ylabel('y');
grid
axis([0 6 -3 3])