x = [1 2 3 4 5 6 7 8 9 10]
y = [6.6 7.4 8 6 5 8 8 7 5 8.5]
plot(x,y,'r');
grid on;
hold on;
x1 = [1 2 3 4 5 6 7 8 9 10]
y1 = [8 9 7 9 7 8 9 8.7 9 8]
plot(x1,y1,'b');
hold on;
x2 = [1 2 3 4 5 6 7 8 9 10]
y2 = [7 4 5 4 6 6 4.9 5 6 7.3]
plot(x2, y2, 'g');
axis([1 10 0 10]);
xlabel('Students');
ylabel('Grades');
title('Experiment Results');