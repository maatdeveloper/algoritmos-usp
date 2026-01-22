/*
 * Programa: ex01.c
 * Autor: Matheus
 * Data: 19/01/2026
 * 
 * Resolução do exercício 7:
 * > Logaritmos na base 10.  Escreva uma função que calcule o piso do logaritmo na base 10 de um número. 
 */

#include <stdio.h>
#include <stdlib.h>

int piso_log10(int N);

int main(void)
{
    int exp, pot;
    
    printf("=========- Piso de N em log10 -=========\n");
    printf("Digite um numero: ");
    
    if (scanf("%d", &exp) != 1) {
        fprintf(stderr, "ERRO! Entrada invalida!\n");
        return EXIT_FAILURE;
    }

    if (exp <= 0) {
        fprintf(stderr, "ERRO! N deve ser maior que 0!\n");
        return EXIT_FAILURE;
    }

    pot = piso_log10(exp);
    printf("\n\nO piso de %d é: %d\n", exp, pot);

    return EXIT_SUCCESS;
}

/* A funçao piso_log10 recebe N > 0
 * e devolve o piso de log10 N
 */
int piso_log10(int N)
{
    int i = 0;
    int n = 1;

    while (n <= N/10) {
        n *= 10;
        i++;
    }

    return i;
}