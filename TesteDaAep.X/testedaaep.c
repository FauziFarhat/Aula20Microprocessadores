/*
 * File:   testedaaep.c
 * Author: Fauzi
 *
 * Created on 11 de Abril de 2018, 17:28
 */


#include <xc.h>

int main()

{

int x;


x = (0x8f > 0x90) || (0x8f < 0x90);

printf ("X = %d", x);

return 0;

}
