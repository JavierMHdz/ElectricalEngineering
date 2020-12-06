%Problem 12.10
IL = 50E-3;
IS = 4.5785E-12;
Vt = 0.0259;
for Voc = 0:0.000599:0.599
    I = IL-(IS*(exp(Voc/Vt)-1));
    plot(Voc, I, 'b--*');
    hold on;
end
axis([0 0.7 0 0.06]);
title('I vs. V');
xlabel('V [V]');
ylabel('I [A]');