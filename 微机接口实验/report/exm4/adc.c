#include <C8051F020.h>
#include "../include/time.h"
#include "../include/adc.h"
#include "../include/keyboard.h"

#define SYSCLK 22118400
#define SAMPLERATE 10000

unsigned int adc_result;

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  int3_init(SYSCLK/SAMPLERATE);
  adc0_init(SYSCLK/2500000);
  display_port_init();
  EA = 1;
  EIE2 |= 0x02;
  while(true) {
    unsigned char i;
    unsigned j;
    j = adc_result;
    for(i = 0;i < 4;i ++) {
      digital_number = digital_trans[j & 0xF];
      delay(1);
      digital_selecte = digital_index[i];
      j = j >> 4;
      delay(1000);
    }
  }
}

void adc0_int(void) interrupt 15 {
  static unsigned int count = 0;
  count ++;
  AD0INT = 0;
  if(count >= SAMPLERATE/2) {
    adc_result = ADC0;
    count = 0;
  }
}
