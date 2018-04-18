#include <C8051F020.h>
#include <stdio.h>
#include "communicate.h"
#include "time.h"

int main() {
  int a,b,c,result;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  TI0 = 1;
  printf("Enter number cacu number\n");
  while(1) {
    if(scanf("%b %b %b",&a,&b,&c) == 6) {
      switch(b) {
        case '+' : printf("%b\n",a+c);
        break;
        case '-':
        printf("%b\n",a-c);
        break;
        case '*':
        printf("%b\n",a*c);
        break;
        case '/':
        printf("%b\n",a/c);
        break;
      }
    }
  }
}
