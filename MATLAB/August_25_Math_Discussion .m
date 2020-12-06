x = 0:0.1:2*pi

x =

  Columns 1 through 5

         0    0.1000    0.2000    0.3000    0.4000

  Columns 6 through 10

    0.5000    0.6000    0.7000    0.8000    0.9000

  Columns 11 through 15

    1.0000    1.1000    1.2000    1.3000    1.4000

  Columns 16 through 20

    1.5000    1.6000    1.7000    1.8000    1.9000

  Columns 21 through 25

    2.0000    2.1000    2.2000    2.3000    2.4000

  Columns 26 through 30

    2.5000    2.6000    2.7000    2.8000    2.9000

  Columns 31 through 35

    3.0000    3.1000    3.2000    3.3000    3.4000

  Columns 36 through 40

    3.5000    3.6000    3.7000    3.8000    3.9000

  Columns 41 through 45

    4.0000    4.1000    4.2000    4.3000    4.4000

  Columns 46 through 50

    4.5000    4.6000    4.7000    4.8000    4.9000

  Columns 51 through 55

    5.0000    5.1000    5.2000    5.3000    5.4000

  Columns 56 through 60

    5.5000    5.6000    5.7000    5.8000    5.9000

  Columns 61 through 63

    6.0000    6.1000    6.2000

2*pi

ans =

    6.2832

y1 = sin(x);
y2 =  cos(x);
plot(x, y1)
plot(y1,x)
plot(x, y1)
axis([0 2*pi -1.25 1.25])
plot(x, y1)
axis([0 2*pi -1.25 1.25])
grid
xlabel('x')
ylabel('y')
hold on //hold on is to freeze the graph and add another graph
plot(x,y2)
plot(x,y2,'--r') //two graphs on the same figure
legend('sin(x)','cos(x)') //name of the different lines
subplot (2,1,1) //rows, column, position of the graph... subplot is to make two graphs
plot(x,y1)
grid
xlabel('x')
ylabel('y')
subplot(2,1,2)
plot(x,y1)
grid
