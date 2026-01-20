#include <stdlib.h>

typedef unsigned char byte;

void ordenacao_digital(byte **v, int n, int W, int R)
{
    int *fp;
    byte **aux;

    fp = malloc((R + 1) * sizeof (int));
    aux = malloc(n * sizeof (byte *));

    for (int d = W-1; d >= 0; --d) {
        int r;

        for (r = 0; r <= R; ++r) fp[r] = 0;
        for (int i = 0; i < n; ++i) {
            r = v[i][d];
            fp[r+1] += 1;
        }

        for (r = 1; r <= R; ++r) fp[r] += fp[r-1];
        for (int i = 0; i < n; ++i) {
            r = v[i][d];
            aux[fp[r]] = v[i];
            fp[r++];
        }

        for (int i = 0; i < n; ++i) v[i] = aux[i];
    }

    free(fp);
    free(aux);
}