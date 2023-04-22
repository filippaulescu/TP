#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>


/*Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y);*/

void absN( int n,...)
{
	va_list va; 
	va_start(va,n); 
	for( int i=0; i<n; i++)
	{
	float *p=va_arg(va, float* );
	*p= fabsf(va_arg(va, double));
	}
	va_end(va);
}


int main()
{
	float x=1, y=-2;
	//printf("%f %f\n", x,y);
	absN( 2, (float *) &x, (float *) &y);
	printf("%f %f\n", x,y);
	


	return 0;
	
}
