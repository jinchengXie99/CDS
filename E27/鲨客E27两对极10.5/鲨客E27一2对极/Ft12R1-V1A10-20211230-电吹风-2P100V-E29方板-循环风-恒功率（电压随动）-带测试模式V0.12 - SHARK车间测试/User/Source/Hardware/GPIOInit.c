/**************************** (C) COPYRIGHT 2017 Fortiortech shenzhen *****************************
* File Name          : GPIOInit.c
* Author             : Fortiortech  Appliction Team
* Version            : V1.0
* Date               : 010-Apr-2017
* Description        : This file contains GPIO initial function used for Motor Control.
***************************************************************************************************
* All Rights Reserved
**************************************************************************************************/

/* Includes -------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>

/*-------------------------------------------------------------------------------------------------
  Function Name :  void GPIO_Default_Init(void)
  Description   :  为提高芯片的抗干扰能力，降低芯片功耗，请在具体项目时，将不需要用的GPIO默认都配置为输入上拉。
  Input         :  无
  Output        :  无
-------------------------------------------------------------------------------------------------*/
void GPIO_Default_Init(void)//为提高芯片的抗干扰能力，降低芯片功耗，请在具体项目时，将不需要用的GPIO默认都配置为输入上拉。
{
  P2_OE = 0;
  P2_PU = P21|P22|P23|P24|P25|P26|P27;      // 需确认这些端口能接受上拉
  
  P3_OE = 0;
  P3_PU = P30|P31|P32|P33|P34|P35|P36|P37;  // 需确认这些端口能接受上拉
  
  P0_OE = 0;
  P0_PU = P00|P01|P02|P03|P04|P05|P06|P07;  // 需确认这些端口能接受上拉
  
  P1_OE = 0;
  P1_PU = P10|P11|P12|P13|P14|P15|P16|P17;  // 需确认这些端口能接受上拉
  
  P4_OE = 0;
  P4_PU = P40|P41;                          // 使用步进电机时，P40，P41不能配置输入上拉，上拉会导致直通
  
}

/*-------------------------------------------------------------------------------------------------
  Function Name :  void GPIO_Init(void)
  Description   :  GPIO初始化配置,可将I/O口配置成输入或输出模式，上拉还是不上拉，模拟输出还是数字输出
  Input         :  无
  Output        :  无
-------------------------------------------------------------------------------------------------*/
void GPIO_Init(void)
{
  SetBit(P0_PU, P05);            // LOCK
  SetBit(P0_PU, P06);            // GO
  
  SetBit(P3_OE, P36);            // LED1
  GP36 = 1;
  SetBit(P3_OE, P37);            // LED2
  GP37 = 1;
  SetBit(P0_OE, P00);            // LED3
  GP00 = 1;
  SetBit(P0_OE, P01);            // LED4
  GP01 = 1;
  SetBit(P0_OE, P02);            // LED5
  GP02 = 1;
  SetBit(P0_OE, P03);            // LED6
  GP03 = 1;
  
  SetBit(P1_OE, P10);            // 发热丝输出位 1
  SetBit(P1_PU, P10);            // 
  GP10 = 1;    
  SetBit(P1_OE, P11);            // 发热丝输出位 2
  SetBit(P1_PU, P11);            // 
  GP11 = 1;   
  
  ClrBit(P1_OE, P17);            // SW1
  SetBit(P1_PU, P17);            // 
  ClrBit(P1_OE, P15);            // SW2
  SetBit(P1_PU, P15);            // 
  ClrBit(P1_OE, P13);            // SW3
  SetBit(P1_PU, P13);            // 
  
  
//  SetBit(P3_OE, P36);            // 
//  SetBit(P3_PU, P36);            // LED1
//  GP36 = 1;
//  SetBit(P3_OE, P37);            // 
//  SetBit(P3_PU, P37);            // LED2
//  GP37 = 1;
//  SetBit(P0_OE, P00);            // 
//  SetBit(P0_PU, P00);            // LED3
//  GP00 = 1;
//  SetBit(P0_OE, P01);            // 
//  SetBit(P0_PU, P01);            // LED4
//  GP01 = 1;
//  SetBit(P0_OE, P02);            // 
//  SetBit(P0_PU, P02);            // LED5
//  GP02 = 1;
//  SetBit(P0_OE, P03);            // 
//  SetBit(P0_PU, P03);            // LED6
//  GP03 = 1;                      //LED初始化，先关断
//  
//  ClrBit(P0_OE, P06);            // 
//  SetBit(P0_PU, P06);            // 开机
//  
//  ClrBit(P0_OE, P05);            // 
//  SetBit(P0_PU, P05);            // LOCK,锁定档位
//  
//  ClrBit(P1_OE, P10);            // 
//  SetBit(P1_PU, P10);            // 
//  GP10 = 1;    
//  SetBit(P1_OE, P11);            // 
//  SetBit(P1_PU, P11);            // 发热丝输出位
//  GP11 = 1;   

//  SetBit(P2_OE, P22);            // 
//  SetBit(P2_PU, P22);            // 
//  GP22 = 1;                      // FLZ

//  ClrBit(P1_OE, P17);            // 
//  SetBit(P1_PU, P17);            // SW1
//  ClrBit(P1_OE, P15);            // 
//  SetBit(P1_PU, P15);            // SW2
//  ClrBit(P1_OE, P13);            // 
//  SetBit(P1_PU, P13);            // SW3
}

