#include<stdio.h>
#include<stdlib.h>

struct Lista
{
	int*dato;
	int fin;
	int actual;
};
struct Lista crearlista(int n)
{
	struct Lista lista;
	lista.dato = (int*)malloc((sizeof(int))*(2*n));
	lista.actual = 0;
	lista.fin = (2*n)-1;
	return lista;
}
struct Lista agregarlista(struct Lista *lista, int dato)
{
	lista->dato[lista->actual] = dato;
	(*lista).actual++;
	return *lista;
}
void mostrarlista(struct Lista lista)
{
	int i;
	for(i=0;i<(lista.actual);i++)
	{
		printf("%d\n",lista.dato[i]);
	}
}
int main()
{
	struct Lista lista;
	int n=4;
	lista = crearlista(n);
	agregarlista(&lista, 1);
	agregarlista(&lista, 2);
	agregarlista(&lista, 3);
	agregarlista(&lista, 4);
	agregarlista(&lista, 5);
	agregarlista(&lista, 6);
	agregarlista(&lista, 7);
	agregarlista(&lista, 8);
	mostrarlista(lista);
	return 0;
}
