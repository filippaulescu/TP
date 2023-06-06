#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20
int front=-1, rear=-1;


/*Aplicatia 3.4 Sa se implementeze cu ajutorul unei cozi un buffer care retine temporar informatiile
primite de la diversi transmitatori (informatia este adaugata in coada) si le transmite mai apoi catre
un receptor (informatia este eliminata din coada). Informatia primita in buffer are urmatoare
structura: numar identificare transmitator (int), mesaj (sir de caractere de maxim 256 caractere).*/

typedef struct elem
{
	int transmitator;
	char sir[256];
}elem;

elem queue[MAX_SIZE];

void enqueue(int t, char mesaj[])
{
	if( rear == MAX_SIZE-1)
	{
		printf("coada e plina");
		return ;
	}
	rear++;
	queue[rear].transmitator= t;
	strcpy(queue[rear].sir, mesaj);
}

elem dequeue()
{
	if(rear == -1 || front > rear)
	{
		printf("coada este goala");
		exit(-1);
	}
	front ++;
	return queue[front-1];
}




int main()
{
	enqueue(1, "mamamia");
	enqueue(2, "tatamia");
	dequeue();
			

    return 0;
}
