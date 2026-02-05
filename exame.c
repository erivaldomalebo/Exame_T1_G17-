#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define TEMPO_SIMPLES 1
#define TEMPO_ESPECIAIS 3
#define TEMPO_ATENDIMENTO_PADRAO 5
#define MAX 50
#define WIDTH_NOME 20 //evitar crash da tabela de apresentacao dos dados


struct lista{
	char nome[MAX];
	int id, itens_simples, itens_especiais, tempo_atendimento;
	struct lista* prox;
};

struct fila{
	struct lista *inicio;
	struct lista *fim;
};

struct lista_fila{
	int id, estado; //1-aberta, 0-fechada
	struct fila *cx;
	struct lista_fila *prox;
};

struct stats {
	int totalClientAtendidos;
    int totalItensProcessados;
    int tempoTotalAtendimento;
    int filaMaisDemorada;
};

int gerarAleatorio(int min, int max) {

    return min + rand() % (max - min + 1);
}


Supermercado *criarCaixas(){return NULL;}


Caixa *inicializarCaixa(){

	Caixa *cx = (Caixa*)malloc(sizeof(Caixa));
	if(cx){
		cx->inicio = NULL;
		cx->fim = NULL;
	}

	else
		printf("Erro na Alocação de memória");

	return cx;
}



Relatorio *inicializar(){

	Relatorio *rel = (Relatorio*)malloc(sizeof(Relatorio));
	if(rel){
	   rel->totalClientAtendidos =0;
       rel->totalItensProcessados=0;
       rel->tempoTotalAtendimento=0;
       rel->filaMaisDemorada=0;
	}

	else
		printf("Erro na Alocação de memória");

	return rel;
}


Supermercado * ler_arquivo(Supermercado *s){
    char linha[100];
    FILE *arquivo = fopen("dados.txt", "r");

    if(arquivo == NULL)
        return NULL;


    while(fgets(linha, sizeof(linha), arquivo) != NULL){

        char nome_temp[50];
        int itens_temp, caixa_temp;
        if(sscanf(linha,"%s %d %d",nome_temp,&itens_temp, &caixa_temp) == 3){
            int itens_simples = (int) itens_temp / 2;
            int itens_especiais = itens_temp - itens_simples;
            if(verificarCaixa(s,caixa_temp) != 0){
                 s = abrirCaixa(s, caixa_temp);
            }

            inserirCliente(s, caixa_temp, nome_temp, itens_simples, itens_especiais);

        }
    }

    fclose(arquivo);
    return s;
}




Caixa *inserirCliente(Supermercado *sp,int id_caixa, char *nome, int itens_simples, int itens_especiais){

	Caixa *cx = procurarCaixa(sp,id_caixa);

	if (!cx) {
      	if(id_caixa>0 && id_caixa<11)
      	  	printf("Caixa [%d] está fechada\n",id_caixa);
      	else
      		printf("Verifique o id da Caixa [id]-[1-10]\n");
        return NULL;
    }

		Cliente *cl = (Cliente*)malloc(sizeof(Cliente));

		if(!cl){
			printf("Erro de alocação de memória");
			return cx;
		}


            cl->id =  gerarAleatorio(1,999);
			strcpy(cl->nome,nome);
			cl->itens_especiais = itens_especiais;
			cl->itens_simples = itens_simples;
			cl->tempo_atendimento = TEMPO_ATENDIMENTO_PADRAO+(TEMPO_SIMPLES*itens_simples)+(TEMPO_ESPECIAIS*itens_especiais);
			cl->prox = NULL;

		if(!cx->inicio){
            cx->inicio = cl;
		}
		else{
            cx->fim->prox = cl;
		}

        cx->fim = cl;


        return cx;



}

int contaCaixasAbertas(Supermercado *sp){

	if(!sp) return 0;

    return 1+contaCaixasAbertas(sp->prox);
}

