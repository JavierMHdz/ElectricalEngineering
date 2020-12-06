yValue = zeros(1,30);
yMean = zeros(1,30);
for i = 1:30
    yValue(i) = rand()*100;
    yMean(i) = sum(yValue)/i;
    hold on plot(1:i,yValue(1:i),'ko-');
    plot(yMean(1:i));
    hold off
    axis([0 30 0 100]);
    M(i) = getframe;
end
movie(M);