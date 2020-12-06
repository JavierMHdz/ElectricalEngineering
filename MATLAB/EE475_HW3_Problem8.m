%EE475 HW3 Problem 8

for f = 3:0.1:100
    
    %BPSK
    x = sqrt(2*f);
    BER = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
    
    %creating the plot
    horizontal = pow2db(f);
    semilogy(horizontal, BER,'b--*');
    hold on;
    
    %DPSK
    BER = 0.5*exp(-f);
    
    %creating the plot
    horizontal = pow2db(f);
    semilogy(horizontal, BER,'r-*');
    
    %16QAM
    l = 4;
    x = sqrt(((3*log2(l))/((l^2)-1))*(2*f));
    q = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
    BER = 2*(1-(l^-1))/log2(l)*q;
    
    %creating the plot
    horizontal = pow2db(f);
    semilogy(horizontal, BER,'y-*');
    
    %32QAM
    l = sqrt(32);
    x = sqrt(((3*log2(l))/((l^2)-1))*(2*f));
    q = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
    BER = 2*(1-(l^-1))/log2(l)*q;
    
    %creating the plot
    horizontal = pow2db(f);
    semilogy(horizontal, BER,'c-*');
    
end
grid on
xlabel('Eb/No [dB]');
ylabel('BER');
title('BER vs. Eb/No');
axis([6, 20, 1e-10, 1e-1]);