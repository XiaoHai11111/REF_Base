#include "led_base.h"

void LedBase::Tick(uint32_t _timeElapseMillis, uint8_t _state)
{
    timer += _timeElapseMillis;

    switch (_state)
    {
        case 0:
            heartBeatEnable = true;
            break;
        case 1:
            heartBeatEnable = true;
            break;
    }

    if (heartBeatEnable)
    {
        switch (heartBeatPhase)
        {
            case 1:
                if (timer - timerHeartBeat > 1000)
                {
                    SetLedState(0, false);
                    timerHeartBeat = timer;
                    heartBeatPhase = 2;
                }
                break;
            case 2:
                if (timer - timerHeartBeat > 10000)
                {
                    SetLedState(0, true);
                    timerHeartBeat = timer;
                    heartBeatPhase = 3;
                }
                break;
            case 3:
                if (timer - timerHeartBeat > 1000)
                {
                    SetLedState(0, true);
                    timerHeartBeat = timer;
                    heartBeatPhase = 1;
                }
                break;
        }
    } else
    {
        SetLedState(0, false);
        heartBeatPhase = 1;
    }
}


