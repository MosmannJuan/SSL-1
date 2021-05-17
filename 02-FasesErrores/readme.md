 ## Compilador utilizado y funcionalidad

GCC es el compilador utilizado, el cual proviene de la familia de compiladores de GNU.

El compilador ofrece una serie de comandos que permiten restringir el proceso de buildeo de manera que podamos "aislar" y obtener cada archivo correspondiente a cada etapa del proceso.

- **Archivo fuente preprocesado:**  Una vez pasadas las revisiones y ediciones del preprocesador, nos va a devolver un fuente preprocesado en un formato **(file.i)**. Análogamente, podemos crear un archivo con dicho formato lo cual le indicará al preprocesador que no debe revisar el archivo.
En Particular, con GCC, podemos obtener este archivo mediante el comando.

- - **cpp file.c > file.i **
- - **gcc -E file.c > file.i **

El resultado obtenido será el archivo en formato (.i)

-  **Archivo assembler:** Una vez compilado el archivo fuente preprocesado  **(file.i) **el resultado obtenido será un archivo en lenguaje assembler en formato **(file.s)**, en este caso, para un Intel x86
Para obtener este archivo en GCC, se utiliza.

- - **gcc -S file.i**

El cual dará como resultado un archivo en código assembler file.s el cual puee ser visualizado utilizando **more file.s**

. **Archivo objeto**: Luego de ser ensamblado y pasado a lenguaje de máquina, esto se puede obtener mediante:

- - **as -o file.o file.s**

El cual, si se quiere, se puede visualizar mediante **more file.o**

- **Linkeo y ejecutable:** Para la fase de linkeo, es necesario ingresar la ruta de la biblioteca estandar para incorporar el código binario de las funciones utilizadas (el vinculador no conoce de lenguaje c, en las bibliotecas ya se encuentra el código compilado y ensamblado).
Esto se puede realizar mediante:

- - **ld -o file.exe file.o (ruta de biblioteca estandar)** 
Esto último no es lo más común. Podemos ahorrar esto último con el comando
- - **gcc file.o **

El resultado final será el archivo ejecutable del programa.

**El proceso completo puede ser visualizado mediante el comando: gcc -v -o file.o file.c**


#### **Documentación utilizada**

- http://www.davidam.com/docu/gccintro.es.pdf
- https://gcc.gnu.org/onlinedocs/gcc-11.1.0/gcc.pdf
- https://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Overall-Options.html
- https://iie.fing.edu.uy/~vagonbar/gcc-make/gcc.htm
- https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html

~~------------------------------------------------------------------------------------------~~

# Secuencia de pasos

#### Preprocesador

#### **a.** 
Código utilizado **"hello2.c"**:
```c
#include <stdio.h>

int/*medio*/main(void){
int i=42;
prontf("La respuesta es %d\n");
```

#### **b.** 
Al preprocesarlo, no se generó ningún inconveniente. 
Esto se debe a que el preprocesador no se encarga de evaluar la sintaxis o código utilizado, no entiende de lenguaje C, sino que se encarga de llevar a cabo las acciones que lo involucren. 
En este caso, el preprocesador hará un copy de todo el contenido de stdio.h (por la instrucción **#include**) y lo traerá al código. Si visualizamos el contenido de **hello2.i** podremos visualizar que, además de lo que ya teníamos, trae las funciones contenidas en stdio.h, como si fuese un paste del contenido.
Además se encarga de reemplazar el comentario entre int y main por un espacio en blanco.

#### **c.**
Código utilizado "hello3.c":
```c
int printf(const char * restrict s, ...);

int main(void){
int i=42;
 prontf("La respuesta es %d\n");
```

#### **d.**

el termino **restrict** establece un "contrato" entre el parámetro y la función printf(). En otras palabra, estamos definiendo printf y no estamos obteniendo información de la misma por la biblioteca estandar.

#### **e.**

Al preprocesar **hello3.i** y al compararlo con **hello2.i** se puede visualizar que el contenido de **hello3.i** es exactamente el mismo que el de **hello3.c**, mientras que en **hello2.i** hay muchos más datos y funciones.
Esto ocurre debido a que en **hello3.i** no estamos utilizando la instrucción *#include* por lo cual el preprocesador no va a hacer un copy paste de todo lo que hay en stdio.h como lo hace con **hello2.i**.
Además, en **hello3.c** no hay comentarios.

~~------------------------------------------------------------------------------------------~~

#### Compilador

#### **b.**
Se genera el siguiente código, corrigiendo los errores, **"hello4.c"**:
```c
int printf(const char * restrict s, ...);

int main(void){
int i=42;
printf("La respuesta es %d\n");
}

```
Se le agrega una llave de cierre ** } ** a la función main y se corrige prontf por printf. 
Luego fue compilado para obtener las instrucciones lenguaje assembler.

