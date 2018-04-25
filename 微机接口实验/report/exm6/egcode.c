#include <C8051F020.h>
#include <stdio.h>
#include "time.h"
#include "SPI.h"
#include "communicate.h"

void main() {
  unsigned char v;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  P6 = 0x80;
  uart0_init();
  spi_init();
  delay(1000)l
  P6 = 0x00;
  delay(1);
  spi_write(0x9F);
  v = spi_write(0x00);
  printf("Manufacturer ID: %bx\r\n",v);
  v = spi_write(0x00);
  printf("Memory Type ID: %bx\r\n", v);
  v = spi_write(0x00);
  printf("Capacity ID: %bx\r\n", v);
  delay(1);
  P6 = 0x80;
  while(1);
}
