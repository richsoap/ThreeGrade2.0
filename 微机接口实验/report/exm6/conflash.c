#include <C8051F020.h>
#include <stdio.h>
#include "time.h"
#include "SPI.h"
#include "communicate.h"

void main() {
  unsigned char v;
  unsigned char c;
  unsigned int addr;
  unsigned int v1;
  unsigned int v2;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  P6 = 0x80;
  uart0_init();
  spi_init();
  while(1){
    do {
      c = getchar();
    }while((c == '') || (c == '\r') || (c == '\n'));
    scanf("%lx", &addr);
    switch(c) {
      case 'd':
      ///////////////////////
      break;
      case 'w':
      scanf("%bx", &v1);
      flash_write(addr,v1);
      printf("\r\n W %lx %bx OK\r\n",addr,v1);
      break;
      case 'c':
      flash_erease(addr);
      printf("\r\n C %lx OK\r\n",addr);
      break;
    }
  }
}
