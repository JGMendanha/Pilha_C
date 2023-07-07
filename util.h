#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

typedef struct {
    int codigo;
    char nome[80];
    char descricao[200];
    float preco;
    int quantidade;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula* prox;
} TCelula;

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif
