// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 20000000

#define dig1 RC0
#define dig2 RC1
#define dig3 RC2
#define dig4 RC3

unsigned int a,b,c,d,e,f,g,h;
int i = 0;
int flag = 0;

unsigned int seg[]={0b00111111,
                    0b00000110,
                    0b01011011,
                    0b01001111,
                    0b01100110,
                    0b01101101,
                    0b01111101,
                    0b00000111,
                    0b11111111,
                    0b01101111
                    };

void main(void){
    TRISC = 0b00000000;
    TRISB = 0b00000000;
    PORTC = 0b00000000;
    PORTB = 0b00000000;
    
    while(1)
    {
        a=i%10;
        b=i/10;
        c=b%10;
        d=b/10;
        e=d%10;
        f=d/10;
        g=f%10;
        h=f/10;
        
        PORTB=seg[g];
        dig1=1;
        __delay_ms(5);
        dig1=0;
        PORTB=seg[e];
        dig2=1;
        __delay_ms(5);
        dig2=0;
        PORTB=seg[c];
        dig3=1;
        __delay_ms(5);
        dig3=0;
        PORTB=seg[a];
        dig4=1;
        __delay_ms(5);
        dig4=0;
        
        if(flag>=10)
        {
            i++;
            flag=0;
        }
        flag++; 

    }
}