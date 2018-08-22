/*
 * File:   Contador0a99.c
 * Author: Fauzi
 *
 * Created on 17 de Abril de 2018, 19:48
 */


#include <xc.h>
int cnt, dezena, unidade, centena, milhar;
void delay(){
    long x=5000;
    while(x>0) x--;
    
}
void delay_mx(){
    long x=5000;
    while(x>0) x--;
}
void incrementa(){
    if (cnt<9999){
    if (RC0==1){
        cnt++;
        
    }    
    }
}

void mostrar(){
    milhar=cnt/1000;
    centena=cnt/100;
    dezena=cnt/10;
    unidade=cnt%10;
    
    
    switch (milhar){
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
    RC1=1;
    RC2=0;
    RC4=0;
    RC5=0;
    RC6=0;
    delay_mx();
    
    
    switch (centena){
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
    
    RC1=0;
    RC2=1;
    RC4=0;
    RC5=0;
    delay_mx();
    
    
    switch (dezena){
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
    RC1=0;
    RC2=0;
    RC4=1;
    RC5=0;
    delay_mx();
    
        switch (unidade){
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
    RC1=0;
    RC2=0;
    RC4=0;
    RC5=1;
    delay_mx();
}



void main() {
    cnt=0;
    TRISD=0b00000000;
    TRISC=0b00000001;
    
    while(1){
        mostrar();
        if (RC0==1){
            incrementa();
        }  
        delay();
    }
  
}
