#include "STD_TYPES.h"
#include "MGPIO_int.h"
#include "keypad_int.h"

/* Keypad buttons definition */
static u8 Keypad_Buttons [KEYPAD_ROWS][KEYPAD_COLS] = {
		{ '1' , '2' , '3' },
		{ '4' , '5' , '6' },
		{ '7' , '8' , '9' },
		{ '*' , '0' , '#' }
};



void keypad_init(void){

	MGPIO_SetPinMode(KEYPAD_PORT, ROW0, OUTPUT);
	MGPIO_SetPinMode(KEYPAD_PORT, ROW1, OUTPUT);
	MGPIO_SetPinMode(KEYPAD_PORT, ROW2, OUTPUT);
	MGPIO_SetPinMode(KEYPAD_PORT, ROW3, OUTPUT);


	MGPIO_SetPinValue(KEYPAD_PORT, ROW0, 1);
	MGPIO_SetPinValue(KEYPAD_PORT, ROW1, 1);
	MGPIO_SetPinValue(KEYPAD_PORT, ROW2, 1);
	MGPIO_SetPinValue(KEYPAD_PORT, ROW3, 1);

	    MGPIO_SetPinMode(KEYPAD_PORT, COL0, INPUT);
		MGPIO_SetPinMode(KEYPAD_PORT, COL1, INPUT);
		MGPIO_SetPinMode(KEYPAD_PORT, COL2, INPUT);

		MGPIO_SetInputPin(KEYPAD_PORT, COL0, INPUT_PULLUP);
		MGPIO_SetInputPin(KEYPAD_PORT, COL1, INPUT_PULLUP);
		MGPIO_SetInputPin(KEYPAD_PORT, COL2, INPUT_PULLUP);


}

u8 keypad_Get_Pressed_Key(void){
	u8 r,c,key=NO_KEY;
		for (r=0;r<ROWS;r++)
		{

			MGPIO_SetPinValue(KEYPAD_PORT,FIRST_OUTPUT+r,0);
			for (c=0;c<COLS;c++)
			{
				if (MGPIO_voidGetPinValue(KEYPAD_PORT,(FIRST_INPUT+c))==0)
				{
					key=Keypad_Buttons [r][c];
					while(MGPIO_voidGetPinValue(KEYPAD_PORT,(FIRST_INPUT+c))==0);
				}
			}
			MGPIO_SetPinValue(KEYPAD_PORT,FIRST_OUTPUT+r,1);
		}

		return key;

}
