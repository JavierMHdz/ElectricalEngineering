%[t,y] = ode45(@ode function file, tspan, y0)
tspan = [0 6]; %interval of t
y0 = [0.5,1,1.5,2,3,4,5]; %various intial values

%solve ODE
for i = 1:7
[t,y] = ode45(@math245_simulation_problem_one, tspan,y0);
plot(t,y)
hold on
end

%plot results
xlabel('t');
ylabel('y');
grid