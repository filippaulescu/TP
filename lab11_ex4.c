#include <stdio.h>
#include <stdlib.h>
#define max_size 10

/*Aplicația 11.4: La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int).
Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor, astfel
încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și ei în
grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe, pentru
valori citite dintr-un fișier*/





typedef struct jucator
{
    char nume[15];
    int valoare;
} jucator;


void sortare( jucator v[], int n)
{
	
	for( int i=0; i<n-1; i++)
		for( int j=i+1; j<n; j++)
			if(v[i].valoare>v[j].valoare)
			{
				jucator aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
}

void grupe( jucator v[], int n, int m)
{
	for( int i=0; i<n; i++)
		printf("%s se afla in echipa %d\n", v[i].nume, i%m+1);
}


int main()
{
    FILE *f;
    f = fopen("jucatori.txt", "r");

    if (f == NULL)
    {
        printf("Nu s-a putut deschide fisierul.\n");
        exit(-1);
        
    }

    int n, m;
    scanf("%d %d", &n, &m);

    jucator jucatori[max_size];
    
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }

    fclose(f);
    
    /*
    	
    for (int i = 0; i < n; i++)
	{
		printf("Valoarea jucatorului %s: %d\n", jucatori[i].nume, jucatori[i].valoare);
	}
	
	
	for (int i = 0; i < n; i++)
	{
		printf("Valoarea jucatorului %s: %d\n", jucatori[i].nume, jucatori[i].valoare);
	}
    */
    
    sortare(jucatori, n);
    grupe( jucatori, n, m);
    

  

    return 0;
}
