%define parameter values
tspan = [0,15];
init = [-2,1]; %two values because we have a 2nd order ODE
a = -8;

%call ode45 to solve ODES
[t,u] = ode45(@September_15_Math_Discussion_my2ndode, tspan, init,[], a); %to add a = -8 to function file, we need to add square bracket []

%plot results
figure
plot(t,u(:,1)) %only plot position, to plot du/dt I need to put u(2)
hold on
plot(t,u(:,2),'--r')
xlabel('t')
ylabel('u and du/dt')
legend('u','du/dt')
grid

%plot phase plane
figure
plot(u(:,1),u(:,2))
xlabel('u')
ylabel('du/dt')