%Boltzmann's constant
k = 8.62*10.^-5;

%holes
mp = 0.48;

%electrons
mn = 0.067;

%T(K)
T1 = 200;
T2 = 400;
T3 = 600;

E1 = (3/4)*k*T1*log(mp/mn)
E2 = (3/4)*k*T2*log(mp/mn)
E3 = (3/4)*k*T3*log(mp/mn)

%plot
X = [T1 T2 T3];
Y = [E1 E2 E3];
figure;
plot(X,Y,'b-o');
title('Gallium Arsenide Intrinsic Fermi Energy vs. Temperature');
xlabel('Temperature in Kelvins');
ylabel('Intrinsic Fermi Energy');
grid;