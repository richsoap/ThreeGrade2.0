#ifndef STORAGE_H
#define STORAGE_H
void storage_port_init() {
  EMIOCF = 0x1F;
  XBR2 = 0x42;
  P0MDOUT = 0xC0;
  P1MDOUT = 0xFF;
  P2MDOUT = 0xFF;
  P3MDOUT = 0xFF;
}
#endif
