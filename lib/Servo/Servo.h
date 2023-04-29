#ifndef __SERVO_H
#define __SERVO_H

#include <Arduino.h>

#define SERVO_FREQUENCY 50   // Hz(默认值)
#define SERVO_PIN 13         // 引脚
#define SERVO_CHANNEL 0      // 通道
#define SERVO_RESOLUTION 14  // 占空比位数(14为最大)
#define SERVO_PULSE_MIN 500  // us
#define SERVO_PULSE_MAX 2500 // us
#define SERVO_ANGLE_MIN 0    // 度
#define SERVO_ANGLE_MAX 180  // 度
#define CAR_ANGLE_MIN 5      // 度
#define CAR_ANGLE_MAX 60     // 度
#define CAR_ANGLE_MIDDLLE ((CAR_ANGLE_MAX + CAR_ANGLE_MIN) / 2)

/*
    软件PWM在100Hz以内较为稳定
    舵机脉宽:0.5 ~ 2.5ms
    舵机角度:0 ~ 180度
*/

void Servo_Init();
void Servo_Turn(int angle);
void Servo_Start();
void Servo_Stop();

#endif // !__SERVO_H