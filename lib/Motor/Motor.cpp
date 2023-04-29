#include "Motor.h"
/**
 * @brief  电机初始化
 * @param  None
 * @retval None
 */
void Motor_Init()
{
    // 初始化PWM
    if (ledcSetup(MOTOR_LEFT_CHANNEL_1, MOTOR_FREQUENCY, MOTOR_RESOLUTION) == 0)
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor1] 电机通道1初始化失败");
#endif
    }
    else
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor1] 电机通道1初始化成功");
#endif
    }
    if (ledcSetup(MOTOR_LEFT_CHANNEL_2, MOTOR_FREQUENCY, MOTOR_RESOLUTION) == 0)
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor1] 电机通2初始化失败");
#endif
    }
    else
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor1] 电机通道2初始化成功");
#endif
    }
    if (ledcSetup(MOTOR_RIGHT_CHANNEL_1, MOTOR_FREQUENCY, MOTOR_RESOLUTION) == 0)
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor2] 电机通道1初始化失败");
#endif
    }
    else
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor2] 电机通道1初始化成功");
#endif
    }
    if (ledcSetup(MOTOR_RIGHT_CHANNEL_2, MOTOR_FREQUENCY, MOTOR_RESOLUTION) == 0)
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor2] 电机通道2初始化失败");
#endif
    }
    else
    {
#ifdef CAR_DEBUG
        Serial.println("[Motor2] 电机通道2初始化成功");
#endif
    }
}

/**
 * @brief  速度转占空比
 * @param  speed        电机转速
 * @retval 占空比
 */
int Motor_Speed2Duty(int speed)
{
    speed = speed > MOTOR_SPEED_MAX ? MOTOR_SPEED_MAX : speed < MOTOR_SPEED_MIN ? MOTOR_SPEED_MIN
                                                                                : speed;
    return 1.0 * (speed - MOTOR_SPEED_MIN) * (1 << MOTOR_RESOLUTION) / (MOTOR_SPEED_MAX - MOTOR_SPEED_MIN);
}

/**
 * @brief  设置电机速度
 * @param  motor            电机编号
 * @param  speed            电机转速
 * @retval None
 */
void Motor_Run(Motor motor, int speed)
{
    int channel1, channel2;
    Motor_Start(motor);
    if (motor == Motor_left)
    {
        channel1 = MOTOR_LEFT_CHANNEL_1;
        channel2 = MOTOR_LEFT_CHANNEL_2;
    }
    else if (motor == Motor_right)
    {
        channel1 = MOTOR_RIGHT_CHANNEL_1;
        channel2 = MOTOR_RIGHT_CHANNEL_2;
    }
    if (speed < 0)
    {
        speed = -speed;
        int temp = channel1;
        channel1 = channel2;
        channel2 = temp;
    }
    ledcWrite(channel2, 0);
    ledcWrite(channel1, Motor_Speed2Duty(speed));
#ifdef CAR_DEBUG
    Serial.printf("[Motor%d] Motor Speed %d.\n", Motor_Channel_1 + 1, speed);
#endif
}

/**
 * @brief  电机开启
 * @param  motor            电机编号
 * @retval None
 */
void Motor_Start(Motor motor)
{
    int channel1, channel2, pin1, pin2;
    switch (motor)
    {
    case Motor_left:
        pin1 = MOTOR_LEFT_PIN_1;
        channel1 = MOTOR_LEFT_CHANNEL_1;
        pin2 = MOTOR_LEFT_PIN_2;
        channel2 = MOTOR_LEFT_CHANNEL_2;
        break;
    case Motor_right:
        pin1 = MOTOR_RIGHT_PIN_1;
        channel1 = MOTOR_RIGHT_CHANNEL_1;
        pin2 = MOTOR_RIGHT_PIN_2;
        channel2 = MOTOR_RIGHT_CHANNEL_2;
        break;
    }
    ledcAttachPin(pin1, channel1);
    ledcAttachPin(pin2, channel2);
}

/**
 * @brief  电机停止
 * @param  motor             电机通道号
 * @retval None
 */
void Motor_Stop(Motor motor)
{
    int channel1, channel2, pin1, pin2;
    switch (motor)
    {
    case Motor_left:
        pin1 = MOTOR_LEFT_PIN_1;
        channel1 = MOTOR_LEFT_CHANNEL_1;
        pin2 = MOTOR_LEFT_PIN_2;
        channel2 = MOTOR_LEFT_CHANNEL_2;
        break;
    case Motor_right:
        pin1 = MOTOR_RIGHT_PIN_1;
        channel1 = MOTOR_RIGHT_CHANNEL_1;
        pin2 = MOTOR_RIGHT_PIN_2;
        channel2 = MOTOR_RIGHT_CHANNEL_2;
        break;
    }
    ledcWrite(channel1, 0);
    ledcAttachPin(pin1, channel1);
    ledcWrite(channel2, 0);
    ledcAttachPin(pin2, channel2);
#ifdef CAR_DEBUG
    Serial.printf("[Motor%d] Motor Stoped.\n", motor + 1);
#endif
}