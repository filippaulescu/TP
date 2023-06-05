#include <stdio.h>
#include <stdlib.h>


/*Subiectul 2.1 Să se scrie un program pentru tabelarea unor funcţii matematice. Programul trebuie să tabeleze
funcţiile (x*x*x+4)/(x*x+5), x+10 şi 2*x*x-1.
Tabelarea se va realiza pe intervalul [A,B] cu pasul P. Valorile A, B şi P se vor citi de la tastatură. Programul va
afişa valorile funcţiilor sub formă de tabel.
Trebuie să se folosească pointeri la funcţii. Scrieţi o funcţie generică pentru tabelarea unei funcţii matematice
oarecare. Această funcţie generică va avea un parametru de tip pointer la funcţie.
Folosind funcţia generică, tabelaţi cele patru funcţii matematice amintite mai sus.*/

double f1( int x)
{
	return (x*x*x+4)/(x*x+5);
}

double f2(int x)
{
	return x+10;
}

double f3( int x)
{
	return 2*x*x-1;
}

void tabelare(double (*f)(int), int A, int B, int P) {
    printf("x\tf(x)\n");
    for (int x = A; x <= B; x += P) {
        printf("%d\t%lf\n", x, f(x));
    }
}

int main()
{
	//double (*f1)(int);
	//double (*f3)(int);
	double (*pf2)(int);
	pf2=&f2;
	tabelare(pf2, 1,10,1);
	
	

    return 0;
}
