#include "led_stm32.h"
#include <gpio.h>

void Led::SetLedState(uint8_t _id, bool _state)
{
    switch (_id)
    {
        case 0:
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, _state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        default:
            break;
    }
}

void Led::SetLedState_n(uint8_t _id, bool _state)
{
    switch (_id)
    {
        case 0:
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, _state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        default:
            break;
    }
}
