#include "Task.h"

// 任务列表
vector<Task_Control_Block> Task_List{
    // {Load_Track_Task, "Load_Track", Running, 1},
    {Track_Task, "Track", Running, 1},
    {Infrared_Detect_Task, "Infrared_Detect", Running, 2},
    // {Servo_Turn_Task, "Servo_Turn", Running, 2},
    {Motor_Run_Task, "Motor_Run", Running, 2},
    // {Servo_Calibrate_Task, "Servo_Calibrate", Running, 2},
};

// 硬件运行参数
// 红外对管数据
volatile int Infrared1_Data;
volatile int Infrared2_Data;
volatile int Infrared3_Data;
volatile int Infrared4_Data;

// 红外对管权重
const double Infrared1_weight = 30.0;
const double Infrared2_weight = 10.0;
const double Infrared3_weight = 10.0;
const double Infrared4_weight = 30.0;

// 舵机角度
// volatile int Servo_Angle = 0;
// volatile int Servo_Angle_Old = 0;

// 电机速度
volatile int Motor_Left_Speed = 0;
volatile int Motor_Left_Speed_Old = 0;
volatile int Motor_Right_Speed = 0;
volatile int Motor_Right_Speed_Old = 0;

// 舵机校正系数
// const double Servo_Coefficient = 10.0;

/**
 * @brief  任务初始化
 * @param  None
 * @retval None
 */
void Task_Init()
{
    // 初始化任务列表中的任务
    for (int i = 0; i < Task_List.size(); i++)
    {
        xTaskCreate(Task_List.at(i).task, Task_List.at(i).name, 2048, (void *)&Task_List.at(i), Task_List.at(i).Priority, NULL);
    }
}

/**
 * @brief  红外对管信号捕捉任务
 * @param  param    参数
 * @retval None
 */
void Infrared_Detect_Task(void *param)
{
    Task_Control_Block *TCB = (Task_Control_Block *)param;
    while (TCB->status == Running)
    {
        Infrared1_Data = Infrared_Detect(Infrared1);
        Infrared2_Data = Infrared_Detect(Infrared2);
        Infrared3_Data = Infrared_Detect(Infrared3);
        Infrared4_Data = Infrared_Detect(Infrared4);
        delay(10);
    }
    vTaskDelete(NULL);
}

// /**
//  * @brief  舵机控制任务
//  * @param  param    参数
//  * @retval None
//  */
// void Servo_Turn_Task(void *param)
// {
//     Task_Control_Block *TCB = (Task_Control_Block *)param;
//     while (TCB->status == Running)
//     {
//         if (Servo_Angle != Servo_Angle_Old)
//         {
//             Servo_Turn(Servo_Angle);
//             Servo_Angle_Old = Servo_Angle;
//         }
//         delay(10);
//     }
//     // 任务结束关闭舵机
//     Servo_Stop();
//     vTaskDelete(NULL);
// }

/**
 * @brief  电机控制任务
 * @param  param    参数
 * @retval None
 */
void Motor_Run_Task(void *param)
{
    Task_Control_Block *TCB = (Task_Control_Block *)param;
    while (TCB->status == Running)
    {
        if (Motor_Left_Speed != Motor_Left_Speed_Old)
        {
            Motor_Run(Motor_left, Motor_Left_Speed);
            Motor_Left_Speed_Old = Motor_Left_Speed;
        }
        if (Motor_Right_Speed != Motor_Right_Speed_Old)
        {
            Motor_Run(Motor_right, Motor_Right_Speed);
            Motor_Right_Speed_Old = Motor_Right_Speed;
        }
        delay(10);
    }
    Motor_Stop(Motor_left);
    Motor_Stop(Motor_right);
    vTaskDelete(NULL);
}

// /**
//  * @brief  舵机校正任务
//  * @param  param    参数
//  * @retval None
//  */
// void Servo_Calibrate_Task(void *param)
// {
//     Task_Control_Block *TCB = (Task_Control_Block *)param;
//     while (TCB->status == Running)
//     {
//         for (int i = SERVO_ANGLE_MIN; i <= SERVO_ANGLE_MAX; i++)
//         {
//             Servo_Turn(i);
// #ifdef CAR_DEBUG
//             Serial.printf("角度:%d\n", i);
// #endif
//             delay(100);
//         }
//     }
//     vTaskDelete(NULL);
// }

/**
 * @brief  赛道循迹测试任务
 * @param  param    参数
 * @retval None
 */
void Track_Task(void *param)
{
    Task_Control_Block *TCB = (Task_Control_Block *)param;
    // int run_code;
    int left_sum, right_sum;
    while (TCB->status == Running)
    {
        // run_code = (Infrared1_Data << 3) | (Infrared2_Data << 2) | (Infrared3_Data << 1) | Infrared4_Data;
        // switch (run_code)
        // {
        // // 往右打死
        // case 8:
        // case 12:
        //     Motor_Left_Speed = 60;
        //     Motor_Right_Speed = 20;
        //     break;
        // // 往右打
        // case 4:
        //     Motor_Left_Speed = 60;
        //     Motor_Right_Speed = 50;
        //     break;
        // // 往左打死
        // case 1:
        // case 3:
        //     Motor_Right_Speed = 60;
        //     Motor_Left_Speed = 20;
        //     break;
        // // 往左打
        // case 2:
        //     Motor_Right_Speed = 60;
        //     Motor_Left_Speed = 50;
        //     break;
        // default:
        //     Motor_Left_Speed = 60;
        //     Motor_Right_Speed = 60;
        //     break;
        // }
        left_sum = Infrared1_Data * Infrared1_weight + Infrared2_Data * Infrared2_weight;
        right_sum = Infrared3_Data * Infrared3_weight + Infrared4_Data * Infrared4_weight;
        Motor_Left_Speed = left_sum - right_sum + MOTOR_NORMAL_SPEED;
        Motor_Right_Speed = right_sum - left_sum + MOTOR_NORMAL_SPEED;
        delay(10);
    }
    vTaskDelete(NULL);
}