%[t,y] = ode45(@ode function file, tspan, y0)
tspan = [0 10];
y0 = [0.1,0.5,0.9,1.1,1.5];
for i = 1:5
[t,y] = ode45(@odefun,tspan, y0(i));
plot(t,y)
hold on
end
xlabel('t')
ylabel('y')