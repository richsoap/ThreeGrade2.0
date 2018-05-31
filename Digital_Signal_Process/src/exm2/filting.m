function [ output_args ] = filting(inputdata, filter)
%FILTING 此处显示有关此函数的摘要
%   此处显示详细说明
convdata = conv(inputdata, filter);
len = length(filter);
output_args = convdata(round(len/2):(length(convdata)-(len-round(len/2))));

end

