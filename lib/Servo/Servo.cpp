#include "Servo.h"
/**
 * @brief  角度转PWM脉宽
 * @param  angle    转向角
 * @retval PWM脉宽
 */
int Servo_Angle2Pulse(int angle)
{
    angle = angle > CAR_MAX_ANGLE ? CAR_MAX_ANGLE : angle < CAR_MIN_ANGLE ? CAR_MIN_ANGLE
                                                                          : angle;
    return angle * 1.0 * (SERVO_MAX_PULSE - SERVO_MIN_PULSE) / (SERVO_MAX_ANGLE - SERVO_MIN_ANGLE) + SERVO_MIN_PULSE;
}

/**
 * @brief  PWM脉宽转占空比
 * @param  pulse    PWM脉宽
 * @retval PWM占空比
 */
int Servo_Pulse2Duty(int pulse)
{
    return pulse * (2 << SERVO_RESOLUTION) * SERVO_FREQUENCY / 1000000;
}

/**
 * @brief  舵机初始化
 * @param  None
 * @retval None
 */
void Servo_Init()
{
    if (ledcSetup(SERVO_CHANNEL, SERVO_FREQUENCY, SERVO_RESOLUTION) == 0)
    {
        Serial.println("舵机初始化失败");
    }
    else
    {
        ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
        Serial.println("舵机初始化成功");
    }
}

/**
 * @brief  舵机转向
 * @param  angle    转向角
 * @retval None
 */
void Servo_Turn(int angle)
{
    ledcWrite(SERVO_CHANNEL, Servo_Pulse2Duty(Servo_Angle2Pulse(angle)));
    Serial.printf("Servo turn %d °.\n", angle);
}

/**
 * @brief  舵机停止
 * @param  None
 * @retval None
 */
void Servo_Stop()
{
    ledcWrite(SERVO_CHANNEL, 0);
    Serial.println("Servo Stoped.");
}