# 1_basic
## 简介
有CPU，有外设，功能比较简单，但成本低廉
## 哈佛架构
数据空间和程序空间(一般都是只读的)分开
## 堆栈
要注意维护堆栈空间，内部空间还是蛮缺的
## 汇编语言的特点
* 直接控制处理器
* 语法相对死板
* 参考讲义附录的汇编指令
### 提示
第一个实验要用到DJNZ(dec jump not zero)指令
### 使用C语言
* 提高编程效率
* _at_ 关键字定义数据保存位置
* interrupt关键字指定中断号
* 特殊的数据类型

### 调试技巧
* 单步调试
* 查看寄存器，内存变量
* 修改寄存器
* 修改PC指针
* 要有流程图
* 程序格式要规范
* 出现问题要定位
* 软件仿真机？
