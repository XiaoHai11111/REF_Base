#include "common_inc.h"


/* Component Definitions -----------------------------------------------------*/
Button button1(1, 1500);
SSD1306 oled(&hi2c0);
MPU6050 mpu6050(&hi2c1);
Led led;
void OnButton1Event(Button::Event _event);


/* FreeRTOS Task Func -----------------------------------------------------*/
osThreadId_t oledTaskHandle;
void ThreadOledUpdate(void* argument)
{
    for (;;)
    {
        mpu6050.Update(true);

        oled.clearBuffer();
        oled.setFont(u8g2_font_5x8_tr);
        oled.setCursor(0, 10);
        oled.printf("IMU:%.3f/%.3f", mpu6050.data.ax, mpu6050.data.ay);
        oled.setCursor(85, 10);
        oled.printf("| FPS:%lu", 20);

        oled.drawBox(0, 15, 128, 3);
        oled.setCursor(0, 30);
        oled.printf(">%3d|%3d|%3d|%3d|%3d|%3d",2, 3, 4, 5, 6, 7);

        oled.drawBox(40, 35, 128, 24);
        oled.setFont(u8g2_font_6x12_tr);
        oled.setDrawColor(0);
        oled.setCursor(42, 45);
        oled.printf("%4d|%4d|%4d", 3, 5 ,7);
        oled.setCursor(42, 56);
        oled.printf("%4d|%4d|%4d", 3, 5, 7);
        oled.setDrawColor(1);
        oled.setCursor(0, 45);
        oled.printf("[XYZ]:");
        oled.setCursor(0, 56);
        oled.printf("[ABC]:");

        oled.setFont(u8g2_font_10x20_tr);
        oled.setCursor(0, 78);
        oled.printf("[%s] %s", "cmd", "======");

        oled.sendBuffer();
    }
}

/* Main Entry ----------------------------------------------------------------*/
void Main()
{
    uint64_t serialNum = GetSerialNumber();
    printf("SerialNum:%d\r\n",serialNum);

    oled.Init();

    do
    {
      mpu6050.Init();
      osDelay(100);
    } while (!mpu6050.testConnection());
    mpu6050.InitFilter(200, 100, 50);


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
            printf("Button1 Long_Press\r\n");
            break;
        case ButtonBase::CLICK:
            printf("Button1 Click\r\n");
            break;
        case ButtonBase::DOUBLE_CLICK:
            printf("Button1 Double Click\r\n");
            break;
    }
}

