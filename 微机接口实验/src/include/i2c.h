#ifndef I2C_H
#define I2C_H
#include "time.h"
void i2c_init() {
  XBR0 = 0x05;
  XBR2 = 0x40;
  P0MDOUT = |= 0x01;
  SMB0CN = 0x07;
  SMB0CR = 257 - (SYSCLK / (2*I2CCLK));
  ST0 = 0;
}
char smb_buf[] = char [256];
int smb_len;
void smbus_int(void) interrupt 7 {
  bit FAIL = 0;
  static unsigned char i;
  switch(SMB0STA) {
    case SMB_START:
    case SMB_RP_START:
    SMB0DAT = smb_buf[0];
    STA = 0;
    i = 0;
    break;
    case SMB_MTADDACK:
    SMB0DAT = smb_buf[1];
    break;
    case SMB_MTDBACK:
    if(i < smb_len) {
      SMB0DAT = smb_buf[i+2];
      i ++;
    }
    else {
      result = S_OVER;
      ST0 = 1;
    }
    break;
    case SMB_MRADDACK:
    if(smb_len == 1)
    AA = 0;
    else
    AA = 1;
    break;
    case SMB_MRDBACK:
    if(i < smb_len) {
      smb_buf[i+1] = SMB0DAT;
      i ++;
      AA = 1;
    }
    if(i >= smb_len)
    AA = 0;
    break;
    case SMB_MRDBNACK:
    smb_buf[i+1] = SMB0DAT;
    ST0 = 1;
    AA = 1;
    result = R_OVER;
    break;
    case SMB_MTADDNACK:
    case SMB_MTDBNACK:
    case SMB_MTARBLOST:
    case SMB_MRADDNACK:
    FAIL = 1;
    break;
    default:
    FAIL = 1;
  }
  if(FAIL) {
    SMB0CN &= -0x40;
    SMB0CN |= 0x40;
    STA = 0;
    ST0 = 0;
    AA = 0;
    result = SMB_FAIL;
    FAIL = 0;
  }
  SI = 0;
}

void smb_transmit(unsigned char addr, unsigned char len, unsigned char* buf) {
  int i = 0;
  result = 0;
  smb_buf[0] = 0xD0;
  smb_buf[1] = addr;
  smb_len = len;
  for(i = 0;i < len;i ++)
    smb_buf[i+2] = buf[i];
  ST0 = 0;
  STA = 1;
  while(result == 0);
  delay(100);
}

void smb_receive(unsigned char len, unsigned char* buf) {
  int i = 0;
  result = 0;
  smb_buf[0] = 0xD1;
  smb_len = len;
  ST0 = 0;
  STA = 1;
  while(result == 0);
  for(i = 0;i < len;i ++)
    buf[i] = smb_buf[i+1];
  delay(100);
}
#endif
