

//
//#define Act_As_Master
////#define Act_As_Slave
//
//#define F_CPU 16000000UL
//
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
////2 HAL
////3 MCAL
//#include "DIO.h"
//#include "I2C.h"
////4
//#include "avr/io.h"
//#include "util/delay.h"
//
//
//
//int main()
//{
//#ifdef Act_As_Master
//	unsigned char ch= 0;
//	I2C_Init(0x48);
//	while(1)
//	{
//		_delay_ms(500);
//		I2C_Start();
//		I2C_Write(0b11010000+0); // Transmit SLA+W(0)
//		while((TWSR&0xF8)!=0x18);		// SLA+W has been transmitted ACK has been received
//		I2C_Write(ch++);
//		while((TWSR&0xF8)!=0x28);		// Data byte has been transmitted ACK has been received
//		I2C_Stop();
//	}
//
//
//	return 0;
//#endif
//
//#ifdef Act_As_Slave
//	u8 status;
//	DDRA = 0xFF;
//	I2C_Set_Address(0b1101000);
//	while(1){
//		PORTA = I2C_Slave_Read(&status);
//	}
//
//
//	return 0;
//#endif
//
//
//}
//
//
//




/*
 * main.c

 *
 *  Created on: Aug 28, 2023
 *      Author: Dell
 */

#define F_CPU 8000000ul
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//2 HAL
//3 MCAL
#include "DIO.h"
#include "I2C.h"
//4
#include "avr/io.h"
#include "util/delay.h"

//MASTER OR SLAVE
//#define MASTER
#define SLAVE
void main(){
#ifdef MASTER
	u8 value =0;
	I2C_Init(0x48);

#ifdef MASTER_TRANSMITTER_SLAVE_RECIEVER
	while(1){
		_delay_ms(500);
		I2C_Start();
		I2C_Write(0b11010000+0); // address + 0 for writing
		while((TWSR &0xF8) != 0x18);	//ack recieved for address
		I2C_Write(value++); // data
		while((TWSR &0xF8) != 0x28);	//ack recieved for data
		I2C_Stop();
	}
#endif
#ifdef MASTER_RECIEVER_SLAVE_TRANSMITTER
	DDRA = 0xFF;
	while(1){
		_delay_ms(500);
		I2C_Start();
		I2C_Write(0b11010000+1); // address + 1 for reading
		PORTA = I2C_Read(0);
		I2C_Stop();
		_delay_ms(500);
	}
#endif
#endif
#ifdef SLAVE


#ifdef MASTER_TRANSMITTER_SLAVE_RECIEVER


	DDRA = 0xFF;
	I2C_SetAddress(0b11010000);
	while(1){
		PORTA = I2C_ReadSlave(1);
	}

#endif
#ifdef MASTER_RECIEVER_SLAVE_TRANSMITTER
	u8 value =0;
	I2C_SetAddress(0b11010000);
	while(1){
		I2C_Read(0);
		I2C_Write(value++); // data
	}

#endif




#endif
}
