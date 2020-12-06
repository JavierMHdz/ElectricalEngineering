%to find the value of the critical k
for k = 1:0.001:5
    poles = roots([1 2.1 2.2 k+0.2]);
    x = real(poles);
    if max(x)>=0
        k_cri=k;
        break;
    end;
end;