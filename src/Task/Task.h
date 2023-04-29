#ifndef __TASK_H
#define __TASK_H
#include "header.h"

// 用于控制任务的进行和结束
typedef enum
{
    Running,
    Stop
} Task_Status;
typedef struct
{
    TaskFunction_t task;
    const char *name;
    Task_Status status;
    int Priority;
} Task_Control_Block;

void Task_Init();

// 任务列表
// 红外对管信号捕捉任务
void Infrared_Detect_Task(void *param);
// 舵机控制任务
// void Servo_Turn_Task(void *param);
// 电机控制任务
void Motor_Run_Task(void *param);


// 调试任务
// 舵机校正任务
// void Servo_Calibrate_Task(void *param);
// 赛道循迹测试任务
void Track_Task(void *param);

#endif // !__TASK_H
