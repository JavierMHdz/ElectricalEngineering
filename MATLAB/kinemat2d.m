%{
KINEMAT2D this function takes parameters, such as intial velocity,
angle, mass1, mass2, time of explosion, impulse magnitude.
Then, it calculates the range and time of travel.
It gives a plot with the Initial Trajectory, Centroid Trajectory,
Mass 1 Trajectory, and Mass 2 Trajectory.
Javier Macossay
ITP 168 - Fall 2015
Homework 7: Kinematics
macossay@usc.edu
Revision History
Date            Changes                                  Programmer
--------------------------------------------------------------------------
11/6/2015        Original                                 Javier Macossay
%}

function kinemat2d(initV, angleDegrees, massOne, massTwo, timeExp, impulse)
if massOne < 0 || massTwo < 0
    error('Mass must be positive');
end;

if impulse < 0
    error ('Impulse must be positive');
end;

if timeExp < 0
    error('Time must be positive');
end;

if angleDegrees <=  0 || angleDegrees >= 90
    error('Angle must be between 0 and 90 (not including 0 or 90)');
end;

%converting angles from degrees to radians
angle = angleDegrees*pi/180;

%1)gravity constant
g = 9.81;

%2)time spent in air
time = (2*initV*sin(angle))/g;

if timeExp > time
    error('The explosion happens after our cannon ball hits the ground');
end;

%3)the range
x = initV*cos(angle)*time;

%4)time vector
t = linspace(0,timeExp);

%5)component velocity
vx = initV*cos(angle);
vy = initV*sin(angle);

%6)call the function
xPosition = kinemat1d(t,vx,0,0);
yPosition = kinemat1d(t,vy,g,0);

%plotting
plotHandle = plot(xPosition(1),yPosition(1),'b-');
axis([0 1.5*x 0 max(yPosition)+10]);
grid;

%Set the XData to be X values from 1 through the index of the loop
%Set the YData to be Y values from 1 through the index of the loop
realTime = linspace(0,time);
for i = 1:length(realTime)
    set(plotHandle,'XData',xPosition(1:i));
    set(plotHandle,'YData',yPosition(1:i));
    drawnow;

end;
hold on
newTime = time-timeExp;
deltaTime = linspace(0,newTime);
%calculate the y component velocity for mass 1
vyExp = vy - g*timeExp;

%starting positions of mass 1
newPosX = kinemat1d(timeExp,vx,0,0);
newPosY = kinemat1d(timeExp,vy,g,0);


%new component velocity for mass 1
vxM1 = vx + (impulse)/massOne;

%vector of X and Y values for mass 1's
xPosM1 = kinemat1d(deltaTime,vxM1,0,newPosX);
yPosM1 = kinemat1d(deltaTime,vyExp,g,newPosY);

%new component velocity for mass 2
vxM2 = vx - (impulse)/massTwo;

%vector of X and Y values for mass 2's
xPosM2 = kinemat1d(deltaTime,vxM2,0,newPosX);
yPosM2 = kinemat1d(deltaTime,vyExp,g,newPosY);

%create a vector of X values for the centroid's position after the
%explosion
xCentroidPos = kinemat1d(timeExp + deltaTime,vx,0,0);
yCentroidPos = kinemat1d(timeExp + deltaTime,vy,g,0);

plotHandle3 = plot(xCentroidPos(1),yCentroidPos(1),'g--');
plotHandle1 = plot(xPosM1(1),yPosM1(1),'m-');
plotHandle2 = plot(xPosM2(1),yPosM2(1),'r-');
for i = 1:length(deltaTime)
    set(plotHandle1,'XData',xPosM1(1:i));
    set(plotHandle1,'YData',yPosM1(1:i));
    set(plotHandle2,'XData',xPosM2(1:i));
    set(plotHandle2,'YData',yPosM2(1:i));
    set(plotHandle3,'XData',xCentroidPos(1:i));
    set(plotHandle3,'YData',yCentroidPos(1:i));
    drawnow;
end;

hold off

legend('Initial Trajectory','Centroid Trajectory','Mass 1 Trajectory','Mass 2 Trajectory');
xlabel('X location (meters)');
ylabel('Y location (meters)');
end
function position = kinemat1d(t,v,g,startPos)

position = startPos+v*t-(0.5)*g*t.^2;

end
