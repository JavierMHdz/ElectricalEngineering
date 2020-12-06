%{
ORBITER this function creates a dot that orbits with the radius
specified by the user. It takes two inputs: one is the radius
and the second one is the number of orbits.
Javier Macossay
ITP 168 - Fall 2015
Lab 17
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/6/2015        Original            Javier Macossay
%}
function orbiter(radius,orbits)

if nargin == 1
    orbits = 1;
end;

[rowsR,colR] = size(radius);
[rowsO,colO] = size(orbits);

if rowsR == 1 && colR == 1 && rowsO == 1 && colO == 1 && radius > 0 && orbits > 0
    for index = 1:orbits
        angle = 0;
        x = radius*sind(angle);
        y = radius*cosd(angle);
        plotHandle = plot(x,y,'b*');
        axis([-1.5*radius 1.5*radius -1.5*radius 1.5*radius]);
     
        for i = 1:360
            angle = i;
            x = radius*sind(angle);
            y = radius*cosd(angle);
            set(plotHandle,'XData',x);
            set(plotHandle,'YData',y);
            drawnow;
        end;
    end;
else
    error('Inputs should be positive scalars!');
end;

end