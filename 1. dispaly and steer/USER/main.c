#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "SG90.h"
#include "math.h"
#include "Subfunctions.h"

int main(void)
 {	 
    int key;
    float b;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	  //串口初始化为115200
 	LED_Init();			      //LED端口初始化
	LCD_Init();			      //LCD初始化 	
    Servo_PWM_Init();         //舵机初始化
    KEY_Init();               //按键初始化
     
    //舵机初始化
    Servo1_SetAngle(135);      //下面转动  左124  中90  右 68
    Servo2_SetAngle(0);       //上面
	while(1)
	{
        Show_location();
        Gimbal();
        key = KEY_Scan(0);
        if(key==KEY1)
        {
             b=90;
             b++;
             Servo1_SetAngle(b);
        }
        if(key==KEY0)
        {
             
        }
        LED0=~LED0;
        delay_ms(500);

	}
 }

 
 

