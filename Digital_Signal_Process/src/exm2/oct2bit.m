function [ outputdata ] = oct2bit( inputdata, outputlength )
%OCT2BIT trans oct data to bit data
%   此处显示详细说明
outputdata = zeros(3,length(inputdata));
outputdata(1,:) = mod(inputdata,2);
inputdata = floor(inputdata/2);
outputdata(2,:) = mod(inputdata,2);
outputdata(3,:) = floor(inputdata/2);
outputdata = reshape(outputdata,[1,3*length(inputdata)]);
outputdata = outputdata(1:outputlength);
end

