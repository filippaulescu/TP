#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<math.h>

/*Aplicația 12.2: Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate
elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare.
Exemplu:
n=5
permutarile care respecta conditia sunt:
3 2 1 4 5
4 2 1 3 5
4 3 1 2 5
5 2 1 3 4
5 3 1 2 4
5 4 1 2 3
*/


int x[1000] ,n;

void Afis()
{
    for( int j=1;j<=n;j++)
        printf("%d ",x[j]);
    printf("\n");
}

int OK(int k)
{
    for(int i=1;i<k;++i)
    {
		if(x[k]==x[i])
		    return 0;
    }
        
    if(k<=n/2+1)
    {
        for(int i=1;i<k-1;++i)
        	if(x[i]<x[i+1])
        return 0;
    }
    else
    {
        for(int i=1;i<=n/2;++i)
        	if(x[i]<x[i+1])
        return 0;
        for(int i=n/2+1;i<=k-1;++i)
        	if(x[i]>x[i+1])
        return 0;
    }
    return 1;
}


int Solutie(int k)
{
    return k == n;
}

void back(int k)
{
    for(int i=1 ; i<=n ; ++i)
    {
        x[k]=i;
        if( OK(k) )
          {
            if(Solutie(k))
                Afis();
            else
                back(k+1);
          }
    }
}

int main(void)
{
    scanf("%d",&n);
    back(1);
    return 0;
}

