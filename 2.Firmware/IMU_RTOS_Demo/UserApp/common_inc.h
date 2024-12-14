#ifndef LOOP_H
#define LOOP_H



#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------- C Scope ---------------------------*/
#include "stdint-gcc.h"
#include "main.h"
#include "st_hardware.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "freertos_inc.h"
#include "tim.h"
#include "i2c.h"

void Main();
void OnUartCmd(uint8_t* _data, uint16_t _len);

#ifdef __cplusplus
}
/*---------------------------- C++ Scope ---------------------------*/
#include <cstdio>
#include "U8g2lib.hpp"
#include "U8g2lib.hpp"
#include "MPU6050.hpp"
#include "../Port/button_stm32.h"
#include "../Port/led_stm32.h"

#endif
#endif
