#include "Subfunctions.h"                  
#include "math.h"

float X_loca(void)    //x
{ 
    float x;
    x=dis*(cos(ang/180.0*3.1415929))-25;
    return x;
}

float Y_loca(void)   //y
{ 
    float y;
    y=(dis*sin(ang/180.0*3.1415929));
    return y;
}
float location(void)     //angle
{
    float a=0;
    a=atan(Y_loca()/X_loca())*180/3.1415926;
    return a;
}

float Distance_A(void) 
{
   float A;
   A=250/sin(location()/180.0*3.1415929);
    return A;
}
void Show_location(void)   //��ʾ
{
   float x,y,a,d;
   x=X_loca();
   y=X_loca();
   a=location();
   d=Distance_A();
   POINT_COLOR=RED;//��������Ϊ��ɫ
   LCD_DrawRectangle(10,40,310,90);     //������  300 50
   Show_Chinese(10,120,0,16,POINT_COLOR,0xFFFF,0);  //�Ƕ�     
   Show_Chinese(30,120,1,16,POINT_COLOR,0xFFFF,0);
   Show_Chinese(10,150,2,16,POINT_COLOR,0xFFFF,0);   //����  
   Show_Chinese(30,150,3,16,POINT_COLOR,0xFFFF,0);
   Show_Chinese(10,180,4,16,POINT_COLOR,0xFFFF,0);    //���� 
   Show_Chinese(30,180,5,16,POINT_COLOR,0xFFFF,0);
   LCD_ShowString(50,120,200,16,16,":");
   LCD_ShowString(50,150,200,16,16,":"); 
   LCD_ShowString(50,180,200,16,16,":"); 
            
    /*   debug   */
   LCD_ShowxNum(70,10,dis,sizeof(dis),16,0);
   LCD_ShowxNum(150,10,ang,sizeof(ang),16,0);
    
   POINT_COLOR=BLUE;//��������Ϊ��ɫ
   LCD_Draw_Circle(x,y,2);   //ʵʱλ�� x,y
   LCD_ShowxNum(70,120,a,2,16,0);    //�Ƕ�
   LCD_ShowString(90,120,200,16,16,".");
   LCD_ShowxNum(100,120,(int)(a*1000)%1000,sizeof(a),16,0);  //С������ wuyumengxie
   
   LCD_ShowxNum(70,150,d,sizeof(d),16,0);    //����
   LCD_ShowString(105,150,200,16,16,".");
   LCD_ShowxNum(110,150,(int)(d*1000)%1000,sizeof((int)(d*1000)%1000),16,0);
            
   LCD_ShowString(70,180,200,16,16, "(");
   LCD_ShowxNum(80,180,x,sizeof(x),16,0);      //����x
   LCD_ShowString(105,180,200,16,16,".");
   LCD_ShowxNum(110,180,(int)(x*100)%100,sizeof((int)(x*100)%100),16,0); 
   
   LCD_ShowString(135,180,200,16,16,",");
   LCD_ShowxNum(140,180,y,sizeof(y),16,0);    //����y
   LCD_ShowString(175,180,200,16,16,".");
   LCD_ShowxNum(180,180,(int)(y*100)%100,sizeof((int)(y*100)%100),16,0); 
   LCD_ShowString(215,180,200,16,16,")");
}

void Gimbal(void)    //��̨ת��  �����������Ż�
{
  float a=0;
  a=location();
  Servo1_SetAngle(90+a);
  LED1=1;
  delay_ms(1500);
  LED1=0;

}
