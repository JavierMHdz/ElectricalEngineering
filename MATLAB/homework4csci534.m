X1 = [0.2 0.5 0.8];
Y1 = [23.953125 17.95049505 14.44954128];
plot(X1,Y1);
grid on;
hold on;
X2 = [0.2 0.5 0.8];
Y2 = [-19.7761194 -12.90526316 -11.15966387];
plot(X2,Y2);
axis([0.1 0.9 -30 30]);
title('Question 7: Impact of Surprise');
xlabel('Probability of Obtained Outcome');
ylabel('Emotional Response');
hold off;