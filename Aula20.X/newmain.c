/*
 * File:   aula.c
 * Author: Administrador
 *
 * Created on 16 de Maio de 2018, 08:34
 */
#pragma config FOSC = XT_XT
#pragma config WDT = OFF

#include <xc.h>
void delay_ms(int tempo)
{
    int x;
    T08BIT = 0;
    T0CS = 0;
    PSA = 1;
    for (x=0; x<tempo; ++x)
    {
        TMR0H = 0xfc;
        TMR0L = 0x18;
        TMR0IF = 0;
        TMR0ON = 1;
        while(TMR0IF == 0);
    }
}


void main(void){
    TRISD = 0b00000000;
    int f=1;
    int T=1;
    PORTD=0;
    int duty = 10;
    while(1)
    {
       /* if(RC5==1 && f<20){
            f=f+1;
            while(RC5==1);
        }
        else if(RC4==1 && f>1){
            f=f-1;
            while(RC4==1);
        }*/
        if ((RC1==1) && (duty<15)){
                                  
                duty=duty+1;
                while(RC1==1);
                   }
        else if((RC0==1)&& (duty>1)){
                duty=duty-1;
                while(RC0==1);
               }
        PORTD=255;
        //RD1=1;
        delay_ms(duty);
        PORTD=0;
        //RD1=0;
        delay_ms(15-duty);
    
        /*
        delay_ms(1000);
        RD0 = 1;
        delay_ms(1000);
        RD0 = 0; */
    }
    return;
}


