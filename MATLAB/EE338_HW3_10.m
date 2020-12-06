%Boltzmann's constant
k = 8.62*10.^-5;

Nd = 10.^15;

Nc = 2.8*10.^19;

%ionization energy
E = -0.045;

%T(K)
T1 = 50;
T2 = 100;
T3 = 200;

%kt
kT1 = k*T1
kT2 = k*T2
kT3 = k*T3

%Nc relative to temperature
Nc50 = Nc*(T1/300).^(3/2)
Nc100 = Nc*(T2/300).^(3/2)
Nc200 = Nc*(T3/300).^(3/2)

%Fraction of total electrons
nd50 = 1/(1+(Nc50/(2*Nd))*exp(E/kT1))
nd100 = 1/(1+(Nc100/(2*Nd))*exp(E/kT2))
nd200 = 1/(1+(Nc200/(2*Nd))*exp(E/kT3))

X = [T1 T2 T3];
Y = [nd50 nd100 nd200];
figure;
plot(X,Y,'b-o');
title('Unionized Donor Atoms vs. Temperature');
xlabel('Temperature in Kelvins');
ylabel('Unionized Donor Atoms to the Total Electron Concentration');
grid;