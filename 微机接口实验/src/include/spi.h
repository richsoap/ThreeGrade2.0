#include "time.h"
#define SPICLK 2000000
void SPI_init() {
  XBR0 = 0x06;
  XBR2 = 0x40;
  P0MDOUT |= 0x15;
  P74OUT = 0x20;
  SPI0CFG = 0x07;
  SPI0CN = 0x03;
  SPI0CKR = SYSCLK/2/SPICLK;
}

unsigned char SPI_write(unsigned char v) {
  SPIF = 0;
  SPI0DAT = v;
  while(SPIF == 0);
  return SPI0DAT;
}

void flash_write(unsigned long int addr, char value) {
  P6 = 0x00;
  delay(1);
  spi_write(0x06);
  delay(1);
  P6 = 0x80;
  delay(1);
  P6 = 0x00;
  delay(1);
  spi_write(0x02);
  spi_write((addr & 0x00FF0000) >> 16);
  spi_write((addr & 0x0000FF00) >> 8);
  spi_write(addr & 0x00FF);
  spi_write(value);
  delay(1);
  P6 = 0x80;
  delay(1);
  busywait();//?????
}
void flash_erease(unsigned long int addr) {
  P6 = 0x00;
  delay(1);
  spi_write(0x06);
  delay(1);
  P6 = 0x80;
  delay(1);
  P6 = 0x00;
  delay(1);
  spi_write(0x20);
  spi_write((addr & 0x00FF0000) >> 16);
  spi_write((addr & 0x0000FF00) >> 8);
  spi_write(addr & 0x00FF);
  delay(1);
  P6 = 0x80;
  delay(1);
  busywait();//?????????????
}
