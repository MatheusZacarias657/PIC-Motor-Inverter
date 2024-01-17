/*
 * File:   general_lib.c
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#include "general_lib.h"
#include <xc.h>
#include "hardware.h"

void Delay(unsigned int interval)
{
    unsigned int i,j;

    for(i=0; i < interval; ++i)
    {
        //Approximately 1 ms Interval
        for(j = 0; j < 1000/9; ++j)
        {
        }
    };
}

void Delay_milliSecond(int delayMS)
{
	unsigned int i;
	for(; delayMS > 0;--delayMS)
	{
		for(i=0; i<=100; ++i)	{}
	}
}

void WriteSelectionPort(unsigned char selection)
{
    TRISE &= ~0x07;

    LATE |= 0x07;

    LATE &= (selection & 0x07);

    TRISB &= ~(1<<2);
    if(selection & (1<<3))
    {
        LATB |= (1<<2);
    }
    else
    {
        LATB &= ~(1<<2);
    }
}
void DeSelectAll(void)
{
    WriteSelectionPort(0x0F);
}
void Write_Port(unsigned char targetPort, unsigned char writeByte)
{
    DeSelectAll();	//All Clock Pin High

    DATA_BUS_DIR = 0;
    DATA_BUS = writeByte;

    WriteSelectionPort(targetPort);	//Clk pin Low

    DeSelectAll();	//Clock Pin Low to High
}

void Init_LatchedOutput(void){
    
    ADCON1 |= 0x0F;	//All Digital i/o
    TRISD = 0;	//Data Pins
    TRISB &= ~(1<<2);	//RB2
    TRISE &= ~(0x07);	//RE2,1,0
    Write_Port(SELECT_BCD_DATA, 0x0F);	//BCD to 7 Segment IC will switch off all LEDs
    DeSelectAll();
}