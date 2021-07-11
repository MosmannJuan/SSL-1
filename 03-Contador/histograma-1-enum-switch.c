#include "histograma.h"
#include <stdio.h>

typedef enum {
        IN = 1,
        OUT = 0
} STATE;

void contadorSwitch (struct ArregloDeLongitudes* arreglo) {
    int caracter, longitud = 0;
    STATE s;

    s = OUT;
    while((caracter = getchar()) != EOF) {
        switch(s){
            case OUT:
              switch(caracter) {
                case '\n':
                case '\t':
                case ' ':
                   ++(arreglo -> longitudes[longitud]);
                break;
                default:
                    s = IN;
                    ++longitud;
                break;
                }

            break;

            case IN:
                switch(caracter) {
                case '\n':
                case '\t':
                case ' ':
                        ++(arreglo -> longitudes[longitud]);
                        longitud = 0;
                        s = OUT;
                break;
                default:
                    ++longitud;
                break;
                }
            break;   
        }  
    
    }
        if (ferror(stdin) && longitud > 0) {
            ++(arreglo -> longitudes[longitud]);
            return; 
        }
}

