/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : LIB		 				******/
/*********************************************************/
#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char		   u8;
typedef unsigned short int	   u16;
typedef unsigned long int	   u32;
typedef unsigned long long int u64;

typedef signed char			   s8;
typedef signed short int	   s16;
typedef signed long int 	   s32;
typedef signed long long int   s64;
							   
typedef float				   f32;
typedef double				   f64;
typedef long double 		   f128;

#define STD_TYPES_OK		1
#define STD_TYPES_NOK		0

#define NULL			   ((void*)0)			//Because NULL is defined inside stdio.h and we're not going to use that

#define	STD_HIGH			1
#define	STD_LOW				0

#endif
