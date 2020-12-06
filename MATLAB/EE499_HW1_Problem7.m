%Change distance from 1m to 6m

d = [1 2 3 4 5 6];
Pr = [30 23.98 20.4575 17.96 16.02 14.44];

plot(d, Pr);
grid
xlabel('Distance (m)');
ylabel('Received Signal Strength');
title('Average Received Signal Strength vs Distance');