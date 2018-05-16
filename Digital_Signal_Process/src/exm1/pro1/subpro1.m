input_data = [0, 3, 5, 7, 9, 8, 1, 2, 4, 6];
input_length = length(input_data);
dft_data = my_dft(input_data);
index_x = linspace(1, input_length, input_length);
subplot(1,2,1);
stem(index_x, abs(dft_data));
xlabel('k');
ylabel('Amp');
title('X（K）幅度谱')
subplot(1,2,2);
stem(index_x, phase(dft_data));
xlabel('k');
ylabel('Phase');
title('X（K）相位谱')