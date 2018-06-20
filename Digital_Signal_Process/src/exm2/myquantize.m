function [ outputdata ] = myquantize( inputdata )
%OCT2BIT trans oct data to bit data
%   此处显示详细说明
outputdata = zeros(8,length(inputdata));
for i = 1:8
    outputdata(i,:) = mod(inputdata,2);
    inputdata = floor(inputdata/2);
outputdata = reshape(outputdata,[1,8*length(inputdata)]);

end

