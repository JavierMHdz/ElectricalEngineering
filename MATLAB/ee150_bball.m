%ee150_bball.m
function ee150_bball
%----------------------------------
% Constants
%----------------------------------
radius = 0.7;     % radius of the ball
x0 = 0;           % position of the center of the ball
y0 = 10 + radius;
w = 3*pi;        % angular velocity (radians/sec.)
g = 9.81;         % gravitational acceleration constant in m/s

%----------------------------------
% Duration of the movie, frames per second, and other values
%----------------------------------
duration = 15;
framerate = 30;
maxframes = duration * framerate + 1;
dt = 1/framerate; % delta time between each frame

%----------------------------------
% Draw the initial ball, ground, and target
%----------------------------------
% to draw the ball we'll have 512 points around the circumference
n = 512;

% Creates a vector of 512 angles from [0 2*PI] radians to be used
% to calculate the points on the circumference of the ball
% rotate/spin the ball
arg = [0 : 2*pi/n : 2*pi];

% Initial ball circumference X,Y coordinates matrix 
%    We will never change this representation of the ball and just 
%    rotate it for each frame
%    8 Rows (1 for each sector) x 512/8 + 1 cols
%    Extra col => starting point of each sector is 0,0
xi = zeros(8,1+n/8);
yi = zeros(8,1+n/8);

%=== For LAB completion====
% We'll cut the ball into 8 sectors filling each sector w/ a unique color
% To do this, modify the xi, yi matrices such that the 1st point of each
% row vector is 0,0 and the rest of the points are the circumference 
% points of the circle (i.e. use the 'arg' vector when calculating your
% circumference points along with the 'radius' value). 
for i=1:8
    j=(i-1)*n/8;
    k=(i*n/8)-1;
    xi(i,:)=[0 radius*cos(arg(j+1:k+1))];
    yi(i,:)=[0 radius*sin(arg(j+1:k+1))];
end

% Draw the 8 sectors filling them with color
draw_ball(xi,yi);
hold on;
line([-1 20],[0 0], 'Color', 'b' );  % Draw the ground
axis([-1 20 -1 20]);
hold off;

% Now let the user pick the initial velocity and angle of the ball
initV = input('Enter the initial velocity in m/s: ');
angle = input('Enter the angle in degrees of the ball: ');
rad = pi*angle/180;
%=== For PRELAB completion====
vy = initV*sin(rad);     % change these assignments appropriately for the ball's velocity
vx = initV*cos(rad);

%----------------------------------
% Ball Path/Trajectory Calculation
%----------------------------------  
% xc and yc are coordinates of the center of the ball at each time
xc = zeros(1,maxframes);
yc = zeros(1,maxframes);

% theta = angle of rotation of the ball at each time frame
theta = zeros(1,maxframes);

% sx, sy are the scaling factors of the ball in the x and y direction
%  at each time frame
sx = ones(1,maxframes);
sy = ones(1,maxframes);

% set the time = 0
t = 0;

%set initial position of the ball and its angle
yc(1) = y0;
xc(1) = x0;
sx(1) = 1;
sy(1) = 1;
theta(1) = 0;
% Calculate the velocity of the ball and change in angle at each timestep i
%   You will need to calculate theta, sx, sy, vx, vy, xc, yc, w, & status
%   You will also need to update i and t in each iteration
% Continue calculation until the LAST position of the ball is past the edge  
%   of the screen (i.e. 20 meters) or the current time has reached the 
%   end of the movie (i.e. time less than (duration - dt) )
% Change the while loop below to perform these operations
i=2;
%=== For PRELAB completion==== 
while t<=duration-dt && xc(i-1)<20+radius
   [vx, vy, w, xc(i), yc(i), theta(i)] = physics_update(vx, vy, w, xc(i-1), yc(i-1), theta(i-1), dt, radius);
   i = i+1;
   t = t+dt;
end
% set the number of frames based on how many times the loop iterated
numframes = i-1;
  
%plot the path of the center of the ball
figure;
plot(xc(1:numframes),yc(1:numframes)); hold on;
line([-1 20], [0 0], 'Color', 'b');  % Draw the ground
axis([-1 20 -1 20]);

%open a new figure;
figure;

%----------------------------------
% Animation (Ball Rotation/Translation along trajectory path)
%----------------------------------

% Rotated, translated ball circumference X,Y coordinates matrix at each
%     frame (we will rotate and traslate xi and yi at each frame to produce 
%     these matrices)
%     8 Rows (1 for each sector) x 512/8 + 1 cols
x = zeros(8,1+n/8);
y = zeros(8,1+n/8);

% Create the movie object
mymovie = moviein(numframes);

% Draw the ball for EACH frame using trajectory/physics calculations 
%      performed above
%  T = Translation matrix - move the ball to the (xc,yc) position
%  S = Scaling matrix - Scaling values for this frame 
%  R = Rotation matrix - Rotation values for this frame

  %=== For LAB completion====   
  % Calculate the geometric modification matrices T, S, R
for h = 1:numframes
    T=[1 0 xc(h); 0 1 yc(h); 0 0 1]; 
    S=[sx(h) 0 0; 0 sy(h) 0;0 0 1]; 
    R=[cos(theta(h)) -sin(theta(h)) 0;sin(theta(h)) cos(theta(h)) 0;0 0 1];
    M=T*S*R; 
  for i=1:8 
      for j=1:1+n/8
          p=[xi(i,j);yi(i,j);1]; 
          p=M*p; 
          x(i,j)=p(1); 
          y(i,j)=p(2); 
      end
  end


  % For each sector perform the affine transformation and place the
  % result in the x,y vectors

  % Draw the 8 sectors filling them with color
  draw_ball(x,y);
  hold on;
  line([-1 20], [0 0], 'Color', 'b');  % Draw the ground
  axis([-1 20 -1 20]);
  hold off;
  
  % Write the frame to the movie
  ballmovie(:,h)=getframe;

end

  % Playback the movie
  movie(ballmovie,1,framerate);

end

function [vx, vy, w, xc_o, yc_o, theta_o] = physics_update(vx, vy, w, xc_i, yc_i, theta_i, dt, radius)
    g = 9.81;
    %=== For PRELAB completion==== 
    % Remember to check if the ball is hitting the ground and update your
    %  velocities appropriately
    xc_o = xc_i + vx*dt;
    yc_o = yc_i + vy*dt; 
    theta_o = theta_i - w*dt;
    vy = vy - g*dt;
    if yc_o <= radius
        vx = .9*vx;
        vy = -.75*vy;
        w = .8*w;
        yc_o=radius;
    end
end

% Expects 8xN x and y point matrices
function draw_ball(x,y)
  %=== For LAB completion====
  % Draw the 8 sectors filling them with color (turn hold on after the
  % first sector and turn hold off after the last sector

  fill(x(1,:),y(1,:),'g');
  hold on
  fill(x(2,:),y(2,:),'b');
  fill(x(3,:),y(3,:),'r');
  fill(x(4,:),y(4,:),'y');
  fill(x(5,:),y(5,:),'g');
  fill(x(6,:),y(6,:),'b');
  fill(x(7,:),y(7,:),'r');
  fill(x(8,:),y(8,:),'y');
  hold off

end