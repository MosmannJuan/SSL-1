#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

typedef enum {
        IN = 1,
        OUT = 0
} STATE;

void contadorSwitch () {
    int caracter, longitud = 0;
    STATE estado;
    int longitudes[SIZE] = {0};

    estado = OUT;
    while((caracter = getchar()) != EOF) {
        switch(estado){
            case OUT:
              switch(caracter) {
                case '\n':
                case '\t':
                case ' ':
                    ++longitudes[longitud];
                break;
                default:
                    estado = IN;
                    longitud = 1;
                break;
                }

            break;

            case IN:
                switch(caracter) {
                case '\n':
                case '\t':
                case ' ':
                        ++longitudes[longitud];
                        estado = OUT;
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

