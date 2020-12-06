%Part C

%Part A
for Vgs = 0:0.05:5
    Id = sqrt(1.725*10.^-4)*(Vgs-1);
    plot(Vgs, Id,'*');
    hold on;
end

%Part B
for Vgs = 0:0.005:5
    Id = sqrt(5*6.9*10.^-8*1000*(Vgs/0.125).^(-1/3))*(Vgs-1);
    plot(Vgs, Id,'-');
    hold on;
end
legend('Part A','Part B');
xlabel('Vgs');
ylabel('Id');
title('Id vs. Vgs');