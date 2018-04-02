x_n = @(n) (n+1).*(0<=n&n<=13)+(27-n).*(14<=n&n<=26);
index_short = linspace(0,15,16);
index_long = linspace(0,31,32);
index_src = linspace(0,26,27);
data_src = x_n(index_src);
fft_short = fft(data_src, 16);
fft_long = fft(data_src, 32);
ifft_short = ifft(fft_short,27);
ifft_long = ifft(fft_long,27);
%%%%
subplot(2,2,1);
stem(index_short, abs(fft_short));
xlabel('k');
ylabel('Amp');
title('16点fft幅度谱');
%%%%
subplot(2,2,2);
stem(index_long, abs(fft_long));
xlabel('k');
ylabel('Amp');
title('32点fft幅度谱');
%%%%
subplot(2,2,3);
stem(index_src, abs(ifft_short),'b');
hold on;
stem(index_src, data_src, 'r');
xlabel('k');
ylabel('Amp');
title('16点还原图');
xlim([0 26]);
legend('还原信号','原始信号');
%%%%
subplot(2,2,4);
stem(index_src, abs(ifft_long));
hold on;
stem(index_src, data_src, 'r');
xlabel('k');
ylabel('Amp');
title('32点还原图');
xlim([0 26]);
legend('还原信号','原始信号');
%%%%