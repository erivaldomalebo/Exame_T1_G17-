#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define MAX 50

/* TAD CLIENTE*/
void menu();
int ler_inteiro(char *s);
int validar_nome(char *s);//serve para garantir que o input deve ser um número e não um texto no scanf


int main() {
  system("chcp 65001 > null"); /*serve para aceitar acentuações para pcs que não           aceitam o locale.h*/

  menu();

  return 0;
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


void menu() {

  int opcao, opcao_eliminar_no, num_itens_simples, num_items_especiais;
  char nome[MAX], input[MAX], input_numero[MAX], input_nome[MAX];

  // Todos os clientes
  Lista_Cliente * clientes = criarLista();

  do {
    printf("\n\n\t\t\t\t-------------------------------------\n\n");
    printf("\t\t\t\t\tS U P E R M E R C A D O \n\n");
    printf("\t\t\t\t-------------------------------------\n\n");

    printf("\n\t\t\t\t\t╔══════════════════════════════════════╗\n");
	printf("\t\t\t\t\t║          MENU PRINCIPAL              ║\n");
	printf("\t\t\t\t\t╠══════════════════════════════════════╣\n");
	printf("\t\t\t\t\t║ 01 - Iniciar a Simulação             ║\n");
	printf("\t\t\t\t\t║ 02 - Abrir Caixa                     ║\n");
	printf("\t\t\t\t\t║ 03 - Fechar Caixa                    ║\n");
	printf("\t\t\t\t\t║ 04 - Inserir Cliente                 ║\n");
	printf("\t\t\t\t\t║ 05 - Pior Fila                       ║\n");
	printf("\t\t\t\t\t║ 06 - Tamanho das Filas               ║\n");
	printf("\t\t\t\t\t║ 07 - Trocar de Fila                  ║\n");
	printf("\t\t\t\t\t║ 08 - Desistir da Fila                ║\n");
	printf("\t\t\t\t\t║ 09 - Imprimir Fila                   ║\n");
	printf("\t\t\t\t\t║ 10 - Simular Atendimento             ║\n");
	printf("\t\t\t\t\t║ 11 - Terminar Simulação              ║\n");
	printf("\t\t\t\t\t║ 12 - Sair                            ║\n");
	printf("\t\t\t\t\t╚══════════════════════════════════════╝\n");
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
        system("cls");

        break;
      }
        //Inicio - > Inserir Cliente
      case 4: {
        system("cls");
        printf("\t\t\t\t\t C A D A S T R O  D E  C L I E N T E S \n\n");
        printf("\t\t\t\t\t | N O M E:  ");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        printf("\n\t\t\t\t\t | I T E N S  S I M P L E S:  ");
        scanf("%d", &num_itens_simples);
        fflush(stdin);
        printf("\n\t\t\t\t\t | I T E N S  E S P E C I A I S:  ");
        scanf("%d", &num_items_especiais);

        clientes = inserir_cliente(clientes, nome,num_itens_simples, num_items_especiais);
        printf("\n\t\t\t\t\t Cliente Inserido com sucesso !!!");
        fflush(stdin);


        break;
      }
        //Fim - > Inserir Cliente
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
        printf("\n╔══════════════════════════════════════════════════════════════╗\n");
        printf("║   BEM-VINDO AO SISTEMA DE GESTÃO DE CLIENTES                 ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");

        printf("\tEste sistema foi desenvolvido para aplicar os nossos conhecimentos\n");
        printf("\tsobre Tipos Abstratos de Dados e Listas encadeadas simples, aprendidos com a \n");
        printf("\tEstimada Professora Sílvia António. \n\n");

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
        break;
      }

      case 12:{
          system("cls");
          fflush(stdin);
          imprimir(clientes);

        break;
      }

      default:
        printf("Opcao Invalida!\n");
      }
  } while (opcao != 9);
}

