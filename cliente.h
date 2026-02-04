
#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX 50

typedef struct cliente {
    int id;
    char nome[MAX];
    int numero_itens_simples, numero_itens_especiais, tempo_atendimento;
    struct cliente *prox;
}Lista_Cliente;

Lista_Cliente* criarLista();
Lista_Cliente* inserir_cliente(Lista_Cliente* l, char *nome, int num_itens_simples, int num_itens_especiais);
void imprimir(Lista_Cliente *l);
void pesquisar_por_id(Lista_Cliente *l, int id);
void pesquisar_por_nome(Lista_Cliente *l, int id);
int gerarAleatorio(int min, int max);




#endif //EXAME_CLIENTE_H
