#ifndef __Subfunctions_H
#define __Subfunctions_H	 
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "SG90.h"

void Show_location(void);   //��ʾ
float location(void) ;      //�Ƕ�
float X_loca(void);         //x			
float Y_loca(void);         //Y
void Gimbal(void);          //��̨ת��
#endif

