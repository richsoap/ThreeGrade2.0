function [ outputdata ] = psk( inputdata,fre)
%PSK 8psk, fre = sample frequency
inputlength = length(inputdata);
outputlength = inputlength * fre;
index = linspace(0.000000001,inputlength,outputlength);
outputdata = sin(2*pi*index + inputdata(ceil(index)) * pi / 4);
end

