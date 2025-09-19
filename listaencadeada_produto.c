#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Produto{
    char nome[15];
    int estoque;
    struct Produto *prox;
}produto;

produto* criarLista(char nomeP[15], int estoqueP){
    produto *novoprod = (produto*) malloc(sizeof(produto));
    if(novoprod == NULL){
        printf("\nERRO de Alocacao de memoria !");
        exit(1);
    }
    strcpy(novoprod->nome, nomeP);
    novoprod->estoque = estoqueP;
    novoprod->prox = NULL;
    return novoprod;
}// fim do metodo criar lista

void insereInicio(produto **lista, char nomeP[15], int estoqueP){
    produto *novoprod = criarLista(nomeP, estoqueP);
    novoprod->prox = *lista;
    *lista = novoprod;
}// fim do inserir no inicio

void insereFim(produto **lista, char nomeP[15], int estoqueP){
    produto *novoprod = criarLista(nomeP, estoqueP);
    if(*lista == NULL){
        *lista = novoprod;
    }else{
        produto *temp = *lista;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novoprod;
    }
}// fim do inserir no final

void imprimirProduto(produto *lista){
    while(lista != NULL){
        printf("\nO produto: %s", lista->nome);
        printf("\nO estoque: %d", lista->estoque);
        lista = lista->prox;
        printf("\n-----------");
    }
}//fim do imprimir

produto* buscar(produto *lista, char nomeP[15]){
    while(lista != NULL){
        if(strcmp(lista->nome, nomeP)==0){
            return lista;
        }//fim do if
        lista = lista->prox;
    }//fim do while
    return NULL;
}//fim do metodo buscar

void excluirProduto(produto **lista, char nomeP) {
    produto *temp = *lista, *anterior = NULL;

    while ((temp != NULL) && (strcmp(temp->nome,nomeP)!=0)) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("Produto %s não encontrado!\n", nomeP);
        return;
    }

    if (anterior == NULL) { // Remover primeiro nó
        *lista = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("O Produto %s removido com sucesso!\n", nomeP);
}


main(){
    int a, b, estoque;
    char nome[15];
    produto *lista = NULL;

    do{
        printf("\n$$$ MENU $$$ ");
        printf("\n1 - CADASTRAR ");
        printf("\n2 - CADASTRAR PRIORIDADE ");
        printf("\n3 - LISTAR");
        printf("\n4 - BUSCAR");
        printf("\n5 - EXCLUIR PRODUTO");
        printf("\nESCOLHA UMA OPCAO:  ");
        scanf("%d", &b);
        switch(b){
            case 1:
                printf("\nMODULO DE CADASTRO ");
                printf("\n\nDIGITE O NOME DO PRODUTO: ");
                scanf("%s", &nome);
                printf("\nDIGITE O estoque: ");
                scanf("%d", &estoque);
                insereFim(&lista, nome, estoque);
                printf("\PRODUTO CADASTRADO COM SUCESSO !");
                break;
            case 2:
                printf("\nMODULO DE CADASTRO EM PRIORIDADE ");
                printf("\nDIGITE O nome PRODUTO: ");
                scanf("%s", &nome);
                printf("\nDIGITE O estoque: ");
                scanf("%d", &estoque);
                insereInicio(&lista, nome, estoque);
                printf("\PRODUTO CADASTRADO COM SUCESSO !");
                break;
            case 3:
                printf("\nLISTA DE PRODUTOS ");
                imprimirProduto(lista);
                break;
            case 4:
                printf("\nBUSCAR PRODUTOS ");
                printf("\nDIGITE O nome p/ a busca: ");
                scanf("%s", &nome);

                produto *b = buscar(lista, nome);

                if(b != NULL)
                    printf("\nProduto Encontrado: %s", b->nome);
                else
                   printf("\nPRODUTO NAO ENCONTRADO !! ");
                break;
            case 5:
                printf("\nEXCLUIR PRODUTO ");
                printf("\nDIGITE O nome p/ a busca: ");
                scanf("%s", &nome);
                excluirProduto(&lista, nome);

                break;
        }

        printf("\nDIGITE 1 P/ CONT OU 0 P/ SAIR: ");
        scanf("%d", &a);
    }while(a !=0);
}
