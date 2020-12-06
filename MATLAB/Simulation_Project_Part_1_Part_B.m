%to plot on the complex plane
for k = 1:0.5:8;
    poles = roots ([1 1.83 3.17 k+0.3]);
    x = real (poles);
    y = imag (poles);
    plot(x,y,'O');
    xlabel('Re(s)');
    ylabel('Im(s)');
    grid;
    hold on
end;