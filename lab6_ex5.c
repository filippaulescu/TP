#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>


/*Aplicația 6.5: Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice
în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe
ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
Exemplu: input(”n=%dch=%c”,&n,&ch); // citește o valoare de tip int în n și de tip char în ch*/

void input( const char *fmt, ...)
{
	va_list va; 
	va_start(va,fmt); 
	
	for( const char *p= fmt; *p!='\0'; p++)
	{	
		if(*p=='%')
			switch(*(++p))
			{
				case 'd':
					scanf("%d", va_arg(va,int*));
					break;
				case 'f':
					scanf("%f", va_arg(va, float*));
					break;
				case 'c':
					scanf(" %c", va_arg(va, char*));
					break;
				default:
					printf("invalid");
					exit(1);
			}
		else
		{
            putchar(*p);
        }
	}
	
	
	
	va_end(va);
}


int main()
{
	int n;
	char ch;

	input("n=%dch=%c",&n,&ch);
	


	return 0;
	
}
