1. 功能：通过USART1（DMA）和按键控制LED的亮灭

2. 实验现象：

   - 当串口以文本的格式发送命令
     - L00,00：LED0 灭
     - L00,01：LED0 亮
     - L01,00：LED1 灭
     - L01,01：LED1 亮
     - c10.0：[success]Current:10.0
     - p20.3：[success]Position:20.3
     - v50：[success]Velocity:50
   - 按键控制LED灯亮灭和串口数据打印
     - BUTTON1
       - 长按:串口打印“Button1 LongPress”
       - 短按:串口打印“Button1 Click”
     - BUTTON2
       - 长按:串口打印“Button2 LongPress”
       - 短按:串口打印“Button2 Click”
   
3. CMAKE配置文件

   ```cmake
   include_directories(
           Core/Inc
           Drivers/STM32F4xx_HAL_Driver/Inc
           Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
           Drivers/CMSIS/Device/ST/STM32F4xx/Include
           Drivers/CMSIS/Include
           Ctrl/Led
           Ctrl/Button
           Port/Platform/Retarget
           Port/Platform/Utils
           UserApp
           UserApp/Protocols
   )
   add_definitions(-DUSE_HAL_DRIVER -DSTM32F405xx)
   
   file(GLOB_RECURSE SOURCES
           "startup/*.*"
           "Drivers/*.*"
           "Core/*.*"
           "Ctrl/*.*"
           "Port/*.*"
           "UserApp/*.*"
           )
   ```
   
