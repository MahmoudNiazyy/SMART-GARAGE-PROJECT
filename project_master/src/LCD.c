


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD.h"
#include"LCD_cfg.h"
#include "MGPIO_cfg.h"
#include "MGPIO_int.h"
#include "MGPIO_prv.h"

#include "STK_int.h"

static void WriteIns(u8 ins)
{

	MGPIO_SetPinMode(PORTB,PIN8,OUTPUT); // RS LOW
	MGPIO_SetPinValue(PORTB,PIN8,0);

	MGPIO_SetPinMode(PORTB,PIN0,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN0,GET_BIT(ins,0));

	MGPIO_SetPinMode(PORTB,PIN1,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN1,GET_BIT(ins,1));

	MGPIO_SetPinMode(PORTB,PIN2,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN2,GET_BIT(ins,2));

	MGPIO_SetPinMode(PORTB,PIN3,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN3,GET_BIT(ins,3));

	MGPIO_SetPinMode(PORTB,PIN4,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN4,GET_BIT(ins,4));

	MGPIO_SetPinMode(PORTB,PIN5,OUTPUT);
	MGPIO_SetPinValue(PORTA,PIN5,GET_BIT(ins,5));

	MGPIO_SetPinMode(PORTB,PIN6,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN6,GET_BIT(ins,6));

	MGPIO_SetPinMode(PORTB,PIN7,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN7,GET_BIT(ins,7));


	MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN HIGH
	MGPIO_SetPinValue(PORTB,PIN9,1);
	MSTK_voidDelayMsec(1);
	MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN LOW
	MGPIO_SetPinValue(PORTB,PIN9,0);
	MSTK_voidDelayMsec(1);



}

static void WriteData(u8 data)
{
	MGPIO_SetPinMode(PORTA,PIN8,OUTPUT); // RS HIGH
	MGPIO_SetPinValue(PORTA,PIN8,1);

	    MGPIO_SetPinMode(PORTA,PIN0,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN0,GET_BIT(data,0));

		MGPIO_SetPinMode(PORTA,PIN1,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN1,GET_BIT(data,1));

		MGPIO_SetPinMode(PORTA,PIN2,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN2,GET_BIT(data,2));

		MGPIO_SetPinMode(PORTA,PIN3,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN3,GET_BIT(data,3));

		MGPIO_SetPinMode(PORTA,PIN4,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN4,GET_BIT(data,4));

		MGPIO_SetPinMode(PORTA,PIN5,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN5,GET_BIT(data,5));

		MGPIO_SetPinMode(PORTA,PIN6,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN6,GET_BIT(data,6));

		MGPIO_SetPinMode(PORTA,PIN7,OUTPUT);
		MGPIO_SetPinValue(PORTA,PIN7,GET_BIT(data,7));


	MGPIO_SetPinMode(PORTA,PIN9,OUTPUT); // EN HIGH
	MGPIO_SetPinValue(PORTA,PIN9,1);
	MSTK_voidDelayMsec(1);
	MGPIO_SetPinMode(PORTA,PIN9,OUTPUT); // EN LOW
		MGPIO_SetPinValue(PORTA,PIN9,0);
		MSTK_voidDelayMsec(1);
}



void LCD_Init(void)
{
	MSTK_voidDelayMsec(50);
	WriteIns(0x38);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	//WriteIns(0x01);//clear screen
	MSTK_voidDelayMsec(1);
	WriteIns(0x06);// increment DDRAM address, no shift

}



void LCD_WriteChar(u8 ch)
{
	WriteData_4BIT(ch);
}


void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}

}


void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns_4BIT(0x80|cell);
	}
	else if (line ==1)
	{
		WriteIns_4BIT(0x80+0x40+cell);
	}

}

void LCD_Clear(void)
{
	WriteIns_4BIT(0x01);
	MSTK_voidDelayMsec(1);
}



void LCD_WriteNumber(s32 num)
{
	u8 str[10],i=0,j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*(-1);
		LCD_WriteChar('-');
	}

	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteChar(str[j-1]);
	}

}


void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar((READ_BIT(num , i)) + '0' );
	}

}


void LCD_ClearLoc(u8 line ,u8 cell,u8 num)
{
	u8 i;
	LCD_SetCursor(line,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}

}

void LCD_WriteNumber_3D(u16 num)
{
	//LCD_WriteChar(((num%100000)/10000)+'0');
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}


