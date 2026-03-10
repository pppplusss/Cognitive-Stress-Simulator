#ifndef GATEWAY_H
#define GATEWAY_H

#include <string>

// 核心：这里必须加上 SHUTDOWN
enum State { NORMAL, IMMERSIVE, DISSOCIATED, SHUTDOWN }; 

class CognitiveGateway {
public:
    CognitiveGateway(float threshold, float sens);
    void process_signal(float input);
    void rest(float recovery_amount);
    
    float get_energy() const { return energy; }
    State get_state() const { return currentState; }
    std::string get_state_string() const;

private:
    float energy;
    float pfc_threshold;
    float sensitivity;
    State currentState;
};

#endif