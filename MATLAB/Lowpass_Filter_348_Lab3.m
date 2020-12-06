freq3db = 5.787e3;
C = 11e-9;
R2 = 2.5e3;


%Lowpass
Vout = [1.14 1.12 1.12 1.12 1.11 1.07 1.02 0.950 0.870 0.540 0.360 0.240 0.220 0.190 0.160 0.140 0.120 0.110];
freq = [100 200 400 800 1000 2000 3e3 4e3 5e3 10e3 20e3 30e3 40e3 50e3 70e3 80e3 90e3 100e3];
Vin = 200e-3;
gaindB = 20*log10(Vout/Vin);
figure
semilogx(freq, gaindB);
title('Lowpass Filter');
xlabel('Frequency (Hz)');
ylabel('Gain (dB)');