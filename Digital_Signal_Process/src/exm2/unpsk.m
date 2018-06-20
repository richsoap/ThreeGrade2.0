function [ outputdata ] = unpsk( inputdata, outputlength, fre, showfig)
%UNPSK trans time wave to oct data
%   此处显示详细说明
target = [[1,0];[sqrt(2)/2,sqrt(2)/2];[0,1];[-sqrt(2)/2,sqrt(2)/2];[-1,0];[-sqrt(2)/2,-sqrt(2)/2];[0,-1];[sqrt(2)/2,-sqrt(2)/2]];
index = linspace(0,outputlength, length(inputdata));
sindata = inputdata.*sin(2*pi*index);
cosdata = inputdata.*cos(2*pi*index);
sindata = reshape(sindata, [length(inputdata)/outputlength, outputlength]);
cosdata = reshape(cosdata, [length(inputdata)/outputlength, outputlength]);
sindata = sum(sindata)/fre*2;%get cos(phi)
cosdata = sum(cosdata)/fre*2;%get sin(phi)
result_dis = zeros(1,outputlength);
result_dis(:) = inf;
result = zeros(1, outputlength);
for i = 1:8
    dics = ((sindata-target(i,1)).^2 + (cosdata-target(i,2)).^2);
    indexs = result_dis > dics;
    result(indexs) = i-1;
    result_dis(indexs) = dics(indexs);
end
outputdata = result;
%outputdata = transtable(asindata(index), acosdata(index));    
if showfig == 1
    figure
    plot(sindata, cosdata, '*')
end

end

