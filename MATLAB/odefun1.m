function dy = odefun1(t,y)
dy = [y(2)
    -0.5*y(2)-y(1)+0.5*(step(t-5)-step(t-20))];
end