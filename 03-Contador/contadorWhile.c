#include "contadorWhile.h"





int caracter, longitud = 0, posicion;
FILE* almacen;
almacen = fopen ("longitudesWhile.txt","w+");

posicion = IN;
//Lee caracteres mientras no encuentra el EOF
while(  ( caracter = getchar() )!= EOF  ) {
    if (caracter == ' ' || caracter == '\n' || caracter == '\r') {
            posicion = OUT;
    } else {
            ++longitud;
            }
    if (posicion == OUT) {
            posicion = IN;
            fprintf(almacen,"%d \n",longitud);
            longitud = 0;
        }
    }
   fclose(almacen);

