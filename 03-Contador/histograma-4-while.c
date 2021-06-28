#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

void contadorWhile () {
        int caracter, longitud = 0;
        STATE posicion;
        int longitudes[SIZE] = {0};

        posicion = IN;
        while(  ( caracter = getchar() )!= EOF  ) {
        if (caracter == ' ' || caracter == '\n' || caracter == '\r') {
                posicion = OUT;
        } else {
                ++longitud;
                }
        if (posicion == OUT) {
                posicion = IN;
                ++longitudes[longitud];
                longitud = 0;
                }
        }
        histograma(longitudes, SIZE);
}

