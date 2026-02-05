//
// Created by Diangienda on 27/01/2026.
//

#ifndef EXAME_CLIENTE_H
#define EXAME_CLIENTE_H

#define MAX 50

typedef struct lista Cliente;
typedef struct fila Caixa;
typedef struct lista_fila Supermercado;


void imprimir(Cliente *l);
Supermercado *ler_arquivo(Supermercado *s);
int gerarAleatorio(int min, int max);
Supermercado *criarCaixas();
Caixa *inicializarCaixa();
Caixa *inserirCliente(Supermercado *sp,int id_caixa, char *nome, int itens_simples, int itens_especiais);
Supermercado *abrirCaixa(Supermercado *sp,int id);
int contaCaixasAbertas(Supermercado *sp);
int tamanhoCaixa(Caixa *cx);
void imprimirTamanhoCaixas(Supermercado *sp);
Caixa* procurarCaixa(Supermercado *sp, int id);
void piorCaixa(Supermercado *sp);
void imprimirInformacoesCaixa(Supermercado *sp, int id);
int verificarCaixa(Supermercado *sp,int id);

/*Caixa *fecharCaixa(Supermercado *sp, int id);*/

/*
void iniciarSimulacao(char *file);
Caixa *trocarCaixa(Caixa *cx, Cliente *cl);
void imprimirCaixa(Caixa *cx);*/




#endif //EXAME_CLIENTE_H
