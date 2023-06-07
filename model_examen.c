#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBIECTE 100
#define MAX_GREUTATE 100

int N, G;

typedef struct obiect
{
    int vi; // valoare
    int gi; // greutatea
    int nr_crt; // numarul de ordine al obiectului
} obiect;

obiect *obiecte = NULL;
obiect ghiozdan[MAX_OBIECTE];
obiect best[MAX_OBIECTE] = { {0, 0} };
int v_best = 0;

void afisare(int pas)
{
    for (int i = 0; i < pas; i++)
    {
        printf("(%d %d)+", best[i].vi, best[i].gi);
    }
    printf("\n");
}

int solutie(int pas)
{
    int g = 0;
    for (int i = 0; i < pas; i++)
    {
        g += ghiozdan[i].gi;
    }
    for (int i = 0; i < pas - 1; i++)
    {
        for (int j = i + 1; j < pas; j++)
            if (ghiozdan[i].nr_crt == ghiozdan[j].nr_crt)
                return 0;
    }
    return (pas <= N && g == G);
}

void solutie_optima(int pas)
{
    int v = 0;
    for (int i = 0; i < pas; i++)
    {
        v += ghiozdan[i].vi;
    }
    if (v > v_best)
    {
        for (int i = 0; i < pas; i++)
        {
            best[i].vi = ghiozdan[i].vi;
            best[i].gi = ghiozdan[i].gi;
        }
        v_best = v;
    }
}

void back(int pas)
{
    if (pas > N)
        return;
    if (solutie(pas))
    {
        solutie_optima(pas);
        afisare(pas);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            ghiozdan[pas] = obiecte[i];
            back(pas + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &G);

    obiecte = malloc(N * sizeof(obiect));
    if (obiecte == NULL)
    {
        printf("NU se poate face alocare dinamica");
        exit(-1);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &obiecte[i].vi, &obiecte[i].gi);
        obiecte[i].nr_crt = i;
    }

    back(0);

    free(obiecte);
    return 0;
}
