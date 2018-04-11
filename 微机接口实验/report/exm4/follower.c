#include <C8051F020.h>
#include "../include/time.h"
#include "../include/adc.h"
#ifndef SYSCLK
#define SYSCLK 22118400
#endif
#define SAMPLERATE 10000

unsigned adc_result;

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  dac0_init();
  adc0_init(SYSCLK/2500000);
  int4_init(SYSCLK/SAMPLERATE);
  int3_init(SYSCLK/SAMPLERATE);
  EIE2 |= 0x02;
  EA = 1;
  while(1);
}

void timer4_int(void) interrupt 16 {
  DAC0 = adc_result;
  T4CON &= ~0x80;
}

void timer3_int(void) interrupt 15 {
    adc_result = ADC0;
}
