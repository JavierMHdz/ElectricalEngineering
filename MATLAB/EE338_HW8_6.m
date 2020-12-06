for vds = 3.13:0.05:8.13
   deltaL = 1.79*10.^-5*(sqrt(3.513+(vds-3.13))-1.8743);
   
   plot(vds, deltaL, 'b--*');
   hold on;
end
xlabel('Vds');
ylabel('delta L');
title('delta L vs. Vds');