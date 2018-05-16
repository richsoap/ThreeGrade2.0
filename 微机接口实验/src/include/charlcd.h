#ifndef CHARLCD_H
#define CHARLCD_H
#include "time.h"
#define DELAY_LCD 100
char isLcdBusy(void) {
  P5 = 0xFF;
  P6 = 0x82;
  delay(DELAY_LCD);
  P6 = 0x83;
  delay(DELAY_LCD);
  return (P5 & 0x80);
}

void lcd_write_command(unsigned char command) {
  while(isLcdBusy());
  P5 = command;
  P6 = 0x80;
  delay(DELAY_LCD);
  P6 = 0x81;
  delay(DELAY_LCD);
  P6 = 0x80;
}

void lcd_write_data(char data) {
  P5 = data;
  P6 = 0x84;
  delay(DELAY_LCD);
  P6 = 0x85;
  delay(DELAY_LCD);
  P6 = 0x84;
}

void lcd_write_xy_data(unsigned char row, unsigned char column, unsigned char data) {
  while(isLcdBusy());
  if(row == 1)
  column |= 0xC0;
  else
  column |= 0x80;
  lcd_write_command(column);
  lcd_write_data(data);
}
#endif
