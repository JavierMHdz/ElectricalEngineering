function orbiter1(radius, orbit)
%ORBITER will begin at one degree and continue onward until 360 degrees,
%the first input is the distance of the radius and the second input is the
%number of orbits

%{
Loren Gutierrez
ITP 168 Fall 2015 Lab 17
lorengut@usc.edu
Revision History

   Date                 Changes                      Programmer
------------------------------------------------------------------
10/29/2015              Original                   Loren Gutierrez

%}


if nargin == 1
    orbit = 1;
end 

radL = length(radius);
orbL = length(orbit);

if (radL ~= 1) 
    error('Radius is not scalar.');
end 

if (orbL ~= 1)
    error('The number of orbits is not scalar.');
end 

if radius < 0
    error('The radius must positive value. ');
end

if orbit < 0
    error('The number of orbits must be positive.');
end 



for j = 1:orbit

angle = 0;
x = radius*cosd(angle);
y = radius*sind(angle);
plotHandle = plot(x,y,'k+');
axis([-1.5*radius 1.5*radius -1.5*radius 1.5*radius]);

    for i = 1:360
    x = radius * (cosd(i));
    y = radius * (sind(i));
    set(plotHandle,'XData',x); 
    set(plotHandle,'YData',y); 
    drawnow;
    end
end



end