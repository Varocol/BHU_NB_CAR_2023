#include "Voice.h"
#include "Serial.h"

void PlayVoice(int voiceNum)
{
    // �뿪���
    if (voiceNum == 1)
    {
        Serial1.println("<G>�뿪���");
    }
    // �����յ�
    if (voiceNum == 2)
    {
        Serial1.println("<G>�����յ�");
    }

    // ��խ��
    if (voiceNum == 3)
    {
        Serial1.println("<G>��խ��");
    }

    // �뿪խ��
    if (voiceNum == 4)
    {
        Serial1.println("<G>�뿪խ��");
    }

    // �Ͻ���
    if (voiceNum == 5)
    {
        Serial1.println("<G>�Ͻ���");
    }

    // �뿪����
    if (voiceNum == 6)
    {
        Serial1.println("<G>�뿪����");
    }

    // �뿪����
    if (voiceNum == 7)
    {
        Serial1.println("<G>ת����ע��");
    }
}

void Play_tip(int type)
{
    if (type == 1)
    {
        Serial1.println("<I>22");
    }
}