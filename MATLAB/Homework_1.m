%Homework 1
dt=.01;
duration=100;
k=[1e6;1e-4]; 
Y=zeros(3,1);
Y(1,1)=4e-7;
Y(2,1)=3e-7;
Y(3,1)=0;
for i=1:(duration/dt)
Y(1,i+1)=Y(1,i)-dt*k(1)*Y(1,i)*Y(2,i)+dt*k(2)*Y(3,i);
Y(2,i+1)=Y(2,i)-dt*k(1)*Y(1,i)*Y(2,i)+dt*k(2)*Y(3,i);
Y(3,i+1)=Y(3,i)+dt*k(1)*Y(1,i)*Y(2,i)-dt*k(2)*Y(3,i);
Y(:,i+1)
end

t=0:dt:duration;
figure;
plot(t,Y(1,:),'r+');
hold on;
plot(t,Y(2,:),'b+');
plot(t,Y(3,:),'g+');