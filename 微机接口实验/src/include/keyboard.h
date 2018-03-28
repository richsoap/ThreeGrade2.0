#include <C8051F020.h>
#ifndef KEYBOARD_H
#define KEYBOARD_H
#define uchar unsigned char
#define NOKEY 255

const uchar code dec[] = {0, 0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0};
const uchar code trans[] = {0xC, 9, 5, 1, 0xD, 0, 6, 2, 0xE, 0xA, 7, 3, 0xF, 0xB, 8, 4};

uchar getKey() {
  uchar i;
  uchar key;
  P4 = 0x0F;
  delay(100);
  i = -P4 & 0x0F;
  if(i == 0)
  return NOKEY;
  key = dec[i] *4;
  delay(1000);
  P4 = 0xF0;
  delay(100);
  i = -P4;
  i >>= 4;
  if(i == 0)
  return NOKEY;
  key = key + dec[i];
  key = trans[key];
  return key;
}

#endif
