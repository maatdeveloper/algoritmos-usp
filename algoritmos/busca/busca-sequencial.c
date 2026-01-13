// Esta funçao recebe um inteiro x e um vetor
// crescente v[0..n-1] e devolve um indice j
// em 0..n tal que v[j-1] < x <= v[j]
int busca_sequencial(int x, int n, int v[])
{
    int j = 0;
    
    while (j < n && v[j] < x) {
        ++j;
    }

    return j;
}