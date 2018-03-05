# 0_start
## 老师
王杰
## 书
Cool Math for Hot Music
## 音乐和数学之间的关系
### 2001：
和谐的主旋律：
* C-G：纯五度音程
* G-C’：纯四度音程
### 起源
毕达哥拉斯认为一切均为数
#### 频率比
* 同度1：1
* 八度2：1
* 五度3：2
* 四度4：3
#### 希腊四艺
都是数和数的比较得到的技艺
## 音乐三要素
### 时间形式——节奏
时值的有序组合
#### 名作
春之祭，斯特拉文斯基
#### 问题
记录，比较，标准
#### 解决
引入几何模型，给出度量特征
##### 研究对象：固定节奏
无变化地反复出现，贯穿始终的节奏模式
>古巴颂乐:以16分音符为一拍进行时间单位划分，0010 1000 1001 0010=0x2892，1代表发声(onset),位于2，4，8，11，14。
计算组合数，16拍中取5个onset，共有4306种，

#### 模式比较
* 极大均衡原则：onset分布均匀
> 5in16：非整数，有16种可能,2-3和3-2的古巴颂乐只有相位差

* 节奏奇性：将节奏分布到圆周上，取onset的对径点，都不是onset，这样会显得有节奏感且比较活跃
> 古巴颂乐都不是onset

##### 定义：节奏的影子
* 影子(shadow)：onset之间的不发声的节拍(取中点)，也成为能被感知的节奏，且不一定非要落在节拍上，比如10100100
#### 距离序列(相对时间单位)
两个onset之间的间隔，且可以为非整数，
> 10100100,[2,3,3]其影子的距离序列为[2.5,3,2.5]

##### 定义：节奏的轮廓
人类对于时间间隔的绝对长度的辨别是不行的，只能分辨相对变化
* 轮廓:计算距离序列的变化 $sgn(b_n-b_{n-1}$

> 古巴颂乐的距离[3,3,4,2,4]，另外一个是，12拍的fume-fume的距离为[2,2,3,2,3]，但人类感受相同。轮廓均为[0,+,-，+，-]

* 轮廓同构：A和B的轮廓序列只相差一个左循环移位
> 古巴颂乐和其影子序列的轮廓同构，且是那16个备选节奏中唯一的一个自身和影子轮廓同构

### 音符形式——旋律
中国人几乎只听旋律，也是最容易被听到的要素
#### 重复原则
重复原则是音乐写作的基本要求，但并不是完全重复，要有其他方面的变化。
* 比如小星星的各种变奏

#### 变化方式——移调
* 改变音高，比如南泥湾按照小节严格降低纯五度，春江花月夜第三段，命运交响曲的“当当当，当”
##### 严格移调和调性移调
调式音阶中，需要依据调式进行升降(3331->2227[调性移调].,而不是3331->222b7.[严格移调，超出了调式])