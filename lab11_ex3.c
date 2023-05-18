#include <stdio.h>

#define MAX_SIZE 10

int minim(int a, int b) {
    return a < b ? a : b;
}

int maxim(int a, int b) {
    return a > b ? a : b;
}

int reducere(int v[][MAX_SIZE], int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return v[0][0];

    if (n == 2)
        return maxim(v[0][0], v[0][1]) - minim(v[1][0], v[1][1]);

    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE], d[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            a[i][j] = v[i][j];

    for (int i = 0; i < n / 2; i++)
        for (int j = n / 2; j < n; j++)
            b[i][j - n / 2] = v[i][j];

    for (int i = n / 2; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            c[i - n / 2][j] = v[i][j + n / 2];

    for (int i = n / 2; i < n; i++)
        for (int j = n / 2; j < n; j++)
            d[i - n / 2][j - n / 2] = v[i][j];

    int red_a = reducere(a, n / 2);
    int red_b = reducere(b, n / 2);
    int red_c = reducere(c, n / 2);
    int red_d = reducere(d, n / 2);

    int max_red = maxim(red_a, red_b);
    int min_red = minim(red_c, red_d);

    return max_red - min_red;
}

int main() {
    int v[4][10] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {5,6,7,8},
        {1,2,3,4}
    };

    printf("%d\n", reducere(v, 4));

    return 0;
}

