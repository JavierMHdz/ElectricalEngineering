for Vgs = 0:0.05:5
    Id = sqrt(5*6.9*10.^-8*1000*(Vgs/0.125).^(-1/3))*(Vgs-1);
    plot(Vgs, Id, 'b--*');
    hold on;
end
xlabel('Vgs');
ylabel('Id');
title('Id vs. Vgs');