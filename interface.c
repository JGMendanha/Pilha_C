#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. DESEMPILHAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. TROCAR A ORDEM DOS N PRIMEIROS NUMEROS DE UMA FILA");
    printf("  \n\t6. CONVERTER UM DECIMAL PARA BINARIO");
    printf("  \n\t7. STRING DE PARENTESES");
    printf("  \n\t8. ENTRE COM UMA EQUACAO E SAIBA SE HA PARENTESES DUPLICADOS");
    printf("  \n\t9. SAIR");
}

void MENU(TPilha *pilha){
    TFila fila;
    FFVazia(&fila);
    TProduto x;
    int opcao=0;
    int i, j;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                LerProduto(&x);
                Empilhar(x, pilha);
                printf("Produto empilhado com sucesso\n");
                system("PAUSE");
                break;
            case 2:
                printf("Digite o nome do produto ");
                scanf("%s", &x.nome);
                i = PesquisarPilha(pilha, &x);
                printf("\n-------------------\n");
                if(i == 1){
                    printf("Produto encontrado\n");
                    ImprimirProduto(x);
                }
                else{
                    printf("Produto nao encontrado\n");
                    ImprimirProduto(x);
                }
                system("PAUSE");
                break;
            case 3:
                Desempilhar(pilha, &x);
                printf("Produto desempilhado com sucesso\n");
                system("PAUSE");
                break;
            case 4:
                ImprimirPilha(pilha);
                system("PAUSE");
                break;
            case 5:
                printf("Digite alguns elementos para a fila ");
                j = 1;
                do{
                    LerProduto(&x);
                    Enfileirar(x, &fila);
                    printf("Deseja continuar ? (1:SIM, 0:NAO) ");
                    scanf("%d",&j);
                }while(j != 0);
                printf("Digite a quantidade de elementos que deseja inverter a ordem ");
                scanf("%d",&i);
                Inverter(&fila, i);
                system("PAUSE");
                break;
            case 6:
                printf("Digite o numero decimal que deseja converter ");
                scanf("%d", &i);
                printf("Digite a base de conversao ");
                scanf("%d", &j);
                Converter(i, j);
                system("PAUSE");
                break;
            case 7:
                printf("Digite a string de parenteses ");
                fflush(stdin);
                scanf("%s", x.descricao);
                Parentese(x);
                system("PAUSE");
                break;;
            case 8:
                printf("Digite a string da equacao ");
                fflush(stdin);
                scanf("%s", x.descricao);
                Expressao(x);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 10);
}
