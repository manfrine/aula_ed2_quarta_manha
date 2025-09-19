#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[15];
    struct Pessoa *prox;
} Pessoa;

typedef struct Fila {
    Pessoa *tras;
    Pessoa *frente;
} Fila;

void iniciaFila(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
}

int filaVazia(Fila *f) {
    return (f->frente == NULL);
}

void enfileirar(Fila *f, char nomeP[15]) { // enqueue
    Pessoa* novopes = (Pessoa*) malloc(sizeof(Pessoa));
    if (!novopes) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    strcpy(novopes->nome, nomeP);
    novopes->prox = NULL;

    if (filaVazia(f)) {
        f->frente = novopes;
    } else {
        f->tras->prox = novopes;
    }
    f->tras = novopes;
    printf("\nElemento enfileirado: %s", nomeP);
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("\nFILA VAZIA, não tem o que excluir!");
        return -1;
    }

    Pessoa* temp = f->frente;
    printf("\nRemovendo: %s", temp->nome);

    f->frente = f->frente->prox;

    if (f->frente == NULL) {
        f->tras = NULL;
    }

    free(temp);
    return 0;
}

void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("\nFILA VAZIA, não tem o que exibir!");
        return;
    }
    Pessoa* atual = f->frente;
    printf("\n## A FILA ###\n");
    while (atual != NULL) {
        printf("O nome: %s\n", atual->nome);
        printf("-------------\n");
        atual = atual->prox;
    }
}

int main() {
    Fila f;
    iniciaFila(&f);

    enfileirar(&f, "Maria");
    enfileirar(&f, "Joao");
    enfileirar(&f, "Helena");

    exibirFila(&f);

    desenfileirar(&f);
    exibirFila(&f);

    return 0;
}
