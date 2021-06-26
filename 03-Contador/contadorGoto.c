#include "contadores.h"
#include <stdio.h>


void contadorGoto(){
    int caracter, longitud = 0;
    FILE* almacen;
    FILE* lector; 
    almacen = fopen ("longitudesGoto.txt","w+");
    lector = fopen("palabrasALeer.txt", "r");
    
    leerCaracter:
        
        caracter = fgetc(lector); 

        if (caracter == ' ' || caracter == '\n' || caracter == '\r') goto finPalabra;

        if (caracter == EOF) goto enviarUltimaPalabraYFinalizar;
        
        goto agregarCaracterAlContador;            
                
    finPalabra:
        fprintf(almacen,"%d \n",longitud);
        longitud = 0;
        goto leerCaracter;

    agregarCaracterAlContador:
        longitud++;
        goto leerCaracter;
    
    enviarUltimaPalabraYFinalizar:
        fprintf(almacen,"%d \n",longitud);
        fclose(lector);
        fclose(almacen); 
   
}

