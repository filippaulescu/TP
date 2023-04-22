#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aplicația 6.11: Un program primește în linia de comandă o expresie formată din numere reale și operatorii 
{add-adunare, sub-scădere, mul-înmulțire, div-împărțire}. Programul va calcula valoarea expresiei și va afișa 
rezultatul. Expresia se calculează de la stânga la dreapta, fără a ține cont de precedența matematică a operatorilor.
Exemplu: ./calcul 10.5 add 1.5 div 3 va afișa: 4 */

int main(int argc, char* argv[]) {
    float result = atof(argv[1]);
    for (int i = 2; i < argc; i += 2) {
        char *op = argv[i];
        float val = atof(argv[i + 1]);
        if (strcmp(op, "add") == 0)
            result += val;
        else if (strcmp(op, "sub") == 0)
            result -= val;
        else if (strcmp(op, "mul") == 0)
            result *= val;
        else if (strcmp(op, "div") == 0)
            result /= val;
    }
    printf("%f\n", result);
    return 0;
}

