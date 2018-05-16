function [ output ] = line_conv( input1, input2)
%LINE_CONV line_conv
%  richsoap 2018.4.2
data_length = length(input1) - 1;
data_zero = zeros(1, data_length);
x1 = [input1, data_zero];
x2 = [input2, data_zero];
output = cir_conv(x1,x2);
end

