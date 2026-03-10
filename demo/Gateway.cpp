#include "Gateway.h"
#include <iostream>

CognitiveGateway::CognitiveGateway(float threshold, float sens) 
    : energy(100.0f), pfc_threshold(threshold), sensitivity(sens), currentState(NORMAL) {}

void CognitiveGateway::process_signal(float input) {
    // --- 【新增】过载保护逻辑 ---
    // 如果能量低于30，拒绝处理高压信号，转入回血模式
    if (energy < 30.0f) {
        currentState = SHUTDOWN;
        energy += 5.0f; // 强制休息，每步回血5点
        return; 
    }

    // 原有逻辑：计算消耗
    float depletion = input * sensitivity;
    energy -= depletion;

    // 状态切换逻辑
    if (energy <= 0) {
        energy = 0;
        currentState = DISSOCIATED;
    } else if (energy < pfc_threshold) {
        currentState = IMMERSIVE;
    } else {
        currentState = NORMAL;
    }
}

void CognitiveGateway::rest(float recovery_amount) {
    energy += recovery_amount;
    if (energy > 100.0f) energy = 100.0f;
    // 休息后尝试恢复正常状态
    if (energy >= pfc_threshold) currentState = NORMAL;
}

std::string CognitiveGateway::get_state_string() const {
    switch (currentState) {
        case NORMAL: return "NORMAL";
        case IMMERSIVE: return "IMMERSIVE";
        case DISSOCIATED: return "DISSOCIATED";
        case SHUTDOWN: return "SHUTDOWN"; // 【新增】
        default: return "UNKNOWN";
    }
}