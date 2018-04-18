#include <C8051F020.h>
#include "communicate.h"
#include "keyboard.h"
#include "display.h"
#define RX_LEN 4
#define EMPTY 255

char RxBuf[RX_LEN];
char TxBuf;
uchar keyResult;

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  int0_init(SYSCLK / 800);
  ESO = 1;
  EA = 1;
  TxBuf = EMPTY;
  TI0 = 1;
  while(1) {
    keyResult = getKey();
    if(keyResult == NOKEY)
      TxBuf = EMPTY;
    else
      TxBuf = keyResult;
  }
}

void uart0_int() interrupt 4 {
  char c;
  int i;
  if(RI0 == 1) {
    RI0 = 0;
    c = SBUF0;
    RxBuf[3] = RxBuf[2];
    RxBuf[2] = RxBuf[1];
    RxBuf[1] = RxBuf[0];
    RxBuf[0] = c;
  }
  else if(TI0 == 1) {
    TI0 = 0;
    if(TxBuf != EMPTY)
      SBUF0 = TxBuf;
    TxBuf = EMPTY;
  }
}

void time0_int() interrupt 1 {
  static int index = 0;
  index ++;
  digital_selecte = digital_index[index];
  if(RxBuf[index] < 16)
    digital_number = digital_trans[RxBuf[index]];
  else
    digital_number = digital_trans[RxBuf[16]];
}
