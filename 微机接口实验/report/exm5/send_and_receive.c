#include <C8051F020.h>
#include "../../includes/communicate.h"
#include "../../includes/display.h"
#define RX_LEN 20

char RxBuf[RX_LEN];
char * TxBuf;
unsigned char RxIdx;

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  ES0 = 1;
  EA = 1;
  TxBuf = "Hello World";
  TI0 = 1;
  RxIdx = 0;
  while(1);
}

void uart0_int() interrupt 4 {
  static int index = 0;
  char c;
  if(RI0 == 1) {
    RI0 = 0;
	TI0 = 1;
	index = 0;
  }
  else if(TI0 == 1) {
    TI0 = 0;
    c = *(TxBuf+index);
    if(c != '\0') {
      index ++;
      SBUF0 = c;
    }
  }
}
