#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

void contadorSwitch () {
    int caracter, longitud = 0;
    STATE posicion;
    int longitudes[SIZE] = {0};

    posicion = IN;
    while((caracter = getchar()) != EOF) {
        switch(posicion){
            case OUT:
            posicion = IN;
            longitud = 1;
            break;

            case IN:
                switch(caracter) {
                case '\n':
                case ' ':
                        ++longitudes[longitud];
                        posicion = OUT;
                break;
                default:
                    ++longitud;
                break;
                }
            break;   
        }  
    
    }
    histograma(longitudes, SIZE);
}

