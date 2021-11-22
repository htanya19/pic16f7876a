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

int i=0;
void __interrupt() T0 (void)
{
    i++;
    TMR0IF = 0;
    if(i==34)
    {
        TMR0 = 167;
    }
    if(i==35)
    {
        RB0 = ~RB0;
        i = 0;
    }    
        
}

void main(void)
{
    TRISB = 0b00000000;
    PORTB = 0b00000000;
      T0CS = 0;
      PSA = 0;
      OPTION_REGbits.PS = 0b111;
      TMR0 = 0;
        GIE = 1;
        PEIE = 1;
        TMR0IE = 1;
    
    while(1)
    {
        RB1=~RB1;
        __delay_ms (20);
    }
}
