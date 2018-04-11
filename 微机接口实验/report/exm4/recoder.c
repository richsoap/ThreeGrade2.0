#include <C8051F020.h>
#include "../include/time.h"
#include "../include/adc.h"
#ifndef SYSCLK
#define SYSCLK 22118400
#endif
#define SAMPLERATE 8000
#define STATE_REC 1
#define STATE_PLAY 2
#define BUF_LEN 16384
unsigned int xdata buf[BUF_LEN] _at_ (0)
unsigned int point;
unsigned int state;

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  state = STATE_REC;
  point = 0;
  dac1_init();
  AMX0SL = 0x01;
  adc0_init(SYSCLK/2500000);
  int4_init(SYSCLK/SAMPLERATE);
  int3_init(SYSCLK/SAMPLERATE);
  EIE2 |= 0x02;
  EA = 1;
  while(1);
}

void timer4_int(void) interrupt 16 {
  if(state == STATE_PLAY) {
    DAC1L = buf[point++];
    DAC1H = buf[point++];
    if(point == BUF_LEN){
      point = 0;
      state = STATE_REC;
    }
  }
  T4CON &= ~0x80;
}

void timer3_int(void) interrupt 15 {
  if(state == STATE_REC) {
      buf[point++] = ADC0L;
      buf[point++] = ADC0H;
      if(point == BUF_LEN) {
        point = 0;
        state = STATE_PLAY;
      }
  }
}
