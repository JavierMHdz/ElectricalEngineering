function [ss,tt] = fourier_synthesis(CC,T,periods,Ns)
%function [ss,tt] = fourier_synthesis(CC,T,periods,Ns)
%
% FOURIER_SYNTHESIS  --  Synthesize a signal using the Fourier Synthesis equation
%
% Input Parameters:
%  CC  --  Fourier coefficients, assumed to contain coefficients C_-N through C_N
%          (i.e., the length of CC should be 2N+1)
%  T   --  Period of the signal to resynthsize in seconds.
%  periods -- number of periods to include in the resynthesis (Default: 1)
%  Ns  --  Number of samples per period to include in the resynthesis (Optional)
%          Should be greater than or equal to length(CC)
%
% Output Paramters:
%  ss  --  Signal vector for the resynthesis
%  tt  --  Support vector for the resynthesis

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)
%    10/12/01 --  Clarified role of Ns, and added input checking


if nargin < 4    
    Ns = length(CC)*50;
end
if nargin < 3
    periods = 1;
end

if Ns < length(CC)
    N = floor((Ns-1)/2);
    CC = CC((-N:N) + ceil(length(CC)/2));
    warning('Ns smaller than length(CC)... truncating CC.');
end

dft = zeros(Ns,1);

N = (length(CC)-1)/2;
dft(1:N+1) = CC(N+1:end);
dft(end-N+1:end) = CC(1:N);

ss = real(ifft(dft))*length(dft);
ss = kron(ones(periods,1),ss);
tt = (1:periods*Ns)'*T/Ns - 1/Ns;
