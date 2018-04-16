x1 = [1, 3, 5, 3, 6, 8, 3, 9];
x2 = [2, 3, 4, 6, 7, 9, 0, 2];
lx1 = [x1,zeros(1,12)];
lx2 = [x2,zeros(1,12)];
circle_short_result = cir_conv(x1,x2)
circle_long_result = cir_conv(lx1,lx2)
line_result = line_conv(x1, x2)