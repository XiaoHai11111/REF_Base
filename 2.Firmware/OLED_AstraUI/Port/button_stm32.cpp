#include "button_stm32.h"
#include <gpio.h>

bool Button::ReadButtonPinIO(uint8_t _id)
{
    switch (_id)
    {
        case 1:
            return HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_SET;
        default:
            return false;
    }
}
bool Button::IsPressed()
{
    return !ReadButtonPinIO(id);
}
