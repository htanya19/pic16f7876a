/*
 * File:   Lab_5.c
 * Author: tanya
 *
 * Created on 21 ?????? 2021, 10:56
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 20000000

void select(int j) {
    switch(j)
    {
        case 0:
            PORTB = ~0b00111111;
            break;
        case 1:
            PORTB = ~0b00000110;
            break;
        case 2:
            PORTB = ~0b01011011;
            break;
        case 3:
            PORTB = ~0b01001111;
            break;
        case 4:
            PORTB = ~0b01100110;
            break;
        case 5:
            PORTB = ~0b01101101;
            break;
        case 6:
            PORTB = ~0b01111101;
            break;
        case 7:
            PORTB = ~0b00000111;
            break;
        case 8:
            PORTB = ~0b11111111;
            break;
        case 9:
            PORTB = ~0b01101111;
            break;
    }
}

void main(void)
{
    unsigned int j=0;
    TRISB = 0b00000000;
    TRISC = 0b11111111;
    PORTB = 0b00000000;

    while(1)
    {
        select(j);
        if(RC5==0)
        {
            j++;
            if(j==10)
            {
                j=0;
            }
            select(j);
                
            while(RC5==0)
            {
                __delay_ms (10);
            }
        }
        if(RC6==0)
        {
            j--;
            if(j==-1)
            {
                j=9;
            }
            select(j);
                
            while(RC6==0)
            {
                __delay_ms (10);
            }
        } 
    }
}
