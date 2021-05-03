# Contenido

##  Conversion.c
Contiene las funciones de conversion:
- Fahrenheit
- Celsius

## Funciones de impresión por pantalla:

- PrintTablaCelsius
- printTablaFahrenheit
Las cuales utilizan printFilas que invoca sucesivamente a printFila para mostrar por pantalla cada conversion.

## Test de funciones:

En conversionTest se realizan, mediante asserts, el analisis de funcionamiento de celsius() y fahrenheit().

## Headers incluidos.

- stdio.h: Standard Input Output la cual es utilizada para obtener la información de printf y getchar
- assert.h: La cual contiene la funcion Assert para, en este caso, realizar distintas pruebas.
- stdlib.h: biblioteca estándar de uso general con la cual se utiliza system (Luego fue removida la función)

--------------------------------------------------------------------------------------------------------------------------------------

## Consigna

Este trabajo está basado en los ejercicios 1-4 y 1-15 de [KR1988] y aplica los
conceptos presentados en [Interfaces-Make]:

1-4. Escriba un programa para imprimir la tabla correspondiente de
Celsius a Fahrenheit
1-15. Reescriba el programa de conversión de temperatura de la sección

1.2 para que use una función de conversión.
Desarrollar un programa que imprima dos tablas de conversión, una de
Fahrenheit a Celsius y otra de Celsius a Fahrenheit.

### 6.1. Objetivos
• Aplicar el uso de interfaces y módulos.
• Construir un programa formado por más de una unidad de traducción.
• Comprender el proceso de traducción o Build cuando intervienen varios
archivos fuente.
• Aplicar el uso de Makefile.
Temas

### 6.2. Temas
• Makefile.
• Archivos header (.h).
• Tipo de dato double.
• Funciones.
• Pruebas unitarias.
• assert.
• Interfaces e Implementación.

### 6.3. Tareas
1. Escribir el Makefile.
2. Escribir Conversion.h
3. Escribir ConversionTest.c
4. Escribir Conversion.c
5. Escribir TablasDeConversion.c.

### 6.4. Restricciones
• Las dos funciones públicas deben llamarse Celsius y Farenheit.
• Utilizar assert.
• Utilizar const y no define.
• Utilizar for con declaración (C99)
