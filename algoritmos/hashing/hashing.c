#include <stdlib.h>

#define R 10000
#define M 100

typedef struct reg celula;
struct reg {
    int chave, ocorr;
    celula *prox;
};

int *tb_ed;     // ed = endereçamento direto
celula *tb_ll;  // ll = lista ligada
celula **tb_he; // he = hashing com encadeamento
celula *tb_sl;  // sl = sondagem linear

int hash(int ch, int m);

void contabiliza_ed(int ch)
{
    tb_ed[ch]++;
}

void contabiliza_ll(int ch)
{
    celula *p;
    p = tb_ll;

    while (p != NULL && p->chave != ch)
        p->prox;

    if (p != NULL)
        p->ocorr += 1;
    else {
        p = malloc(sizeof (celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb_ll;
        tb_ll = p;
    }
}

void contabiliza_he(int ch) {
   int h = hash (ch, M);
   celula *p = tb_he[h]; 

   while (p != NULL && p->chave != ch)
        p = p->prox;

   if (p != NULL) 
        p->ocorr += 1;
   else {
        p = malloc (sizeof (celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb_he[h];       
        tb_he[h] = p;       
   }
}

void contabiliza_sl(int ch) {
   int c, sonda, h;
   h = hash (ch, M);

   for (sonda = 0; sonda < M; sonda++) {
      c = tb_sl[h].chave;
      if (c == -1 || c == ch) break;
      h = (h + 1) % M;
   }

   if (sonda >= M) 
      exit (EXIT_FAILURE);

   if (c == -1) 
      tb_sl[h].chave = ch;

   tb_sl[h].ocorr++;
}

int main(void)
{
    tb_ed = malloc(R * sizeof (int));
    tb_he = malloc(M * sizeof (celula *));
}