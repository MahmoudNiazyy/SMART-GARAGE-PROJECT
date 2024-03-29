#include "STD_TYPES.h"
#include "STK_int.h"
#include "Servo_Motor.h"

//Direction of motion
#define UP   1
#define Down 2


//B8 SERVO1
void Servo1_Entry_Gate_Init(void)
{
	/*SERVO MOTOR 1*/
	MGPIO_SetPinMode(PORTB, PIN10, OUTPUT);
	MGPIO_SetOutputPinMode(PORTB, PIN10, OUTPUT_PUSH_PULL, 0);
}

//Direction Up or Down
void Servo1_Entry_Gate(u8 Direction){
	if(Direction == SERVO_UP){
		//servo1 Enter gate up +90
		MGPIO_SetPinValue(PORTB, PIN10, 1);
		MSTK_voidDelayMsec(500);
		MGPIO_SetPinValue(PORTB, PIN10, 0);
	}
	
	if(Direction == SERVO_DOWN){
		//servo1 Enter gate down -90
		MGPIO_SetPinValue(PORTB, PIN10, 1);
		MSTK_voidDelayMsec(1488);                         //1488
		MGPIO_SetPinValue(PORTB, PIN10, 0);
	}
}

//B9 SERVO2
void Servo2_Exit_Gate_Init(void){
		/*SERVO MOTOR 2*/
	MGPIO_SetPinMode(PORTB, PIN9, OUTPUT);
	MGPIO_SetOutputPinMode(PORTB, PIN9, OUTPUT_PUSH_PULL, OUTPUT_HIGH);
}

//Direction Up or Down
void Servo2_Exit_Gate(u8 Direction){
	if(Direction == SERVO_UP){
		//servo2 Exit gate up +90
		MGPIO_SetPinValue(PORTB, PIN9, 1);
		MSTK_voidDelayMsec(500);
		MGPIO_SetPinValue(PORTB, PIN9, 0);
	}

	if(Direction == SERVO_DOWN){
		//servo2 Exit gate down -90
		MGPIO_SetPinValue(PORTB, PIN9, 1);
		MSTK_voidDelayMsec(500);
		MGPIO_SetPinValue(PORTB, PIN9, 0);
	}
}
