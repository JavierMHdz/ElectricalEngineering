function [CC, ww] = fourier_analysis(ss, T, N)
%function [CC, ww] = fourier_analysis(ss, T, N)
%
% FOURIER_ANALYSIS -- Perform (approximage) Fourier analysis on a signal
%
% Input Paramters:
%   ss  -- A period of a periodic signal
%   T   -- The length (in seconds) of the input period 
%   N   -- The number of positive harmonics to include in the analysis
%
% Output Parameters:
%   CC  -- A vector of 2N+1 Fourier coefficients C_-N through C_N, such that 
%          CC(n) is equivalent to the (n-N-1)th Fourier coefficient.
%   ww  -- Frequencies associated with each Fourier coefficient in Hertz

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)



ss = ss(:);

dft = fft(ss)/length(ss);
CC = [conj(flipud(dft(2:N+1))); dft(1:N+1)];

ww = (-N:N)/T;
