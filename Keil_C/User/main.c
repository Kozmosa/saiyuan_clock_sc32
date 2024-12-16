/**
*****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	         main.c
  * @author	 
  * @version 	
  * @date	
  * @brief	         
  * @details         Contains the MCU initialization function and its H file
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */
/*******************Includes************************************************************************/

#include "SC_Init.h"
#include "SC_it.h"
#include "..\Drivers\SCDriver_list.h"
#include "HeadFiles\SysFunVarDefine.h"
/**************************************Generated by EasyCodeCube*************************************/
//Forbid editing areas between the labels !!!

/*************************************.Generated by EasyCodeCube.************************************/
/**
  * @brief This function implements main function.
  * @note 
  * @param
  */

// disable semihosting mode
#pragma import(__use_no_semihosting)             

////串口打印
int fputc(int c, FILE* f)
{ 
    UART_SendData(UART0, (uint8_t)c);
    while(!UART_GetFlagStatus(UART0, UART_Flag_TX));
    UART_ClearFlag(UART0, UART_Flag_TX);
    return c;
}

// 串口输入
int uart_getc()
{
    while(!UART_GetFlagStatus(UART0, UART_Flag_RX));
    int c = UART_ReceiveData(UART0);
    UART_ClearFlag(UART0, UART_Flag_RX);
    return c;
}

char uart_getchar()
{
    return (char)uart_getc();
}

char uart_scanf(char *buffer)
{
    char c;
    while((c = uart_getchar()) != '\n')
    {
        *buffer = c;
        buffer++;
    }
    *buffer = '\0';
    return 0;
}


////延时函数
void Delay(unsigned int time)
{
    /*<UserCodeStart>*//*<SinOne-Tag><133>*/
    unsigned int i=0;
    unsigned int j=0;
    for(i=0; i<100; i++)
        for(;time>0;time--)
            for(j=0; j<100; j++)
            ;
    /*<UserCodeEnd>*//*<SinOne-Tag><133>*/
}

void Beep(int times)
{
    for(int i = 0; i < times; i++) {
        PWM_SetDuty(PWM0,PWM_Channel_1,500);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,500);
        Delay(5000);
    }
}

int main(void)
{
    /*<Generated by EasyCodeCube begin>*/
    /*<UserCodeStart>*//*<SinOne-Tag><36>*/
    IcResourceInit();
    OLED_Init();
    /*<UserCodeEnd>*//*<SinOne-Tag><36>*/
    /*<UserCodeStart>*//*<SinOne-Tag><4>*/
    char read_buffer[128];
    /*****MainLoop*****/
    while(1)
    {
        /*<UserCodeStart>*//*<SinOne-Tag><14>*/
        /***User program***/
        unsigned int time = 20000;
        // uart_scanf(read_buffer);
        // printf("Read command: %s\n", read_buffer);
        printf("test_command\n");
        printf("check_alarms\n");
        
        Beep(3);
        
        OLED_ShowByte(64,5,0xFF);
        
        PC_BIT(10) = 0;
        PC_BIT(5) = 1;
        PC_BIT(4) = 1;
        PC_BIT(11) = 1;
        PA_BIT(7) = 1;
        PA_BIT(8) = 1;
        PWM_SetDuty(PWM0,PWM_Channel_1,100);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,900);
        Delay(time);
        
        PC_BIT(10) = 1;
        PC_BIT(5) = 0;
        PC_BIT(4) = 1;
        PC_BIT(11) = 1;
        PA_BIT(7) = 1;
        PA_BIT(8) = 1;
        PWM_SetDuty(PWM0,PWM_Channel_1,200);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,800);
        Delay(time);
        
        PC_BIT(10) = 1;
        PC_BIT(5) = 1;
        PC_BIT(4) = 0;
        PC_BIT(11) = 1;
        PA_BIT(7) = 1;
        PA_BIT(8) = 1;
        PWM_SetDuty(PWM0,PWM_Channel_1,300);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,700);
        Delay(time);
        
        PC_BIT(10) = 1;
        PC_BIT(5) = 1;
        PC_BIT(4) = 1;
        PC_BIT(11) = 0;
        PA_BIT(7) = 1;
        PA_BIT(8) = 1;
        PWM_SetDuty(PWM0,PWM_Channel_1,400);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,600);
        Delay(time);
        
        PC_BIT(10) = 1;
        PC_BIT(5) = 1;
        PC_BIT(4) = 1;
        PC_BIT(11) = 1;
        PA_BIT(7) = 0;
        PA_BIT(8) = 1;
        PWM_SetDuty(PWM0,PWM_Channel_1,500);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,500);
        Delay(time);
        
        PC_BIT(10) = 1;
        PC_BIT(5) = 1;
        PC_BIT(4) = 1;
        PC_BIT(11) = 1;
        PA_BIT(7) = 1;
        PA_BIT(8) = 0;
        PWM_SetDuty(PWM0,PWM_Channel_1,800);
        PWM_SetDuty(PWM0,PWM_Channel_2,500);
        PWM_SetDuty(PWM0,PWM_Channel_3,300);
        Delay(time);
        
        TIM_Cmd(TIM2,ENABLE);
        Delay(time);
        TIM_Cmd(TIM2,DISABLE);
        /*<UserCodeEnd>*//*<SinOne-Tag><14>*/
        /*<Begin-Inserted by EasyCodeCube for Condition>*/
    }
    /*<UserCodeEnd>*//*<SinOne-Tag><4>*/
    /*<Generated by EasyCodeCube end>*/
}
