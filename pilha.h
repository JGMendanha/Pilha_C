#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "fila.h"

typedef struct {
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void ImprimirPilha(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TProduto *x);

void Inverter(TFila *fila, int n);

int PVazia(TPilha Pilha);

void Converter(int n, int b);

void ImprimirCodigo(TProduto x);

void Parentese(TProduto x);

int Expressao(TProduto x);

#endif
