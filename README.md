# Cognitive-Stress-Simulator
基于 C++ 的认知压力与解离防御机制模拟系统。通过 FSM 状态机模拟高敏感神经系统在压力下的能量损耗轨迹与自救保护逻辑。A C++ based cognitive stress simulation framework exploring dissociation defense mechanisms and energy depletion patterns in HSP through Finite State Machines.
NeuroGate: 类脑认知仿真与应激防御系统

项目简介
NeuroGate 是一个基于 C++ 开发的轻量级认知神经科学仿真框架。本项目旨在通过计算模型模拟高敏感神经系统（HSP）在持续外部压力下的认知资源分配、能量损耗轨迹以及自动触发的解离（Dissociation）防御机制。
该项目不仅是一个工程实践，更是将心理学理论（如执行功能损耗理论、应激防御模型）转化为可量化、可验证的代码逻辑的尝试。

核心特性
多状态有限自动机 (FSM)：精确模拟从 NORMAL（常态）到 IMMERSIVE（深度投入）再到 DISSOCIATED（解离）的非线性状态切换。
过载保护机制 (Self-Preservation)：内置“强制关机”（SHUTDOWN）逻辑。当认知能量低于阈值时，系统自动拒绝外部输入并触发保护性恢复模式。
动态参数驱动：支持通过外部 config.txt 文件实时调整神经敏感度（Sensitivity）与 PFC 耐受阈值，实现无须重新编译的实验干预。
量化分析输出：自动生成 simulation_report.csv 实验报告，记录每一步的能量波动轨迹，支持导出至 Excel 进行数据可视化。
<img width="2560" height="1368" alt="main1 cpp - c++520 - Visual Studio Code 2026_3_10 23_45_33" src="https://github.com/user-attachments/assets/c3e6bf0d-9584-4cee-bc2d-369ded46a539" />
<img width="2560" height="1368" alt="main1 cpp - c++520 - Visual Studio Code 2026_3_10 23_55_51" src="https://github.com/user-attachments/assets/3dfc01ba-5f01-49ee-bd36-a9a8b4043a6f" />
<img width="2560" height="1368" alt="main1 cpp - c++520 - Visual Studio Code 2026_3_10 23_55_51" src="https://github.com/user-attachments/assets/9254b301-1171-436d-99b5-a7b76a9d750f" />
