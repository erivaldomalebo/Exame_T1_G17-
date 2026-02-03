#include "caixa.h"



Lista_Caixa * criarLista();
    //So inicializa com NULL
void carregarCaixas(Lista_Caixa *l);
    /**
        Inicializa a lista de caixas atraves do ficheiro
    */
void abrirCaixa(Lista_Caixa *l, int nome);
 /**
        A abertura pode ser de forma aleatoria ou manual.

        Abre uma das caixas fechadas e permite que seja criada uma fila
        para atender clientes. Se não houver caixas fechadas, o programa
        deve informar.
 */

