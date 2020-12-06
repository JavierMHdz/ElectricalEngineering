function dy = my2ndode(t,y)
omgf = 1;
dy = [y(2)
    -y(1)+0.5*cos(omgf*t)]; %I need to write it as a column vector