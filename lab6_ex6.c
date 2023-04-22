#include <stdarg.h>
#include <stdio.h> 
#include <stdlib.h> 

/*Aplicația 6.6: Să se scrie o funcție char *concat(int n,...) care primește un număr de șiruri de caractere și apoi
șirurile propriu-zise. Funcția va concatena într-un nou șir, alocat dinamic, conținuturile tuturor șirurilor date, cu câte
un spațiu între ele și va returna acest șir.
Exemplu: concat(3,”Ion”,”si”,”Ana”) => “Ion si Ana”*/

char* concat(int n, ...)
{
    va_list va; 
    va_start(va, n); 

    // determinam lungimea totala a sirurilor de caractere
    int total_length = 0;
    for (int i = 0; i < n; i++) {
        char* str = va_arg(va, char*);
        total_length += strlen(str);
    }

    // adaugam spatiile intre siruri
    total_length += n - 1;

    // alocam un nou sir de caractere
    char* result = (char*) malloc(total_length + 1);
    if (result == NULL) {
        printf("Eroare la alocarea memoriei!");
        exit(1);
    }

    // concatenam sirurile de caractere
    int current_pos = 0;
    for (int i = 0; i < n; i++) {
        char* str = va_arg(va, char*);
        sprintf(result + current_pos, "%s", str);
        current_pos += strlen(str);

        if (i < n - 1) {
            sprintf(result + current_pos, " ");
            current_pos++;
        }
    }

    va_end(va); 

    return result;
}

int main()
{
    char* str = concat(3, "Ion", "si", "Ana");
    printf("%s\n", str);
    free(str);

    return 0;
}
