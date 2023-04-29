#include "Serial.h"

/**
 * @brief  串口初始化
 * @param  None
 * @retval None
 */
void Serial_Init()
{
    Serial.begin(SERIAL_BAUDRATE);
#ifdef CAR_DEBUG
    Serial.println("[Serial] 串口初始化成功");
#endif
}

void Serial1_Init()
{
    Serial1.begin(SERIAL1_BAUDRATE);
#ifdef CAR_DEBUG
    Serial.println("[Serial1] 串口初始化成功");
#endif
}