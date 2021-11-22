#pragma config FOSC = HS     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 20000000


unsigned int i=1;
void main (void)
{
    TRISB = 0b00000000;
    TRISC = 0b11111111;
    PORTB = 0b00000000;
    while (1)
    {
        PORTB = i;
        __delay_ms(300);
        i=i*2;
        if (i==256)
        {
            i=1;
        }
        if(RC4==0)
        {
            if(i==1)
            {
                i=256;
            }
            while(RC4==0)
            {
                i=i/2;
                PORTB = i;
                __delay_ms(300);
                if (i==1)
                {
                    i=256;
                }
            }
            while(RC4==1)
            {
                i=i/2;
                PORTB = i;
                __delay_ms(300);
                if (i==1)
                {
                    i=256;
                }
            }
            if (i==256)
            {
                i=1;
            }
            while(RC4==0)
            {
                PORTB = i;
                __delay_ms(300);
                i=i*2;
                if (i==256)
                {
                    i=1;
                }
            }
        }    
    }
}