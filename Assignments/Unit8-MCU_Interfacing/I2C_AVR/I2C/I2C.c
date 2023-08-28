
//
//
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
////2 HAL
////3 MCAL
//#include "DIO.h"
//#include "I2C.h"
//#include "avr/io.h"
//
//
//
//
//
//
//
//
//void I2C_SetAddress(u8 u8AddressCopy){
//	//setting 7 MSB of address register
//	TWAR = u8AddressCopy;
//
//}
//
//
//
//
//// Read address and continue to read data byte
//u8 I2C_Slave_Read(u8 *status)
//{
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
//	while(!GET_BIT(TWCR,TWINT));	// After its own slave address and the write bit have been received, the TWINT
//	// Flag is set and a valid status code can be read from TWSR
//
//	while (TWSR != TWSR_Add_ACK_RETURNED) {
//		// Handle error, expected SLA+R ACK not received
//		*status = TWSR_Add_ACK_RETURNED;
//	}
//	// Continue Listening
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
//	while(!GET_BIT(TWCR,TWINT));
//	// Data has been received ACK has been returned
//	while(TWSR != TWSR_Data_ACK_RETURNED){
//		*status = TWSR_Data_ACK_RETURNED;
//	}
//
//	return TWDR;
//}
//
//



/*
 * I2C.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Dell
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
//2 HAL
//3 MCAL
#include "DIO.h"
#include "I2C.h"
//4
#include "avr/io.h"
void I2C_Init(u32 SCL_Clock){
	//setting the TWBR value
	TWBR = (u8)(((F_CPU / SCL_Clock) -16) /(2*Prescaler));
	//setting prescalar in TWSR
	if(Prescaler ==1){
		CLEAR_BIT(TWSR ,TWPS0);
		CLEAR_BIT(TWSR ,TWPS1);
	}
	else if(Prescaler == 4 ){
		SET_BIT(TWSR ,TWPS0);
		CLEAR_BIT(TWSR ,TWPS1);
	}
	else if(Prescaler == 16){
		CLEAR_BIT(TWSR ,TWPS0);
		SET_BIT(TWSR ,TWPS1);
	}
	else if(Prescaler == 64){
		SET_BIT(TWSR ,TWPS0);
		SET_BIT(TWSR ,TWPS1);
	}
}


void I2C_Start(void){
	//clearing interrupt flag , setting start bit and twi enable
	TWCR = (1<< TWINT) | ( 1<< TWSTA) | ( 1<< TWEN);
	//to check if start bit is transmitted , flag should be set if transmission done.
	while((TWCR & (1<< TWINT))==0);
	//check statusto check start ack
	while(TWSR != I2C_START_ACK);
}

void I2C_Stop(void){
	//clearing interrupt flag , setting stop bit and twi enable
	TWCR = (1<< TWINT) | ( 1<< TWSTO) | ( 1<< TWEN);
}



void I2C_SetAddress(u8 u8AddressCopy){
	//setting 7 MSB of address register
	TWAR = u8AddressCopy;

}



u8 I2C_Read(u8 u8read){
	TWCR = (1<< TWINT) | ( 1<< TWEA) | ( 1<< TWEN);
	while(!(TWCR & (1<< TWINT)));

	return TWDR;
}




u8 I2C_ReadSlave(u8 u8read){

	TWCR = (1<< TWINT) | ( 1<< TWEA) | ( 1<< TWEN);
	while(!(TWCR & (1<< TWINT)));
	while(TWSR != I2C_ADDRESS_ACK);

	if(u8read ==1){
		TWCR = (1<< TWINT) | ( 1<< TWEA) | ( 1<< TWEN);
		while(!(TWCR & (1<< TWINT)));
		while(TWSR != I2C_DATA_ACK);
		return TWDR;
	}

}


void I2C_Write(u8 u8write){
	TWDR =u8write;
	// Clear TWINT bit in TWCR to start transmission
	TWCR = (1<< TWINT)  | ( 1<< TWEN);
	while((TWCR & (1<< TWINT))==0);
}








