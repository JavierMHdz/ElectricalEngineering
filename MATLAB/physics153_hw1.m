%{
Javier Jesús Macossay-Hernández
Physics 153
Written HW #1 - Diffraction Grating
%}

%Angle needed in the entire problem
theta = 0:0.01:0.5;

%{
Using formula:
I/I0 = sin(x).^2/sin(phi).^2
where x = N*phi and phi = (pi*d*sin(theta))/lambda

since d = 3*lambda, the lambdas get cancelled. Leaving the following
equation:

phi = (pi*3*sin(theta))
%}

phi = (pi*3*sin(theta));

%Intensity = sin(x).^2/sin(phi).^2

%For N = 1
x = 1*phi;
Intensity_1 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_1,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 1')
title('N = 1 before being normalized')
grid on

%For N = 2
x = 2*phi;
Intensity_2 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_2,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 2')
title('N = 2 before being normalized')
grid on

%For N = 3
x = 3*phi;
Intensity_3 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_3,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 3')
title('N = 3 before being normalized')
grid on

%For N = 4
x = 4*phi;
Intensity_4 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_4,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 4')
title('N = 4 before being normalized')
grid on

%For N = 5
x = 5*phi;
Intensity_5 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_5,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 5')
title('N = 5 before being normalized')
grid on

%For N = 10
x = 10*phi;
Intensity_10 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_10,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 10')
title('N = 10 before being normalized')
grid on

%Now, I will normalize the graphs

%For N = 1
x = 1*phi;
Intensity_1 = sin(x).^2./sin(phi).^2;
figure
plot(theta,Intensity_1,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 1')
title('N = 1 after being normalized')
grid on

%For N = 2
x = 2*phi;
Intensity_2 = sin(x).^2./sin(phi).^2;
NewIntensity_2 = Intensity_2./4;
figure
plot(theta,NewIntensity_2,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 2')
title('N = 2 after being normalized')
grid on

%For N = 3
x = 3*phi;
Intensity_3 = sin(x).^2./sin(phi).^2;
NewIntensity_3 = Intensity_3./9;
figure
plot(theta,NewIntensity_3,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 3')
title('N = 3 after being normalized')
grid on

%For N = 4
x = 4*phi;
Intensity_4 = sin(x).^2./sin(phi).^2;
NewIntensity_4 = Intensity_4./16;
figure
plot(theta,NewIntensity_4,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 4')
title('N = 4 after being normalized')
grid on

%For N = 5
x = 5*phi;
Intensity_5 = sin(x).^2./sin(phi).^2;
NewIntensity_5 = Intensity_5./25;
figure
plot(theta,NewIntensity_5,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 5')
title('N = 5 after being normalized')
grid on

%For N = 10
x = 10*phi;
Intensity_10 = sin(x).^2./sin(phi).^2;
NewIntensity_10 = Intensity_10./100;
figure
plot(theta,NewIntensity_10,'*-');
xlabel('Angle')
ylabel('Intensity Values at N = 10')
title('N = 10 after being normalized')
grid on
