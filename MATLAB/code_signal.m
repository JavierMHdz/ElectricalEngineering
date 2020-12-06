function out = code_signal(in,chips)
%function out = code_signal(in,chips)
%
% CODE_SIGNAL -- produces DS/SS code signals for Lab #2 
%
% Input Parameters:
%   in    -- the number used to generate a chip sequence
%   chips -- the number of chips in the code signal
%
% Output Parmaeters:
%   out   -- the code signal
%

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)



bit_width = 10;

x = double(2*(dec2bin(in)- '0' - .5));
if length(x) > chips
    error('Not enough chips to represent given number');
end

y = -1*ones(1,chips);
y(end-length(x)+1:end) = x;

out = kron(y,ones(1,bit_width))';
