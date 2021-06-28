#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

void menu() {
    printf("Seleccione que contador desea usar: \n");
    printf("a - Contador con while \n");
    printf("b - Contador con switch \n");
    printf("c - Contador con goto\n");
    printf("Presione ESC para finalizar \n");
    printf("\n");
}


int main() {
   int opcion;
   menu();
   opcion = getchar();
      switch (opcion) {
         case 'a':
            system("clear");
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorWhile();
         break;
         case 'b':
            system("clear");
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorSwitch();
         break;
         case 'c':
            system("clear");
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorGoto();
         break;
      }

   return 0;
}

