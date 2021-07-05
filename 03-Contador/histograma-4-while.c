#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

typedef enum {
        IN = 1,
        OUT = 0
} STATE;

void contadorWhile () {
        int caracter, longitud = 0;
        STATE estado;
        int longitudes[SIZE] = {0};

        estado = IN;
        while(  ( caracter = getchar() )!= EOF  ) {
        if (caracter == ' ' || caracter == '\n' || caracter == '\r') {
                estado = OUT;
        } else {
                ++longitud;
                }
        if (estado == OUT) {
                estado = IN;
                ++longitudes[longitud];
                longitud = 0;
                }
        }
        histograma(longitudes, SIZE);
}

