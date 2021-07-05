#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

void contadorGoto(){
    int caracter, longitud = 0, stopper = 0;
    int longitudes[SIZE] = {0};
    
    IN:
    caracter = getchar();
    if(caracter == EOF) {
        if (stopper == 0) {
            stopper = 1;
            histograma(longitudes, SIZE);
        }
    }
    else if (caracter == ' ' || caracter == '\n' || caracter == '\t') 
        goto OUT;
    else {
        ++longitud;
        goto IN;        
    }
                
    OUT:
        ++longitudes[longitud];
        longitud = 0;
        goto IN;
   
}

