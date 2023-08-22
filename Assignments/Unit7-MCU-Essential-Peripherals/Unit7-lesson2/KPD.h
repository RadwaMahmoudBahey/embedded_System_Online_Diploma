#ifndef KPD_H_
#define KPD_H_

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KPD_DIRECTION 	DDRD
#define KPD_VALUE 		PORTD
#define KPD_READ_VALUE 	PIND

#define COLUMNS_SIZE 4
#define ROWS_SIZE 4
#define ArrValues {{'7','8','9','%'},\
		{'4','5','6','X'},\
		{'1','2','3','-'},\
		{'?','0','=','+'}}
void KPD_Init(void);
char KPD_Value(void);

#endif
