%Boltzmann's constant
k = 8.62*10.^-5;

%Bandgap Energy
energyS = 1.12;
energyG = 0.66;
energyGaAs = 1.42;

%Nc
NcS = 2.8*10.^19;
NcG = 1.04*10.^19;
NcGaAs = 4.7*10.^17;

%Nv
NvS = 1.04*10.^19;
NvG = 6*10.^18;
NvGaAs = 7*10.^18;

%T(K)
T1 = 200;
T2 = 400;
T3 = 600;

%Silicon
SniT1 = sqrt(NcS*NvS*(T1/300).^3*exp(-energyS/(k*T1)))
SniT2 = sqrt(NcS*NvS*(T2/300).^3*exp(-energyS/(k*T2)))
SniT3 = sqrt(NcS*NvS*(T3/300).^3*exp(-energyS/(k*T3)))

%Germanium
GniT1 = sqrt(NcG*NvG*(T1/300).^3*exp(-energyG/(k*T1)))
GniT2 = sqrt(NcG*NvG*(T2/300).^3*exp(-energyG/(k*T2)))
GniT3 = sqrt(NcG*NvG*(T3/300).^3*exp(-energyG/(k*T3)))

%Gallium Arsenide
GaAsniT1 = sqrt(NcGaAs*(T1/300).^3*NvGaAs*exp(-energyGaAs/(k*T1)))
GaAsniT2 = sqrt(NcGaAs*(T2/300).^3*NvGaAs*exp(-energyGaAs/(k*T2)))
GaAsniT3 = sqrt(NcGaAs*(T3/300).^3*NvGaAs*exp(-energyGaAs/(k*T3)))

%plots

%Silicon
xS = [T1 T2 T3];
yS = [SniT1 SniT2 SniT3];
figure;
semilogy(xS,yS,'b-o');
title('Silicon Intrinsic Carrier Concentration vs. Temperature');
xlabel('Temperature in Kelvins');
ylabel('Intrinsic Carrier Concentration');
grid;

%Germanium
xG = [T1 T2 T3];
yG = [GniT1 GniT2 GniT3];
figure;
semilogy(xG,yG,'b-o');
title('Germanium Intrinsic Carrier Concentration vs. Temperature');
xlabel('Temperature in Kelvins');
ylabel('Intrinsic Carrier Concentration');
grid;

%Gallium Arsenide
xGaAs = [T1 T2 T3];
yGaAs = [GaAsniT1 GaAsniT2 GaAsniT3];
figure;
semilogy(xGaAs,yGaAs,'b-o');
title('Gallium Arsenide Intrinsic Carrier Concentration vs. Temperature');
xlabel('Temperature in Kelvins');
ylabel('Intrinsic Carrier Concentration');
grid;