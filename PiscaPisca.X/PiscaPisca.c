#include <xc.h>

void acende(){
    RD0=1;    
}
void apaga(){
    RD0=0;
}
void delay(){
    long x=100000;
    while(x>0) x--;
}

void main(void) {
    TRISD=0b00000000;
    
    while(1){
        acende();
        delay();
        apaga();
        delay();
        
        
    }
    
    
    
    
}