Supermercado *abrirCaixa(Supermercado *sp,int id){

	if(!(id>0 && id<11)){
		printf("Verifique o id da Caixa [id]-[1-10]\n");
		return NULL;
	}


	 else if(contaCaixasAbertas(sp)>10){
	 	 printf("Sem Caixas fechadas\n");
	 	 return NULL;
	 }

	 else{

            Supermercado *lista_caixa = (Supermercado*)malloc(sizeof(Supermercado));

            if (lista_caixa == NULL) {
                printf("Erro na alocação da caixa n");
                return sp;
            }

			lista_caixa->id = id;
			lista_caixa->prox = NULL;
			lista_caixa->cx = inicializarCaixa();
			lista_caixa->estado = 1;

			// Criar novo no na lista de caixas (Supermercado)
            if(verificarCaixa(sp,id)){
                if (sp) {
                    Supermercado *aux = sp;

                    while (aux->prox)
                        aux = aux->prox;

                    aux->prox = lista_caixa;
                }else{
                    sp = lista_caixa;
                }
                
                printf("Caixa [%d] aberta com sucesso!\n", id);

            }else
                printf("Caixa[%d] Já aberta!\n",id);


		return sp;
	 }


}

int tamanhoCaixa(Caixa *cx){
    int count = 0;

    Cliente *temp = cx->inicio;

    while (temp) {
        count++;
        temp = temp->prox;
    }

    return count;
}

void imprimirTamanhoCaixas(Supermercado *sp){
	int tam = 0;
    Supermercado *temp = sp;
    while (temp) {
        tam = tamanhoCaixa(temp->cx);
        printf("\nCaixa [%d] -> [%d] clientes na fila\n", temp->id, tam);
        temp = temp->prox;
    }
}

Caixa *procurarCaixa(Supermercado *sp,int id){
    Supermercado *temp = sp;
    while (temp){
    	if(temp->id == id)
    		 return temp->cx;

    	temp = temp->prox;
	}

   return NULL;
}


int verificarCaixa(Supermercado *sp,int id){
    Supermercado *temp = sp;
    while (temp){
    	if(temp->id == id)
    		 return 0;

    	temp = temp->prox;
	}

   return 1;
}


int piorCaixa(Supermercado *sp){

	if(sp){
		Supermercado *temp = sp;
		int maior = 0;
		int soma;
		int id =-1;

		while(temp){
		soma =0;
		 Cliente *aux = temp->cx->inicio;

		 while(aux){
		 	soma += aux->tempo_atendimento;
		 	aux = aux->prox;
		 }

		 if(soma>maior){
		 	maior = soma;
		 	id = temp->id;
		 }


		temp = temp->prox;
		}

			return id;
	}

}

void imprimirInformacoesCaixa(Supermercado *sp, int id){

	Caixa *cx = procurarCaixa(sp,id);
	int tempo_total =0, itens_simples = 0, itens_especiais=0;
	
	
	 if (!cx) {
      	if(id>0 && id<11)
      	  	printf("\t\t\t\t\Caixa [%d] fechada\n", id);
      	else
      		printf("\t\t\t\t\Verifique o id da Caixa [id]-[1-10]\n");
        return sp;
    }
        printf("\n\t\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t\t            C A I X A  %d",id);
		printf("\n\t\t\t\t\t-----------------------------------\n");
		printf("\t\t\t\t\t| Numero de Clientes        -> %d\n", tamanhoCaixa(cx));
		Cliente *aux = cx->inicio;
		while (aux) {
			tempo_total += aux->tempo_atendimento;
			itens_simples += aux->itens_simples;
			itens_especiais += aux->itens_especiais;
			aux = aux->prox;
		}
		printf("\t\t\t\t\t| Tempo Total de Atendiento -> %d seg\n", tempo_total);
		printf("\t\t\t\t\t| Numero de itens especiais -> %d\n", itens_especiais);
		printf("\t\t\t\t\t| Numero de itens simples   -> %d\n\n", itens_simples);
		
		imprimir_clientes(cx->inicio);

}

