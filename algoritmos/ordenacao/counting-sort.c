#include <stdlib.h>

void counting_sort(int *v, int n, int R)
{
    int r;
    int *fp, *aux;

    fp = malloc((R + 1) * sizeof (int));
    aux = malloc(n * sizeof (int));

    for (r = 0; r <= R; ++r) fp[r] = 0;
    for (int i = 0; i < n; ++i) {
        r = v[i];
        fp[r+1] += 1;
    }

    for (r = 1; r <= R; ++R) fp[r] += fp[r-1];
    for (int i = 0; i < n; ++i) {
        r = v[i];
        aux[fp[r]] = v[i];
        fp[r]++;
    }

    for (int i = 0; i < n; ++i) v[i] = aux[i];

    free(fp);
    free(aux);
}