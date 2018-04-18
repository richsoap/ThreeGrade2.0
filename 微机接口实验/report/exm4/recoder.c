#include <C8051F020.h>
#include "../../includes/time.h"
#include "../../includes/adc.h"
#include "../../includes/display.h"
#define SAMPLERATE 8000
#define STATE_REC 1
#define STATE_PLAY 2
//#define BUF_LEN 16384
#define BUF_LEN 16384
unsigned int xdata buf[BUF_LEN] _at_ (0x0000);
unsigned int point;
unsigned int state;

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  state = STATE_REC;
  point = 0;
  dac1_init();
  display_port_init();
  adc0_init(SYSCLK/2500000,0x01);
  int4_init(SYSCLK/SAMPLERATE);
  int3_init(SYSCLK/SAMPLERATE);
  EIE2 |= 0x02;
  EA = 1;
  T4CON &= ~0x04;
  while(1);
}

void timer4_int(void) interrupt 16 {
  if(state == STATE_PLAY) {
    DAC1 = buf[point++];
    if(point >= BUF_LEN){
      point = 0;
      state = STATE_REC;
	  TMR3CN |= 0x04;
	  T4CON &= ~0x04;
    }
  }
  T4CON &= ~0x80;
}

void adc_int(void) interrupt 15 {
	AD0INT = 0;
  	if(state == STATE_REC) {
      buf[point++] = ADC0;
      if(point >= BUF_LEN) {
        point = 0;
        state = STATE_PLAY;
		TMR3CN &= ~0x04;
		T4CON |= 0x04;
      }
  }
}
