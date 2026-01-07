/*
 * Programa: vetor.c
 * Autor: Matheus
 * Data: 06/01/2026
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define VECSIZE 1024

int busca(int x, int n, int v[]);
int busca_r(int x, int n, int v[]);
int remove(int k, int n, int v[]);
int remove_r(int k, int n, int v[]);
void insere(int k, int x, int n, int v[]);
void insere_r(int k, int x, int n, int v[]);

// A função recebe x, n >= 0 e v e devolve
// um indice k em 0..n-1 tal que x == v[k].
// Se k não existir, devolve -1
int busca(int x, int n, int v[])
{
    int k = n-1;
    while (k >= 0 && v[k] != x) k--;

    return k;
}

// Recebe x, n >= 0 e v, devolve k
// tal que 0 <= k < n e v[k] == x.
// Se k não existe, devolve -1
int busca_r(int x, int n, int v[])
{
    if (n == 0) return -1;
    if (x = v[n-1]) return n-1;

    return busca_r(x, n-1, v);
}

// Esta função recebe um vetor v[0..n-1]
// e um índice tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor
int remove(int k, int n, int v[])
{
    int x = v[k];
    for (int j = k+1; j < n; ++j)
        v[j-1] = v[j];
    
    return x;
}

// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor
int remove_r(int k, int n, int v[])
{
    int x = v[k];
    if (k < n-1) {
        int y =  remove_r(k+1, n, v);
        v[k] = y;
    }

    return x;
}

// Esta função insere x entre as
// posiçoes k-1 e k do vetor v[0..n-1]
// supondo que 0 <= k <= n.
void insere(int k, int x, int n, int v[])
{
    for (int j=n; j>k; --j)
        v[j] = v[j-1];
    v[k] = x;
}

// Esta função insere x entre as
// posiçoes k-1 e k do vetor v[0..n-1]
// supondo que 0 <= k <= n
void insere_r(int k, int x, int n, int v[])
{
    if (k == n) v[n] = x;
    else {
        v[n] = v[n-1];
        insere_r(k, x, n-1, v);
    }
}