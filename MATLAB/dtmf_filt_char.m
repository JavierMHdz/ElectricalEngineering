function gain = dtmf_filt_char(M,frq,display)
%function gain = dtmf_filt_char(M,frq,display)
%
% DTMF_FILT_CHAR -- a function to help characterize the effects
%                   of a DTMF bandpass filter.  Displays the
%                   gains as a table and on a plot of the 
%                   filter's frequency response.
%
% Input Parameters:
%   M       -- the order of the bandpass filter
%   frq     -- center frequency of the bandpass filter in Hz
%   display -- indicates whether or not to display the frq response (optional)
%
% Ouptut Parameters:
%   gain    -- The gain of the filter at the DTMF frequencies, from the
%              lowest DTMF frequency to the highest DTMF frequency
%

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)


if ~exist('display','var') | isempty(display)
    display = 1;
end


frqs = [697 770 852 941 1209 1336 1477];

fs = 8192;
t = 0:1/fs:(1-1/fs);

h = sin(t(1:(M+1))*2*pi*frq);

[H,w] = freqz(h,1,fs/2);

gain = abs(H(frqs+1));

frq_H = abs(freqz(h,1,[0 frq*2*pi/fs]));
frq_H = frq_H(2);

if display
    plot(w*fs/2/pi,abs(H));
    xlabel('Frequency (Hz)');
    ylabel('Gain');
    
    hold on
    stem(frqs,abs(H(frqs+1)),'g');
    stem(frq,frq_H,'r');
    hold off;
    
    ax = axis;
    axis([500 2000 0 ax(end)]);
end

%fprintf(1,'Frequency:  ');
%fprintf(1,'%8d ',frqs);
%fprintf(1,'\nGain:       ');
%fprintf(1,'%8g ',gain);
%fprintf(1,'\n\n');