Supermercado *abandonarCaixa(Supermercado *sp, int id_caixa, int idCliente){
	
    if (!sp) {
        return NULL;
    }

    Caixa *cx = procurarCaixa(sp, id_caixa);
    
    if (!cx) {
      	if(id_caixa>0 && id_caixa<11)
      	  	printf("Caixa [%d] fechada\n", id_caixa);
      	else
      		printf("Verifique o id da Caixa [id]-[1-10]\n");
        return sp;
    }

    if (!cx->inicio) {
        printf("Caixa vazia\n");
        return sp;
    }
    
    
    Cliente *aux = cx->inicio;
    Cliente *temp = NULL;


    if (aux->id == idCliente) {
        cx->inicio = aux->prox;
        free(aux);
        return sp;
    }

    while (aux && aux->id != idCliente) {
        temp = aux;
        aux = aux->prox;
    }

    if (!aux) {
        printf("Cliente não encontrado na fila\n");
        return sp;
    }

    temp->prox = aux->prox;
    printf("Cliente [%s] desistiu da fila",aux->nome);
    free(aux);

    return sp;
}
	
void simularAtendimentoGeral(Supermercado *sp, Relatorio *rel){
    if (!sp) {
        printf("Lista de Caixas inexistente\n");
        return;
    }
    
   

    Supermercado *aux = sp;
    while (aux) {
        printf("\nAtendimento na Caixa %d:\n", aux->id);
        printf("+-----------------------------------------------------------------------------------------------+\n");
        printf("|  ID   |      Nome            | Itens Simples      | Itens Especiais    | Tempo de Atendimento |\n");
        printf("+-----------------------------------------------------------------------------------------------+\n");

        int atendidos = 0;
        int tam = tamanhoCaixa(aux->cx);
        Cliente *cl = aux->cx->inicio;

        while (cl && atendidos < tam) {

			  char nome_temp[WIDTH_NOME + 1];
       		 strncpy(nome_temp, cl->nome, WIDTH_NOME);
       		 nome_temp[WIDTH_NOME] = '\0';

        // Remove '\n' que vem do fgets
        char *p = strchr(nome_temp, '\n');
        if (p) *p = '\0';
        
        
            printf("| %-5d | %-20s | %-18d | %-18d | %-20d |\n",cl->id, nome_temp, cl->itens_simples, cl->itens_especiais,cl->tempo_atendimento);

            // atualizar estatísticas globais
             rel->totalClientAtendidos++;
        	 rel->totalItensProcessados += (cl->itens_especiais + cl->itens_simples);
        	 rel->tempoTotalAtendimento += cl->tempo_atendimento;
        	 rel->filaMaisDemorada = piorCaixa(sp);


            // dequeue: remover cliente da fila
            Cliente *remover = cl;
            cl = cl->prox;
            free(remover);
            aux->cx->inicio = cl;

            atendidos++;
        }

        if (atendidos == 0) {
            printf("Nenhum cliente atendido.\n");
        } else {
            printf("+-----------------------------------------------------------------------------------------------+\n");
            printf("Total atendidos nesta caixa: %d\n", atendidos);
        }

       

        aux = aux->prox; // próxima caixa
    }
}

void simularAtendimentoCaixa(Supermercado *sp, int idCaixa, int quantCliente, Relatorio *rel){
    if (!sp) {
        printf("Lista de Caixas inexistente\n");
        return;
    }
    

    // Procurar a caixa específica
    Caixa *cx = procurarCaixa(sp, idCaixa);
    if (!cx) {
      	if(idCaixa>0 && idCaixa<11)
      	  	printf("Caixa [%d] fechada\n", idCaixa);
      	else
      		printf("Verifique o id da Caixa [id]-[1-10]\n");
        return;
    }
    
    if(quantCliente>tamanhoCaixa(cx)){
    	printf("Quantidade de clientes maior que o disponivel\nClientes na caixa [%d]: %d",idCaixa,tamanhoCaixa(cx));
    	return sp;
	}

    printf("\nAtendimento na Caixa %d:\n", sp->id);
    printf("+-----------------------------------------------------------------------------------------------+\n");
    printf("|  ID   |      Nome            | Itens Simples      | Itens Especiais    | Tempo de Atendimento |\n");
    printf("+-----------------------------------------------------------------------------------------------+\n");

    int atendidos = 0;
    Cliente *cl = cx->inicio;

    while (cl && atendidos < quantCliente) {

		  char nome_temp[WIDTH_NOME + 1];
       	  strncpy(nome_temp, cl->nome, WIDTH_NOME);
          nome_temp[WIDTH_NOME] = '\0';

        // Remove '\n' que vem do fgets
        char *p = strchr(nome_temp, '\n');
        if (p) *p = '\0';
        
        
        printf("| %-5d | %-20s | %-18d | %-18d | %-20d |\n", cl->id, nome_temp, cl->itens_simples, cl->itens_especiais, cl->tempo_atendimento);

        // atualizar relatório global
        rel->totalClientAtendidos++;
        rel->totalItensProcessados += (cl->itens_especiais + cl->itens_simples);
        rel->tempoTotalAtendimento += cl->tempo_atendimento;
        rel->filaMaisDemorada = piorCaixa(sp);

        // remover cliente da fila
        Cliente *remover = cl;
        
        cl = cl->prox;
        
        free(remover);
        
        cx->inicio = cl;

        atendidos++;
    }

    if (atendidos == 0) {
        printf("Nenhum cliente atendido.\n");
    } else {
        printf("+-----------------------------------------------------------------------------------------------+\n");
        printf("Total atendidos nesta caixa: %d\n", atendidos);
    }
 
}	
	

