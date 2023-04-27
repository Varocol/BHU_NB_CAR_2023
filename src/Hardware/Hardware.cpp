#include "Hardware.h"

/**
 * @brief  硬件初始化
 * @param  None
 * @retval None
 */
void Hardware_Init()
{
    Serial_Init();
    Servo_Init();
}