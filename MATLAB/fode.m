function dy = fode(t,y)
lmd = 1/8;
omg = 1;
omgf = 1;
f0= 1;
dy = [y(2)
    -2*lmd*omg*y(2)-omg^2*y(1)+f0*sin(omgf*t)];