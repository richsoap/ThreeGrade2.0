x_a = @(t)sin(2*pi*1*t)+0.5*sin(6*pi*1*t);
src_time = linspace(0,3,10000);
src_wave = x_a(src_time);
hz5_time = linspace(0,3,15);
hz5_wave = x_a(hz5_time);
hz10_time = linspace(0,3,30);
hz10_wave = x_a(hz10_time);
hz15_time = linspace(0,3,45);
hz15_wave = x_a(hz15_time);
%%%%
subplot(1,3,1);
plot(src_time, src_wave, 'b');
xlabel('time');
ylabel('value');
title('5hz');
hold on;
stem(hz5_time, hz5_wave, 'o');
%%%%
subplot(1,3,2);
plot(src_time, src_wave, 'b');
xlabel('time');
ylabel('value');
title('10hz');
hold on;
stem(hz10_time, hz10_wave, 'o');
%%%%
subplot(1,3,3);
plot(src_time, src_wave, 'b');
xlabel('time');
ylabel('value');
title('15hz');
hold on;
stem(hz15_time, hz15_wave, 'o');
