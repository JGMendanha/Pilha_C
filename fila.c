#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FFVazia (TFila *Fila) {
    Fila->frente = (TCelula *) malloc (sizeof (TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia (TFila Fila) {
    return (Fila.frente == Fila.tras);
}

void Enfileirar (TProduto x, TFila *Fila) {
    Fila->tras->prox = (TCelula *) malloc (sizeof (TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar (TFila *Fila, TProduto *Item) {
    TCelula *Aux;
    if (!Vazia (*Fila)){
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free (Aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
    Fila->tamanho--;
    }
}

void Imprimir1(TFila *fila){
    int j = fila->tamanho;
    TProduto x;
    for(int i = 0; i < j; i++){
        Desenfileirar(fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, fila);
    }
}
