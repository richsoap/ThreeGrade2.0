inputfilename=''

with open(inputfilename,'r') as inf:
    with open(inputfilename + '.char','w') as outf:
        for lines in inf:
            if lines.find('-') == -1:
                temp = 0
                for i in range(len(lines)):
                    if i != 0 and i % 8 == 0:
                        outf.write(hex(temp))
                        temp = 0
                    temp = temp << 1;
                    temp += int(lines[i])
                outf.write(hex(temp))
                outf.write('/n')
