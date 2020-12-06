%main task 2
tspan = [0 800];
init = [0,0,0];
[t,y]=ode45(@gtask2,tspan, init);

%plot
figure
plot(t,y(:,1),'--',t,y(:,2),'O',t,y(:,3),'*')
xlabel('Time (days)');
ylabel('Amount of Lead (micrograms)');
title('Task #2');
legend('Concentration of lead in the blood','Concentration of lead in soft tissues','Concentration of lead in the bones');