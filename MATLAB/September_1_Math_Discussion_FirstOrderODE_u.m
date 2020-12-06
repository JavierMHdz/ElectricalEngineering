% solve 1st order ODE
% set up argument variables
tspan = [0 3]; %interval
u0 = 1; %intial value (initial condition)

% solve ODE
[t,u] = ode45(@odefun_u, tspan, u0);

%plot results
plot(t,u);
xlabel('t');
ylabel('u');
grid
