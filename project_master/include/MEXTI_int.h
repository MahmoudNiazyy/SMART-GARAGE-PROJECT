#ifndef EXTI_INT_H
#define EXTI_INT_H

#include"STD_TYPES.h"


typedef enum {
	RISING_EDGE		=0,
	 FALLING_EDGE		,
	 ON_CHANGE
}EXTI_TriggerMode_t;

typedef enum{
	 EXTI_LINE0		  =0,
	 EXTI_LINE1			,
	 EXTI_LINE2			,
	 EXTI_LINE3			,
	 EXTI_LINE4		    ,
	 EXTI_LINE5		    ,
	 EXTI_LINE6		    ,
	 EXTI_LINE7		    ,
	 EXTI_LINE8		    ,
	 EXTI_LINE9		    ,
	 EXTI_LINE10	    ,
	 EXTI_LINE11	    ,
	 EXTI_LINE12	    ,
	 EXTI_LINE13	    ,
	 EXTI_LINE14	    ,
	 EXTI_LINE15	    ,
}EXTI_LINE_type;

void EXTI0_VoidCallBack(void (*ptr)(void));
void EXTI1_VoidCallBack(void (*ptr)(void));

void MEXTI_voidEnableEXTI(u8 Copy_uddtLineNum);
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);

void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

void MEXTI_voidSetTriggerSource(EXTI_LINE_type Copy_uddtLineNum, EXTI_TriggerMode_t Copy_uddtTriggerMode);

void MEXTI_voidSetPortExtiCfg(EXTI_LINE_type Copy_uddtLineNum, u8 Copy_u8GpioPortNum );


#endif
