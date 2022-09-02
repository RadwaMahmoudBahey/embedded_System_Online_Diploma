#ifndef TYPE_H_
#define TYPE_H_
typedef unsigned char		Boolean;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
typedef unsigned char			uint8;
typedef signed char		    	sint8;
typedef unsigned short			uint16;
typedef signed short	   		sint16;
typedef unsigned int			uint32;
typedef signed int		    	sint32;
typedef unsigned long long int	uint64;
typedef signed long long int    sint64;
typedef float   		    	float32;
typedef double   		    	float64;

typedef volatile unsigned char			vuint8_t;
typedef volatile signed char			vint8_t;
typedef volatile unsigned short			vuint16_t;
typedef volatile signed short	    	vint16_t;
typedef volatile unsigned int			vuint32_t;
typedef volatile signed int		        vint32_t;
typedef volatile unsigned long long int	vuint64;
typedef volatile signed long long int   vint64;
typedef volatile float   		    	vfloat32;
typedef volatile double   		   		vfloat64;
#endif
