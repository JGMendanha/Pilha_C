#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void LerProduto(TProduto *x){
    printf("\ndigite o codigo do produto: ");
    scanf("%d",&x->codigo);
    printf("digite a quantidade do produto: ");
    scanf("%d",&x->quantidade);
    printf("digite o peco do produto: ");
    scanf("%f",&x->preco);
    printf("digite a descricao do produto (ate 100 letras): ");
    fflush(stdin);
    scanf ("%s", x->descricao);
    printf("digite o nome do produto (ate 10 letras): ");
    fflush(stdin);
    scanf ("%s", x->nome);
    printf("==========================================\n");

}

void ImprimirProduto(TProduto x){
    printf("\ncodigo: %d\n", x.codigo);
    printf("quantidade: %d\n", x.quantidade);
    printf("peco: %f\n", x.preco);
    printf("nome: ");
    puts(x.nome);
    printf("descricao: ");
    puts(x.descricao);
    printf("\n==========================================\n");
}