void imprimirRelatorio(Relatorio *rel){
    if (!rel) {
        printf("Relatório inexistente\n");
        return;
    }

    printf("\n================ RELATÓRIO FINAL DA SIMULAÇÃO ================\n");
    printf("+------------------------------------------------------------+\n");
    printf("| Métrica                          | Valor                   |\n");
    printf("+------------------------------------------------------------+\n");
    printf("| Total de clientes atendidos      | %-23d |\n", rel->totalClientAtendidos);
    printf("| Total de itens  process.         | %-23d |\n", rel->totalItensProcessados);
    printf("| Caixa mais demorada              | %-23d |\n", rel->filaMaisDemorada);
    printf("| Tempo total de atendimento       | %-23d |\n", rel->tempoTotalAtendimento);

    printf("+-------------------------------------------------------------+\n");
    printf("===============================================================\n\n");
}	
	
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


Cliente *removerCliente(Caixa *cx, int id)
{
	if (!cx || !cx->inicio)
		return NULL;

	Cliente *atual = cx->inicio;
	Cliente *anterior = NULL;

	// Procurar o cliente
	while (atual && atual->id != id)
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

void trocarClientFila(Supermercado *sp, int id)
{
	// Verificar se existe sp
	if (!sp)
	{
		printf("\nNenhuma caixa aberta!\n");
		return;
	}

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
			if (aux->id == id)
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
		printf("\nCliente não encontrado!\n", cliente_encontrado->nome);
		return;
	}

	printf("\nCliente encontrado na Caixa [%d]\n", id_caixa_atual);

	// Encontrar a melhor caixa (menor tempo)
	Caixa *melhor = melhorCaixa(sp);

	if (!melhor || melhor == caixa_atual)
	{
		printf("\nCliente já está na melhor fila!\n");
		return;
	}

	// Remover cliente da fila atual
	Cliente *removido = removerCliente(caixa_atual, id);

	if (!removido)
	{
		printf("\nErro ao remover cliente!\n");
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

	printf("\nCliente '%s' trocado para a melhor fila!\n",removido->nome);
}


void imprimir_clientes(Cliente *l)
{

    printf("\n");
    printf("+-------+----------------------+------------------+------------------+----------------------+\n");
    printf("|  ID   |        Nome          | Itens Simples    | Itens Especiais  | Tempo Atendimento    |\n");
    printf("+-------+----------------------+------------------+------------------+----------------------+\n");

    if (l == NULL)
    {
        printf("|                                  Nenhum cliente cadastrado                                   |\n");
        printf("+-------+----------------------+------------------+------------------+----------------------+\n");
        return;
    }

    while (l != NULL)
    {
        char nome_temp[WIDTH_NOME + 1];
        strncpy(nome_temp, l->nome, WIDTH_NOME);
        nome_temp[WIDTH_NOME] = '\0';

        // Remove '\n' que vem do fgets
        char *p = strchr(nome_temp, '\n');
        if (p) *p = '\0';

        printf("| %-5d | %-20s | %-16d | %-16d | %-20d |\n",
               l->id,
               nome_temp,
               l->itens_simples,
               l->itens_especiais,
               l->tempo_atendimento);

        l = l->prox;
    }

    printf("+-------+----------------------+------------------+------------------+----------------------+\n");
    printf("\n");
}
