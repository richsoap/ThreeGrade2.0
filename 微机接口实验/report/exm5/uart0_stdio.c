#include <C8051F020.h>
#include <stdio.h>
#include "../../includes/communicate.h"
#include "../../includes/time.h"

int main() {
  int a,c,result;
  char b;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  uart0_port_init();
  uart0_init();
  TI0 = 1;
  printf("Enter number cacu number\n");
  while(1) {
    if(scanf("%d %c %d",&a,&b,&c)) {
      switch(b) {
        case '+' :
		result = a+c; 
        break;
        case '-':
		result = a-c;
        break;
        case '*':
		result = a*c;
        break;
        case '/':
		result = a/c;
        break;
		default:
		result = -1;
      }
	  printf("\r\n=%d \r\n",result);
    }
  }
}
