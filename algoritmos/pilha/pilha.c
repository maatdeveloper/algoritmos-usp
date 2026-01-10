#include <stdlib.h>

typedef struct reg {
    int val;
    struct reg *prox;
} celula;

celula *criar_pilha()
{
    celula *pi;
    pi = malloc(sizeof (celula));
    pi->prox = NULL;

    return pi;
}

void empilhar(int x, celula *pi)
{
    celula *novo;
    
    novo = malloc(sizeof (celula));
    novo->val = x;
    novo->prox = NULL;
    pi->prox = novo;
}

int desempilhar(celula *pi)
{
    celula *bye;

    bye = pi->prox;
    int x = pi->val;
    pi->prox = bye->prox;

    free(bye);
    return x;
}