dt=.1;
g=9.8;
a=0;
b=12;
m=(b-a)/dt;
v=zeros(1,m+1);
y=zeros(1,m+1);
v(1,1)=35;
x(1,1)=0;
v(2,1)=70;
v(2,1)=0;
i=1;
t=a:dt:b;
while x(2,i)>=0
    x(1,i+1)=x(1,i)+v(1,i)*dt;
    v(1,i+1)=v(1,i)-(b/m)*dt*v(1,i)*sqrt(v(1,i)^2+v(2,i)^2);
    x(2,i+1)=x(2,i)+v(2,i)*dt;
    v(2,i+1)=v(2,i)-(b/m)*dt*v(2,i)*sqrt(v(1,i)^2+v(2,i)^2)-gt*dt;
    i=i+1
end
plot(x(1,:),x(2,:));
