%Problem 5.6

for vds = 0:.001:0.05
    %For Vgs = 0.5
    id05 = (0.005*(0.5-0.5))*vds;

    %For Vgs = 1
    id1 = (0.005*(1-0.5))*vds;

    %For Vgs = 1.5
    id15 = (0.005*(1.5-0.5))*vds;

    %For Vgs = 2
    id2 = (0.005*(2-0.5))*vds;

    %For Vgs = 2.5
    id25 = (0.005*(2.5-0.5))*vds;
    
    plot(vds,id05,'b--o')
    hold on
    plot(vds,id1,'r--*')
    plot(vds,id15,'g--o')
    plot(vds,id2,'y--*')
    plot(vds,id25,'c-*')
end
xlabel('Vds');
ylabel('Id');
legend('Vgs = 0.5','Vgs = 1','Vgs = 1.5','Vgs = 2','Vgs = 2.5');
title('Id vs. Vds');

