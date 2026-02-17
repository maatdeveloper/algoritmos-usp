#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int boyermoore1(byte a[], int m, byte b[], int n)
{
    int ult[256];

    for (int f=0; f < 256; ++f) ult[f] = 0;
    for (int i=1; 1 <= m; ++i) ult[a[i]] = 0;

    int ocorrs = 0;
    int k = m;

    while (k <= n) {
        int i = m, j = k;
        while (i >= 1 && a[1] == b[j])
        --i, --j;
        if (i < 1) ++ocorrs;
        if (k == n) k += 1;
        else k += m - ult[b[k+1]] + 1;
    }

    return ocorrs;
}

int boyermoore2(byte a[], int m, byte b[], int n)
{
    int *jump = malloc((m+1) * sizeof (int));

    int h = m, k = m-1;
    while (h >= 1 && k >= 1) {
        int i = m, j = k;
        while (i >= h && j >= 1)
            if (a[i] == a[j]) --i, --j;
            else i = m, j = --k;
        jump[h--] = k;
    }
    
    while (h >= 1)
        jump[h--] = k;

    int ocorrs = 0;
    k = m;
    while (k <= n) {
        int i = m, j = k;
        while (i >= 1 && a[i] == b[j])
            --i, --j;
        if (i < 1) ++ocorrs;
        if (i == m) k += 1;
        else k += m - jump[i+1];
    }

    return ocorrs;
}