#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int gerarAleatorio(int min, int max)
{

	return min + rand() % (max - min + 1);
}

void imprimir(Cliente *l)
{
	// Cabeçalho da tabela
	printf("\n");
	printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");
	printf("| ID   | Nome                           | Itens simples | Itens Especiais | Tempo de atendimento  |\n");
	printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");

	// Verifica se a lista está vazia
	if (l == NULL)
	{
		printf("|                                  Nenhum cliente cadastrado                                      |\n");
		printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");
		return;
	}

	// Imprime cada cliente5

	while (l != NULL)
	{
		printf("| %-4d | %-30s | %-13d | %-15d | %-19d s |\n",
			   l->id, l->nome, l->itens_simples, l->itens_especiais, l->tempo_atendimento);
		l = l->prox;
	}

	// Rodapé da tabela
	printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");

	printf("\n");
}

Supermercado *criarCaixas() { return NULL; }

Caixa *inicializarCaixa()
{

	Caixa *cx = (Caixa *)malloc(sizeof(Caixa));
	if (cx)
	{
		cx->inicio = NULL;
		cx->fim = NULL;
	}

	else
		printf("Erro na Alocação de memória");

	return cx;
}

Caixa *inserirCliente(Supermercado *sp, int id_caixa, char *nome, int itens_simples, int itens_especiais)
{

	Caixa *cx = procurarCaixa(sp, id_caixa);

	if (cx == NULL)
	{
		printf("Erro ao localizar Caixa");
		return NULL;
	}

	Cliente *cl = (Cliente *)malloc(sizeof(Cliente));

	if (!cl)
	{
		printf("Erro de alocação de memória");
		return cx;
	}

	cl->id = gerarAleatorio(1, 999);
	strcpy(cl->nome, nome);
	cl->itens_especiais = itens_especiais;
	cl->itens_simples = itens_simples;
	cl->tempo_atendimento = 5 + (1 * itens_simples) + (3 * itens_especiais);
	cl->prox = NULL;

	if (!cx->inicio)
	{
		cx->inicio = cl;
	}
	else
	{
		cx->fim->prox = cl;
	}

	cx->fim = cl;

	return cx;
}

int contaCaixasAbertas(Supermercado *sp)
{

	if (!sp)
		return 0;

	return 1 + contaCaixasAbertas(sp->prox);
}

Supermercado *abrirCaixa(Supermercado *sp, int id)
{

	if (!(id > 0 && id < 11))
	{
		printf("Verifique o id da Caixa [id]-[1-10]\n");
		return sp;
	}
	else if (contaCaixasAbertas(sp) > 10)
	{
		printf("Sem Caixas fechadas\n");
		return sp;
	}
	else
	{
		Supermercado *lista_caixa = (Supermercado *)malloc(sizeof(Supermercado));

		if (lista_caixa == NULL)
		{
			printf("Erro na alocação da caixa n");
			return sp;
		}

		lista_caixa->id = id;
		lista_caixa->prox = NULL;
		lista_caixa->cx = inicializarCaixa();
		lista_caixa->estado = 1;

		// Criar novo no na lista de caixas (Supermercado)
		if (verificarCaixa(sp, id))
		{
			if (sp)
			{
				Supermercado *aux = sp;

				while (aux->prox)
					aux = aux->prox;

				aux->prox = lista_caixa;
			}
			else
			{
				sp = lista_caixa;
			}
		}
		else
			printf("Caixa[%d] Já aberta!\n", id);

		return sp;
	}
}

int tamanhoCaixa(Caixa *cx)
{
	int count = 0;

	Cliente *temp = cx->inicio;

	while (temp)
	{
		count++;
		temp = temp->prox;
	}

	return count;
}

void imprimirTamanhoCaixas(Supermercado *sp)
{
	int tam = 0;
	Supermercado *temp = sp;
	while (temp)
	{
		tam = tamanhoCaixa(temp->cx);
		printf("\nCaixa [%d] -> [%d] clientes na fila\n", temp->id, tam);
		temp = temp->prox;
	}
}

Caixa *procurarCaixa(Supermercado *sp, int id)
{
	Supermercado *temp = sp;
	while (temp)
	{
		if (temp->id == id)
			return temp->cx;

		temp = temp->prox;
	}

	return NULL;
}

int verificarCaixa(Supermercado *sp, int id)
{
	Supermercado *temp = sp;
	while (temp)
	{
		if (temp->id == id)
			return 0;

		temp = temp->prox;
	}

	return 1;
}

