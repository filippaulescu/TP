#include <stdio.h>
#include <stdlib.h>


/*Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.*/

#include <stdio.h>
#include <stdlib.h>
// un element al listei
typedef struct elem{
int n; // informatia utila
struct elem *urm; // camp de inlantuire catre urmatorul element
}elem;
// aloca un nou element si ii seteaza campurile corespunzatoare
elem *nou(int n,elem *urm)
{
elem *e=(elem*)malloc(sizeof(elem));
if(!e){
printf("memorie insuficienta");
exit(EXIT_FAILURE);
}
e->n=n;
e->urm=urm;
return e;
}
// adauga un element la inceputul listei
// returneaza noua lista
elem *adaugaInceput(elem *lista,int n)
{
return nou(n,lista);
}
// adauga un element la sfarsitul listei
// returneaza noua lista
elem *adaugaSfarsit(elem *lista,int n)
{
if(!lista)return nou(n,NULL);
elem *p=lista,*urm;
for(urm=p->urm;urm;p=urm,urm=p->urm){}
p->urm=nou(n,NULL);
return lista;
}
void afisare(elem *lista)
{
for(;lista;lista=lista->urm){
printf("%d ",lista->n);
}
putchar('\n');
}
// elibereaza memoria ocupata de o lista
void eliberare(elem *lista)
{
elem *p;
while(lista){
p=lista->urm;
free(lista);
lista=p;
}
}



int comparare( elem *l1, elem *l2)
{
	while( l1!=NULL && l2!=NULL)
	{
		if(l1->n != l2->n)
			return 0;
		l1=l1->urm;
		l2=l2->urm;
	
	}
	return l1==NULL && l2==NULL;
}


int main()
{

	elem *lista1=nou(108,nou(-1,nou(49,NULL)));
	afisare(lista1);
	
	
	elem *lista2=nou(108,nou(-1,nou(40,NULL)));
	afisare(lista2);
	
	
	printf("%d", comparare(lista1, lista2));

	eliberare(lista1);
	eliberare(lista2);
	
	return 0;
}
