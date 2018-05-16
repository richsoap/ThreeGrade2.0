function [ outputdata ] = psk( inputdata, fre )
%PSK 8psk, fre = sample frequency
inputlength = length(inputdata);
outputlength = inputlength * fre;
outputdata = zeros(1,outputlength);
outputdata = outputdata()


end

