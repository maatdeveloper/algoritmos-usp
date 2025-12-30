/*
 * Programa: pisolog.c
 * Autor: Matheus
 * Data: 30/12/2025
 * 
 *  Este programa imprime uma tabela dos valores do
 * piso de log N para N = B^1, B^2, ..., B^K.
 *  Como de hábito, log é o logaritmo na base 2.
 *  Os valores são especificados na linha de comando:
 *  para executar o programa com B = 10 e K = 6, por
 *  exemplo, diga
 *      
 *      ./pisolog 10 6
 */

/*
 * Protótipos de funções.
 * O programa usa as funções externas printf (da
 * biblioteca stdio) e strtol (da biblioteca stdlib).
 */

#include <stdio.h>
#include <stdlib.h>

int lg(int N);

int main(int argc, char *argv[])
{
    int B = strtol(argv[1], NULL, 10);
    int K = strtol(argv[2], NULL, 10);
    int N = 1;

    printf("\n          N  lg(N)\n\n");
    for (int i = 1; i <= K; ++i) {
        N *= B;
        printf("%11d %5d\n", N, lg(N));
    }

    return EXIT_SUCCESS;
}

int lg(int N)
{
    int i = 0;
    int n = N;

    while (n > 1) {
        i++;
        n /= 2;
    }

    return i;
}