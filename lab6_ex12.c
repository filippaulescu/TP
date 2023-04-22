#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aplicația 6.13: Un program primește în linia de comandă ca prim argument un cod de operație și pe urmă o serie
de cuvinte. Codul poate fi: 0-afișează numărul total de litere din toate cuvintele: 1-afișează fiecare literă de câte ori
apare în toate cuvintele.
Exemplu: ./statistica 0 ion merge la film va afișa: 14 */

int main(int argc, char* argv[]) {
    int cod = atoi(argv[1]);

    if (cod == 0) {
        int total_litere = 0;
        for (int i = 2; i < argc; i++) {
            total_litere += strlen(argv[i]);
        }
        printf("%d\n", total_litere);
    } else if (cod == 1) {
        int v['z' - 'a' + 1] = {0};
        int V['Z' - 'A' + 1] = {0};
        for (int i = 2; i < argc; i++) {
            for (int j = 0; j < strlen(argv[i]); j++) {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z') {
                    v[argv[i][j] - 'a']++;
                } else if (argv[i][j] >= 'A' && argv[i][j] <= 'Z') {
                    V[argv[i][j] - 'A']++;
                }
            }
        }
        for (int i = 0; i < ('z' - 'a' + 1); i++) {
            if (v[i] > 0) {
                printf("%c-%d\n", 'a' + i, v[i]);
            }
        }
        for (int i = 0; i < ('Z' - 'A' + 1); i++) {
            if (V[i] > 0) {
                printf("%c-%d\n", 'A' + i, V[i]);
            }
        }
    } else {
        printf("Cod de operatie invalid: %d\n", cod);
        return 1;
    }

    return 0;
}
