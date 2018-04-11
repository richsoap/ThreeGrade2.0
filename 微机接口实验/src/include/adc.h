#ifndef ADC_H
#define ADC_H

sfr16 DAC0 = 0xD2;
sfr16 ADC0 = 0xBE;

void dac0_init() {
  REF0CN = 0x03;
  DAC0CN = 0x97;//使用Timer4作为触发,左对齐
}
void adc0_init(int clock) {
  ADC0CN = 0x05; //由TImer3触发，左对齐
  REF0FN = 0x03;
  AMX0SL = 0x00;
  ADC0CF = clock << 3;
  ADC0CF &= ~0x07;
  EIE2 &= ~0x02;
  AD0EN = 1;
}
#endif
