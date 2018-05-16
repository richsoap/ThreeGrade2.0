% input data
testdata = [1,1,0,0,1,1,1,0,0,1];
octdata = bit2oct(testdata);
pskdata = psk(octdata,10);
updata = upsample(pskdata,8);
% filter
senddata = filt(updata,filter);
% add noise
awgndata = awgn();
% filter
receivedata = filt(awgndata, filter);
downdata = downsample(receivedata);