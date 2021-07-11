#include "histograma.h"
#include <stdio.h>

void contadorGoto(struct ArregloDeLongitudes* arreglo){
    int caracter, longitud = 0;
    
    OUT:
        caracter = getchar();
        if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        goto OUT;
    }
        ++longitud;
        goto IN;

    IN:
    caracter = getchar();
    if(caracter == EOF) {
        if (ferror(stdin) && longitud > 0) 
            ++(arreglo -> longitudes[longitud]);
    return; 
    }
    else if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        ++(arreglo -> longitudes[longitud]);
        longitud = 0;
        goto OUT;
    }
    else {
        ++longitud;
        goto IN;        
    }
}

