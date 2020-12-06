for Vgs = 0:0.05:5
    Id = sqrt(1.725*10.^-4)*(Vgs-1);
    plot(Vgs, Id, 'b--*');
    hold on;
end
xlabel('Vgs');
ylabel('Id');
title('Id vs. Vgs');