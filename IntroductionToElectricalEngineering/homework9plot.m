%**************************************
% This script generates 2D plot
% of y versus x over the domain [0,3] using resolution defined by a step
% size of 0.01.
clear;clc;
% STEP 1: Generate the vector x
x = [0:0.01:3]; % x is generated using
                 % the colon notation
                 % The increment= 0.01
                 
% STEP 2: Calculate y using Element-wise
          % operations
          
y = cos(2*x)./exp(.5*x.^2);

% STEP 3: plot the function y(x) using
       % the individual points
% plot (x,y,'r'); % The option 'r' represents the
                  % color of the marker
                
plot (x,y,'r', 'LineWidth',2.0); % Joint the points with a straight 
                % line
                
% Add labels
xlabel('x');
ylabel('y (meter)');

%Add the title
title('y(x)=cos(2x)/e^{0.5x^{2}}');

%Add a grid to the plot
grid on;



