/*
 * File:   testesteste.c
 * Author: Fauzi
 *
 * Created on 3 de Junho de 2018, 20:36
 */


#include <xc.h>

void main(void) {
    
    T0CS = 0;

PSA = 0;

T0PS0 = 1;

T0PS1 = 0;

T0PS2 = 1;

TMR0IF = 0;

T08BIT = 1;

TMR0L = 0;

TMR0ON = 1;

while (TMR0IF == 0);  
    
    return;
}
