/*
 * Programa: ex02.c
 * Autor: Matheus
 * Data: 20/01/2026
 * 
 * Resolução do exercício 3:
 * > Escreva uma versão recursiva da função lg.
 * 
 * Resolução do exercício 5:
 * > O que é o teto de um número real r?  Se R é um número estritamente positivo, qual a relação entre o  * > teto de  log10 R  e  R?  Escreva uma função recursiva que receba um número inteiro estritamente 
 * > positivo N e devolva o teto de log10 N. 
 */

#include <stdio.h>
#include <stdlib.h>

int lg_r(int N);
int log10_teto(int R);

int main(void)
{
    int exp;
    int pot;

    // Exercício 3
    printf("<-====== Piso de 'n' em log2 ======->\n");
    printf("Digite um valor: ");
    if (scanf("%d", &exp) != 1) {
        fprintf(stderr, "ERRO! Entrada invalida\n");
        return EXIT_FAILURE;
    }

    if (exp <= 0) {
        fprintf(stderr, "ERRO! N deve ser maior que zero!\n");
        return EXIT_FAILURE;
    }

    pot = lg_r(exp);
    printf("\nO piso de %d é de: %d\n", exp, pot);

    // Exercício 5
    printf("<-====== Teto de 'r' em log10 ======->\n");
    printf("Digite um valor: ");
    if (scanf("%d", &exp) != 1) {
        fprintf(stderr, "ERRO! Entrada invalida\n");
        return EXIT_FAILURE;
    }

    if (exp <= 0) {
        fprintf(stderr, "ERRO! N deve ser maior que zero!\n");
        return EXIT_FAILURE;
    }

    pot = log10_teto(exp);
    printf("O teto de %d é de: %d\n", exp, pot);

    return EXIT_SUCCESS;
}

int lg_r(int N)
{
    if (N <= 1)
        return 0;

    return 1 + lg_r(N / 2);
}

int log10_teto(int R)
{
    int i = 0;
    int r = 1;
    
    while (r < R/10) {
        r *= 10;
        i++;
    }

    return i;
}