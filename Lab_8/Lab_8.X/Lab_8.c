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

void strob (void)
{
    RC7 = 0;
    __delay_us (50);
    RC7 = 1;
    __delay_us (50);
}
char x;
char* v;
unsigned int i;
int A[16]={128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143};
void main (void)
{
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    
    __delay_ms (20);
    RC5=0;
    RC7=1;
    __delay_us (100);
    
    PORTB=0b00110000;
    __delay_ms (5);
    strob ();
    
    PORTB=0b00110000; 
    __delay_ms (5);
    strob ();
    
    PORTB=0b00110000;
    __delay_ms (5);
    strob ();
    
    PORTB=0b00111000;
    __delay_us (100);
    strob ();

    PORTB=0b00001100;
    __delay_us (100);
    strob ();
    
    PORTB=0b00000000;
    __delay_us (100);
      strob ();
    
    RC5 = 0;
    PORTB = 128;
    __delay_us (100);
    strob ();
    
    i = 0;
    RC5 = 0;
    PORTB = A[i];
    __delay_us (50);
    strob();
          
    while (1)
    {
        RC5 = 0;
        PORTB = A[i];
        __delay_us (50);
        strob();
        
        RC5 = 1;
        PORTB = 0b11110011;
        __delay_us (50);
        strob();
        __delay_ms (100);
        
        RC5 = 0;
        PORTB = A[i];
        __delay_us (50);
        strob();
        
        RC5 = 1;
        PORTB = ' ';
        __delay_us (50);
        strob();
        __delay_ms (1);
        i++;
        if(i==16)
        {
            while(i>=1)
            {
                RC5 = 0;
                PORTB = A[i];
                __delay_us (50);
                strob();
        
                RC5 = 1;
                PORTB = 0b11110011;
                __delay_us (50);
                strob();
                __delay_ms (100);
            
                RC5 = 0;
                PORTB = A[i];
                __delay_us (50);
                strob();

                RC5 = 1;
                PORTB = ' ';
                __delay_us (50);
                strob();
                __delay_ms (1);
                i--;
            }
        }
    }
}