#### **c.**

En el contenido de hello4.s tenemos:
```
      	.file	"hello4.c"
	.text
	.section	.rodata
.LC0:
	.string	"La respuesta es %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$42, -4(%rbp)
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	prontf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits

```

El lenguaje assembler es de un bajo nivel de abstracción y es la representación más entendible y directa del código máquina de cada arquitectura.
Cada procesador tiene un set de instrucciones con traducción a código binario incorporado. Esto le permite al programador poder interactuar con cada arquitectura y que luego el ensamblador se encargue de traducir cada instrucción a código máquina.

Por último, se ensambló **hello4.s**.


~~------------------------------------------------------------------------------------------~~

## Vinculación

#### **a.**

Al querer vincular hello4.o, obtenemos el siguiente mensaje:
**/usr/bin/ld: hello4.o: en la función `main': hello4.c:(.text+0x1c): referencia a `prontf' sin definir collect2: error: ld devolvió el estado de salida 1 **

#### **b.**

Se corrigió lo pedido en el mensaje en hello5.c
```c
int printf(const char * restrict s, ...);

int main(void){
int i=42;
printf("La respuesta es %d\n");
}

```
#### **c.**

Al buildear el hello5.c, el resultado final fue la obtención del ejecutable con el mensaje indicado, pero con la diferencia que el número mostrado en el printf es distinto en cada ejecución ya que no tiene el ** int i=42 **pasado como parámetro en el printf.

~~------------------------------------------------------------------------------------------~~

## Corrección de Bug

#### **a.**

Se crea hello6.c con la observación anterior.
```c
int printf(const char * restrict s, ...);

int main(void){
int i=42;
printf("La respuesta es %d\n", i);
}

```
El resultado obtenido es el esperado, imprime por pantalla el ** int i = 42 **

~~------------------------------------------------------------------------------------------~~

## Remoción de prototipo

#### **a.**
Se crea hello7.c:
```c
int main(void){
 int i=42;
 printf("La respuesta es %d\n", i);
}
```

#### **b.**

Al buildear, se cumplen todas las fases correctamente. Esto es debido a que el compilador se encarga de traer la biblioteca estándar para que se pueda compilar correctamente el programa. El mensaje que muestra la consola es el siguiente:

```c
gcc -S hello7.i
hello7.c: En la función ‘main’:
hello7.c:3:2: aviso: declaración implícita de la función ‘printf’ [-Wimplicit-function-declaration]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
hello7.c:3:2: aviso: declaración implícita incompatible de la función interna ‘printf’
hello7.c:1:1: nota: incluya ‘<stdio.h>’ o proporcione una declaración de ‘printf’
  +++ |+#include <stdio.h>
    1 | int main(void){

```

En la línea 8, se puede ver que el compilador nos advierte de la necesidad de tener la declaración de printf o traerla de la biblioteca estándar. En este caso, declara ** #include < stdio.h >** (Los +++ al principio indican que una línea fue agregada).

