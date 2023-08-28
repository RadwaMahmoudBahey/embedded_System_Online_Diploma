//
//#ifndef MCAL_I2C_I2C_H_
//#define MCAL_I2C_I2C_H_
//
//
//#define F_CPU 16000000UL
//
//
//// TWSR STATUS CODES
//#define TWSR_START_TRANSMITTED	0x08
//#define TWSR_Add_ACK_RETURNED	0x60
//#define TWSR_Data_ACK_RETURNED  0x80
//
//// Prescalares used in Bit rate
//#define I2C_PRESCALAR_1			1
//#define I2C_PRESCALAR_4			4
//#define I2C_PRESCALAR_16		16
//#define I2C_PRESCALAR_64		64
//
//#define I2C_PRESCALAR	I2C_PRESCALAR_1
//#define MASTER_TRANSMITTER_SLAVE_RECIEVER
//
//
//// APIs
//void I2C_Init(unsigned long SCL_Clock);
//void I2C_Start(void);
//void I2C_Write(u8 cByte);
//void I2C_Stop(void);
//void I2C_SetAddress(u8 slaveAddress);
//u8 I2C_Slave_Read(u8 *status);
//
//u8 I2C_Master_Read(void);
//
//
//#endif /* MCAL_I2C_I2C_H_ */
//
//
//
//
//
//




/*
 * I2C.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Dell
 */

#ifndef I2C_H_
#define I2C_H_

//mode
//#define MASTER_TRANSMITTER_SLAVE_RECIEVER
#define MASTER_RECIEVER_SLAVE_TRANSMITTER

//prescalar
#define Prescaler			1
// ack
#define I2C_ADDRESS_ACK   		0x60
#define I2C_DATA_ACK   			0x80
#define I2C_START_ACK   		0x08
//TWCR

#define TWINT				7
#define TWEA				6
#define TWSTA				5
#define TWSTO				4
#define TWEN				2



//TWSR
#define TWPS1				0
#define TWPS0				1


//APIS

void I2C_Init(u32 SCL_Clock);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SetAddress(u8 u8AddressCopy);
u8 I2C_Read(u8 u8read);
u8 I2C_ReadSlave(u8 u8read);
void I2C_Write(u8 u8write);


#endif /* I2C_H_ */
