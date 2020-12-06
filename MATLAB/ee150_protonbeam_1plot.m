function ee150_protonbeam_1plot(v0, B, Ei, dE, Ef)
%v0=Initial velocity in x-direction
%B=Magnetic field (0.5 Tesla)
%Ei=Initial value of the electric field
%dE=Stepsize of electric field
%Ef=Final value of the electric field
dt=1e-9; %Delta t
duration=10e-6 %Computes the values of velocity and position for this duration of time.
q=1.6e-19; %Charge of a proton in coloumbs. Must be +.
m=(1.67e-27); %Mass of a proton in kilograms.
I=duration/dt;
w=(q*B)/m;
for E=Ei:dE:Ef
    vy=zeros(1,I+1);
    vx=zeros(1,I+1);
    vx(1,1)=v0;
    x=zeros(1,I+1);
    y=zeros(1,I+1);
    a_e=(q*E)/m;
    for t=1:I
        vx(1,t+1)=vx(1,t)+dt*(w*vy(1,t));
        vy(1,t+1)=vy(1,t)+dt*(-w*vx(1,t)+a_e);
        x(1,t+1)=x(1,t)+vx(1,t)*dt;
        y(1,t+1)=y(1,t)+vy(1,t)*dt;
    end
    if y==0;%If we look at the plot for ee150_protonbeam,
            %we can see that the correct value of E has a
            %value of 0 for y. Thus, it should only pass
            %the plot of a proton who goes through an E-field
            %where the proton's y value is 0; basically saying
            %when the particle travels in a straight line.
    figure;
    plot(x,y,'r');
    xlabel('X-Pos(m)');
    ylabel('Y-Pos(m)');
    title(['Proton Trajectory for E =' int2str(E) ' in V/m']);
    axis([-0.2 0.2 -0.1 0.1]);
    end
end

