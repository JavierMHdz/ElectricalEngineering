%Probability of a successful reception at a common receiver

for p = 0:0.01:1
    y = 4*p*(1-p)^3;
    plot(p,y,'*');
    hold on;
end
xlabel('Value of P');
ylabel('Success Probability');
title('Probability of a Successful Reception at a Common Receiver');
grid;