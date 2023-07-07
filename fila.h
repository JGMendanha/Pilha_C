#ifndef Fila_HEADER
#define Fila_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

typedef struct fila {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void Enfileirar (TProduto x, TFila *Fila);

void FFVazia (TFila *Fila);

int Vazia (TFila Fila);

void Desenfileirar (TFila *Fila, TProduto *Item);

void Imprimir1(TFila *fila);

#endif
