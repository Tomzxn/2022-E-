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
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	  //���ڳ�ʼ��Ϊ115200
 	LED_Init();			      //LED�˿ڳ�ʼ��
	LCD_Init();			      //LCD��ʼ�� 	
    Servo_PWM_Init();         //�����ʼ��
    KEY_Init();               //������ʼ��
     
    //�����ʼ��
    Servo1_SetAngle(135);      //����ת��  ��124  ��90  �� 68
    Servo2_SetAngle(0);       //����
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

 
 

