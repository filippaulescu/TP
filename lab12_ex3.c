#include <stdio.h>

/*Aplicația 12.3: Se citesc doua numere naturale n si k, k fiind mai mic decat numarul de cifre ale numarului n. Afisati
cel mai mare numar care se poate forma eliminand k cifre din numarul n.
Exemplu:
n=3452234
k=4
numarul cautat este 534*/

int v[20],x[20], nrc=0, k, maxim=0;

int formare_numar()
{
	int solutie=0;
	
	for(int i=0; i<nrc-k; i++)
		solutie=solutie*10+x[i];
		
	return solutie;
}

int verificare_solutie()
{
	for(int i=0; i<nrc-k-1; i++)
		for( int j=i+1; j<nrc-k; j++)
			if( x[i] == x[j] ) 
				return 0;
	return 1;
}

void back(int pas)
{
	for( int i=0; i<nrc; i++)
	{
		x[pas]=v[i];
	if(pas +1 == nrc-k) 
	{
		if(verificare_solutie())
			if(formare_numar()>maxim) 
				maxim = formare_numar();
			
	}
	else
		back(pas+1);
	}

}




int main(void)
{
	int n;
	scanf("%d%d", &n, &k);
	
	int i=-1;
	while( n>0)
	{
		v[++i]=n%10;
		nrc++;
		n=n/10;
	}
	
	back(0);
	printf("maximul = %d" ,maxim);
	


    return 0;
}


