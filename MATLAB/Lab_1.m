%Laboratory 1 Part 1
dt=0.01;
duration=100;
k=[1e6, 1e-4, 1e-1];
Y=zeros(3,1);
Y(1,1)=5e-7; %red
Y(2,1)=2e-7; %blue
Y(3,1)=0; %green
Y(4,1)=0; %yellow

for i=1:(duration/dt)
Y(1,i+1)=Y(1,i)-dt*k(1)*Y(1,i)*Y(2,i)+dt*k(2)*Y(3,i); %red
Y(2,i+1)=Y(2,i)-dt*k(1)*Y(1,i)*Y(2,i)+dt*k(2)*Y(3,i)+dt*k(3)*Y(3,i); %blue
Y(3,i+1)=Y(3,i)+dt*k(1)*Y(1,i)*Y(2,i)-dt*k(2)*Y(3,i)-dt*k(3)*Y(3,i); %green
Y(4,i+1)=Y(4,i)+dt*k(3)*Y(3,i); %yellow
Y(:,i+1)
end

t=0:dt:duration;
figure;
plot(t,Y(1,:),'r+');
hold on;
plot(t,Y(2,:),'b+');
plot(t,Y(3,:),'g+');
plot(t,Y(4,:),'y+');

%Laboratory 1 Part 2
dt=0.01;
k=[1e8, 1e-3, 1e-2, 1e-1];
Y=zeros(5,1);
Y(1,1)=5e-5; %red
Y(2,1)=3e-5; %blue
Y(3,1)=5e-5; %green
Y(4,1)=0; %cyan
Y(5,1)=0; %magenta
i=1;

while Y(1,i)>=1e-8
Y(1,i+1)=Y(1,i)-dt*k(1)*Y(1,i)*Y(2,i)*Y(3,i)+dt*k(2)*Y(4,i); %red
Y(2,i+1)=Y(2,i)-dt*k(1)*Y(1,i)*Y(2,i)*Y(3,i)+dt*k(2)*Y(4,i)+dt*k(4)*Y(4,i); %blue
Y(3,i+1)=Y(3,i)-dt*k(1)*Y(1,i)*Y(2,i)*Y(3,i)+dt*k(2)*Y(4,i)+dt*k(3)*Y(4,i); %green
Y(4,i+1)=Y(4,i)+dt*k(1)*Y(1,i)*Y(2,i)*Y(3,i)-dt*k(2)*Y(4,i)-dt*k(3)*Y(4,i)-dt*k(4)*Y(4,i); %cyan
Y(5,i+1)=Y(5,i)+dt*k(3)*Y(4,i)+dt*k(4)*Y(4,i); %magenta
i=i+1;
end

t=0:dt:dt*(i-1);
figure;
plot(t,Y(1,:),'r+');
hold on;
plot(t,Y(2,:),'b+');
plot(t,Y(3,:),'g+');
plot(t,Y(4,:),'c+');
plot(t,Y(5,:),'m+');