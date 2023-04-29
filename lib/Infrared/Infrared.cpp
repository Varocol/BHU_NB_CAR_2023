#include "Infrared.h"
/**
 * @brief  红外对管初始化
 * @param  None
 * @retval None
 */
void Infrared_Init()
{
    pinMode(Infrared1_Pin, INPUT);
    pinMode(Infrared2_Pin, INPUT);
    pinMode(Infrared3_Pin, INPUT);
    pinMode(Infrared4_Pin, INPUT);
}

/**
 * @brief  红外对管信号获取
 * @param  infrared             红外对管编号
 * @retval 红外对管信号数据
 */
int Infrared_Detect(Infrared infrared)
{
    int pin;
    switch (infrared)
    {
    case Infrared1:
        pin = Infrared1_Pin;
        break;
    case Infrared2:
        pin = Infrared2_Pin;
        break;
    case Infrared3:
        pin = Infrared3_Pin;
        break;
    case Infrared4:
        pin = Infrared4_Pin;
        break;
    }
    return digitalRead(pin);
}