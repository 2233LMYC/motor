#ifndef __CONTROL_H
#define __CONTROL_H

#include "main.h"

#define  Amplitude     7100     /* PWM满幅是3600 */
#define  Dead_Voltage  200     /* 死区电压 */
#define  Rpm_Max       320      /* 最大转速 */

#define  AIN1(x)  do{x?HAL_GPIO_WritePin(GPIOA,AIN1_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,AIN1_Pin,GPIO_PIN_RESET);}while(0) /* AIN1翻转 */
#define  AIN2(x)  do{x?HAL_GPIO_WritePin(GPIOA,AIN2_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,AIN2_Pin,GPIO_PIN_RESET);}while(0) /* AIN2翻转 */

enum {
    L = 1,
    R
};

int Xianfu(int data,int max);
void SET_PWM(int L_R,int pwm);

#endif