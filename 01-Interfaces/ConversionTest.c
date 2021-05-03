#include "Conversion.h"
#include <assert.h>
#include <stdio.h>

int main(void) {

    assert(fahrenheit(0)  == 32);
    assert(fahrenheit(0)  != 25);

    //Pruebas de conversion a celsius
    assert(celsius(32)  == 0);
    assert(celsius(25)  != 0);

    printf("Test superado, presione enter para continuar.\n");
    getchar();

    return 0;
}