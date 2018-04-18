#include <C8051F020.h>
#include "../../includes/time.h"
#include "../../includes/adc.h"
#define SAMPLERATE 10000

unsigned adc_result;

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  adc_result = 0x60;
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
	int i;
	i = 0;
	i ++;
  DAC0 = adc_result;
  T4CON &= ~0x80;
}

void adc_int(void) interrupt 15 {
	int i;
	i = 0;
	i ++;
	AD0INT = 0;
    adc_result = ADC0;
} 



