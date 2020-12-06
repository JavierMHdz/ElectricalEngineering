%Problem 5.28
vt = 0.4;
geom = 1E-3;
vds = 1;
for vgs = 0:0.1:1.8
    if (vgs <= 0.4)
        id = 0;
    elseif (vgs > 0.4) && (vgs<=1.4)
        %saturation
        id = (0.5)*geom*(vgs-vt).^2;
    else
        %triode
        id = geom*((vgs-vt)-(0.5*vds))*vds;
    end
    
    plot(vgs,id,'b-*')
    hold on
end
xlabel('Vgs [V]');
ylabel('Id [microAmps]');
legend('Vgs');
title('Id vs. Vgs');