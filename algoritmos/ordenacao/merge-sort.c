#include <stdlib.h>

static void intercala(int p, int q, int r, int v[])
{
    int *w;
    int i = p;
    int j = q;
    int k = 0;

    w = malloc((r - p) * sizeof(int));

    while (i < q && j < r) {
        if (v[i] < v[j])    w[k++] = v[i++];
        else                w[k++] = v[j++];
    }

    while (i < q)   w[k++] = v[i++];
    while (j < r)   w[k++] = v[j++];

    for (i = p; i < r; ++i) v[i] = w[i-p];
    free(w);
}

static void intercala_s(int p, int q, int r, int v[])
{
    int i, j, *w;

    w = malloc((r - p) * sizeof (int));

    for (i = p; i < q; ++i) w[i-p] = v[i];
    for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];

    i = 0;
    j = r - p - 1;

    for (int k = p; k < r; ++k) {
        if (w[i] <= w[j])   v[k] = w[i++];
        else                v[k] = w[j--];
    }
    free(w);
}

void mergesort(int p, int r, int v[])
{
    if (p < r-1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r ,v);
    }
}