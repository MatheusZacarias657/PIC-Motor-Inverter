/*
 * File: main.c
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <pic18f4520.h>
#include "fuses.h"
#include "hardware.h"
#include "general_lib.h"
#include "lcd_lib.h"
#include "keys_lib.h"

void main(void){
    
    bool Hora, Anti, Freq;
    
    TRISCbits.RC2 = 0;
    TRISCbits.RC0 = 0;
    
    Init_LCD();
    ClearDisplay();
    Init_LatchedOutput();
    
    SetCharPosition (1,1);
    strcpy(str,(const char*)"INVERSOR DE");
    WriteString(str);
    SetCharPosition (2,1);
    strcpy(str,(const char*)"FREQUENCIA");
    WriteString(str);
    Delay (2000);
    Anti = Hora = Freq = 0;
    
    while(1){
        
        Delay (5);

        if (INT0 != 0 && INT1 != 0){
            while (Freq == 0){
                ClearDisplay();
                SetCharPosition (1,1);
                strcpy(str,(const char*)"INT0-HORARIO");
                WriteString(str);
                SetCharPosition (2,1);
                strcpy(str,(const char*)"INT1-ANTIHORARIO");
                WriteString(str);
                Anti = Hora = 0;
                Freq = 1;
            }
            
            Keys ();
        }
        
        if (INT0 == 0 && INT1 != 0){
            while (Hora == 0){
                ClearDisplay();
                SetCharPosition (1,1);
                strcpy(str,(const char*)"SENTIDO");
                WriteString(str);
                SetCharPosition (2,1);
                strcpy(str,(const char*)"HORARIO");
                WriteString(str);
                Anti = Freq = 0;
                Hora = 1;
            }
            
            Keys ();
        }
        
        if (INT1 == 0 || (INT1 == 0 && INT0 == 0)){
            while (Anti == 0){
                ClearDisplay();
                SetCharPosition (1,1);
                strcpy(str,(const char*)"SENTIDO");
                WriteString(str);
                SetCharPosition (2,1);
                strcpy(str,(const char*)"ANTIHORARIO");
                WriteString(str);
                Hora = Freq = 0;
                Anti = 1;
            }
            
            Keys ();
        }
        
        
    }
}