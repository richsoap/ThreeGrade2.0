#ifndef COMMUNICATE_H
#define COMMUNICATE_H
void uart0_port_init() {
  XBR0 = 0x04;
  XBR2 = 0x40;
  POMDOUT |= 0x01;
}
void uart0_init() {
  SCON0 = 0x50;
  TMOD = 0x20;
  TH1 = -(SYSCLK/BAUDRATE/16/12);
  TR1 = 1;
  PCON |= 0x80;
}

#endif
