%EE499 Lab2 Problem 4
PRR = [1 1 1 1 0.9 0.8 0.6 0.1];
distance = [1 3 5 7 10 15 20 25];

figure
plot(distance,PRR, 'r*-');
axis([1 25 0 1.1]);
grid
xlabel('Distance (m)');
ylabel('PRR');
title('PRR vs Distance');