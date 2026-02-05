#ifndef EXAME_CLIENTE_H
#define EXAME_CLIENTE_H

#define MAX 50

#define TEMPO_SIMPLES 1
#define TEMPO_ESPECIAIS 3
#define TEMPO_ATENDIMENTO_PADRAO 5

struct lista
{
    char nome[50]; // O cliente será identificado pelo nome
    int id, itens_simples, itens_especiais, tempo_atendimento;
    struct lista *prox;
};

struct fila
{
    struct lista *inicio;
    struct lista *fim;
};

struct lista_fila
{
    int id, estado; // 1-aberta, 0-fechada
    struct fila *cx;
    struct lista_fila *prox;
};

struct stats
{
    int totalClientAtendidos;
    int totalItensProcessados;
    int tempoTotalAtendimento;
    int filaMaisDemorada;
};

typedef struct lista Cliente;
typedef struct fila Caixa;
typedef struct lista_fila Supermercado;
typedef struct stats Estatistica;

void imprimir(Cliente *l);
Supermercado *ler_arquivo(Supermercado *s);
int gerarAleatorio(int min, int max);
Supermercado *criarCaixas();
Caixa *inicializarCaixa();
Caixa *inserirCliente(Supermercado *sp, int id_caixa, char *nome, int itens_simples, int itens_especiais);
Supermercado *abrirCaixa(Supermercado *sp, int id);
int contaCaixasAbertas(Supermercado *sp);
int tamanhoCaixa(Caixa *cx);
void imprimirTamanhoCaixas(Supermercado *sp);
Caixa *procurarCaixa(Supermercado *sp, int id);
void piorCaixa(Supermercado *sp);
<<<<<<< HEAD
int verificarCaixa(Supermercado *sp, int id);

void trocarClientFila(Supermercado *sp);
Cliente *removerClientePorNome(Caixa *cx, char *name);
Caixa *melhorCaixa(Supermercado *sp);
void limparBuffer();
=======
void imprimirInformacoesCaixa(Supermercado *sp, int id);
int verificarCaixa(Supermercado *sp,int id);
>>>>>>> f6851844e20bbb6d4bf92d98f6636ef2bd95ed77

/*Caixa *fecharCaixa(Supermercado *sp, int id);*/

/*
void iniciarSimulacao(char *file);
Caixa *trocarCaixa(Caixa *cx, Cliente *cl);
void imprimirCaixa(Caixa *cx);*/

#endif // EXAME_CLIENTE_H
