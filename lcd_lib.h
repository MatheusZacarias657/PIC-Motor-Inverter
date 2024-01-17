/*
 * File: lcd_lib.h
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#ifndef XC_LCD_LIB_H
#define XC_LCD_LIB_H

#define	PIN_RS	0                      // LCD Register Select
#define	PIN_RW	1                      // LCD ReadWrite
#define	PIN_EN	4                      // LCD Enable
#define	DATA_PORT_DIR           TRISD  //RD0	RD1	RD2	RD3	RD4	RD5	RD6	RD7
#define	LAT_DATA                LATD

const char blankLine[] = "                ";

void LCD_RS(unsigned char X);
void LCD_RW(unsigned char X);
void LCD_EN(unsigned char X);
void LCD_DB(unsigned char X);
void Soft_NOP(void);
unsigned char IsBusy(void);
void Write_IR(unsigned char instruction);
void SetCharPosition(unsigned char lineNo,unsigned char charNo);
void Init_LCD(void);
void WriteData(unsigned char b);
void WriteString(char *s);
void WriteLCDRow(unsigned char lineNo,unsigned char charNo,char *s);
void ClearDisplay(void);
void DispDriverIOconfig(void);

#endif /* XC_LCD_LIB_H */