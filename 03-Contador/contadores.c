#include <stdio.h>
#include <stdlib.h>
#include "contadores.h"

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
   while((int)opcion != 27) {
      switch (opcion) {
         case 'a':
            system("clear");
            printf("Escriba caracteres y luego presione escape para finalizar... \n");
            contadorWhile();
            system("clear");
         break;
         case 'b':
            system("clear");
            printf("Escriba caracteres y luego presione escape para finalizar... \n");
            system("clear");
         break;
         case 'c':
            system("clear");
            printf("Escriba caracteres y luego presione escape para finalizar... \n");
            contadorGoto();
            system("clear");
         break;
      }
      menu();
      opcion = getchar();
   }

   return 0;
}

