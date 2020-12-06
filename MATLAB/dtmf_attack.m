function success_rate = dtmf_attack(noise_pwr)
%function success_rate = dtmf_attack(noise_pwr)
%
% DTMF_ATTACK  --  A function that tests the robustness of your
%                  DTMF decoder to random noise over 10 trials
%
% Input Parameter
%   noise_pwr  --  Determines the power (strength) of the noise signal to be added
%                  to the DTMF signal
% 
% Output Parmaeter:
%   success_rate -- The fraction of the trials that were decoded without error
%

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)


trials = 10;

nums = (1:12)';
orig_sig = dtmf_dial(nums);

success = 0;
displ = 0;

for j = 1:trials
    
    if j == trials
        displ = 1;
    end
    
    disp(['Noise Power: ' num2str(noise_pwr) '  Trial ' num2str(j) '/' num2str(trials)]);
    
    sig = orig_sig + noise_pwr*randn(size(orig_sig));
    
    decoded = dtmf_decode(sig,displ);
    
    if length(decoded) == length(nums) & all(decoded == nums)
        success = success + 1;
        disp('   Decoding successful.');
    else
        disp('   *** Decoder Error ***');
        disp(['     Original: ' num2str(nums')]);
        disp(['     Decoded : ' num2str(decoded')]);
    end
end

success_rate = success/trials;
