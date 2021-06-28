#include "contadores.h"
#include <stdio.h>

#define IN  1
#define OUT  0

void contadorSwitch () {
    int caracter, longitud = 0, posicion;
    FILE* almacen;
    almacen = fopen ("longitudesSwitch.txt","w+");

    posicion = IN;
    while(  ( caracter = getchar() )!= EOF  ) {
    switch(caracter) {
        case '\n':
        case ' ':
        case '\r':
                fprintf(almacen,"%d \n", longitud);
                posicion = OUT;
        break;
        default:
            if (posicion == OUT) {
                posicion = IN;
                longitud = 1;
            }
            else
                ++longitud;
        break;
    }
    }
    fclose(almacen);
}

