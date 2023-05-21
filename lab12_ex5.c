#include <stdio.h>

/*Aplicația 12.5: Se cere un 0<n<=100 și apoi n valori reale, fiecare reprezentând volumul unui obiect. În final se
cere v, volumul unei cutii. Se cere să se umple cutia cu unele dintre obiecte date, astfel încât volumul ei să fie
utilizat în mod optim.
*/

int x[100], v, n,vol[100];

int verificare_solutie(int pas)
{
	int suma=0;
	for( int i=0; i < pas-1; i++)
		for(int j=i+1; j<pas; j++)
			if(x[i] == x[j]) 
				return 0;
	for( int i=0; i < pas; i++)
		suma+=x[i];
	return suma==v;
}

void afisare(int pas)
{
	for( int i=0; i < pas; i++)
		printf("%d ",x[i]);
	printf("\n");
}

void back( int pas)
{

	for( int i= n-1; i>=0; i--)
	{
		x[pas]=vol[i];
		if(verificare_solutie(pas))
		{
			afisare(pas);
		}
		else
		{
			back(pas+1);
		}
	}
	return 0;
	
}

int main()
{
	printf("n=");
	scanf("%d", &n);
	printf("\n");
	for( int i =0 ; i<n;i++)
	{
		printf("vol[%d]=", i);
		scanf("%d", &vol[i]);
	}
	printf("v=");
	scanf("%d", &v);
	
	back(0);
	
	return 0;
}
