/*
 * File: general_lib.h
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#ifndef XC_GENERAL_LIB_H
#define XC_GENERAL_LIB_H

#define DATA_BUS        LATD
#define DATA_BUS_DIR	TRISD

#define	SELECT_COLUMN	0
#define SELECT_ROW      1
#define SELECT_STEPPER	2
#define SELECT_BCD_DATA	3	//CS-SEG_DATA 	: BCD DATA TO SEVEN SEGMENT LED
#define SELECT_7SDIGIT	4	//CS-SEG_DECODER: SELECTING THE 7 SEGMENT LED DIGIT
#define SELECT_POT2     5
#define SELECT_POT1     6
#define SELECT_EEPROM	7
#define SELECT_LCD_CTRL	8	//CS-174 : CHAR LCD CONTROL PINS

unsigned char portByte;
char str[32];

void Delay(unsigned int interval);
void Delay_milliSecond(int delayMS);
void WriteSelectionPort(unsigned char selection);
void DeSelectAll(void);
void Write_Port(unsigned char targetPort, unsigned char writeByte);
void Init_LatchedOutput(void);

#endif /* XC_GENERAL_LIB_H */