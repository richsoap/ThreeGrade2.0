x_a = @(t)sin(2*pi*1*t)+0.5*sin(6*pi*1*t);
src_time = linspace(0,3,1024);
src_index = linspace(0,1023,1024);
src_wave = x_a(src_time);
src_fft = fftshift(fft(src_wave));
hz5_time = linspace(0,3,15);
hz5_index = linspace(0, 14, 15);
hz5_wave = x_a(hz5_time);
hz5_fft = fftshift(fft(hz5_wave));
hz10_time = linspace(0,3,30);
hz10_index = linspace(0, 29, 30);
hz10_wave = x_a(hz10_time);
hz10_fft = fftshift(fft(hz10_wave));
hz15_time = linspace(0,3,45);
hz15_index = linspace(0, 44, 45);
hz15_wave = x_a(hz15_time);
hz15_fft = fftshift(fft(hz15_wave));
%%%%
subplot(2,2,1);
plot(src_index, abs(src_fft));
xlabel('k');
ylabel('Amp');
title('原信号fft幅度谱');
%%%%
subplot(2,2,2);
stem(hz5_index, abs(hz5_fft));
xlabel('k');
ylabel('Amp');
title('5hz信号fft幅度谱');
%%%%
subplot(2,2,3);
stem(hz10_index, abs(hz10_fft));
xlabel('k');
ylabel('Amp');
title('10hz信号fft幅度谱');
%%%%
subplot(2,2,4);
stem(hz15_index, abs(hz15_fft));
xlabel('k');
ylabel('Amp');
title('15hz原信号fft幅度谱');

