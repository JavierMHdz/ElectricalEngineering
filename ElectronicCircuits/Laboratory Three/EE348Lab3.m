1.12freq3db = 5.787e3;
C = 11e-9;
R2 = 2.5e3;


%Lowpass
Vout = [1.14 1.12 1.12 1.12 1.11 1.07 1.02 0.950 0.870 0.540 0.360 0.240 0.220 0.190 0.160 0.140 0.120 0.110];
freq = [100 200 400 800 1000 2000 3e3 4e3 5e3 10e3 20e3 30e3 40e3 50e3 70e3 80e3 90e3 100e3];
Vin = 200e-3;
gaindB = 20*log10(Vout/Vin);
semilogx(freq, gaindB);

%Highpass

Vin2 = 200e-3;
Vout2 = [60e-3 66e-3 80e-3 400e-3 0.800 1 1.2 1.2 840e-3 480e-3 320e-3 120e-3 70e-3 60e-3];
freq2 = [300 600 1000 10e3 20e3 30e3 50e3 100e3 200e3 500e3 1e6 2e6 5e6 10e6];
gaindB2 = 20*log10(Vout2/Vin2);

figure
semilogx(freq2, gaindB2);