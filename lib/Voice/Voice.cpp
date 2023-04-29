#include "Voice.h"
#include "Serial.h"

void PlayVoice(int voiceNum)
{
    // 离开起点
    if (voiceNum == 1)
    {
        Serial1.println("<G>离开起点");
    }
    // 到达终点
    if (voiceNum == 2)
    {
        Serial1.println("<G>到达终点");
    }

    // 上窄桥
    if (voiceNum == 3)
    {
        Serial1.println("<G>上窄桥");
    }

    // 离开窄桥
    if (voiceNum == 4)
    {
        Serial1.println("<G>离开窄桥");
    }

    // 上阶梯
    if (voiceNum == 5)
    {
        Serial1.println("<G>上阶梯");
    }

    // 离开阶梯
    if (voiceNum == 6)
    {
        Serial1.println("<G>离开阶梯");
    }

    // 离开阶梯
    if (voiceNum == 7)
    {
        Serial1.println("<G>转弯请注意");
    }
}

void Play_tip(int type)
{
    if (type == 1)
    {
        Serial1.println("<I>22");
    }
}