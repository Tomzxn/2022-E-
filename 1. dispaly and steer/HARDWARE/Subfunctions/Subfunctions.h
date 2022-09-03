#ifndef __Subfunctions_H
#define __Subfunctions_H	 
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "SG90.h"

void Show_location(void);   //显示
float location(void) ;      //角度
float X_loca(void);         //x			
float Y_loca(void);         //Y
void Gimbal(void);          //云台转动
#endif

