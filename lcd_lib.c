/*
 * File: lcd_lib.c
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#include <string.h>
#include <xc.h>
#include "lcd_lib.h"
#include "general_lib.h"

void LCD_RS(unsigned char X){
    
    if(X){
        portByte |= (1<<PIN_RS);
    }
    else{
        portByte &= ~(1<<PIN_RS);
    }
    
    Write_Port(SELECT_LCD_CTRL, portByte);
}
void LCD_RW(unsigned char X){
    
    if(X){
        portByte |= (1<<PIN_RW);
    }
    else{
        portByte &= ~(1<<PIN_RW);
    }
    
    Write_Port(SELECT_LCD_CTRL, portByte);
}
void LCD_EN(unsigned char X){
   
    TRISC &= ~(1<<1);
    
    if(X){
        LATC |= (1<<1);
    }
    else{
        LATC &= ~(1<<1);
    }
}

void LCD_DB(unsigned char X){
	
    DATA_PORT_DIR = 0;
    LAT_DATA = X;
}

void Soft_NOP(void){

    NOP();
}

unsigned char IsBusy(void){
    
    unsigned int i,j;
    
    for(i = 0; i < 10; ++i){
        for(j = 0; j < 100; ++j)   
            NOP();
    };
    
    return 0x00;
}

void Write_IR(unsigned char instruction){
    
    int i;
    
    while( IsBusy() == 0xFF ){
    
        for(i = 0; i< 0xFF; ++i);
    };

    LCD_EN(0);
    LCD_RS(0);
    LCD_RW(0);

    Soft_NOP();

    LCD_DB(instruction);

    LCD_EN(1);

    Soft_NOP();

    LCD_EN(0);

    Soft_NOP();
}

void SetCharPosition(unsigned char lineNo,unsigned char charNo){
   
    unsigned char instruction;

    if((charNo >= 1) && (charNo <= 40)){
        instruction = charNo - 1;
    }
    else{
        return;
    }

    if(lineNo == 1){
        instruction |= 0x80;
    }
    else{
        instruction |= 0xC0;
    }
    Write_IR(instruction);	
                         
}

void Init_LCD(void){

    portByte = 0;

    Delay_milliSecond(100);

    DispDriverIOconfig();

    Write_IR(0x30); 	
    Delay_milliSecond(50);
    Write_IR(0x30);
    Delay_milliSecond(50);
    Delay_milliSecond(50);

    Write_IR(0x38); 	
    Write_IR(0x08);
    Write_IR(0x06);
    Write_IR(0x01);	
    Write_IR(0x0C);	
}

void WriteData(unsigned char b){

    IsBusy();   

    LCD_RS(1);

    LCD_RW(0);

    LCD_DB(b);   

    Soft_NOP();

    LCD_EN(1);

    Soft_NOP();

    LCD_EN(0);
}

void WriteString(char *s){
  
    unsigned char len,i;

    len = strlen(s);            

    if(len > (unsigned char)16)	len = 16;

    for(i = 0;i < len; i++){
        if(*s == '\n')	
            break;
        WriteData(*s);         
        s++;
    }
}

void WriteLCDRow(unsigned char lineNo,unsigned char charNo,char *s){
    
    SetCharPosition(lineNo, charNo);
    WriteString(s);
}

void ClearDisplay(void){
    
    Write_IR(0x01);
}

void DispDriverIOconfig(void){
    
    TRISC &= ~(1<<1);

    DATA_PORT_DIR = 0;
}
