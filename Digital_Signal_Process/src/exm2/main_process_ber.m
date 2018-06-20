% input data
%testdata = [1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1];
% generate random bit sequence for test
testdata = get_bits(1e6);

testlength = 200;
fre = 8; % Fs for PSK data
Eb0 = linspace(-10,30,testlength); % Eb0 for awgn channel
SNR = Eb0 + 10*log10(3) - 10*log10(fre*8);
SNR_line = 10.^(SNR./10);
theo = qfunc(0.3827.*sqrt(SNR_line));
%theo = exp(-2*SNR*(sin(pi/16)^2));
%theo_best = erfc(sqrt(SNR_line)*sin(pi/8))/3;
theo_best = qfunc(sqrt(2)*sqrt(SNR_line)*sin(pi/3))/4;
berlist = zeros(1,testlength);

octdata = bit2oct(testdata); % transform bit data to oct data, so that make it easier to 8psk
pskdata = psk(octdata, fre); % 8psk modulation
updata = upsample(pskdata,8); % upsample psk data

filter = filter_6_8_24(); % get filter

senddata = filting(updata, filter); % send low pass filting
for i = 1:testlength
awgndata = awgn(senddata, SNR(i),'measured');
%awgndata = awgn(senddata, Eb0(i) + 10*log10(3) - 10*log10(1/fre),'measured');
receivedata = filting(awgndata, filter); % receive low pass filting
downdata = downsample(receivedata,8); % downsample psk data
downdata = downdata / max(downdata); % normalization

downdata_nofilting = downsample(awgndata, 8);
downdata_nofilting = downdata_nofilting / max(downdata_nofilting);

unpsk(downdata_nofilting, length(octdata), fre, 0);
pskresult = unpsk(downdata,length(octdata), fre, 0); % 8psk demodulation
bitdata = oct2bit(pskresult, length(testdata)); % transform oct data back to bit data
equ = bitdata == testdata;
bit_error = 1-sum(equ) / length(equ); % caculate ber
berlist(i) = bit_error;
if mod(i,50) == 0
    i = i
end
end
semilogy(Eb0, (berlist))
hold on;
semilogy(Eb0, (theo))
semilogy(Eb0, (theo_best))
legend('仿真值','理论无滤波','理论最优值')