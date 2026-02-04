
#include "cliente.h"
#define MAX 50

// Uma caixa eh uma fila de clientes
// Uma caixa aponta para a proxima caixa (lista encadeada)

typedef struct caixa {
    int estaAberta;
    int nome;
    Lista_Cliente * inicio;
    Lista_Cliente * fim;
    struct caixa *prox;
}Lista_Caixa;

Lista_Caixa * criarLista();
Lista_Caixa * carregarCaixas(Lista_Caixa *l);
Lista_Caixa * abrirCaixa(Lista_Caixa *l, int nome);
Lista_Caixa * fecharCaixa(Lista_Caixa *l);