#include <stdlib.h>

typedef struct reg {
    int val;
    struct reg *prox;
} celula;

celula *criar_fila()
{
    celula *fi;
    fi = malloc(sizeof (celula));
    fi->prox = fi;

    return fi;
}

int remover(celula *fi)
{
    celula *p;

    p = fi->prox;
    int x = p->val;
    fi->prox = p->prox;

    free(p);
    return x;
}

celula *adicionar(int x, celula *fi)
{
    celula *nova;

    nova = malloc(sizeof (celula));
    nova->prox = fi->prox;
    fi->prox = nova;
    fi->val = x;

    return nova;
}