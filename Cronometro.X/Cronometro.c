/*
 * File:   Contador0a99.c
 * Author: Fauzi
 *
 * Created on 17 de Abril de 2018, 19:48
 */


#include <xc.h>
int cnt_1ms=0, cnt_10ms=0, cnt_s=0, unidade_c=0, dezena_c=0, unidade_s=0, dezena_s=0;
void delay(){
    long x=5000;
    while(x>0) x--; 
}
void delay_ms(int x){
    while(x>0){
        for (int y=0; y<1; y++){
        }
        x--;
    }
}
void delay_mx(){
    long x=5000;
    while(x>0) x--;
}
void incrementa(){
    cnt_10ms++;
    if(cnt_10ms>99){
        cnt_10ms=0;
        cnt_s++;
    }
    if (cnt_s>99){
        cnt_s=0;
    }
}

void mostrar(){
    dezena_s=cnt_s/10;
    unidade_s=cnt_s%10;
    dezena_c=cnt_10ms/10;
    unidade_c=cnt_10ms%10;
    
    
    switch (dezena_s){
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
    delay_ms(1);
    
    
    switch (unidade_s){
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
    delay_ms(1);
    
    
    switch (dezena_c){
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
    delay_ms(1);
    
        switch (dezena_s){
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
    delay_ms(1);
}



void main() {
    TRISD=0b00000000;
    TRISC=0b00000001;
    
    while(1){
        mostrar();
        if (RC0==1){
            cnt_1ms++;
            if(cnt_1ms>=10){
                incrementa();
                cnt_1ms=0;
            }
            delay_ms(1);
        }  
    }
  
}
