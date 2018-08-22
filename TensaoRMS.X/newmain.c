/*
 Primeiro teste com LCD no pic18f4550
 */


#include <xc.h>
#include <stdio.h>      // biblioteca que contem o printf
#include <math.h>

#pragma config FOSC = XT_XT     // Oscilador com cristal
#pragma config WDT = OFF        // Watchdog desligado


void delay_ms(int tempo)
{
    while (tempo > 0)
    {
        
        T0CS = 0;
        PSA = 0;
        T0PS0 = 1;
        T0PS1 = 0;
        T0PS2 = 0;
        TMR0IF = 0;
        T08BIT = 1;
        TMR0L = 0;
        TMR0ON = 1;
        while (TMR0IF == 0);
        --tempo;
    }
}



void enviar_comando_lcd(char valor)
{
    PORTD = valor;
    PORTCbits.RC0 = 0;      // RS = 0
    PORTCbits.RC1 = 1;      // E = 1
    delay_ms(1);
    PORTCbits.RC1 = 0;      // E = 0
    delay_ms(1);
}

void escrever_lcd(char valor)
{
    PORTD = valor;
    PORTCbits.RC0 = 1;      // RS = 1
    PORTCbits.RC1 = 1;      // E = 1
    delay_ms(1);
    PORTCbits.RC1 = 0;      // E = 0
    delay_ms(1);
}

void putch (char x)
{
    escrever_lcd(x);
}

void inicializa_lcd()
{
// Function set
    // RS = 0
    // R/W = 0
    // DB7 = 0
    // DB6 = 0
    // DB5 = 1
    // DB4 = 1 (8 bits)
    // DB3 = 1 (2 linhas)
    // DB2 = 0 (fonte 5x7)
    // DB1 = *
    // DB0 = *
    enviar_comando_lcd(0b00111000); // Function Set (modo 8 bits, 1/16 duty(2 linhas), caractere 5x7
    enviar_comando_lcd(0b00001100); // Display On/Off Control, cursor ligado, piscante, display ligado
    enviar_comando_lcd(0b00000110); // Entry mode set, incrementa cursor, sem deslocamento do display
    enviar_comando_lcd(0b00000001); // limpar o display
    delay_ms(5);
}


void posicionar_cursor(int linha, int coluna)
{
// linha1
    if ((linha == 1) && (coluna == 1)) enviar_comando_lcd(0b10000000);
    if ((linha == 1) && (coluna == 2)) enviar_comando_lcd(0b10000001);
    if ((linha == 1) && (coluna == 3)) enviar_comando_lcd(0b10000010);
    if ((linha == 1) && (coluna == 4)) enviar_comando_lcd(0b10000011);
    if ((linha == 1) && (coluna == 5)) enviar_comando_lcd(0b10000100);
    if ((linha == 1) && (coluna == 6)) enviar_comando_lcd(0b10000101);
    if ((linha == 1) && (coluna == 7)) enviar_comando_lcd(0b10000110);
    if ((linha == 1) && (coluna == 8)) enviar_comando_lcd(0b10000111);
    if ((linha == 1) && (coluna == 9)) enviar_comando_lcd(0b10001000);
    if ((linha == 1) && (coluna == 10)) enviar_comando_lcd(0b10001001);
    if ((linha == 1) && (coluna == 11)) enviar_comando_lcd(0b10001010);
    if ((linha == 1) && (coluna == 12)) enviar_comando_lcd(0b10001011);
    if ((linha == 1) && (coluna == 13)) enviar_comando_lcd(0b10001100);
    if ((linha == 1) && (coluna == 14)) enviar_comando_lcd(0b10001101);
    if ((linha == 1) && (coluna == 15)) enviar_comando_lcd(0b10001110);
    if ((linha == 1) && (coluna == 16)) enviar_comando_lcd(0b10001111);
// linha2
    if ((linha == 2) && (coluna == 1)) enviar_comando_lcd(0b11000000);
    if ((linha == 2) && (coluna == 2)) enviar_comando_lcd(0b11000001);
    if ((linha == 2) && (coluna == 3)) enviar_comando_lcd(0b11000010);
    if ((linha == 2) && (coluna == 4)) enviar_comando_lcd(0b11000011);
    if ((linha == 2) && (coluna == 5)) enviar_comando_lcd(0b11000100);
    if ((linha == 2) && (coluna == 6)) enviar_comando_lcd(0b11000101);
    if ((linha == 2) && (coluna == 7)) enviar_comando_lcd(0b11000110);
    if ((linha == 2) && (coluna == 8)) enviar_comando_lcd(0b11000111);
    if ((linha == 2) && (coluna == 9)) enviar_comando_lcd(0b11001000);
    if ((linha == 2) && (coluna == 10)) enviar_comando_lcd(0b11001001);
    if ((linha == 2) && (coluna == 11)) enviar_comando_lcd(0b11001010);
    if ((linha == 2) && (coluna == 12)) enviar_comando_lcd(0b11001011);
    if ((linha == 2) && (coluna == 13)) enviar_comando_lcd(0b11001100);
    if ((linha == 2) && (coluna == 14)) enviar_comando_lcd(0b11001101);
    if ((linha == 2) && (coluna == 15)) enviar_comando_lcd(0b11001110);
    if ((linha == 2) && (coluna == 16)) enviar_comando_lcd(0b11001111);
}


void inicializa_ad()
{
    ADCON0 = 0b00000001;   // canal 0 selecionado, ad habilitado
    ADCON1 = 0b00001110;   // vref+ = 5v, vref- = gnd, an0 = analogico, outros = digital
    ADCON2 = 0b10010110;    // Justificado a direita, 4 TAD, FOSC/4  
}

int capturar_ad()
{
    int resultado;
    
    GO_DONE = 1;            // disparar o ad
    while (GO_DONE == 1);   // aguardar terminar
    resultado = (ADRESH << 8) | ADRESL;
    return (resultado);    
}

void inicializa_pinos()
{
    TRISC = 0b01110000;  // saida
    TRISD = 0;  // saida
    PORTC = 0;  // valor inicial
    PORTD = 0;  // valor inicial
}


void main(void)
{   
float volts, RMS, integral;

    inicializa_pinos();
    inicializa_lcd();
    inicializa_ad();
    posicionar_cursor(1, 1);    
    printf ("Vrms = ");
    while (1)
    {
        posicionar_cursor(1, 8);
        for (int i=0; i<100; i++){
            volts = capturar_ad()*(5.0/1023.0);             
            delay_ms(10);
            integral=volts*volts+integral;
        }
        RMS=sqrt(integral/100);
        printf ("%3.0f", RMS);
    }    
}
