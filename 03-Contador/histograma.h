#ifndef CONTADORES_H_INCLUDED

typedef enum {
        IN = 1,
        OUT = 0,
        SIZE = 100
} STATE;

static const int CONTADORES_H_INCLUDED; 

void contadorSwitch(void);
void contadorWhile(void);
void contadorGoto(void);

#endif