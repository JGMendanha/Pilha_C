#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void FPVazia(TPilha *Pilha){
    Pilha -> topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha -> fundo = Pilha -> topo;
    Pilha -> topo -> prox = NULL;
    Pilha -> tamanho = 0;
}

int PVazia(TPilha Pilha){
    return(Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha){
    TCelula* Aux;
    Aux = (TCelula*) malloc(sizeof(TCelula));
    Pilha -> topo -> item = x;
    Aux -> prox = Pilha -> topo;
    Pilha -> topo = Aux;
    Pilha -> tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item){
    TCelula* q;
    if(PVazia(*Pilha)){
        printf("\nErro: Lista vazia!\n");
        return;
    }
    q = Pilha -> topo;
    Pilha -> topo = q -> prox;
    *Item = q -> prox -> item;
    free(q);
    Pilha -> tamanho--;
}

void ImprimirPilha(TPilha *Pilha){
    TPilha p2;
    FPVazia(&p2);
    TProduto x;

    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &x);
        Empilhar(x, &p2);
    }

    while(!PVazia(p2)){
        Desempilhar(&p2, &x);
        ImprimirProduto(x);
        Empilhar(x, Pilha);
    }
    free(p2.topo);
}

int PesquisarPilha(TPilha *Pilha, TProduto *x){
    TPilha p2;
    int i = 0;
    FPVazia(&p2);
    TProduto p;

    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &p);
        if(strcmp(x->nome, p.nome)==0){
            *x = p;
            i++;
        }
        Empilhar(p,&p2);
    }

    while(!PVazia(p2)){
        Desempilhar(&p2, &p);
        Empilhar(p, Pilha);
    }

    free(p2.topo);

    if(i > 0)
        return 1;

    else{
        x->codigo = -1;
        return 0;
    }
}

void Inverter(TFila *fila, int n){
    TPilha pilha;
    FPVazia(&pilha);
    TFila fila2;
    FFVazia(&fila2);
    TProduto x;
    int i;

    for(i = 1; i <= n; i++){
        Desenfileirar(fila, &x);
        Empilhar(x, &pilha);
    }

    while(!Vazia(*fila)){
        Desenfileirar(fila, &x);
        Enfileirar(x, &fila2);
    }

    while(!PVazia(pilha)){
       Desempilhar(&pilha, &x);
       Enfileirar(x, fila);
    }

    while(!Vazia(fila2)){
       Desenfileirar(&fila2, &x);
       Enfileirar(x, fila);
    }

    Imprimir1(fila);

    free(pilha.topo);
    free(fila2.frente);
}

void ImprimirCodigo(TProduto x){
    printf("%d", x.codigo);
}

void Converter(int n, int b){
    TPilha pilha;
    FPVazia(&pilha);
    TProduto x;
    int r = n, re;
    while(r != 1){
        re = r % b;
        r = r / b;

        x.codigo = re;

        Empilhar(x, &pilha);

        if(r == 1){
            x.codigo = 1;
            Empilhar(x, &pilha);
        }
    }
    printf("\nO resultado da conversao de %d em binarios e ", n);
    while(!PVazia(pilha)){
        Desempilhar(&pilha, &x);
        ImprimirCodigo(x);
    }

    printf("\n\n");

    free(pilha.topo);
}

void Parentese(TProduto x){
    TPilha pilha;
    TProduto y;
    int i = 0, cont = 0;
    FPVazia(&pilha);
    while(x.descricao[i] != '\0'){
        if(x.descricao[i] == '('){
            y.descricao[0] = x.descricao[i];
            Empilhar(y, &pilha);
        }
        if(x.descricao[i] == ')'){
            if(!PVazia(pilha)){
                Desempilhar(&pilha, &y);
                cont+=2;
            }
        }
        i++;
    }

    printf("Numero de parenteses corretos %d\n", cont);
}



int Expressao(TProduto x){
    int i = 0, cont = 0, j = 0, l;
    char c;
    l = strlen(&x.descricao);
    TProduto y;
    TPilha p;
    FPVazia(&p);
    while(i < l){
        if(x.descricao[i] != ')'){
            c = x.descricao[i];
            y.descricao[0] = c;

            Empilhar(y, &p);

        }
        else if(x.descricao[i] == ')'){
            if(!PVazia(p)){
                while(p.topo->prox->item.descricao[0] != '('){
                    cont++;
                    Desempilhar(&p, &y);
                }
                Desempilhar(&p, &y);
                if(cont == 0){
                    printf("Expressao com parentese duplicado\n");
                    return 0;
                }
                cont = 0;
            }
        }
        i++;
    }

    printf("Expressao sem parentes duplicado\n");

    return 1;

    free(&p);
}
