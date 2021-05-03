#include "Conversion.h"
#include <stdlib.h>  // system
#include <stdio.h>


void menu() {
    printf("Seleccione que tabla desea mostrar: \n");
    printf("c - Tabla de celsius a fahrenheit \n");
    printf("f - Tabla de fahrenheit a celsius \n");
    printf("Presione ESC para finalizar \n");
    printf("\n");
}

int main() {
char option;

while((int)option != 27) {
menu();
    option = getchar();
    printf("\n");
    switch(option) {
        // Pasamos los parámetros directamente para que no se realicen conversiones múltiples
        case 'c': {
            printTablas('c', 0, 300, 20);
            break;
        }

        case 'f': {
            printTablas('f', -17.8, 148.9, 11.1);
            break;
        }
    }
}
    return 0;
}