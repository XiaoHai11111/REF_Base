//
// Created by 24302 on 2024/12/4.
//

#ifndef OLED_RTOS_DEMO_FREERTOS_INC_H
#define OLED_RTOS_DEMO_FREERTOS_INC_H

#ifdef __cplusplus
extern "C" {
#endif
// List of Tasks
/*---------------------------------- User Tasks --------------------------------------*/
extern osThreadId_t oledTaskHandle;         // Usage: 4000 Bytes stack
/*---------------- 60K (used) / 64K (for FreeRTOS on ccram) ------------------*/


#ifdef __cplusplus
}
#endif

#endif //OLED_RTOS_DEMO_FREERTOS_INC_H
