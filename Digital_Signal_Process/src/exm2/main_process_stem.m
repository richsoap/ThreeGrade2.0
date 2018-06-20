datalength = 2100;
testdata = get_bits(datalength);
fre = 8; % Fs for PSK data
Eb0 = 14; % Eb0 for awgn channel
SNR = Eb0 + 10*log10(3) - 10*log10(fre*8);

figure
stem(linspace(1,datalength,datalength), testdata);%plot1

octdata = bit2oct(testdata); % transform bit data to oct data, so that make it easier to 8psk
pskdata = psk(octdata, fre); % 8psk modulation
updata = upsample(pskdata,8); % upsample psk data

figure%plot2
stem(linspace(1,datalength/3*fre,datalength/3*fre),pskdata)
figure%plot3
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),updata)

filter = filter_6_8_24();
senddata = filting(updata, filter); % send low pass filting

figure%plot4
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),senddata)

awgndata = awgn(senddata, SNR,'measured');

figure%plot5
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),awgndata)
hold on 
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),senddata)
legend('AWGN后','AWGN前')

receivedata = filting(awgndata, filter); % receive low pass filting

figure%plot6
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),receivedata)
hold on
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),awgndata)
hold on 
stem(linspace(1,datalength/3*fre*8,datalength/3*fre*8),senddata)
legend('滤波后','AWGN后','AWGN前')

figure%plot7
histogram(receivedata,30)
hold on
x = linspace(-1,1,100);
plot(x,6000*gaussmf(x,[0.23 0]))

downdata = downsample(receivedata,8); % downsample psk data
downdata = downdata / max(downdata); % normalization

pskresult = unpsk(downdata,length(octdata), fre, 1); % 8psk demodulation
bitdata = oct2bit(pskresult, length(testdata)); % transform oct data back to bit data

figure%plot8
stem(linspace(1,datalength,datalength),bitdata)
hold on
stem(linspace(1,datalength,datalength),testdata)
legend('输入信号','输出信号')

equ = bitdata == testdata;
bit_error = 1-sum(equ) / length(equ) % caculate ber
