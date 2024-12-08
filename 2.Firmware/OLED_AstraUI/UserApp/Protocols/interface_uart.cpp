#include "common_inc.h"

extern Led led;

void OnUartCmd(uint8_t* _data, uint16_t _len)
{
    float cur, pos, vel, led_id, led_status;
    int ret = 0;
    switch (_data[0])
    {
        case 'c':
            ret = sscanf((char*) _data, "c %f", &cur);
            if (ret < 1)
            {
                printf("[error] Command_c format error!\r\n");
            } else if (ret == 1)
            {
                printf("[success]Current:%f\r\n", cur);
            }
            break;
        case 'v':
            ret = sscanf((char*) _data, "v %f", &vel);
            if (ret < 1)
            {
                printf("[error] Command_v format error!\r\n");
            } else if (ret == 1)
            {
                printf("[success]Velocity:%f\r\n", vel);
            }
            break;
        case 'p':
            ret = sscanf((char*) _data, "p %f", &pos);
            if (ret < 1)
            {
                printf("[error] Command_p format error!\r\n");
            } else if (ret == 1)
            {
                printf("[success]Position:%f\r\n", pos);
            }
            break;
    }
}

