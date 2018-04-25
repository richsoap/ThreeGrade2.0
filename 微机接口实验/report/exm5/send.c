<<<<<<< HEAD
#include <C8051F020.h>
#include "../../includes/time.h"
#include "../../includes/communicate.h"
void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  while (1) {
    SBUF0 = 0x55;//0x8A
    while(!TI0);
    TI0 = 0;
  }
}
=======
#include <C8051F020.h>
#include "../../include/communicate.h"
void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  while (1) {
    SBUF0 = 0x8A;
    while(!TI0);
    TI0 = 0;
  }
}
>>>>>>> 39c049beb19b1056eb1ee906be3afdf5f37b94bf
