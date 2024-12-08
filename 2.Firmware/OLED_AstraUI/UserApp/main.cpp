#include "common_inc.h"
#include "st_hardware.h"
#include <tim.h>
#include "astra_rocket.h"
/* Component Definitions -----------------------------------------------------*/
Button button1(1, 1500);
SSD1306 oled(&hi2c0);
uint8_t button1_event = 0;
void OnButton1Event(Button::Event _event);
Led led;

/* FreeRTOS Task Func -----------------------------------------------------*/
osThreadId_t oledTaskHandle;
void ThreadOledUpdate(void* argument)
{
    for (;;)
    {
        astraCoreUpdate();
    }
}

/* Main Entry ----------------------------------------------------------------*/
void Main()
{
    uint64_t serialNum = GetSerialNumber();
    printf("SerialNum:%d\r\n",serialNum);

    astraCoreInit();
//    astraCoreTest();
    /*------------- Init peripherals -------------*/
    button1.SetOnEventListener(OnButton1Event);

    /*------- Start Close-Loop Control Tick ------*/
    HAL_Delay(100);
    HAL_TIM_Base_Start_IT(&htim5);

    /*------- FreeRTOS Task ------*/
    const osThreadAttr_t oledTask_attributes = {
            .name = "OledTask",
            .stack_size = 2000,
            .priority = (osPriority_t) osPriorityNormal,   // should >= Normal
    };
    oledTaskHandle = osThreadNew(ThreadOledUpdate, nullptr, &oledTask_attributes);

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
            //printf("Button1 Up\r\n");
            break;
        case ButtonBase::DOWN:
            //printf("Button1 Down\r\n");
            break;
        case ButtonBase::LONG_PRESS:
            //printf("Button1 Long_Press\r\n");
            button1_event = 3;
            break;
        case ButtonBase::CLICK:
            button1_event = 1;
            //printf("Button1 Click\r\n");
            break;
        case ButtonBase::DOUBLE_CLICK:
            button1_event = 2;
            //printf("Button1 Double_Click\r\n");
            break;
    }
}

