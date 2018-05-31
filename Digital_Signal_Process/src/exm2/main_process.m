% input data
%testdata = [1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1];
testdata = get_bits(10000);
fre = 21;
Eb0 = -100;


octdata = bit2oct(testdata);
testdata = oct2bit(octdata,100 * 3);
pskdata = psk(octdata, fre);
updata = upsample(pskdata,8);
filter = filter_6_12_16();
senddata = filting(updata, filter);
% add noise
awgndata = awgn(senddata, Eb0 + 10*log10(3) - 10*log10(1/fre),'measured');
%awgndata = updata;
% filter
%receivedata = awgndata;
receivedata = filting(senddata, filter);
downdata = downsample(receivedata,8);
downdata = downdata / max(downdata);
pskresult = unpsk(downdata,length(octdata), fre);
bitdata = oct2bit(pskresult, length(testdata));
equ = bitdata == testdata;
bit_error = 1-sum(equ) / length(equ)
%figure
%subplot(2,2,1);
%plot(pskdata);
%subplot(2,2,2);
%plot(updata);
%subplot(2,2,3);
%plot(pskresult)
%subplot(2,2,4);
%plot(downdata);