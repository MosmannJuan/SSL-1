#include "Conversion.h"
#include "stdio.h"

double celsius (double fahr) {
    return (5.0/9.0) * (fahr-32);
}

double fahrenheit (double cels) {
    return (cels*(9.0/5.0))+32 ;
}

void printFila (char convertTo, float aux, float LOWER, float UPPER, float STEP) {
    switch(convertTo) {

        case 'c': {
            aux = (int)aux;
            LOWER = (int)LOWER;
            UPPER = (int)UPPER;
            STEP = (int)STEP;
            printf("%3.0f %6.1f\n", aux,  celsius(aux));
        break;
        }
        case 'f': {
            printf("%6.1f %3.0f\n", aux, fahrenheit(aux));
        break;
        }
        
    }

}

void printFilas (char convertTo, float LOWER, float UPPER, float STEP) {
    switch(convertTo) {

        case 'c': {
            for(float fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
                printFila('c', fahr, LOWER, UPPER, STEP);
            }
            break;
        }
        case 'f': {
            for(float cels = LOWER; cels <= UPPER; cels = cels + STEP) {
                printFila('f', cels, LOWER, UPPER, STEP);
            }
            break;
        }

    }
}

void printTablaCelsius (int LOWER, int UPPER, int STEP) {
    printf("cels  fahr\n");
    printf("\n");
    printFilas('c', LOWER, UPPER, STEP);
    printf("\n");
}

void printTablaFahrenheit (float LOWER, float UPPER, float STEP) {
    printf("fahr  cels\n");
    printf("\n");
    printFilas('f', LOWER, UPPER, STEP);
    printf("\n");
}


void printTablas (char convertTo, float LOWER, float UPPER, float STEP) {
    // Le indicamos mediante convertTO que tabla mostrar.
    switch(convertTo) {
         case 'c': {
            //Convertimos los tipos de variable float a int
            LOWER = (int)LOWER;
            UPPER = (int)UPPER;
            STEP = (int)STEP;
            printTablaCelsius(LOWER, UPPER,STEP);
            break;
        }
        case 'f': {
            printTablaFahrenheit(LOWER, UPPER, STEP);
            break;
        }
        default: {
            break;
        }
    }
    
}


