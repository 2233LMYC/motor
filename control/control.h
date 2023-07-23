#ifndef __CONTROL_H
#define __CONTROL_H

#include "main.h"

#define  Amplitude     7100     /* PWM������3600 */
#define  Dead_Voltage  200     /* ������ѹ */
#define  Rpm_Max       320      /* ���ת�� */

#define  AIN1(x)  do{x?HAL_GPIO_WritePin(GPIOA,AIN1_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,AIN1_Pin,GPIO_PIN_RESET);}while(0) /* AIN1��ת */
#define  AIN2(x)  do{x?HAL_GPIO_WritePin(GPIOA,AIN2_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,AIN2_Pin,GPIO_PIN_RESET);}while(0) /* AIN2��ת */

enum {
    L = 1,
    R
};

int Xianfu(int data,int max);
void SET_PWM(int L_R,int pwm);

#endif