~~------------------------------------------------------------------------------------------~~

## Compilación Separada: Contratos y Módulos

Se escribe studio1.c y hello 8.c

studio1.c con su implementación:
```c
void prontf(const char* s, int i){
    printf("La respuesta es %d\n", i);
}
```
hello8.c (Sin incluir al header correspondiente)

```c
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```
#### **b.**

Al buildear hello8.c, se utiliza el comando: **  gcc hello8.c studio1.c -o hello8 ** para que en base a hello8.c y studio1.c se genere el ejecutable.
El compilador, al igual que ocurría en hello7.c, nos advierte de la declaración implícita (En este caso, de prontf) y se encarga de realizar una inclusión:

```c
hello8.c: En la función ‘main’:
hello8.c:3:2: aviso: declaración implícita de la función ‘prontf’ [-Wimplicit-function-declaration]
    3 |  prontf("La respuesta es %d\n", i);
      |  ^~~~~~
studio1.c: En la función ‘prontf’:
studio1.c:2:5: aviso: declaración implícita de la función ‘printf’ [-Wimplicit-function-declaration]
    2 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
studio1.c:2:5: aviso: declaración implícita incompatible de la función interna ‘printf’
studio1.c:1:1: nota: incluya ‘<stdio.h>’ o proporcione una declaración de ‘printf’
  +++ |+#include <stdio.h>
    1 | void prontf(const char* s, int i){

```
El ejecutable muestra el mensaje deseado.

#### **c.**

Al eliminar en studio1.c, el parámetro '"La respuesta es %d\n" y buildeamos, se genera el ejecutable, pero se muestra el siguiente mensaje ** Violación de segmento (core generado) **. Esto significa que el programa intenta entrar una sección el la memoria que no tiene permitida, es decir, está buscando acceder a un área más allá del límite posible establecido por el sistema operativo.
En nuestro caso, puede producirse porque la cadena tiene que tener el mismo número de conversores que argumentos pasados. Es decir, estamos haciendo un ** printf (i) ** sin pasarle, por ejemplo, un %d.

#### **d.**

Se escriben:
* hello9.c 

```c
#include "studio.h"
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```

* studio.h
```c
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_
void prontf(const char*, int);
#endif
```

* studio2.c

```c
#include "studio.h"
#include <stdio.h> 
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```
La ventaja de incluir el contrato entre el cliente y el proveedor, se encuentran por ejemplo en el compilador al cual le permite detectar errores relacionados con la invocación incorrecta (Consumidor) o la definición incorrecta (Proveedor). Se sabe cómo se usan las funciones y qué funciones tiene (El linker las busca y encuentra, si es que están en la biblioteca). Si no incluimos el contrato, no habría errores pero se incorporarían mal las funciones.

~~------------------------------------------------------------------------------------------~~


#### Investigue sobre bibliotecas. ¿Qué son? ¿Se puden distribuir? ¿Son portables?¿Cuáles son sus ventajas y desventajas?. Desarrolle y utilice la biblioteca studio.

Las bibliotecas contienen el código objeto de muchos programa que permiten hacer cosas comunes (Escribir en pantalla, realizar funciones matemáticas, etc).
Se pueden distribuir. Pero en cuanto a la portabilidad, depende del archivo, si fuese un archivo fuente sería portable, pero como se dijo anteriormente, las bibliotecas contienen lenguaje en código objeto, por lo cual dependerá de la arquitectura para poder interpretarlo.
Una ventaja es que nos proporcionan distintos tipos de funciones útiles para el desarrollo pero una desventaja es la anteriormente dicha sobre su portabilidad.

En el ejemplo utilizado anteriormente:

```c
#include "studio.h"
#include <stdio.h> 
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```

Define las funciones de la biblioteca. 

En el header:
```c
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_
void prontf(const char*, int);
#endif
```
Se declara la función. Es decir, la cabecera únicamente.

