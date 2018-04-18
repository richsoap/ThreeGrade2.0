#include <C8051F020.h>
#include "communicate.h"
#include "display.h"
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
  ESO = 1;
  EA = 1;
  TxBuf = "Hello";
  TI0 = 1;
  RxIdx = 0;
  while(1);
}

void uart0_int() interrupt 4 {
  char c;
  if(RI0 == 1) {
    RI0 = 0;
    c = SBUF0;
    RxBuf[RxIdx] = c;
    RxIdx ++;
    RxIdx %= RX_LEN;
  }
  else if(TI0 == 1) {
    TI0 = 0;
    c = *TxBuf;
    if(c != '\0') {
      TxBuf ++;
      SBUF0 = c;
    }
  }
}
