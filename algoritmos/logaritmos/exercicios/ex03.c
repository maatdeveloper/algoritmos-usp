/* 
 * Programa: ex03.c
 * Autor: Matheus
 * Data: 21/01/2026
 *
 * Resuloção do exercício 1:
 * > Como se sabe, log Bi = i log B para quaisquer B e i.  Poderíamos pensar em reescrever o programa 
 * > pisolog da seguinte maneira: calcule b = lg(B) e depois imprima b, 2*b, … , K*b.  Isso produziria
 * > uma tabela correta? R: não 👍
 * 
 * Resolução do exercício 2:
 * > Ao calcular as potências de B em main, o programa corre o risco de produzir resultados errados em
 * > virtude de um overflow aritmético. (Isso acontece, por exemplo, se B vale 2 e K vale 31.) Modifique 
 * > o código de main de modo que a execução seja interrompida antes que ocorra um overflow.
 * 
 * Resulção do exercício 3:
 * > Se R é um número estritamente positivo, qual a relação entre o piso de log10 R e R?  Escreva uma
 * > função recursiva que receba um número inteiro estritamente positivo m e devolva o piso de log10 m.
 */

///////////////////////////////////////////////////
// Protótipos de funções.
// O programa usa as funções externas printf (da
// biblioteca stdio) e strtol (da biblioteca 
// stdlib).

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int lg (int);
int lg10_r(int);

// Comunicação com o usuário. 
// Os dois argumentos na linha de comando, B e K,
// devem ser menores que INT_MAX (veja a interface
// limits.h).

int main (int numargs, char *arg[])
{ 
    long tmp;

    if (numargs != 3) {
        fprintf(stderr, "Use: ./pisolog B K\n");
        return EXIT_FAILURE;
    }

    tmp = strtol (arg[1], NULL, 10);
    if (tmp < 2 || tmp > INT_MAX) {
        fprintf(stderr, "B deve ser >= 2\n");
        return EXIT_FAILURE;
    }
    int B = (int) tmp;

    tmp = strtol (arg[2], NULL, 10);
    if (tmp < 1 || tmp > INT_MAX) {
        fprintf(stderr, "K deve ser >= 1\n");
        return EXIT_FAILURE;
    }
    int K = (int) tmp;

    int N = 1;
    int b = lg(B);

    printf ("\n          N  lg(N)  i*lg(b)\tlg10(n)\n\n");
    for (int i = 1; i <= K; ++i) {
        if (N > INT_MAX / B) {
            fprintf(stderr, "\noverflow!\n\n");
            return EXIT_FAILURE;
        }

        N = B * N;
        printf ("%11d %5d %5d\t\t", N, lg (N), i * b);
        printf("lg10_r(%d) = %d\n", N, lg10_r(N));
    }


    return EXIT_SUCCESS;
}
 
// A função lg recebe um inteiro N > 0
// e devolve o piso de log N.

int lg (int N)
{  
    int i = 0, n = N;
    while (n > 1) {
        i += 1;
        n /= 2;
    }
    return i;    
}

int lg10_r(int m)
{
    if (m < 10)
        return 0;

    return 1 + lg10_r(m / 10);
}