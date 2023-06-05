#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < m; i++)
    {
        b[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    }

    int nr = 0;
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            int ok = 1;
            for (int k = 0; k < m; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (a[i + k][j + l] != b[k][l])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (ok)
            {
                printf("(%d,%d) ", i, j);
                nr++;
            }
        }
    }

    if (nr == 0)
        printf("Nu apare\n");

    // Eliberarea memoriei alocate pentru matrici
    for (int i = 0; i < n; i++)
        free(a[i]);
    for (int i = 0; i < m; i++)
        free(b[i]);
    free(a);
    free(b);

    return 0;
}

