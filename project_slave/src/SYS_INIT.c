#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "STK_int.h"

#include "LCD.h"
#include "keypad_int.h"
#include "LEDMATRIX_int.h"
#include "Servo_Motor.h"

#include "SYS_INIT.h"
#include "MUART_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"



#define MEXTI0     6
#define MEXTI1     7
void func1(void);
void func2(void);
//void func3(void);
//void func4 (void);

  u8 user1 = 0 ;
  u8 user2 = 0 ;
  u8 user3 = 0 ;




void SYS_INIT(void)

{

}

void ADMIN_STATE (void)
{
	 LCD_SetCursor(0,5);
     LCD_WriteString("WELCOME");


	 LCD_SetCursor(1,0);
	 LCD_WriteString("TO SMART PARKING ");

	 MSTK_voidDelayMsec(50000);

	 LCD_Clear();
	 MSTK_voidDelayMsec(200);
	 USER1();
	 USER2();
	 USER3();





}

void USER1(void)
{
	while (1)
	{
		u8 k;
		     LCD_SetCursor (0,0);
			 LCD_WriteString("FIRST CUSTOMER ");
			 LCD_SetCursor(1,0);
			 LCD_WriteString("ENTER ID : ");
			 LCD_SetCursor(1,11);
			 k= keypad_Get_Pressed_Key();
			 if (k!= NO_KEY)
			 {
				 user1 = k;
					 LCD_WriteChar(k);

					 MSTK_voidDelayMsec(2000);
					 LCD_Clear();
					 MSTK_voidDelayMsec(1000);
					 break;
			 }


	}
}
void USER2(void){
	u8 k;
	while (1){

			     LCD_SetCursor (0,0);
				 LCD_WriteString("SECOND CUSTOMER ");
				 LCD_SetCursor(1,0);
				 LCD_WriteString("ENTER ID : ");
				 LCD_SetCursor(1,11);
				 k= keypad_Get_Pressed_Key();
				 if (k != user1){
					 if (k!= NO_KEY)
					 				 {
					 					 user2 = k;
					 						 LCD_WriteChar(k);
					 						 MSTK_voidDelayMsec(2000);
					 						 LCD_Clear();
					 						 MSTK_voidDelayMsec(1000);
					 						 break;
					 				 }
				 }
				 if (k== user1){
				                                 LCD_Clear();
					 							 MSTK_voidDelayMsec(200);
					 							 LCD_SetCursor(0,5);
					 							      LCD_WriteString("INVALID!");
					 							     MSTK_voidDelayMsec(1000);


				 }

	}
}

void USER3(void)
{
	u8 k;
		while (1){
				     LCD_SetCursor (0,0);
					 LCD_WriteString("THIRD CUSTOMER ");
					 LCD_SetCursor(1,0);
					 LCD_WriteString("ENTER ID : ");
					 LCD_SetCursor(1,11);
					 k= keypad_Get_Pressed_Key();
					 if (k!= user1 && k!=user2){
					 if (k!= NO_KEY)
					 {
						 user3 = k;
							 LCD_WriteChar(k);
							 MSTK_voidDelayMsec(2000);
							 LCD_Clear();
							 MSTK_voidDelayMsec(1000);
							 LCD_WriteString("LOADING");
							 MSTK_voidDelayMsec(500);
							 LCD_SetCursor(0,8);
							 LCD_WriteChar('.');
							 MSTK_voidDelayMsec(500);
							 LCD_SetCursor(0,9);
							 LCD_WriteChar('.');
							 MSTK_voidDelayMsec(500);
							 LCD_SetCursor(0,10);
							 LCD_WriteChar('.');
							 MSTK_voidDelayMsec(2000);
							 LCD_SetCursor(1,0);
							 LCD_WriteString("SUCCESSFUL");
							 MSTK_voidDelayMsec(2000);
							 LCD_Clear();
							 MSTK_voidDelayMsec(200);
							 LCD_SetCursor(0,5);
							      LCD_WriteString("WELCOME");



							 break;
					 }
					 }
					 if (k == user1 || k == user2 ){

                         LCD_Clear();
							 MSTK_voidDelayMsec(200);
							 LCD_SetCursor(0,5);
							      LCD_WriteString("INVALID!");
							     MSTK_voidDelayMsec(1000);


					 }
		}
}

void MUART_RUNNABLE (void)
{
	//MGPIO_SetPinMode(PORTA,PIN9,ALT_FUNC);
	    MGPIO_SetPinMode(PORTA,PIN10,ALT_FUNC);
	   // MGPIO_SetPinAlterFunc(PORTA, PIN9, AF7_USART1_USART2);
	    MGPIO_SetPinAlterFunc(PORTA, PIN10, AF7_USART1_USART2);
	   // MGPIO_SetPinMode(PORTA,PIN2,ALT_FUNC);
	    MGPIO_SetPinMode(PORTA,PIN3,ALT_FUNC);
	   // MGPIO_SetPinAlterFunc(PORTA, PIN2, AF7_USART1_USART2);
	   MGPIO_SetPinAlterFunc(PORTA, PIN3, AF7_USART1_USART2);
	   MUSART_voidInit1();
	    MUSART_voidInit2();
	  //  MUART_voidEnable2();
	    MUART_voidEnable();

}



void EXTI_INIT(void)
{
	MNVIC_SetIntterruptGroupMode(MNVIC_GROUPMODE_G16S0);

	//MNVIC_SetIntterruptPriority(MEXTI0, 2, 0);
	//MNVIC_SetIntterruptPriority(MEXTI1, 0, 0);
	MNVIC_SetIntterruptPriority(37,3,0);
	MNVIC_SetIntterruptPriority(38,2,0);
	//MNVIC_SetIntterruptPriority(35,1,0);

	//MNVIC_EnableInterrupt(MEXTI0);
	//MNVIC_EnableInterrupt(MEXTI1);
	MNVIC_EnableInterrupt(37);
	MNVIC_EnableInterrupt(38);

	//MNVIC_u8IsInterruptActive(37);
	//MNVIC_u8IsInterruptActive(38);


			//MGPIO_SetPinMode(PORTB,  PIN1, INPUT);
		//	MGPIO_SetInputPin(PORTB, PIN1, INPUT_PULLUP);

		//	MGPIO_SetPinMode(PORTB,  PIN2, INPUT);
		//	MGPIO_SetInputPin(PORTB, PIN2, INPUT_PULLUP);


		//	MEXTI_voidSetPortExtiCfg(EXTI_LINE0,PORTB);
	//	MEXTI_voidSetTriggerSource(EXTI_LINE0,ON_CHANGE);
			//MEXTI_voidSetPortExtiCfg(EXTI_LINE1,PORTB);
		//	MEXTI_voidSetTriggerSource(EXTI_LINE1,ON_CHANGE);
			//EXTI0_VoidCallBack(func2);
			//EXTI1_VoidCallBack(func2);
			MUART_voidCallBack(func1);
			MUART2_voidCallBack(func2);

			//Servo1_Entry_Gate_Init();

}





