function avgflips = ee150_broke1(initP1,initP2,initP3, p, n)
totalflips=0;
a=p-p^2;
for i=1:n
P1=initP1;
P2=initP2;
P3=initP3;
while P1>0 && P2>0 && P3>0
r = rand;
if r>=0 && r<a
    P1=P1+2;
    P2=P2-1;
    P3=P3-1;
elseif r>=a && r<2*a
    P1=P1-1;
    P2=P2+2;
    P3=P3-1;
elseif r>=2*a && r<3*a
    P1=P1-1;
    P2=P2-1;
    P3=P3+2;
elseif r>=3*a && r<=1
    P1=P1;
    P2=P2;
    P3=P3;
end
end
end
totalflips = totalflips+1;
avgflips=totaflips/n
