contadores: contadores.o contadorSwitch.o contadorWhile.o contadorGoto.o histograma.o
	gcc -o contadores contadores.o contadorSwitch.o contadorWhile.o contadorGoto.o histograma.o -std=c99

contadorSwitch.o: contadorSwitch.c contadores.h
	gcc -c contadorSwitch.c

contadorWhile.o: contadorWhile.c contadores.h
	gcc -c contadorWhile.c

contadores.o: contadores.c contadores.h
	gcc -c contadores.c

contadorGoto.o: contadorGoto.c contadores.h
	gcc -c contadorGoto.c

histograma.o: histograma.c histograma.h
	gcc -c histograma.c