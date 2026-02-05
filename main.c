#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

#define MAX 50

void menu();
int ler_inteiro(char *s);
int validar_nome(char *s);

<<<<<<< HEAD
int main()
{
=======
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
>>>>>>> f6851844e20bbb6d4bf92d98f6636ef2bd95ed77
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    menu();
    return 0;
}

int ler_inteiro(char *str)
{
    char *final;
    long valor = strtol(str, &final, 10);

    if (*final != '\0')
    {
        return -1;
    }

    return (int)valor;
}

int validar_nome(char *nome)
{
    if (nome == NULL || strlen(nome) == 0)
    {
        printf("[ O nome não pode estar vazio! ]\n");
        return 0;
    }

    int apenasEspacos = 1;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\t' && nome[i] != '\n')
        {
            apenasEspacos = 0;
            break;
        }
    }

    if (apenasEspacos)
    {
        printf("[ O nome não pode conter apenas espaços! ]\n");
        return 0;
    }

    if (strlen(nome) > 30)
    {
        printf("[ O nome não pode ter mais de 30 caracteres! ]\n");
        return 0;
    }

    return 1;
}
<<<<<<< HEAD

void menu()
{
    int opcao, id_caixa, num_itens_simples, num_items_especiais;
    char nome[MAX], input[MAX];

    // Inicializar supermercado (lista de caixas)
    Supermercado *supermercado = NULL;

    do
    {
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
        printf("\t\t\t\t\t║ 08 - Creditos                        ║\n");
        printf("\t\t\t\t\t║ 09 - Imprimir Fila                   ║\n");
        printf("\t\t\t\t\t║ 10 - Simular Atendimento             ║\n");
        printf("\t\t\t\t\t║ 11 - Terminar Simulação              ║\n");
        printf("\t\t\t\t\t║ 12 - Sair                            ║\n");
        printf("\t\t\t\t\t╚══════════════════════════════════════╝\n");

        printf("\nEscolha uma Opcao: ");
        fgets(input, MAX, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline
        opcao = ler_inteiro(input);

        switch (opcao)
        {
        case 1:
        {
            printf("\n[ Simulação Iniciada ]\n");
            break;
        }
        case 2:
        {
            printf("\n[ ABRIR CAIXA ]\n");
            printf("Digite o ID da caixa (1-10): ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0;
            id_caixa = ler_inteiro(input);

            supermercado = abrirCaixa(supermercado, id_caixa);
            printf("Caixa %d aberta com sucesso!\n", id_caixa);
            break;
        }
        case 3:
        {
            printf("\n[ FECHAR CAIXA ]\n");
            printf("Funcionalidade em desenvolvimento...\n");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n[ CADASTRO DE CLIENTES ]\n");

            printf("Digite o ID da caixa: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0;
            id_caixa = ler_inteiro(input);

            printf("Nome do cliente: ");
            fgets(nome, MAX, stdin);
            nome[strcspn(nome, "\n")] = 0;

            if (!validar_nome(nome))
            {
                printf("Nome inválido!\n");
                break;
            }

            printf("Itens simples: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0;
            num_itens_simples = ler_inteiro(input);

            printf("Itens especiais: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0;
            num_items_especiais = ler_inteiro(input);

            inserirCliente(supermercado, id_caixa, nome, num_itens_simples, num_items_especiais);
            printf("\n[ Cliente inserido com sucesso! ]\n");
            break;
        }
        case 5:
        {
            printf("\n[ PIOR FILA ]\n");
            piorCaixa(supermercado);
            break;
        }
        case 6:
        {
            printf("\n[ TAMANHO DAS FILAS ]\n");
            imprimirTamanhoCaixas(supermercado);
            break;
        }
        case 7:
        {
            printf("\n[ TROCAR DE FILA ]\n");
            trocarClientFila(supermercado);
            break;
        }
        case 8:
        {
            printf("\n╔══════════════════════════════════════════════════════════════╗\n");
            printf("║   BEM-VINDO AO SISTEMA DE GESTÃO DE SUPERMERCADO            ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n\n");
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
        case 9:
        {
            printf("\n[ IMPRIMIR FILA ]\n");
            printf("Digite o ID da caixa: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0;
            id_caixa = ler_inteiro(input);

            Caixa *cx = procurarCaixa(supermercado, id_caixa);
            if (cx)
            {
                imprimir(cx->inicio);
            }
            else
            {
                printf("Caixa não encontrada!\n");
            }
            break;
        }
        case 10:
        {
            printf("\n[ SIMULAR ATENDIMENTO ]\n");
            printf("Funcionalidade em desenvolvimento...\n");
            break;
        }
        case 11:
        {
            printf("\n[ TERMINAR SIMULAÇÃO ]\n");
            printf("Funcionalidade em desenvolvimento...\n");
            break;
        }
        case 12:
        {
            printf("\n[ Encerrando programa... ]\n");
            break;
        }
        default:
            printf("\n[ Opção Inválida! ]\n");
        }
    } while (opcao != 12);
}
=======
>>>>>>> f6851844e20bbb6d4bf92d98f6636ef2bd95ed77
