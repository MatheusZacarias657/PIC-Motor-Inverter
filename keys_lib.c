/*
 * File: keys_lib.c
 * Autor: Matheus Zacarias
 * Licence: GPL
 */

#include <xc.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "keys_lib.h"
#include "lcd_lib.h"
#include "general_lib.h"

void Keys(void){
    
    unsigned char INT0, INT1;
    int contador, posi, dec;
    char valor [5];
    bool chave1, chave2, seg;
    
    
    
    INT0 = PORTB & 0x01;
    INT1 = PORTB & 0x02;
    
    
    if (INT0 != 0 && INT1 != 0){
        
        DIN1 = DIN2 = 1;
        contador = chave1 = chave2 = 0;
        posi = 16;
        dec = 10;
        seg = 1;
        
     }
             
    if (INT0 == 0 && INT1 != 0){
        
        while (chave1 == 0){
            contador = 0;
            chave2 = 0;
            posi = 16;
            dec = 10;
            chave1 = 1;
        }
        
        while (seg == 0){
            contador = 0;
            chave2 = 0;
            posi = 16;
            dec = 10;
            chave1 = 0;
            seg = 1;
        }
        
        do{
            DIN1 = 0; 
            DIN2 = 0; 
            
            contador ++;
            itoa (valor, contador, 10);
            
            if (contador == dec){
                posi = posi - 1;
                dec = dec * 10;
            }
            
            SetCharPosition (2,posi);
            strcpy(str,(const char*)valor);
            WriteString(str);
            Delay (500);
            
        }while ((INT0 != 0) && (INT1 == 0)); 
    }   
    

            
    if (INT1 == 0 || (INT1 == 0 && INT0 == 0)){
        
        while (chave2 == 0){
            contador = 0;
            chave1 = 0;
            posi = 16;
            dec = 10;
            seg = 0;
            chave2 = 1;
        }
        
        do{
            DIN1 = 0;
            DIN2 = 1;
            
            contador ++;
            itoa (valor, contador, 10);
            
            if (contador == dec){
                posi = posi - 1;
                dec = dec * 10;
            }
            
            SetCharPosition (2,posi);
            strcpy(str,(const char*)valor);
            WriteString(str);
            Delay (500);
            
        }while (INT1 != 0);
    }
}
