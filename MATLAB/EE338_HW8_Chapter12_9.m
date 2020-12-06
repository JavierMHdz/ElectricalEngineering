%Open-Circuit Voltage

%Given values
Nd = 10.^19;
Dn = 225;
Dp = 7;
Tn = 5*10.^-8;
Tp = 5*10.^-8;
JL = 30*10.^-3;
e = 1.6*10.^-19;
ni = 1.5*10.^10;
Vt = 0.0259;
Ln = 0.003354;
Lp = 0.000592;

for Na = (10^.15):0.001:(10^.18)
    JS = e*(ni.^2)*((Dn/(Ln*Na))+(Dp/(Lp*Nd)));
    Voc = Vt*log(1+(JL/JS));
    plot(Na, Voc,'*--');
    hold on;
end
xlabel('Na');
ylabel('Voc');
title('Voc vs. Na');