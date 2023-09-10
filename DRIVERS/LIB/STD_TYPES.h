
#ifndef STD_TYPES_
#define STD_TYPES_
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f96;

typedef unsigned char uint8_t;
typedef unsigned char* ptr_uint8_t;


typedef unsigned char			STATUS_t ;
#define OK  		(STATUS_t)0x00
#define NOK  		(STATUS_t)0x01

typedef void(* ptr_func)(void);
#define NULL_PTR  		(void *)0

#endif
