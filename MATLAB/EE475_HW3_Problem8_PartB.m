%EE475 HW3 Problem 8 Part B

f = 10;

%BPSK
x = sqrt(2*f);
BER1 = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2)

%DPSK
BER2 = 0.5*exp(-f)

%16QAM
l = 4;
x = sqrt(((3*log2(l))/((l^2)-1))*(2*f));
q = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
BER3 = 2*(1-(l^-1))/log2(l)*q

%32QAM
l = sqrt(32);
x = sqrt(((3*log2(l))/((l^2)-1))*(2*f));
q = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
BER4 = 2*(1-(l^-1))/log2(l)*q