#include "common_inc.h"
#include "st_hardware.h"
#include "../Port/button_stm32.h"
#include "../Port/led_stm32.h"
#include <tim.h>
/* Component Definitions -----------------------------------------------------*/
Button button1(1, 1500);
void OnButton1Event(Button::Event _event);
void OnButton2Event(Button::Event _event);
Led led;
/* Main Entry ----------------------------------------------------------------*/
void Main()
{
    uint64_t serialNum = GetSerialNumber();
    printf("SerialNum:%d\r\n",serialNum);

    /*------------- Init peripherals -------------*/
    button1.SetOnEventListener(OnButton1Event);

    /*------- Start Close-Loop Control Tick ------*/
    HAL_Delay(100);
    HAL_TIM_Base_Start_IT(&htim5);
}

/* Event Callbacks -----------------------------------------------------------*/
extern "C" void Tim5Callback100Hz()
{
    __HAL_TIM_CLEAR_IT(&htim5, TIM_IT_UPDATE);
    button1.Tick(10);
    led.Tick(200, 0);
}

void OnButton1Event(Button::Event _event)
{
    switch (_event)
    {
        case ButtonBase::UP:
            break;
        case ButtonBase::DOWN:
            break;
        case ButtonBase::LONG_PRESS:
            printf("Button1 Long_Press\r\n");
            break;
        case ButtonBase::CLICK:
            printf("Button1 Click\r\n");
            break;
    }
}