void LCD_CustomChar(u8 loc,u8*pattern)
{
	WriteIns(0x40+loc*8);
	for(u8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}


static void WriteIns_4BIT(u8 ins)
{

	MGPIO_SetPinMode(PORTB,PIN8,OUTPUT); // RS LOW
	MGPIO_SetPinValue(PORTB,PIN8,0);

	MGPIO_SetPinMode(PORTB,PIN7,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN7,GET_BIT(ins,7));

	MGPIO_SetPinMode(PORTB,PIN6,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN6,GET_BIT(ins,6));

	MGPIO_SetPinMode(PORTB,PIN5,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN5,GET_BIT(ins,5));

	MGPIO_SetPinMode(PORTB,PIN4,OUTPUT);
	MGPIO_SetPinValue(PORTB,PIN4,GET_BIT(ins,4));


	MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN HIGH
	MGPIO_SetPinValue(PORTB,PIN9,1);
	MSTK_voidDelayMsec(1);
	MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN LOW
	MGPIO_SetPinValue(PORTB,PIN9,0);
	MSTK_voidDelayMsec(1);

	MGPIO_SetPinMode(PORTB,PIN7,OUTPUT);
		MGPIO_SetPinValue(PORTB,PIN7,GET_BIT(ins,3));

		MGPIO_SetPinMode(PORTB,PIN6,OUTPUT);
		MGPIO_SetPinValue(PORTB,PIN6,GET_BIT(ins,2));

		MGPIO_SetPinMode(PORTB,PIN5,OUTPUT);
		MGPIO_SetPinValue(PORTB,PIN5,GET_BIT(ins,1));

		MGPIO_SetPinMode(PORTB,PIN4,OUTPUT);
		MGPIO_SetPinValue(PORTB,PIN4,GET_BIT(ins,0));

		MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN HIGH
			MGPIO_SetPinValue(PORTB,PIN9,1);
			MSTK_voidDelayMsec(1);
			MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN LOW
			MGPIO_SetPinValue(PORTB,PIN9,0);
			MSTK_voidDelayMsec(1);
}

static void WriteData_4BIT(u8 data)
{
	MGPIO_SetPinMode(PORTB,PIN8,OUTPUT); // RS HIGH
		MGPIO_SetPinValue(PORTB,PIN8,1);

		    MGPIO_SetPinMode(PORTB,PIN7,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN7,GET_BIT(data,7));

			MGPIO_SetPinMode(PORTB,PIN6,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN6,GET_BIT(data,6));

			MGPIO_SetPinMode(PORTB,PIN5,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN5,GET_BIT(data,5));

			MGPIO_SetPinMode(PORTB,PIN4,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN4,GET_BIT(data,4));

			MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN HIGH
			MGPIO_SetPinValue(PORTB,PIN9,1);
			MSTK_voidDelayMsec(1);
			MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN LOW
				MGPIO_SetPinValue(PORTB,PIN9,0);
				MSTK_voidDelayMsec(1);


			MGPIO_SetPinMode(PORTB,PIN7,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN7,GET_BIT(data,3));

			MGPIO_SetPinMode(PORTB,PIN6,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN6,GET_BIT(data,2));

			MGPIO_SetPinMode(PORTB,PIN5,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN5,GET_BIT(data,1));

			MGPIO_SetPinMode(PORTB,PIN4,OUTPUT);
			MGPIO_SetPinValue(PORTB,PIN4,GET_BIT(data,0));


		MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN HIGH
		MGPIO_SetPinValue(PORTB,PIN9,1);
		MSTK_voidDelayMsec(1);
		MGPIO_SetPinMode(PORTB,PIN9,OUTPUT); // EN LOW
			MGPIO_SetPinValue(PORTB,PIN9,0);
			MSTK_voidDelayMsec(1);

}

void LCD_Init_4BIT(void)
{
	MSTK_voidDelayMsec(50);
	WriteIns_4BIT(0x02);//5*7 2 lines
	WriteIns_4BIT(0x28);//0x0c,0x0e,0x0f cursor
	WriteIns_4BIT(0x0c);
	//WriteIns_4BIT(0x01);
	//WriteIns(0x01);//clear screen
	MSTK_voidDelayMsec(1);
	WriteIns_4BIT(0x06);// increment DDRAM address, no shift

}
