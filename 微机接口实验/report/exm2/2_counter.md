# 实验二 定时器和计数器
<div style="text-align:center">实验人:杨庆龙<br/>实验日期:2018.3.21</div>

## 实验目的
1. 掌握使用C语言进行单片机程序开发，熟悉开发环境
2. 熟悉单片机C语言开发中的特殊语法
3. 了解单片机中的定时器和计数器
4. 了解单片机的中断系统原理和编程方法
## 实验原理
### C51简介
#### 特殊数据类型
1. 位类型(bit):有C51编译器在RAM20H-2FH中的128个位地址中分配一个位地址
2. 特殊功能寄存器(sfr):访问产品的特殊功能寄存器必须采用直接寻址的方式来访问，在头文件中完成相应映射
3. 16为特殊功能寄存器(sfr16):特殊的16位功能寄存器，比如DPTR
4. 可寻址位类型(sbit):可以对8051内部RAM的位寻址空间和特殊功能寄存器的可寻址位进行定义
#### 定义
* data，直接寻址片内RAM
* bdata，直接寻址片内RAM的位和字节
* idata，间接访问片内全部256个地址空间
* pdata，使用MOVX@Ri指令访问外部
* xdata，使用MOVX@DPTR访问外部RAM
* code， 使用MOVC@A+DPTR访问程序存储器
#### 特殊关键字
* \_at\_ 关键字指定具体的存储内容
#### 中断
函数类型 函数名 () [interrupt n] [using n]
### 并行端口
可设置输出方式
### 中断系统
#### IE中断允许
|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|
|总中断||计数器2|串行通信|计数器1|外部中断INT1|计数器0|外部中断INT0|

#### IP中断优先
|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|
|||计数器2|串行口|计数器1|外部中断1|计数器0|外部中断0|

* 同级中断，小号优先级高
* 全局中断是否打开
* 中断是否被允许
* 复位后中断都是禁止的
* 中断控制位普遍为位寻址
* 中断还会有相应的中断标识，比如串口之类
* 中断标志有的是自动清除，有的是手动清除
#### TCON中断控制
|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|
|计数器1溢出|计数器1控制|计数器0溢出|计数器0控制|INT1请求|INT1控制|INT0控制|INT0控制|
#### OSCICN时钟控制器
|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|
|时钟失效检测|||振荡器是否工作在设置频率下|内外振荡器选择|设置内部振荡器状态|设置内部振荡器频率PartA|设置内部振荡器频率PartB|

* 内部自带时钟电路，精度和频率都比较不可靠
* 需要手动设置外部时钟
## 实验内容
### 控制LED闪烁
主板上的LED与CPU的P7端最高位相连，通过控制P7的输出，可以让这个LED闪烁。
### 使用计数器延时
使用计数器0控制LED的闪烁频率为1Hz，为了保证计时精度，使用外部晶振。
### 控制LED亮度
使用PWM技术，控制亮度变化，实现亮暗交替的循环。

## 源码
### 控制LED闪烁
```
#include <C8051F020.h>
void port_init(void) {
  P74OUT = 0x80;
}
void delay() {
  int i,j;
  for(i = 0;i < 500;i ++) {
    for(j = 0;j < 100;j ++);
  }
}
void main(void) {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  port_init();
  while(1) {
    P7 = 0x80;
    delay();
    P7 = 0x00;
    delay();
  }
}
```

### 使用计数器延时
```
void sysclk_init() {
  int i;
  OSCXCN = 0x67;
  for(i=0;i < 256;i ++);
  while(!(OSCXCN & 0x80));
  OSCICN = 0x88;
}

void port_init() {
  P74OUT = 0x80;
}

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  port_init();

  EA = 1;
  TMOD = 0x02;//
  TH0 = 0x00;
  TL0 = 0x00;
  TR0 = 1;//定时器0计数开始
  ET0 = 1;//定时器0允许中断
  P7 = 0x80;
  while(1);
}

void timer_int(void) interrupt 1 {
  static int count = 0;
  count ++;
  if(count > 3600) {
    count = 0;
    P7 = ~P7;
  }
}
```

### 控制LED亮度
```
void sysclk_init() {
  int i;
  OSCXCN = 0x67;
  for(i=0;i < 256;i ++);
  while(!(OSCXCN & 0x80));
  OSCICN = 0x88;
}

void port_init() {
  P74OUT = 0x80;
}

void main() {
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  sysclk_init();
  port_init();

  EA = 1;
  TMOD = 0x02;//
  TH0 = 0x00;
  TL0 = 0x00;
  TR0 = 1;//定时器0计数开始
  ET0 = 1;//定时器0允许中断
  while(1);
}

void timer_int(void) interrupt 1 {
  static int pulsecount;
  static int pulsewidth;
  static int delta = 3;
  pulsecount ++;
  if(pulsecount > 48) {//150Hz
    pulsecount = 0;
    pulsewidth += delta;
    if(pulsewidth <= 0 || pulsewidth >= 24)
      delta = -delta;
  }
  else {
    if(pulsecount <= pulsewidth)
      P7 = 0x80;
    else
      P7 = 0x00;
  }
}
```
