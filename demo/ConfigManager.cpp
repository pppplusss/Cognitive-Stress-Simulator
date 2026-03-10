#include "ConfigManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

SystemConfig ConfigManager::load_from_file(const std::string& filename) {
    SystemConfig config = {50.0f, 2.0f, 15.0f, 5}; // 默认值

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "!!! [Warning] Using default config." << std::endl;
        return config;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, ':')) {
            std::string value;
            if (std::getline(is_line, value)) {
                if (key == "pfc_threshold") config.threshold = std::stof(value);
                else if (key == "sensitivity") config.sensitivity = std::stof(value);
                else if (key == "energy_recovery") config.recovery = std::stof(value);
            }
        }
    }
    file.close();
    std::cout << ">>> [System] Config loaded from " << filename << std::endl;
    return config;
}