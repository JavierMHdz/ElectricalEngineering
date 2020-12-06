%Maximum throughput

for n = 0:0.01:30
    y = (1-1/n)^(n-1);
    plot(n,y,'*');
    hold on;
end
xlabel('Value of n');
ylabel('Throughput Value');
title('Expression for the maximum throughput');
grid;