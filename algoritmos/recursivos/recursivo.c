/*
 * Programa: recursivo.c
 * Nome: Matheus
 * Data: 07/01/2026
 * 
 */

int maximo(int n, int v[]);

int main(void)
{
    return 0;
}

// Ao receber v e n >= 1, a funçao devolve
// o valor de um elemento máximo do
// vetor v[0..n-1]
int maximo(int n, int v[])
{
    if (n == 1) return v[0];
    else {
        int x;

        x = maximo(n-1, v);
        if (x > v[n-1]) return x;
        else            return v[n-1];
    }
}