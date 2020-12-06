%[t,y] = ode45(@ode function file, tspan, y0)
function dy = odefun(t,y);
dy = y - y^2;