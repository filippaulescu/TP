#include <stdio.h>

/* Aplicația 12.4: Se dau următoarele 6 culori: alb, galben, rosu, verde, albastru și negru.
Construiți toate steagurile formate din 3 culori care îndeplinesc următoarele condiții:
- Orice steag trebuie să conțină culoarea verde sau culoarea galben la mijloc.
- Culorile din fiecare steag trebuie să fie distincte.
*/

int steag[3];

int verificare_solutie()
{
	if (!(steag[1] == 2 || steag[1] == 4))
		return 0;
	for (int i = 0; i < 2; i++)
		for (int j = i + 1; j < 3; j++)
			if (steag[i] == steag[j])
				return 0;

	return 1;
}

void afisare_solutie()
{
	for (int i = 0; i < 3; i++)
		switch (steag[i])
		{
			case 1:
				printf("alb ");
				break;

			case 2:
				printf("galben ");
				break;

			case 3:
				printf("rosu ");
				break;

			case 4:
				printf("verde ");
				break;

			case 5:
				printf("albastru ");
				break;

			case 6:
				printf("negru ");
				break;
		}

	
}

void back(int pas)
{

	for (int i = 1; i <= 6; i++)
	{
		steag[pas] = i;
		if (pas==2)
		{
			if (verificare_solutie())
			{
				afisare_solutie();
				printf("\n");
			}
		}
		else
				back(pas + 1);
	}
}

int main()
{
	back(0);
	return 0;
}
