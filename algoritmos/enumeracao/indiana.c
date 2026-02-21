#include <stdio.h>
#include <stdlib.h>

int indiana(int** pp, int n)
{
    int i, k, t;
    i = n-1;

    while (i >= 1 && pp[i] > pp[i+1]) i--;
    if (i < 1) return 0;

    k = n;
    while (pp[i] > pp[k]) k--;

    t = pp[k];
    pp[k] = pp[i];
    pp[i] = t;

    i += 1;
    k = n;
    while (i < k) {
        t = pp[i];
        pp[i] = pp[k];
        pp[k] = t;
        i++;
        k--;
    }

    return 1;
}