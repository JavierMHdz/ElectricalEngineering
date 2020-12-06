%Problem 6.19

Q = 3.3E-8;
Vfb = -0.9;
FP = 0.659;
epsilon = 3.9*8.85E-14;

for tox = 20E-8:25E-8:500E-8
    Vt = (Q*tox)/epsilon + Vfb + FP;
    
    %plotting
    plot(tox,Vt,'b--*');
    hold on
end
xlabel('tox');
ylabel('Vt');
title('Vt vs. tox');