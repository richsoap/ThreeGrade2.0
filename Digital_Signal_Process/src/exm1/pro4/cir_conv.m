function [ output_args ] = cir_conv(input1, input2)
%CIR_CONV 圆周卷积
%   richsoap,2018.3.30
length1 = length(input1);
conv_index = zeros(length1);
conv_index(1,:) = linspace(1,length1,length1);
for i = 1:length1-1
   conv_index(i+1,:) = circshift(conv_index(1,:),i); 
end
input1_mat = input1(conv_index);
output_args = input1_mat' * input2';
end

