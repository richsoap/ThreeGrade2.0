function [ out ] = get_bits( length )
%GET_BITS 此处显示有关此函数的摘要
%   此处显示详细说明
out = mod(ceil(rand(1,length)*255),2);

end

