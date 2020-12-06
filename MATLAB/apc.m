function [A, phi] = apc(target, support, frq);

A=max(abs(target));

ref=cos(2*pi*frq.*support);

ref=ref(:);

target=target(:)/A;

T=diff(support);

T=T(1);

correlation=sum(ref.*target).*T

cos0=correlation*2/(max(support)-min(support))

phi=abs(acos(cos0));


end
