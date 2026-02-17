#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    node *pai;
    node *esq;
    node *dir;
} node;

typedef node *arvore;

void erd (arvore r)
{
    if (r != NULL) {
        erd (r->esq);
        printf("%d\n", r->conteudo);
        erd (r->dir);
    }
}

int altura(arvore r)
{
    if (r == NULL)
        return -1;
    else {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he < hd)    return hd + 1;
        else            return he + 1;
    }
}

node *primeiro(arvore r)
{
    while (r->esq != NULL)
        r = r->esq;
    return r;
}

node *seguinte(node *x)
{
    if (x->dir != NULL) {
        node *y = x->dir;
        while (y->esq != NULL) y = y->esq;
        return y;
    }

    while (x->pai != NULL && x->pai->dir == x)
        x = x->pai;
    return x->pai;
}