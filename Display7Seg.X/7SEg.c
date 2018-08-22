/*
 * File:   Displayay.c
 * Author: Fauzi
 *
 * Created on 16 de Abril de 2018, 17:06
 */


#include <xc.h>

int cnt;
void incrementa(){
    if(RC0==1) {
        if (cnt<9) {
            while (RC0 == 1);
            cnt++;
        }
                
    }
}

void decrementa(){
    if(RC1==1){
        if(cnt>0){
            while(RC1==1);
            cnt--;
        }
    }
    
}

void mostrar(){
    switch (cnt){
        case 0: PORTD=0b00111111;
                break;
        case 1: PORTD=0b00000110;
                break;
        case 2: PORTD=0b01011011;
                break;
        case 3: PORTD=0b01001111;
                break;
        case 4: PORTD=0b01100110;
                break;
        case 5: PORTD=0b01101101;
                break;
        case 6: PORTD=0b01111101;
                break;
        case 7: PORTD=0b00000111;
                break;
        case 8: PORTD=0b01111111;
                break;
        case 9: PORTD=0b01101111;
                break;
    }
}


void main(void) {
    
    TRISD=0b00000000;
    TRISC=0b00000011;
    
    while(1){
        mostrar();
        if (RC0==1){
            incrementa();
        }
        else if(RC1==1){
            decrementa();
        }
    }
    
}
