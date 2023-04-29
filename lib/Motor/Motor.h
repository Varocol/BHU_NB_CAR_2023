#ifndef __MOTOR_H
#define __MOTOR_H

#include <Arduino.h>

#define MOTOR_LEFT_PIN_1 2     // 左电机引脚1
#define MOTOR_LEFT_PIN_2 3      // 左电机引脚2
#define MOTOR_RIGHT_PIN_1 10     // 右电机引脚1
#define MOTOR_RIGHT_PIN_2 6     // 右电机引脚2
#define MOTOR_LEFT_CHANNEL_1 0  // 左电机引脚1通道
#define MOTOR_LEFT_CHANNEL_2 1  // 左电机引脚2通道
#define MOTOR_RIGHT_CHANNEL_1 2 // 右电机引脚1通道
#define MOTOR_RIGHT_CHANNEL_2 3 // 右电机引脚2通道
#define MOTOR_RESOLUTION 14     // 占空比位数(14为最大)
#define MOTOR_FREQUENCY 2000    // Hz(默认值)
#define MOTOR_SPEED_MIN 0
#define MOTOR_SPEED_MAX 100

#define MOTOR_NORMAL_SPEED 60

typedef enum
{
    Motor_left,
    Motor_right,
} Motor;

void Motor_Init();
void Motor_Run(Motor motor, int speed);
void Motor_Start(Motor motor);
void Motor_Stop(Motor motor);

#endif // !__MOTOR_H