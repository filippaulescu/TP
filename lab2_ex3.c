#include <stdio.h>
#include <stdlib.h>


/*Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
și bsearch.*/

int compare( const void * x_void, const void * y_void)
{
	float * x= ( float *) x_void;
	float * y= ( float *) y_void;
	float x_val = *x;
	float y_val = *y;
	
	if( x_val - y_val < -0.00001 )
		return -1;
	else 
		if(x_val - y_val > 0.00001)
			return 1;
		else 
			return 0;
}


int main()
{
	int n;
	float v[11];
	scanf("%d", &n);
	for( int i=0; i<n; i++)
		scanf("%f", &v[i]);
	
	qsort( v, n, sizeof(float), compare);
	
	for( int i=0; i<n; i++)
		printf("%f\n", v[i]);
	float key=7.0;
	int *cautat=(int *)bsearch(&key, v, n, sizeof(float), compare);
	if( cautat== NULL)
		printf("NU");
	else
		printf("DA");

    return 0;
}
