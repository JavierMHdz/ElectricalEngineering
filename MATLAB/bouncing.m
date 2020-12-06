function [times, height] = bouncing(h0,rFactor,dt,tmax)
index = 1;
for t = 0:dt:tmax
    check = h0-((0.5)*9.81*t^2);
    index = index + 1;
    if check < 0
        break;
    else
      height(index) = check
      times(index) = t;
    end
end

figure
plot(times,height)
end