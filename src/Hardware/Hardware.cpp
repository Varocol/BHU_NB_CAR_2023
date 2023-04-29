#include "Hardware.h"

/**
 * @brief  硬件初始化
 * @param  None
 * @retval None
 */
void Hardware_Init()
{
    Serial_Init();
    Serial1_Init();
    Motor_Init();
    Infrared_Init();
}