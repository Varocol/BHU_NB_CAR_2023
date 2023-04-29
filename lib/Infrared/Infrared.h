#ifndef __INFRARED_H
#define __INFRARED_H

#include <Arduino.h>
#include <deque>

using namespace std;

#define Infrared1_Pin 9
#define Infrared2_Pin 8
#define Infrared3_Pin 4
#define Infrared4_Pin 7

typedef enum
{
    Infrared1,
    Infrared2,
    Infrared3,
    Infrared4
} Infrared;

void Infrared_Init();
int Infrared_Detect(Infrared infrared);

#endif // !__INFRARED_H