#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


/*Aplicația 6.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente
iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele.
Exemplu: allocVec(3,7.2,-1,0) => {7.2, -1, 0}*/

float *allocVec( int n,...)
{
	va_list va; 
	va_start(va,n); 
	float *v;
	v = (float *) malloc( n * sizeof( float));
	if( v== NULL)
		{
		printf("%s", "eroare alocare");
		exit( -1);
		}
	for( int i=0 ;i<n; i++)
		v[i]= va_arg( va, double);
	return v; 
	
}


int main()
{
	float* vec = allocVec(3, 7.2, -1.0, 0.0);
    
    printf("{ ");
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", vec[i]);
    }
    printf("}\n");


	return 0;
	
}
