#include <C8051F020.h>
#ifndef TIME_H
#define TIME_H

void sysclk_init() {
  int i;
  OSCXCN = 0x67;
  for(i=0;i < 256;i ++);
  while(!(OSCXCN & 0x80));
  OSCICN = 0x88;
}
void int0_init(int delta) {
  EA = 1;
  TMOD |= 0x02;
  TH0 = delta;
  TL0 = 0x00;
  TR0 = 1;
  ET0 = 1;
}

void int1_init(int delta) {
  EA = 1;
  TMOD |= 0x20;
  TH1 = delta;
  TL1 = 0x00;
  TR1 = 1;
  ET1 = 1;
}

void int4_init(int delta) {
  T4CON = 0;
  CKCON |= 0x40;
  RCAP4 = -delta;
  T4 = RCAP4;
  EIE2 |= 0x04;
  T4CON |= 0x04;
}

void delay(int delta) {
  int i, j;
  for(i = 0;i < 500;i ++)
    for(j = 0;j < delta;j ++);
}

#endif
