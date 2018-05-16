function [ result ] = bit2oct( input_args )
%BIT2OCT trans bit sequence to oct bits, so that we can 8PSK more easily
inputlength = length(input_args);
octlength = ceil(inputlength/3);
buffer = zeros(1,octlength * 3);
buffer(1:inputlength) = input_args;
buffer = reshape(buffer,[3,octlength]);
result = buffer(1,:) + buffer(2,:) .* 2 + buffer(3,:) .* 4;
end
