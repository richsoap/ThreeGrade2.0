#include <C8051F020.h>
#include "../include/time.h"
#include "../include/adc.h"
#define SYSCLK 22118400
#define SAMPLERATE 10000

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  dac0_init();
  int4_init(SYSCLK/SAMPLERATE);
  EA = 1;
  while(1);
}

void timer4_int(void) interrupt 16 {
  static unsigned phase = 0;
  DAC0 = phase;
  phase += 0x10;
  T4CON &= ~0x80;
}
