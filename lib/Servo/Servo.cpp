#include "Servo.h"
/**
 * @brief  角度转PWM脉宽
 * @param  angle    转向角
 * @retval PWM脉宽
 */
int Servo_Angle2Pulse(int angle)
{
    angle = angle > CAR_ANGLE_MAX ? CAR_ANGLE_MAX : angle < CAR_ANGLE_MIN ? CAR_ANGLE_MIN
                                                                          : angle;
    return angle * 1.0 * (SERVO_PULSE_MAX - SERVO_PULSE_MIN) / (SERVO_ANGLE_MAX - SERVO_ANGLE_MIN) + SERVO_PULSE_MIN;
}

/**
 * @brief  PWM脉宽转占空比
 * @param  pulse    PWM脉宽
 * @retval PWM占空比
 */
int Servo_Pulse2Duty(int pulse)
{
    return pulse * 1.0 * (1 << SERVO_RESOLUTION) * SERVO_FREQUENCY / 1000000;
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
#ifdef CAR_DEBUG
        Serial.println("[Servo] 舵机初始化失败");
#endif
    }
    else
    {
#ifdef CAR_DEBUG
        Serial.println("[Servo] 舵机初始化成功");
#endif
    }
    // 校正舵机
    Servo_Turn(CAR_ANGLE_MIDDLLE);
}

/**
 * @brief  舵机转向
 * @param  angle    转向角
 * @retval None
 */
void Servo_Turn(int angle)
{
    Servo_Start();
    ledcWrite(SERVO_CHANNEL, Servo_Pulse2Duty(Servo_Angle2Pulse(angle)));
#ifdef CAR_DEBUG
    Serial.printf("[Servo] Servo turn %d°.\n", angle);
#endif
}

/**
 * @brief  舵机开启
 * @param  None
 * @retval None
 */
void Servo_Start()
{
    ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
}

/**
 * @brief  舵机停止
 * @param  None
 * @retval None
 */
void Servo_Stop()
{
    ledcWrite(SERVO_CHANNEL, 0);
    ledcDetachPin(SERVO_PIN);
#ifdef CAR_DEBUG
    Serial.println("[Servo] Servo Stoped.");
#endif
}