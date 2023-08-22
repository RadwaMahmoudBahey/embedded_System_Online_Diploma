
#include "BIT_MATH.h"
//2-mcal
#include "KPD.h"
//3-AVR
#include "avr/io.h"
#include "util/delay.h"
void KPD_Init(void){
	KPD_DIRECTION = 0xF0; // columns as output , rows input
	KPD_VALUE=0xFF; // rows PUR , columns values are high
}
char KPD_Value(void){
	volatile char i,j;
	char KPD_ColumnPin[COLUMNS_SIZE]={C0 ,C1 ,C2 ,C3};
	char KPD_RowPin[ROWS_SIZE]={R0,R1 ,R2 , R3};
	for(i=0;i< COLUMNS_SIZE;i++){
		CLEAR_BIT(KPD_VALUE,KPD_ColumnPin[i]);
		for (j=0 ; j <ROWS_SIZE ;j++){
			char value = GET_BIT(KPD_READ_VALUE,KPD_RowPin[j]);
			if(value ==0){
				//for debouncing:
				_delay_ms(50);
				value = GET_BIT(KPD_READ_VALUE,KPD_RowPin[j]);
				if(value ==0){
					//for polling
					while(value ==0)
						value = GET_BIT(KPD_READ_VALUE,KPD_RowPin[j]);
					char KPD_Arr[COLUMNS_SIZE][ROWS_SIZE] =ArrValues;
					return KPD_Arr[j][i];
				}
			}
		}
		SET_BIT(KPD_VALUE,KPD_ColumnPin[i]);

	}
	return 'A';
}
