function [ output_args ] = my_idft( input_args )
%MY_DFT 一维IDTF变换
%   输入数据列，输出与原数据列长度相同的数据列
%   richsoap，2018.3.29
W = @(n,N)exp(-1i*2*pi*n/N);
input_size = size(input_args);
if(input_size(1) == 1)
    input_args = input_args';
end
input_length = length(input_args);
data_index = linspace(0, input_length-1, input_length);
exp_mat = -data_index' * data_index;
W_mat = W(exp_mat, input_length);
output_args = W_mat*input_args/input_length;
end
