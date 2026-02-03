#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define TEMPO_SIMPLES 1
#define TEMPO_ESPECIAIS 3
#define TEMPO_ATENDIMENTO_PADRAO 5



Lista_Cliente *criarLista() { return NULL; }

int gerarAleatorio(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}


Lista_Cliente* inserir_cliente(Lista_Cliente* l, char *nome, int num_itens_simples, int num_itens_especiais){

    Lista_Cliente *novo = (Lista_Cliente*)malloc(sizeof(Lista_Cliente));

    if (!novo) {
        printf("Erro de alocação...\n");
        return NULL;
    }


    //Inicializando o novo cliente
    novo->id =  gerarAleatorio(1,999);

    strcpy(novo->nome,nome);
    novo->numero_itens_simples = num_itens_simples;
    novo->numero_itens_especiais = num_itens_especiais;
    novo->tempo_atendimento = TEMPO_ATENDIMENTO_PADRAO + (TEMPO_SIMPLES * num_itens_simples + TEMPO_ESPECIAIS * num_itens_especiais  );
    novo->prox = NULL;

    //Se a lista estiver vazia
    if (l == NULL) {
       return novo;
    }

    Lista_Cliente *aux =l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return l;
}

void imprimir(Lista_Cliente *l) {
    // Cabeçalho da tabela
    printf("\n");
    printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");
    printf("| ID   | Nome                           | Itens simples | Itens Especiais | Tempo de atendimento  |\n");
    printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");


    // Verifica se a lista está vazia
    if (l == NULL) {
        printf("|                                  Nenhum cliente cadastrado                                      |\n");
        printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");
        return;
    }

    // Imprime cada cliente5

    while (l != NULL) {
        printf("| %-4d | %-30s | %-13d | %-15d | %-19d s |\n",
               l->id, l->nome, l->numero_itens_simples,l->numero_itens_especiais, l->tempo_atendimento);
        l = l->prox;
    }

    // Rodapé da tabela
    printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");

    printf("\n");
}

