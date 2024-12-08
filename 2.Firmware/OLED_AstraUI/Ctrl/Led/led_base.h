#ifndef CTRL_STEP_FW_LED_BASE_H
#define CTRL_STEP_FW_LED_BASE_H

#include <cstdint>

class LedBase
{
public:
    LedBase()
    = default;

    void Tick(uint32_t _timeElapseMillis, uint8_t _state);

private:
    uint32_t timer = 0;
    uint32_t timerHeartBeat = 0;
    bool heartBeatEnable = false;
    uint8_t heartBeatPhase = 1;

    virtual void SetLedState(uint8_t _id, bool _state) = 0;
};


#endif
