#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pessoa{
    char nome[15];
    struct Pessoa *prox;
}pessoa;

pessoa* criarLista(char nomeP[15]){
    pessoa *novopes = (pessoa*)malloc(sizeof(pessoa));
    if(novopes == NULL){
        printf("\nErro de alocacao de Memoria !");
        exit(1);
    }
    strcpy(novopes->nome,nomeP);
    novopes->prox = NULL;
    return novopes;
}

void inserirInicio(pessoa **lista, char nomeP[15]){
    pessoa *novaP = criarLista(nomeP);
    novaP->prox = *lista;
    *lista = novaP;
}

void insereFim(pessoa **lista, char nomeP[15]){
     pessoa *novaP = criarLista(nomeP);
     if(*lista == NULL){
        *lista = novaP;
     }else{
        pessoa *temp = *lista;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novaP;
     }
}

pessoa* buscar(pessoa *lista, char nomeP) {
while (lista != NULL) {
    if (strcmp(lista->nome ,nomeP)==0){
        return lista;
    }
        lista = lista->prox;
    }
    return NULL;
}


void imprimir(pessoa *lista){
    while(lista != NULL){
        printf("\nO nome: %s", lista->nome);
        lista = lista->prox;
        printf("\n------------");
    }
    printf("\nNULL - Fim da Lista");
}

main(){
    pessoa *lista = NULL;

    inserirInicio(&lista, "Marcelo");
    inserirInicio(&lista, "Maria");
    insereFim(&lista, "Tiago");
    inserirInicio(&lista, "Ana");
    insereFim(&lista, "Mariana");

    pessoa *b = buscar(&lista, "Tiago");

    if (b != NULL)
        printf("Valor %d encontrado!\n", b->nome);
    else
        printf("Valor não encontrado!\n");

    printf("\nA Lista");
    imprimir(lista);
}


