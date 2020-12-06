%{
Javier Jesús Macossay-Hernández
Physics 153
Written HW #3 - Twin Paradox
%}

D = 1000;

%Graph 1 - Speed = 0.1*c
figure

%Traveling Twin
for x = 0:D
    ct = 0.1*x;
    plot(x,ct);
    hold on
    
    ct = (-0.1*x)+(2*0.1*D);
    plot(x,ct)
    hold on
    grid on
end


%Earth-bound Twin
for ct = 0:5:(2*0.1*D)
    x = 0;
    plot(x,ct,'r*');
    hold on;
end

%Outbound rocket ship
for x = 0:100:2*D
    ct = 0.1*x;
    plot(x,ct,'o');
    hold on
end

%Inbound rocket ship
for x = 0:100:2*D
    ct = (-0.1*x)+(2*0.1*D);
    plot(x,ct,'k+')
    hold on
end
title('Twin Paradox at 0.1*c');
xlabel('x');
ylabel('ct');

%Graph 2 - Speed = 0.5*c
figure

%Traveling Twin
for x = 0:D
    ct = 0.5*x;
    plot(x,ct);
    hold on
    
    ct = (-0.5*x)+(2*0.5*D);
    plot(x,ct)
    hold on
    grid on
end


%Earth-bound Twin
for ct = 0:5:(2*0.5*D)
    x = 0;
    plot(x,ct,'r*');
    hold on;
end

%Outbound rocket ship
for x = 0:100:2*D
    ct = 0.5*x;
    plot(x,ct,'o');
    hold on
end

%Inbound rocket ship
for x = 0:100:2*D
    ct = (-0.5*x)+(2*0.5*D);
    plot(x,ct,'k+')
    hold on
end
title('Twin Paradox at 0.5*c');
xlabel('x');
ylabel('ct');

%Graph 3 - Speed = 0.9*c
figure

%Traveling Twin
for x = 0:D
    ct = 0.9*x;
    plot(x,ct);
    hold on
    
    ct = (-0.9*x)+(2*0.9*D);
    plot(x,ct)
    hold on
    grid on
end


%Earth-bound Twin
for ct = 0:5:(2*0.9*D)
    x = 0;
    plot(x,ct,'r*');
    hold on;
end

%Outbound rocket ship
for x = 0:100:2*D
    ct = 0.9*x;
    plot(x,ct,'o');
    hold on
end

%Inbound rocket ship
for x = 0:100:2*D
    ct = (-0.9*x)+(2*0.9*D);
    plot(x,ct,'k+')
    hold on
end
title('Twin Paradox at 0.9*c');
xlabel('x');
ylabel('ct');