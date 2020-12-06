%EE475 HW3 Problem 7
for f = 9:0.1:9.5
    x = sqrt(2*f);
    BER = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2)
end
    f = 9.1;
    x = sqrt(2*f);
    BER = 1/(x*sqrt(2*pi))*exp(-(x.^2)/2);
    fprintf('The value of f is equal to %.1f since the BER value is %0.5f\n',f, BER);