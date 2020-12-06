freq3db = 5.787e3;
C = 11e-9;
R2 = 2.5e3;

%Highpass

Vin2 = 200e-3;
Vout2 = [60e-3 66e-3 80e-3 400e-3 0.800 1 1.2 1.2 840e-3 480e-3 320e-3 120e-3 70e-3 60e-3];
freq2 = [300 600 1000 10e3 20e3 30e3 50e3 100e3 200e3 500e3 1e6 2e6 5e6 10e6];
gaindB2 = 20*log10(Vout2/Vin2);
figure
semilogx(freq2, gaindB2);
title('Highpass Filter');
xlabel('Frequency (Hz)');
ylabel('Gain (dB)');
