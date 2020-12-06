%to plot on the complex plane
for k = 1:0.5:10;
    poles = roots ([1 2.1 2.2 k+0.2]);
    x = real (poles);
    y = imag (poles);
    plot(x,y,'O');
    xlabel('Re(s)');
    ylabel('Im(s)');
    grid;
    hold on
end;