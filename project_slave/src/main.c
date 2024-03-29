
// SLAVE        TFT W LED MATRIX


#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "STK_int.h"



#include "LEDMATRIX_int.h"

#include "MUART_int.h"

#include "MNVIC_int.h"

#include "SYS_INIT.h"
#include "MEXTI_int.h"
#include "SPI_int.h"
#include "TFT_cfg.h"

#include "TFT_int.h"
#include "TFT_prv.h"
#include "TFT_img.h"
void func1(void);
void func2(void);
#define MEXTI0   6


u8 arr;
u8 user;
u8 motionsenser;
u8 flag_motion =0;


s32 entire ;
s32 space = 3 ;
u8 k ;
u8 m ;

u8 user1_flag = 0 ;
u8 user2_flag = 0 ;
u8 user3_flag = 0 ;
u8 data []={0, 0, 126, 121, 121, 126, 0, 0};
u8 data1 []={3, 1, 126, 120, 120, 120, 0, 0};


 u8 led_flag =0 ;

int main(void)
{

	 MRCC_InitSysClk ();

	 MRCC_vidEnable_Peripheral (RCC_AHB1,AHB1ENR_GPIOAEN) ;  //INITIALIZE RCC PORTA
	 MRCC_vidEnable_Peripheral (RCC_AHB1,AHB1ENR_GPIOBEN) ;  //INITIALIZE RCC PORTB
	 MRCC_vidEnable_Peripheral (RCC_APB2,APB2ENR_USART1EN) ;
	 MRCC_vidEnable_Peripheral (RCC_APB1,APB1ENR_USART2EN) ;
		MRCC_vidEnable_Peripheral(RCC_APB2,APB2ENR_SPI1EN);
	 MRCC_vidEnable_Peripheral(RCC_APB2, APB2ENR_SYSCFGEN);
	// MRCC_voidInitSysClk();
	 		MSTK_voidInit();
	 		MGPIO_SetPinMode(PORTA,PIN0,OUTPUT);
	 				MGPIO_SetPinMode(PORTA,PIN1,OUTPUT);
	 				MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);
	 				MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);

	 				MSPI_voidInit();

	 				HTFT_voidInit();


LEDMTX_vidInit();


	 EXTI_INIT();
	MUART_RUNNABLE();

	 //MUART_voidCallBack (func1);//INITIALIZE SYSTICK












while (1)
{


LEDMTX_vidDisplay(data);




}




}


void func1(void)
{

	k = UART_READ_DATA();
	for ( u8 i= 0 ; k == '1' && i <250  ;i ++ )
	{
		LEDMTX_vidDisplay(data1);
	}

}











void func2(void){

	k= UART2_READ_DATA();
		for ( u8 i= 0 ; k == '1' && i <250  ;i ++ )
		{
			LEDMTX_vidDisplay(data1);
		}

}

void func3(void){}
void func4(void){}


