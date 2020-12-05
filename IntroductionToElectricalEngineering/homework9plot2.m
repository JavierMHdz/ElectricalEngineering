%**************************************
% This script generates 2D plot
% of g(theta)=12./(abs(theta^3)+ theta^2+1) over the domain [-2,4]
% using resolution defined by a step
% size of 0.0001.
clear;clc;
% STEP 1: Generate the vector theta
theta = [-2:0.0001:4]; % theta is generated using
                 % the colon notation
                 % The increment= 0.0001
                 
% STEP 2: Calculate theta using Element-wise
          % operations
          
g = 12./(abs(theta.^3)+theta.^2+1);

% STEP 3: plot the function g(theta) using
       % the individual points
% plot (theta,g,'m'); % The option 'm' represents the
                      % color of the marker
                
plot (theta,g,'m', 'LineWidth',1.5); % Joint the points with a straight 
                                     % line
                
% Add labels
xlabel('\theta (theta)');
ylabel('g');

%Add the title
title('g(\theta)=12/(|\theta^{3}|+\theta^{2}+1)');

%Add a grid to the plot
grid on;

