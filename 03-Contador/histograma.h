#ifndef HISTOGRAMA_H_INCLUDED
#define HISTOGRAMA_H_INCLUDED;

struct ArregloDeLongitudes {
      int longitudes[100];
   };

void contadorSwitch(struct ArregloDeLongitudes *);
void contadorGoto(struct ArregloDeLongitudes *);
void contadorRecursivo(struct ArregloDeLongitudes *);
void contadorPorParametro(struct ArregloDeLongitudes*, int, int, int);

#endif