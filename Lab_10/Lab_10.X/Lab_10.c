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

unsigned i=0, j=0;

void __interrupt() T0(void)
{
    i++;
    j++;
    if(j>256)
    {
        i=510-j;
        if(j==510)
        {
            j=0;
        }
    }
    CCPR1L = i;
    TMR2IF = 0;
}

void main(void)
{
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    PORTB = 0b00000000;
    GIE = 1;
    PEIE = 1;
    TMR2IE = 1;
    
    TMR2 = 0;
    PR2 = 256;
    
    CCPR1L = 150;
    CCP1CONbits.CCP1X = 0;
    CCP1CONbits.CCP1Y = 0;
    
    T2CONbits.TOUTPS = 0b1111;
    T2CONbits.T2CKPS = 0b11;
    T2CONbits.TMR2ON = 1;
    
    CCP1CONbits.CCP1M = 0b1111;
    
    while(1)
    {
        
    }    
}
