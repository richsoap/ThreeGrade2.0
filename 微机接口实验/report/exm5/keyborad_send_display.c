#include <C8051F020.h>
#include "../../includes/communicate.h"
#include "../../includes/keyboard.h"
#include "../../includes/display.h"
#include "../../includes/storage.h"
#define RX_LEN 4
#define EMPTY 255

int RxBuf[RX_LEN];
char TxBuf;
uchar keyResult;

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  storage_port_init();
  int0_init(SYSCLK / 800);
  ES0 = 1;
  EA = 1;
  TxBuf = '\0';
  while(1) {
  	delay(1000);
    keyResult = getKey();
    if(keyResult != NOKEY) {
	    SBUF0 = keyResult + '0';
		keyResult = NOKEY;
		TI0 =1;
	}
  }
}

void uart0_int() interrupt 4 {
  char c;
  if(RI0 == 1) {
    RI0 = 0;
    c = SBUF0;
	c -= '0';
    RxBuf[3] = RxBuf[2];
    RxBuf[2] = RxBuf[1];
    RxBuf[1] = RxBuf[0];
    RxBuf[0] = c;
  }
  else if(TI0 == 1)
  TI0 = 0;
}

void time0_int() interrupt 1 {
  static int index = 0;
  index ++;
  index %= 4;
  digital_selecte = digital_index[index];
  if(RxBuf[index] < 16)
    digital_number = digital_trans[RxBuf[index]];
  else
    digital_number = digital_trans[16];
}
