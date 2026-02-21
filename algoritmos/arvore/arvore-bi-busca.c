#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int chave;
    int conteudo;
    struct reg *esq, *dir;
} node;

typedef node* arvore;

node *busca(arvore r, int k)
{
    if (r == NULL || r->chave == k) {
        return r;
    }
    if (r->chave < k)
        return busca(r->esq, k);
    else
        return busca(r->dir, k);
}

arvore insere(arvore r, node *novo)
{
    if (r == NULL) return novo;

    if (r->chave > novo->chave)
        r->esq = insere(r->esq, novo);
    else
        r->dir = insere(r->esq, novo);

    return r;
}

arvore remove_raiz(arvore r)
{
    node *p, *q;

    if (r->esq == NULL) {
        q = r->dir;
        free(r);
        return q;
    }

    p = r;
    q = r->esq;
    while (q->dir != NULL) {
        p = q;
        q = q->dir;
    }

    if (p != q) {
        p->dir = q->esq;
        q->esq = r->esq;
    }

    q->dir = r->dir;
    free(r);
    return q;
}