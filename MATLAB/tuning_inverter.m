%Tuning Inverter
freq = 13.56e6;
Lf = 5.5e-6;
Cf = 1/(9*pi^2*freq^2*Lf);
Lmr = 1/(15*pi^2*freq^2*Cf);
Cmr = (15/16)*Cf;

fprintf('The value of freq is %e \n',freq);
fprintf('The value of Lf is %e \n',Lf);
fprintf('The value of Cf is %e \n',Cf);
fprintf('The value of Lmr is %e \n',Lmr);
fprintf('The value of Cmr is %e \n',Cmr);