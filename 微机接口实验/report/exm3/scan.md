# 实验三 键盘与现实
<div style="text-align:center">实验人:杨庆龙<br/>实验日期:2018.3.28</div>

## 实验目的
1. 了解键盘扫描的原理
2. 了解扫描显示的原理
3. 了解总线扩展外设的原理
## 实验原理
### 交叉开关
C8051F020可以将各种外设管脚按照一个优先级顺序映射到特定的IO端口上，此时这些接口就成了特殊的IO端口。可以通过XBR0，XBR1和XBR2寄存器进行设置。其中，外设优先级是上端最高，而端口优先级是左边最高。
### MCS-51外部总线接口
当片上内存不够时，就必须通过外部总线扩展提供更多的数据存储器。可以使用A[15:8]由P2驱动，AD[7:0]由P0驱动，并在ALE的上升沿将其锁存。
### 扫描显示
开发板上有两个373锁存器，驱动了四个共阳极的数码管，其中一个373驱动数码管的四个阳极，另外一个用来驱动四个数码管的阴极。
### 矩阵键盘
#### 扫描法
先使行/列输出低电平，然后判断列/行状态，不为高电平的列即为按下的列。
#### 线反转法
第一步把列线置为低电平，行置为高电平，然后读行状态。第二步与第一步相反，然后读列状态。通过两次读入结果判断按下按键即可。行线列线分别占用P4的高四位和低四位。
## 实验内容
### 键盘显示联调
* 初始状态显示全暗
* 输入按键的内容显示在最右边的数码管上
* 输入新内容时，数码管上原有的内容左移一位
* 主义判断单次按键的逻辑
### 设计数码电子表
#### 基础要求
* 显示分秒计数，均为60进制
* 可以设置电子表的显示值并继续技术
#### 附加要求
* 可以按键切换现实时分/分秒两种模式
* 可以有秒表功能：清零，暂停，继续，恢复时钟模式
* 其他可扩展功能
## 源码
### 数字显示
```
#include <C8051F020.h>
#include <time.h>
#include <display.h>
#include <keyborad.h>

unsigned int shownumber[] = {16, 16, 16, 16};//4 numbers to show

void main(void) {
  uchar nowkey;
  uchar prekey;
  WDTCN = 0xDE;
  WDTCN =0xAD;
  sysclk_init();
  display_port_init();
  int0_init();
  prekey = NOKEY;
  while(1) {
    nowkey = getKey();
    if(nowkey != NOKEY && prekey != nowkey) {
      shownumber[3] = shownumber[2];
      shownumber[2] = shownumber[1];
      shownumber[1] = shownumber[0];
      shownumber[0] = nowkey;
    }
    prekey = nowkey;
    delay(300);
  }
}

void timer_int(void) interrupt 1 {
  static int count;
  count = (count + 1) % 4;
  digital_number = digital_trans[count];
  digital_selecte = digital_index[count];
}
```
### 设计数码电子表//
```
#include <C8051F020.h>
#include "time.h"
#include "display.h"
#include "keyboard.h"
#define RUNCLOCK 0
#define SETCLOCK 1

const unsigned char limits = {0x0A, 0x06, 0x0A, 0x06};

unsigned char* show_number;
unsigned char clock_number = {0, 0, 0, 0, 0, 0};
//0:sl,1:sh,2:ml,3:mh,4:hl,5:hh
unsigned char stopwatch_number = {0, 0, 0, 0};
//0:sl,1:sh,2:ml,3:mh
int state;
int setclock_choice;
int setclock_isshow;

void main(void) {
  uchar nowkey;
  uchar prekey;
  state = RUNCLOCK;
  prekey = NOKEY;
  show_number = clock_number;
  WDTCN = 0xDE;
  WDTCN =0xAD;
  sysclk_init();
  display_port_init();
  int0_init();
  while(1) {
    nowkey = getKey();
    if(nowkey != NOKEY && prekey != nowkey) {
      switch(state) {
        case(RUNCLOCK):
          onrunclock(nowkey);
          break;
        case(SETCLOCK):
          onsetclock(nowkey);
          break;
      }
    }
    prekey = nowkey;
    delay(300);
  }
}

void set_number_at(int _index, unsigned char _value) {
  switch(_index) {
    case 0:
    case 1:
    case 2:
    case 3:
    clock_number[_index] = _value < limits[_index]? _value : clock_number[_index];
    break;
    case 4:
    clock_number[4] = (clock_number[5] == 2 && _value < 0x04) || (clock_number[5] < 2 && _value < 0x0A)? _value : clock_number[4];
    break;
    case 5:
    clock_number[5] = (clock_number[4] < 4 && _value < 0x03) || (_value < 0x02) ? _value : clock_number[5];
    break;
    default:
  }
}

void onrunclock(unsigned char key) {
  switch(key) {
    case(0x0A):
    state = SETCLOCK;
    setclock_choice = 0;
    setclock_isshow = 0;
    break;
    case(0x0B):
    show_number = show_number == lock_number?clock_number+2:clock_number;//change from mm:ss mode to hh:mm mode
    break;
  }
}

void onsetclock(unsigned char key) {
  switch(key) {
    case(0x0A):
    state = RUNCLOCK;
    break;
    case(0x0C):
    setclock_choice = (setclock_choice + 1) % 4;
    break;
    case(0x0F):
    setclock_choice = (setclock_choice + 3) % 4;
    break;
    default:
    if(show_number == clock_number)
      set_number_at(setclock_choice, key);
    else
      set_number_at(setclock_choice + 2,key);
  }
}
void main_timer_int(void) interrupt 1 {
  //todo: add time
  //todo: refresh time
  static int clock_count = 0;
  static int display_count = 0;
  static int display_index = 0;
  static int stopwatch_count = 0;
  clock_count ++;
  //state for clock
  switch(state) {
    case RUNCLOCK:
    if(7200 <= clock_count) {
      clock_count = 0;
      clock_number[0] ++;
      clock_number[1] = clock_number[0] == 0x0A? clock_number[1] + 1:clock_number[1];
      clock_number[0] = clock_number[0] == 0x0A? 0: clock_number[0];
      clock_number[2] = clock_number[1] == 0x06? clock_number[2] + 1:clock_number[2];
      clock_number[1] = clock_number[1] == 0x06? 0: clock_number[1];
      clock_number[3] = clock_number[2] == 0x0A? clock_number[3] + 1:clock_number[3];
      clock_number[2] = clock_number[2] == 0x0A? 0: clock_number[2];
      clock_number[4] = clock_number[3] == 0x06? clock_number[4] + 1:clock_number[4];
      clock_number[3] = clock_number[3] == 0x06? 0: clock_number[3];
      clock_number[5] = clock_number[4] == 0x0A? clock_number[5] + 1:clock_number[5];
      clock_number[4] = clock_number[4] == 0x0A? 0: clock_number[4];
      if(clock_count[4] == 0x04 && clock_count[5] == 0x02) {
        clock_count[4] = 0x00;
        clock_count[5] = 0x00;
      }
    }
    break;
    case SETCLOCK:
      setclock_isshow = clock_count % 3600 == 0 ? (setclock_isshow + 1) % 2;
      clock_count = clock_count >= 7200? 0: clock_count;
      break;
    default:
  }
  display_count ++;
  if(24 <= display_count) {
    display_count = 0;
    display_index = (display_index + 1) % 4;
    switch(state) {
      case RUNCLOCK:
      digital_number = digital_trans[show_number[display_index]];
      digital_selecte = digital_index[display_index];
      break;
      case SETCLOCK:
      digital_number = setclock_isshow? digital_trans[show_number[display_index]] : digital_trans[16];
      digital_selecte = digital_index[display_index];
      break;
      default:
    }
  }
}
```
