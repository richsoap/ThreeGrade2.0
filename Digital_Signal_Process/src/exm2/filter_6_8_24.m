function y = filter_6_8_24(x)
%FILTER_6_8_24 Filters input x and returns output y.

% MATLAB Code
% Generated by MATLAB(R) 9.1 and the DSP System Toolbox 9.3.
% Generated on: 13-Jun-2018 13:34:28

%#codegen

% To generate C/C++ code from this function use the codegen command. Type
% 'help codegen' for more information.
  
    % The following code was used to design the filter coefficients:
    % % FIR Window Lowpass filter designed using the FIR1 function.
    %
    % % All frequency values are in kHz.
    % Fs = 24;  % Sampling Frequency
    %
    % Fpass = 6;                % Passband Frequency
    % Fstop = 8;                % Stopband Frequency
    % Dpass = 0.0057563991496;  % Passband Ripple
    % Dstop = 0.0001;           % Stopband Attenuation
    % flag  = 'scale';          % Sampling Flag
    %
    % % Calculate the order from the parameters using KAISERORD.
    % [N,Wn,BETA,TYPE] = kaiserord([Fpass Fstop]/(Fs/2), [1 0], [Dstop Dpass]);
    %
    % % Calculate the coefficients using the FIR1 function.
    % b  = fir1(N, Wn, TYPE, kaiser(N+1, BETA), flag);
    
    y=[-1.6980170847524e-05 -3.98938605037357e-05 ...
        0.000114506520497387 2.73549411403662e-05 -0.000327177939083541 ...
        0.000189032588655167 0.000564432253766747 -0.00078838700546167 ...
        -0.000517957050024124 0.00178936960227078 -0.000308488047070515 ...
        -0.00281487955468693 0.00235865831066704 0.00296382463947962 ...
        -0.00559341294408928 -0.000973823303702763 0.00904482736125161 ...
        -0.00424134299374383 -0.0106271067941106 0.0127957342348494 ...
        0.00741557612392984 -0.0230756826573066 0.0036564066619003 ...
        0.0313084484795595 -0.0251904319481394 -0.0312409988929008 ...
        0.0603106121368152 0.0113093449240218 -0.123157973123648 ...
        0.0804913546299716 0.504575052876543 0.504575052876543 ...
        0.0804913546299716 -0.123157973123648 0.0113093449240218 ...
        0.0603106121368152 -0.0312409988929008 -0.0251904319481394 ...
        0.0313084484795595 0.0036564066619003 -0.0230756826573066 ...
        0.00741557612392984 0.0127957342348494 -0.0106271067941106 ...
        -0.00424134299374383 0.00904482736125161 -0.000973823303702763 ...
        -0.00559341294408928 0.00296382463947962 0.00235865831066704 ...
        -0.00281487955468693 -0.000308488047070515 0.00178936960227078 ...
        -0.000517957050024124 -0.00078838700546167 0.000564432253766747 ...
        0.000189032588655167 -0.000327177939083541 2.73549411403662e-05 ...
        0.000114506520497387 -3.98938605037357e-05 -1.6980170847524e-05];
end



% [EOF]
