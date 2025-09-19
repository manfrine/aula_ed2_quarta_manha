#include <stdio.h>
#include <stdlib.h>
// Estrutura do nó da lista
typedef struct Node {
    int dado;
    struct Node *prox;
} Node;
// Função para criar um novo nó
Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
return novo;
}
// Inserir no início da lista
void inserirInicio(Node **lista, int valor) {
    Node *novo = criarNo(valor);
    novo->prox = *lista;
    *lista = novo;
}
// Inserir no fim da lista
void inserirFim(Node **lista, int valor) {
    Node *novo = criarNo(valor);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Node *temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}
// Remover um nó com determinado valor
void removerValor(Node **lista, int valor) {
    Node *temp = *lista, *anterior = NULL;
    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->prox;
    }
    if (temp == NULL) {
        printf("Valor %d não encontrado!\n", valor);
        return;
    }
    if (anterior == NULL) { // Remover primeiro nó
        *lista = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }
    free(temp);
    printf("Valor %d removido com sucesso!\n", valor);
}
// Buscar um valor na lista
Node* buscar(Node *lista, int valor) {
while (lista != NULL) {
        if (lista->dado == valor)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}
// Imprimir lista
void imprimir(Node *lista) {
    while (lista != NULL) {
        printf("%d - ", lista->dado);
        lista = lista->prox;
}

}
// Liberar memória da lista
void liberarLista(Node **lista) {
    Node *temp;
    while (*lista != NULL) {
        temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
}

int main() {
    Node *lista = NULL;
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFim(&lista, 30);
    inserirFim(&lista, 40);
    printf("Lista atual: ");
    imprimir(lista);

    Node *busca = buscar(lista, 30);
    if (busca != NULL)
        printf("Valor %d encontrado!\n", busca->dado);
    else
        printf("Valor não encontrado!\n");

    removerValor(&lista, 20);
    imprimir(lista);

    liberarLista(&lista);
    return 0;
}
