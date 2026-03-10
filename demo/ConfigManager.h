#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>

struct SystemConfig {
    float threshold;
    float sensitivity;
    float recovery;
    int memory_size;
};

class ConfigManager {
public:
    static SystemConfig load_from_file(const std::string& filename);
};

#endif