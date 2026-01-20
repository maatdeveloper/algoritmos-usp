#define troca (A, B) {int t = A; A = B; B = t;}

static void constroi_heap(int m, int v[])
{
    for (int k = 1; k < m; ++k) {
        int f = k + 1;
        while (f > 1 && v[f/2] < v[f]) {
            troca (v[f/2], v[f]);
            f /= 2;
        }
    }
}

static void peneira(int m, int v[])
{
    int p = 1;
    int f = 2;
    int x = v[1];

    while (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (x >= v[f]) break;
        
        v[p] = v[f];
        p = f;
        f = 2 * p;
    }

    v[p] = x;
}

void heapsort(int n, int v[])
{
    constroi_heap(n, v);
    for (int m = n; m >= 2; --m) {
        troca(v[1], v[m]);
        peneira(m-1, v);
    }
}