NeuroGate Algorithm Mapping

NeuroGate 算法结构说明

项目背景 | Project Background

NeuroGate 是一个使用 C++ 编写的类脑认知模拟系统。
该系统尝试模拟高敏感神经系统（HSP）在压力环境下的认知资源分配，以及防御机制（如解离或系统关闭）的触发过程。

NeuroGate is a brain-inspired cognitive simulation system implemented in C++.
The project models how highly sensitive neural systems allocate cognitive resources and activate defensive mechanisms under stress.

该项目将认知科学建模思想与计算机科学中的经典数据结构和算法结合起来。

The system integrates cognitive modeling concepts with classical data structures and algorithms from computer science.

---

核心算法结构 | Core Algorithm Structures

本文件说明 NeuroGate 系统内部使用的主要算法结构以及它们在系统中的作用。

This document explains the major algorithmic structures used in the NeuroGate system and their roles in the architecture.

---

Vector —— 认知历史记录

NeuroGate 使用 "std::vector" 存储认知负载的历史数据。

示例代码：

std::vector<double> cognitive_history;

主要作用：

- 记录每一步模拟中的认知负载
- 存储认知状态变化轨迹
- 为后续统计分析提供数据基础

Vector 的优势：

- 自动扩展内存
- 支持快速随机访问
- 可以配合 STL 算法使用

在认知模型中，这个结构相当于一个“认知能量历史记录区”。

---

Sort —— 认知过载检测

系统使用 "std::sort" 对认知负载数据进行排序，从而检测异常值。

示例代码：

std::sort(cognitive_history.begin(), cognitive_history.end());

作用：

- 找到认知负载的极值
- 识别可能触发解离的负载峰值
- 分析认知能量分布情况

这一机制模拟了神经系统中的“阈值检测”。

---

Queue —— 外部刺激处理

系统使用队列结构处理外部刺激事件。

示例代码：

std::queue<StimulusEvent> eventQueue;

作用：

- 按顺序处理输入刺激
- 模拟有限认知带宽
- 控制信息处理顺序

从算法角度看，这种机制类似 BFS 风格的信息传播结构。

---

FSM —— 认知状态机

NeuroGate 使用有限状态机（FSM）模拟认知状态。

系统状态包括：

NORMAL
IMMERSIVE
DISSOCIATED
SHUTDOWN

状态转换由以下因素决定：

- 认知负载
- 外部刺激强度
- 系统敏感度参数

这种结构可以清晰地描述认知防御机制的触发过程。

---

未来扩展 | Future Extensions

未来版本可能加入更多算法结构，例如：

滑动窗口算法
用于预测短期认知负载变化

图结构
用于模拟记忆网络

优先队列
用于处理不同优先级的刺激

动态规划
用于模拟复杂认知决策路径

---

总结 | Summary

NeuroGate 将经典算法结构与认知模拟系统结合。

该项目既可以作为：

- 一个计算神经科学实验原型
- 一个 C++ 算法实践项目

同时也展示了算法知识在类脑计算系统中的应用。
