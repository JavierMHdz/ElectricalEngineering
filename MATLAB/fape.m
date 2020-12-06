function [frq,A,phi,X] = fape(target,support)
A=max(abs(target));
target=target(:)/A;
support=support(:);

X = zeros(floor(length(target)/2),1);
N = length(target);

T_s = diff(support);
T_s = T_s(1);
f=1/(max(support)-min(support));

for k = 1:N/2
   ref = 1*exp(j*2*pi*f*k.*support);
   correlation = sum(ref.*target).*T_s/(max(support)-min(support));
   X(k) = correlation;
end

[value,location]=max(X);
k=1:N/2;
k_prime = k(location);

figure
plot(k,abs(X))
frq = k_prime.*f
[eee,phi] = apc(target,support,frq);

end