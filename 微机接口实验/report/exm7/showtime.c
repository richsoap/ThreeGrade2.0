#include <stdio.h>
#include "time.h"
#include "i2c.h"
void main() {
  int i;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  i2c_init();
  uart0_init();
  TI0 = 1;
  SI = 0;
  EIE1 |= 0x02;
  EA = 1;
  smb_transmit(0,0);
  smb_receive(1);
  if (smb_buf[1] & 0x80) {
    unsigned char b = smb_buf[1];
    smb_buf[2] = b & 0x7F;
    smb_transmit(0,1);
  }
  while(1) {
    smb_transmit(0,0);
    smb_receiver(8);
    delay(100);
    for (i = 0;i < 8;i ++) {
      printf("%02bx", smb_buf[i+1]);
    }
    printf("\r\n");
  }
}
