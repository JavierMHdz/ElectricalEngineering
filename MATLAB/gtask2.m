function dy = gtask2(t,y)
dy = [-0.0381*y(1)+0.0128*y(2)+0.000042*y(3)+62.5*step(t)-56*step(t-365)
    0.0115*y(1)-0.029*y(2)
    0.0041*y(1)-0.000042*y(3)];
end