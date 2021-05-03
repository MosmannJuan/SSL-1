#ifndef CONVERSION_H_INCLUDED
static const int CONVERSION_H_INCLUDED; 
/* El tipo estático, permite mantener el ciclo de vida de la variable declarada. Esto lo hace
almacenando en la memoria la variable en cuestión, de manera que nunca será "destruida" durante
la ejecución del programa
Declaramos el tipo de variable const, indicando que su valor no va a cambiar en tiempo de 
ejecución.
*/

double celsius(double);
double fahrenheit(double);
void printTablas(char, float, float, float);

#endif

