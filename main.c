#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "exame.h"

#define VERDE "\033[92m"
#define BRANCO  "\033[97m"

#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define PAUSA(ms) usleep(ms * 1000)
#endif




void menu2();
int ler_inteiro(char *s);
int validar_nome(char *s);//serve para garantir que o input deve ser um número e não um texto no scanf

void menu();
int cabecalho();
void limparTela();
void barraProgresso(const char *mensagem, int segundos);

Supermercado *supermercado = NULL;
int main(){

  //setlocale(LC_ALL, "Portuguese");
  system("chcp 65001 > null"); /*serve para aceitar acentuações para pcs que não aceitam o locale.h*/


  cabecalho();


 	//Apenas para teste a parte de baixo

  //Supermercado *supermercado  = criarCaixas();

    /* abrir caixas*/
    /* supermercado = abrirCaixa(supermercado,1);
     supermercado = abrirCaixa(supermercado,2);
     supermercado = abrirCaixa(supermercado,2);
     supermercado = abrirCaixa(supermercado,-1);


    inserirCliente(supermercado,1,"ivanildo",1,0);
    inserirCliente(supermercado,1,"ivanildo",3,2);
    inserirCliente(supermercado,2,"ivanildo",1,1);

   imprimirTamanhoCaixas(supermercado);
   piorCaixa(supermercado);*/



  return 0;
}


int cabecalho() {
  supermercado = criarCaixas();
	 char opcao[10];
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
      printf("║       SIMULAÇÂO DE GESTÂO DE FILAS DE SUPERMERCADOS          ║\n");
      printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    printf("||                                                            ||\n");
    printf("||  Disciplina : Estrutura de Dados I                         ||\n");
    printf("||  Curso      : Engenharia Informática                       ||\n");
    printf("||  Docente    : Silvia António                               ||\n");
    printf("||  Semestre   : 2026 / 1                                     ||\n");
    printf("||                                                            ||\n");
    printf("┌──────────────────────────────────────────────────────────────┐\n");
	printf("│                     Dados do Grupo                           │\n");
    printf("├──────────────────────────────────────────────────────────────┤\n");
    printf("│  Grupo Nº 17                                                 │\n");
    printf("│  Integrantes:                                                │\n");
    printf("│    -> Diangienda Nkana  - 20240092                           │\n");
    printf("│    -> Ivanildo Almeida  - 20240147                           │\n");
    printf("│    -> Erivaldo Caginga  - 20241000                           │\n");
    printf("│  Turma: 2º Ano T1                                            │\n");
    printf("└──────────────────────────────────────────────────────────────┘\n\n");
    printf("||  Pressione ENTER para iniciar a simulação                  ||\n");
    printf("||                                                            ||\n");
    printf("||  Pressione Q e ENTER para sair                             ||\n");
    printf("||                                                            ||\n");
    printf("================================================================\n");
    printf("\nOpcao: ");
    fgets(opcao, sizeof(opcao), stdin);

    if (opcao[0] == 'q' || opcao[0] == 'Q')
        return 0; // sair

    else
    	{
    		limparTela();
    		//Trocar para 3seg
    		barraProgresso("Carregando dados do ficheiro .txt...", 2);
    		supermercado = ler_arquivo(supermercado);
    		if(supermercado != NULL){
                menu();
    		}else{
                printf("Erro ao carregar dados do ficheiro");
    		}

		}
}



void menu() {

  int opcao, opcao_8;
  char input[50],input_8[20], opcao_continuar[20];
  limparTela();

  do {


    printf("\n\n\t\t\t\t------------------------------------------------\n\n");
    printf("\t\t\t\tS U P E R M E R C A D O - I S P T E C _ M A L L \n\n");
    printf("\t\t\t\t------------------------------------------------\n\n");
    printf("\t\t\t\t\t1 -  Abrir caixa  \n");
    printf("\t\t\t\t\t2 -  Fechar caixa \n");
    printf("\t\t\t\t\t3 -  Inserir cliente \n");
    printf("\t\t\t\t\t4 -  Mostrar Pior fila\n");
    printf("\t\t\t\t\t5 -  Tamanho das filas\n");
    printf("\t\t\t\t\t6 -  Trocar de fila \n");
    printf("\t\t\t\t\t7 -  Desistir da fila\n");
    printf("\t\t\t\t\t8 -  Imprimir fila\n");
    printf("\t\t\t\t\t9 -  Simular atendimento \n");
    printf("\t\t\t\t\t10 - Terminar simulação \n");
    printf("\t\t\t\t\t11 - SAIR\n");
    fflush(stdin);

    printf("\nEscolha uma Opcao\n");
    gets(input);
    opcao = ler_inteiro(input);

    switch (opcao) {
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      case 3: {
        break;
      }
      case 4:
        break;
      case 5: {
        system("cls");
        break;
      }
      case 6:
        break;

      case 7: {
        break;
      }
      case 8: {

        do{
            limparTela();
            do {
              printf("\t\t\t\tSobre qual fila deseja obter informação ?   ");
              gets(input_8);
              opcao_8 = ler_inteiro(input_8);

              //Nao permite que a fila seja uma letra ou um negativo
              if (opcao_8 < 0) {
                printf("\t\t\t\t[ A fila deve ser um numero inteiro positivo ]\n");
              }
            }while (opcao_8 < 0);

            imprimirInformacoesCaixa(supermercado,opcao_8);
            printf("\n\t\t\t\tDeseja continuar [1-sim/0-nao]?  ");
            gets(opcao_continuar);

        }while(strcmp(opcao_continuar,"1")==0);
        limparTela();
        break;
      }

      case 9: {

        break;
      }

	case 10: {

        break;
      }
      case 11: {

        break;
      }

      default:
        limparTela();
        printf("Opcao Invalida!\n");

      }
  } while (opcao != 11);
}

void limparTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void barraProgresso(const char *mensagem, int segundos) {

   int largura = 30;

    printf("\n%s%s\n", BRANCO, mensagem);

    for (int i = 0; i <= largura; i++) {
        int percent = (i * 100) / largura;

        printf("\r[");
        printf(VERDE);
        for (int j = 0; j < i; j++)
            printf("#");
        printf(BRANCO);
        for (int j = i; j < largura; j++)
            printf(" ");
        printf("] %3d%%", percent);

        fflush(stdout);
        PAUSA((segundos * 1000) / largura);
    }
    printf("\n");
}





int ler_inteiro(char *str) {
  char *final;
  long valor = strtol(str, &final, 10);

  if (*final != '\0') {
    //printf("Erro: entrada não é um número válido.\n");
    return -1;
  }

  return (int)valor;
}

int validar_nome(char *nome) {
  // Verifica se o nome está vazio
  if (nome == NULL || strlen(nome) == 0) {
    printf("[ O nome não pode estar vazio! ]\n");
    return 0;
  }

  // Verifica se contém apenas espaços em branco
  int apenasEspacos = 1;
  for (int i = 0; nome[i] != '\0'; i++) {
    if (nome[i] != ' ' && nome[i] != '\t' && nome[i] != '\n') {
      apenasEspacos = 0;
      break;
    }
  }

  if (apenasEspacos) {
    printf("[ O nome não pode conter apenas espaços! ]\n");
    return 0;
  }

  // Verifica se o tamanho é maior que 30
  if (strlen(nome) > 30) {
    printf("[ O nome não pode ter mais de 30 caracteres! ]\n");
    return 0;
  }

  return 1;  // Nome válido
}
