#ifndef	MNVIC_PRV_H
#define MNVIC_PRV_H

#include"STD_TYPES.h"


#define			NVIC_BASE_ADDRESS			(0xE000E100)
#define			SCB_BASE_ADDRESS			(0xE000ED00)
typedef struct
{
	u32 ISER[8];
	u32 reserved0[24];
	u32 ICER[8];
	u32 reserved1[24];
	u32 ISPR[8];
	u32 reserved2[24];
	u32 ICPR[8];
	u32 reserved3[24];
	u32 IABR[8];
	u32 reserved4[56];
	u8 IPR[240];
	u32 reserved5[580];
	u32 STIR;

}NVIC_t;

#define NVIC         	( (volatile  NVIC_t *)(NVIC_BASE_ADDRESS))

#define MSCB_AIRCR		(*(volatile  u32 *)(SCB_BASE_ADDRESS))

#define	MNVIC_VECTKEY	0x05FA0000

#endif
