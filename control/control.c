#include "main.h"
#include "control.h"
#include "tim.h"
#include "PID.h"
#include "encoder.h"
#include "math.h"


extern PID_struct Velocity;
extern PID_struct Position;

void SET_PWM(int L_R,int pwm)
{
    switch (L_R)
    {
        case L:
            if(pwm>=0)
            {
                AIN1(0);
                AIN2(1);
                __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,pwm);
            }
            else
            {
                AIN1(1);
                AIN2(0);
                __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,-pwm);
            }
            break;
        case R:
            ;
            break;
        default:
            ;
            break;
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM3)
    {
        Velocity.actual = Read_Encoder(2);
        Position.actual += Velocity.actual;

        Position.out = Position_PID(&Position);
        Position.out = Xianfu(Position.out, Rpm_Encoder_Cnt(250,13,30,10));


        if(fabs(Position.actual-Position.target)<3)             /* �˳����ָ��� */
        {
            SET_PWM(L,0);                                         /* ֹͣ��� */
            Velocity.err_sum  =  0;
        }
        else
        {
            Velocity.target =  Position.out;
            Velocity.out = Position_PID(&Velocity);      /* ����ʽ�ٶȿ��� */
            SET_PWM(L,(int)Velocity.out);                                      /* ��ֵ */
        }
    }
}

int Xianfu(int data,int max)
{
    if(data<-max) data=-max;
    if(data> max) data= max;
    return data;
}
