%**************************************
% This script generates 2D plot
% of g(t)=exp(-t)sin(3t)over the domain of [0,10]
clear; clc;
% STEP 1: Generate the vector t
t = linspace(0,10,130); % t is generated using
                        % the colon notation.
                        % The resolution is
                        % equal to 130.
                 
% STEP 2: Calculate g
          
g = exp(-t).* sin(3*t);

% STEP 3: plot the function g(t) using
       % the individual points
% plot (g,t,'g-'); % The option 'g-' represents the
                  % color of the marker and the style
                
plot (t,g,'g-', 'LineWidth',1.5); % Joint the points with a straight 
                % line
                
% Add labels
xlabel('0\leq t\leq 10');
ylabel('g');

%Add a legend
legend('g(t)=e^{-t}sin(3t)');

