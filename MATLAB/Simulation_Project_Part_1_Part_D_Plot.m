%construct a plot showing how the critical gain k varies
%with the damping parameter lambda of the system
Y = [5.502 2.698 1.312];
X = [1/2 1/4 1/8];
plot(X,Y,'bO--');
axis([0 3/5 0 6]);
xlabel('Damping Parameter Lambda');
ylabel('Critical Gain K');
grid