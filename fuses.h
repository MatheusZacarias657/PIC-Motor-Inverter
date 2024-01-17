/*
 * File: fuses.h
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#ifndef XC_FUSES_H
#define XC_FUSES_H

#pragma config  OSC = XT //XT oscillator 
#pragma config  FCMEN   = OFF       //Fail-Safe Clock Monitor disabled
#pragma config  IESO    = OFF       //Oscillator Switchover mode disabled
#pragma config  PWRT    = ON        //PWRT enabled
#pragma config  BOREN   = OFF       //Brown-out Reset disabled in hardware and software
#pragma config  WDT     = OFF       //WDT disabled (control is placed on the SWDTEN bit)
#pragma config  PBADEN  = OFF       //PORTB<4:0> pins are configured as digital I/O on Reset
#pragma config  MCLRE   = ON        //MCLR pin enabled; RE3 input pin disabled
//#pragma config  MCLRE   = OFF     //RE3 input pin enabled; MCLR disabled
#pragma config  STVREN  = ON        //Stack full/underflow will cause Reset
#pragma config  LVP     = OFF       //Single-Supply ICSP disabled
#pragma config  XINST   = OFF       //Instruction set extension and Indexed Addressing mode enabled
#pragma config  CP1     = OFF       //Block 1 (002000-003FFFh) not code-protected
#pragma config  CP2     = OFF       //Block 2 (004000-005FFFh) not code-protected
#pragma config  CP3     = OFF       //Block 3 (006000-007FFFh) not code-protected
#pragma config  CPB     = OFF       //Boot block (000000-0007FFh) not code-protected
#pragma config  CPD     = OFF       //Data EEPROM not code-protecte
#pragma config  WRT0    = OFF       //Block 0 (000800-001FFFh) not write-protected
#pragma config  WRT1    = OFF       //Block 1 (002000-003FFFh) not write-protected
#pragma config  WRT2    = OFF       //Block 2 (004000-005FFFh) not write-protected
#pragma config  WRT3    = OFF       //Block 3 (006000-007FFFh) not write-protected
#pragma config  WRTC    = OFF       //Configuration registers (300000-3000FFh) not write-protected
#pragma config  WRTB    = OFF       //Boot block (000000-0007FFh) not write-protected
#pragma config  WRTD    = OFF       //Data EEPROM not write-protected

#endif /* XC_FUSES_H */