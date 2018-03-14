# 数字信号处理概述
## 数字信号处理技术
### 研究对象
数字信号:X(n)，不严格区分离散时间信号和数字信号
### 分析方法
* 确定数字信号分析，$Acos(\omega n+\phi)$ 中的每个参数都唯一确定
* 随机数字信号处理，参数随机(有按照概率分布)
### 信号特例
各种信号与系统都适用
## 数字信号与连续时间信号
### 量化
量化误差，均匀量化，非均匀量化（极性码，段落码，段内码），增量量化，增量总和调制，自适应量化
## 数字信号处理方法
* 时域分析
* 转换域分析
* 系统分析
### 实现方法
计算机，微处理器，软件处理
## A/D，D/A
### AD
#### 工作原理
将模拟信号转为数字信号，模拟信号 $x_a(t)$， 采样信号 $\hat{x_a}(t)$，冲激串函数 $p(t)=\sum^\infty_{n=-\infty}\delta(t-nT),\hat{x_a}(t)=p(t)\cdot x_a(t)$
#### 频谱
$$x_a(t)\to X_a(j\Omega)\\
p(t)\to P(j\Omega)=\sum^\infty_{k=-infty}2\pi a_k\delta(\Omega-k\Omega_s),\Omega_s=抽样频率\\
\hat{X_a}(j\Omega)=\frac{1}{T}\sum^\infty_{k=-\infty}X_a(j\Omega-jk\Omega_s)$$
### DA
理想低通滤波器的单位冲激响应 $g(t)=\frac{sin(\pi/T)t}{(\pi/T)t}$

实际工作原理，
$$x(n)=to\hat{x}_a(t)\\
\hat{x}_a(t)\to x_a'(t)\\
平滑滤波->x_a(t877)$$
## 模拟信号的数字滤波
$$x_a(nT)=\frac{1}{w\pi}\int X_a(j\Omega)e^{j\Omega nT}d\omega\\
DTFT:x(n)=\frac{1}{2\pi}\int
X(e^{j\omega})=\frac{1}{t}\sum X_a(j\frac{\omega}{T}+j\frac{2\pi r}{T})\\
X(e^{j\Omega})=\hat{X}_a(j\Omega)|_\Omega=\omega/T\\
\hat{X}_a(s)=X(z)|_e^{sT}$$

## DFT(离散时间)
DFT而看作对有限长序列变换域分析的有线点离散抽样，而且有快速算法，FFT。理论基础是，只要在时域上将信号离散化($T$)，得到的频谱就是周期的($\Omega_s=\frac{2\pi}{T}$)，如果时域是周期的(${T_0}$)，那频谱还是离散的($\Omega_0=\frac{2\pi}{T_0}$)
### 定义
$$W_N=e^{-j\frac{2\pi}{N}}\\
X(k)=DFT[x(n)]=\sum^{N-1}_{n=0}x(n)W_N^{nk},0\leq k\leq N-1\\
x(n)=IDFT[X(k)]=\frac{1}{N}\sum_{k=0}^{N-1}X(k)W_N^{-nk},0\leq k\leq N-1\\
N\to 变换区间长度,n\to 离散时间,k\to 离散频率$$
## DFS(离散时间，离散频率)
$$X(k)=DFS[x(n)]=\sum_{n=0}^{N-1}x(n)W_N^{nk}\\
x(n)=IDFS[X(k)]=\frac{1}{N}\sum_{n=0}^{N-1}X(k)W_N^{-nk}$$
### 对于连续信号的时域离散处理
### 离散时间序列的DTFT
离散谱->周期谱，需要周期化，才有频谱的离散化
## 作业
第三章,离散傅里叶变换 2,3,5,6
