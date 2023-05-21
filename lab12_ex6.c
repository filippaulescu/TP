#include <stdio.h>

/*Aplicația 12.6: De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini,
ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli
(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca
vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini
și ateliere. Să se determine toate variantele în care acestea pot fi aranjate.
NU FUNCTIONEAZA!!!!
*/
int b,c,g,a, v[100];

int verificare_solutie( int pas)
{
	int nrb=0, nrc=0, nrg=0, nra=0;
	for( int i=0; i< pas; i++)
		{
			if(v[i]==1) nrb++;
			if(v[i]==2) nrc++;
			if(v[i]==3) nrg++;
			if(v[i]==4) nra++;
		}
	
	
	if(nrb!=b || nrc!=c || nrg!=g || nra!=a) 
		return 0;

		

	printf("%d %d %d %d\n", nrb, nrc, nrg, nra);
	if( pas>2)
		for( int i=0; i< pas-2; i++)
			if(	v[i] == v[i+1] && v[i] == v[i+2] )
				return 0;
	

	if( pas>1)
	{
		for( int i=0; i< pas-1; i++)
			if(	v[i] ==1 && v[i+1] == 3 )
				return 0;
		for( int i=0; i< pas-1; i++)
			if(	v[i] ==1 && v[i+1] == 4 )
				return 0;
		for( int i=0; i< pas-1; i++)
			if(	v[i] ==2 && v[i+1] == 4 )
				return 0;
	}
	
	
	return 1;
}

int solutie( int pas)
{
	return pas==b+c+g+a-1;
}

void afisare()
{
	for( int i=0; i<b+c+g+a; i++)
		{
			switch( v[i])
			{
				case (1):
				printf("bloc ");
				break;
				case (2):
				printf("casa ");
				break;
				case (3):
				printf("gradina ");
				break;
				case (4):
				printf("atelier ");
				break;
			
			}
		
		}
	printf("\n");
}

void back( int pas)
{
	for( int i=1; i<=4; i++)
	{
		v[pas]=i;
		if(verificare_solutie(pas))
		{
			if(solutie(pas))
			{
				afisare();
				printf("\n");
			}
			else 
				back(pas+1);
		}
	}
}


int main()
{
	scanf("%d%d%d%d", &b,&c,&g,&a);
	back(0);
	
	
	return 0;
}
