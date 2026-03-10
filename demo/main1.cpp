#include <iostream>
#include <fstream>
#include "Gateway.h"
#include "ConfigManager.h"

int main() {
    // 1. 加载配置
    SystemConfig cfg = ConfigManager::load_from_file("config.txt");

    // 2. 初始化核心
    CognitiveGateway myBrain(cfg.threshold, cfg.sensitivity);

    // 3. 实验数据记录
    std::ofstream logger("simulation_report.csv");
    logger << "Step,State,Energy,Input\n";

    std::cout << "--- NeuroGate System Running ---" << std::endl;

    for (int i = 0; i < 20; i++) {
        float input = 10.0f + i * 3.0f; // 模拟压力递增
        
        if (i == 10) myBrain.rest(cfg.recovery); // 中途休息

        myBrain.process_signal(input);

        // 输出到屏幕
        std::cout << "Step " << i << " | State: " << myBrain.get_state_string() 
                  << " | Energy: " << myBrain.get_energy() << std::endl;

        // 写入CSV
        logger << i << "," << myBrain.get_state_string() << "," 
               << myBrain.get_energy() << "," << input << "\n";
    }

    logger.close();
    return 0;
}