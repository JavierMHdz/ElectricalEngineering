%Problem 6.41
%ic = Is*exp(Vbe/Vt)*(1+(Vce/Va));

Is = 10E-15;
Va = 100;
Vt = 0.025;

%Vbe = 0.65, 0.70, 0.72, 0.73, 0.74;
%Vce = 0 to 15;

for Vce = 0:0.01:15
    ic1 = Is*exp(0.65/Vt)*(1+(Vce/Va));
    
    ic2 = Is*exp(0.70/Vt)*(1+(Vce/Va));
    
    ic3 = Is*exp(0.72/Vt)*(1+(Vce/Va));
    
    ic4 = Is*exp(0.73/Vt)*(1+(Vce/Va));
    
    ic5 = Is*exp(0.74/Vt)*(1+(Vce/Va));
   
    plot(Vce, ic1,'b','LineWidth', 3);
    hold on
    plot(Vce, ic2,'r','LineWidth', 3);
    plot(Vce, ic3,'y','LineWidth', 3);
    plot(Vce, ic4,'k','LineWidth', 3);
    plot(Vce, ic5,'m','LineWidth', 3);
end
xlabel('Vce [V]');
ylabel('ic [A]');
legend('Vce (Bottom Line) = 0.65V','Vce = 0.70V','Vce = 0.72V', 'Vce = 0.73V', 'Vce (Top Line) = 0.74V');
title('ic vs. Vce');