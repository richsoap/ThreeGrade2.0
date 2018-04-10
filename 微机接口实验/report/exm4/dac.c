#include <C8051F020.h>
#include "../include/time.h"
#define SYSCLK 22118400
#define SAMPLERATE 10000

void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  
}
