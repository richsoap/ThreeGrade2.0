<<<<<<< HEAD
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
=======
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
>>>>>>> 39c049beb19b1056eb1ee906be3afdf5f37b94bf
