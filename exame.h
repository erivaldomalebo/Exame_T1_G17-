
#ifndef EXAME_H
#define EXAME_H

#define MAX 50

typedef struct lista Cliente;
typedef struct fila Caixa;
typedef struct lista_fila Supermercado;
typedef struct stats Relatorio;


Supermercado *ler_arquivo(Supermercado *s);
int gerarAleatorio(int min, int max);
Supermercado *criarCaixas();
Caixa *inicializarCaixa();
Relatorio *inicializar();
Caixa *inserirCliente(Supermercado *sp,int id_caixa, char *nome, int itens_simples, int itens_especiais);
Supermercado *abrirCaixa(Supermercado *sp,int id);
int contaCaixasAbertas(Supermercado *sp);
int tamanhoCaixa(Caixa *cx);
void imprimirTamanhoCaixas(Supermercado *sp);
Caixa* procurarCaixa(Supermercado *sp, int id);
int piorCaixa(Supermercado *sp);
int verificarCaixa(Supermercado *sp,int id);
Supermercado *abandonarCaixa(Supermercado *sp,int id, int idCliente);
void simularAtendimentoCaixa(Supermercado *sp, int idCaixa, int quantCliente, Relatorio *rel);
void simularAtendimentoGeral(Supermercado *sp, Relatorio *rel);
void imprimirRelatorio(Relatorio *rel);
void trocarClientFila(Supermercado *sp, int id);
Cliente *removerCliente(Caixa *cx, int id);
Caixa *melhorCaixa(Supermercado *sp);
void limparBuffer();
void imprimirInformacoesCaixa(Supermercado *sp, int id);
void imprimir_clientes(Cliente *l);

//Falta a função FecharCaixa e Terminar simulação!!



#endif
