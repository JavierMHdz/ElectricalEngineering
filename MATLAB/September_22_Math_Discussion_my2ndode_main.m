%define parameters
tspan = [0, 100];
y0 = [0,0];

%call obde45 to solve ODEs
[t,y] = ode45(@September_22_Math_Discussion_my2ndode, tspan, y0);

%plot solution
figure
plot(t,y(:,1))
xlabel('t')
ylabel('y')