#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>


/*Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/

int crescator( int n,char tip, ...)
{
	va_list va; 
	va_start(va,tip); 
	if(tip=='d')
	{
		int elem=va_arg(va, int);
		for( int i=0; i<n; i++)
		{
			int new_elem= va_arg(va, int);
			if( elem> new_elem) 
				return 0;
			elem=new_elem;
		}
	}
	if(tip=='f')
	{
		double elem=va_arg(va, double);
		for( int i=0; i<n; i++)
		{
			double new_elem= va_arg(va, double);
			if( elem> new_elem) 
				return 0;
			elem=new_elem;
		}
	}
	
	va_end(va);
	
	
	return 1;
}


int main()
{

	printf("%d", crescator(3, 'd', 1,2,3));
	


	return 0;
	
}
