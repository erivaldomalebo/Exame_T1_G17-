
#ifndef EXAME_H
#define EXAME_H

#define MAX 50
#define TEMPO_SIMPLES 1
#define TEMPO_ESPECIAIS 3
#define TEMPO_ATENDIMENTO_PADRAO 5
#define MAX 50
#define WIDTH_NOME 20 // evitar crash da tabela de apresentacao dos dados

typedef struct lista
{
	char nome[MAX];
	int id, itens_simples, itens_especiais, tempo_atendimento;
	struct lista *prox;
} Cliente;

typedef struct fila
{
	struct lista *inicio;
	struct lista *fim;
} Caixa;

typedef struct lista_fila
{
	int id, estado; // 1-aberta, 0-fechada
	struct fila *cx;
	struct lista_fila *prox;
} Supermercado;

typedef struct stats
{
	int totalClientAtendidos;
	int totalItensProcessados;
	int tempoTotalAtendimento;
	int filaMaisDemorada;
} Relatorio;

Supermercado *ler_arquivo(Supermercado *s);
int gerarAleatorio(int min, int max);
Supermercado *criarCaixas();
Caixa *inicializarCaixa();
Relatorio *inicializar();
Caixa *inserirCliente(Supermercado *sp, int id_caixa, char *nome, int itens_simples, int itens_especiais);
Supermercado *abrirCaixa(Supermercado *sp, int id);
int contaCaixasAbertas(Supermercado *sp);
int tamanhoCaixa(Caixa *cx);
void imprimirTamanhoCaixas(Supermercado *sp);
Caixa *procurarCaixa(Supermercado *sp, int id);
int piorCaixa(Supermercado *sp);
int verificarCaixa(Supermercado *sp, int id);
Supermercado *abandonarCaixa(Supermercado *sp, int id, int idCliente);
void simularAtendimentoCaixa(Supermercado *sp, int idCaixa, int quantCliente, Relatorio *rel);
void simularAtendimentoGeral(Supermercado *sp, Relatorio *rel);
void imprimirRelatorio(Relatorio *rel);
void trocarClientFila(Supermercado *sp, int id);
Cliente *removerCliente(Caixa *cx, int id);
Caixa *melhorCaixa(Supermercado *sp);
void imprimirInformacoesCaixa(Supermercado *sp, int id);
void imprimir_clientes(Cliente *l);
void terminarSimulação(Supermercado *sp);
void gerarRelatorioArquivo(Relatorio *rel, const char *nomeArquivo);
Supermercado *fecharCaixa(Supermercado *sp, int id);

#endif
