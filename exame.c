
//
// Created by Diangienda on 27/01/2026.
//

#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define TEMPO_SIMPLES 1
#define TEMPO_ESPECIAIS 3
#define TEMPO_ATENDIMENTO_PADRAO 5


struct lista{
	char nome[50];//O cliente será identificado pelo nome
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



Supermercado *criarCaixas(){return NULL;}

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

Caixa *inserirCliente(Supermercado *sp,int id_caixa, char *nome, int itens_simples, int itens_especiais){

	Caixa *cx = procurarCaixa(sp,id_caixa);

	if(cx == NULL){
		printf("Erro ao localizar Caixa");
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
			cl->tempo_atendimento = 5+(1*itens_simples)+(3*itens_especiais);
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
		return sp;
	}


	 else if(contaCaixasAbertas(sp)>10){
	 	 printf("Sem Caixas fechadas\n");
	 	 return sp;
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

void imprimirInformacoesCaixa(Supermercado *sp, int id){

	Caixa *cx = procurarCaixa(sp,id);
	int tempo_total =0, itens_simples = 0, itens_especiais=0;
	if (cx) {
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

	}else {
		printf("\t\t\t\t\tCaixa nao encontrada\n\n");
	}

}


void piorCaixa(Supermercado *sp){

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


		if(id!=-1)
			printf("Pior Caixa: FILA[%d]\n",id);
		else
			printf("Nenhuma caixa encontrada!");
	}

}


int gerarAleatorio(int min, int max) {

    return min + rand() % (max - min + 1);
}

void imprimir(Cliente *l) {
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
               l->id, l->nome, l->itens_simples,l->itens_especiais, l->tempo_atendimento);
        l = l->prox;
    }

    // Rodapé da tabela
    printf("+------+--------------------------------+---------------+-----------------+-----------------------+\n");

    printf("\n");
}

