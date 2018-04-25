#include "time.h"
void SPI_init(int spiclk) {
  XBR0 = 0x06;
  XBR2 = 0x40;
  P0MDOUT |= 0x15;
  P74OUT = 0x20;
  SPI0CFG = 0x07;
  SPI0CN = 0x03;
  SPI0CKR = SYSCLK/2/spiclk;
}

unsigned char SPI_write(unsigned char v) {
  SPIF = 0;
  SPI0DAT = v;
  while(SPIF == 0);
  return SPI0DAT;
}
