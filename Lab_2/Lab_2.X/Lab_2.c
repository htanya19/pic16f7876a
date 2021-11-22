/*
 * File:   Lab_2.c
 * Author: tanya
 *
 * Created on 15 ??????? 2021, 20:21
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
unsigned int i;

void main(void) {
    TRISB = 0b00000000;
    PORTB = 0b00000000;
    i = 1;
    while (1)
    {
        PORTB = i;
        __delay_ms (300);
        i = i*2;
        if (i>128)
        {
            i = 1;
        }
    }
}