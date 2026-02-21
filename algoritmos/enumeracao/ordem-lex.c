#include <stdio.h>
#include <stdlib.h>

void ss_lex(int n)
{
    int* ss, k;
    ss = malloc ((n+1) * sizeof (int));
    ss[k=0] = 0;

    while (1) {
        if (ss[k] < n) {
            ss[k+1] = ss[k] + 1;
            ++k;
        }
        else {
            ss[k-1] += 1;
            --k;
        }

        if (k == 0) break;
    }

    free(ss);
}