#include "Serial.h"

/**
 * @brief  串口初始化
 * @param  None
 * @retval None
 */
void Serial_Init()
{
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println("串口初始化成功");
}