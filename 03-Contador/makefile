histograma: main.o histograma-1-enum-switch.o histograma-4-while.o histograma-2-goto.o Graficador.o
	gcc -o histograma main.o histograma-1-enum-switch.o histograma-4-while.o histograma-2-goto.o Graficador.o -std=c99

histograma-1-enum-switch.o: histograma-1-enum-switch.c Graficador.h Graficador.h
	gcc -c histograma-1-enum-switch.c

histograma-4-while.o: histograma-4-while.c Graficador.h Graficador.h
	gcc -c histograma-4-while.c

main.o: main.c Graficador.h
	gcc -c main.c

histograma-2-goto.o: histograma-2-goto.c Graficador.h Graficador.h
	gcc -c histograma-2-goto.c

Graficador.o: Graficador.c Graficador.h
	gcc -c Graficador.c