void piorCaixa(Supermercado *sp)
{

	if (sp)
	{
		Supermercado *temp = sp;
		int maior = 0;
		int soma;
		int id = -1;

		while (temp)
		{
			soma = 0;
			Cliente *aux = temp->cx->inicio;

			while (aux)
			{
				soma += aux->tempo_atendimento;
				aux = aux->prox;
			}

			if (soma > maior)
			{
				maior = soma;
				id = temp->id;
			}

			temp = temp->prox;
		}

		if (id != -1)
			printf("Pior Caixa: FILA[%d]\n", id);
		else
			printf("Nenhuma caixa encontrada!");
	}
}

/* Limpa o buffer do teclado */
void limparBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

// Encontra a MELHOR caixa (menor tempo)
Caixa *melhorCaixa(Supermercado *sp)
{
	if (!sp)
	{
		printf("Nenhuma caixa aberta!\n");
		return NULL;
	}

	Supermercado *temp = sp;
	int menor = -1;
	int soma;
	Caixa *melhor = NULL;
	int id_melhor = -1;

	while (temp)
	{
		soma = 0;
		Cliente *aux = temp->cx->inicio;

		while (aux)
		{
			soma += aux->tempo_atendimento;
			aux = aux->prox;
		}

		if (menor == -1 || soma < menor)
		{
			menor = soma;
			melhor = temp->cx;
			id_melhor = temp->id;
		}

		temp = temp->prox;
	}

	if (melhor != NULL)
	{
		printf("Melhor Caixa: FILA[%d] com tempo total de %d segundos\n", id_melhor, menor);
		return melhor;
	}
	else
	{
		printf("Nenhuma caixa encontrada!\n");
		return NULL;
	}
}

Cliente *removerClientePorNome(Caixa *cx, char *nome)
{
	if (!cx || !cx->inicio)
		return NULL;

	Cliente *atual = cx->inicio;
	Cliente *anterior = NULL;

	// Procurar o cliente
	while (atual && strcmp(atual->nome, nome) != 0)
	{
		anterior = atual;
		atual = atual->prox;
	}

	// Cliente não encontrado
	if (!atual)
		return NULL;

	// Remover o cliente
	if (anterior == NULL)
	{
		// Cliente está no início
		cx->inicio = atual->prox;
		if (cx->inicio == NULL)
			cx->fim = NULL;
	}
	else
	{
		// Cliente está no meio ou fim
		anterior->prox = atual->prox;
		if (atual == cx->fim)
			cx->fim = anterior;
	}

	atual->prox = NULL;
	return atual;
}

void trocarClientFila(Supermercado *sp)
{
	// Verificar se existe sp
	if (!sp)
	{
		printf("\n✗ Nenhuma caixa aberta!\n");
		return;
	}

	// Perguntar o nome do cliente
	char nome[MAX];
	printf("\nNome do cliente: ");
	fgets(nome, MAX, stdin);
	nome[strcspn(nome, "\n")] = 0;

	// Procurar o cliente em todas as filas
	Supermercado *temp = sp;
	Caixa *caixa_atual = NULL;
	Cliente *cliente_encontrado = NULL;
	int id_caixa_atual = -1;

	while (temp)
	{
		Cliente *aux = temp->cx->inicio;
		while (aux)
		{
			if (strcmp(aux->nome, nome) == 0)
			{
				cliente_encontrado = aux;
				caixa_atual = temp->cx;
				id_caixa_atual = temp->id;
				break;
			}
			aux = aux->prox;
		}
		if (cliente_encontrado)
			break;

		temp = temp->prox;
	}

	// Verificar se o cliente foi encontrado
	if (!cliente_encontrado)
	{
		printf("\n✗ Cliente '%s' não encontrado!\n", nome);
		return;
	}

	printf("\nCliente encontrado na Caixa [%d]\n", id_caixa_atual);

	// Encontrar a melhor caixa (menor tempo)
	Caixa *melhor = melhorCaixa(sp);

	if (!melhor || melhor == caixa_atual)
	{
		printf("\n✗ Cliente já está na melhor fila!\n");
		return;
	}

	// Remover cliente da fila atual
	Cliente *removido = removerClientePorNome(caixa_atual, nome);

	if (!removido)
	{
		printf("\n✗ Erro ao remover cliente!\n");
		return;
	}

	// Adicionar na melhor fila
	if (!melhor->inicio)
	{
		melhor->inicio = removido;
		melhor->fim = removido;
	}
	else
	{
		melhor->fim->prox = removido;
		melhor->fim = removido;
	}
	removido->prox = NULL;

	printf("\n✓ Cliente '%s' trocado para a melhor fila!\n", nome);
}