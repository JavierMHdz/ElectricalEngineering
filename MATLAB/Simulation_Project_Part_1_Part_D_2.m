%to find the value of the critical k
for k = 1:0.001:8
    poles = roots ([1 0.53 3.04 k+0.3]);
    x = real(poles);
    if max(x)>= 0
        k_cri = k;
        break;
    end;
end;
display(k_cri);
