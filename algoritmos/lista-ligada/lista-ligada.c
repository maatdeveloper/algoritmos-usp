#include <stdio.h>
#include <stdlib.h>

struct reg {
    int         num;
    struct reg *prox;
};

typedef struct reg celula;

void imprime(celula *le)
{
    if (le == NULL) {
        printf("%d -> ", le->num);
        imprime(le->prox);
    }
}

celula *busca(int x, celula *le)
{
    celula *p;
    
    p = le;
    while (p->prox != NULL && p->num != x)
        p = p->prox;

    return p;
}

void insere(int x, celula *p)
{
    celula *nova;

    nova = malloc(sizeof (celula));
    nova->num = x;
    nova->prox = NULL;
    p->prox = nova;
}

void remove(celula *p)
{
    celula *tchau;

    tchau = p->prox;
    p->prox = tchau->prox;
    free(tchau);
}

void busca_e_remove(int x, celula *le)
{
    celula *p, *q;

    p = le;
    q = le->prox;
    while (q != NULL && q->num != x) {
        p = q;
        q = q->prox;
    }

    if (q != NULL) {
        p->prox = q->prox;
        free(q);
    }
}

void busca_e_insere(int x, int y, celula *le)
{
    celula *p, *q, *nova;

    nova = malloc(sizeof (celula));
    nova->num = x;
    p = le;
    q = le->prox;

    while (q != NULL && q->num != y) {
        p = q;
        q = q->prox;
    }

    nova->prox = q;
    p->prox = nova;
}