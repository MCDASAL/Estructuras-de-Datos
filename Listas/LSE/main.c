#include <stdio.h>
#include <stdlib.h>

struct LSE
{
  int dato;
  struct LSE *siguiente;
};

//Ingresa por el inicio
void
IngresarElem (struct LSE **cab, int dato)
{
  struct LSE *aux = NULL;
  aux = (struct LSE *) malloc (sizeof (struct LSE));
  if (aux == NULL)
    {
      return;
    }
  if (*cab == NULL)
    {
      (*cab) = aux;
      (*cab)->siguiente = NULL;
      aux->dato = dato;
    }
  else
    {
      aux->dato = dato;
      aux->siguiente = (*cab);
      (*cab) = aux;
    }
}

void
mostrarLSE (struct LSE **cab)
{
  struct LSE *aux = NULL;
  aux = (struct LSE *) malloc (sizeof (struct LSE));
  if ((*cab) == NULL)
    {
      printf ("LISTA VACIA");
    }
  else
    {
      aux = (*cab);
    }

  while (aux != NULL)
    {
      printf ("%d \n", aux->dato);
      aux = aux->siguiente;
    }
}

/*void mostrarLSE (struct LSE *cab){
	if (cab != NULL){
		printf ("%d \n",cab->dato);
		mostrarLSE (cab->siguiente);
	}
}*/

void
eliminarDato (struct LSE **cab, int dato)
{

  if ((*cab) == NULL)
    {
      return;
    }

  struct LSE *aux = NULL;
  struct LSE *aux2 = NULL;
  aux = (struct LSE *) malloc (sizeof (struct LSE));
  aux2 = (struct LSE *) malloc (sizeof (struct LSE));

  if ((*cab)->dato == dato)
    {
      aux = (*cab);
      (*cab) = (*cab)->siguiente;
      free (aux);
    }
  else if ((*cab)->siguiente != NULL)
    {
      aux = (*cab);
    }
  else
    {
      return;
    }

  while (aux->siguiente != NULL && aux->siguiente->dato != dato)
    {
      aux = aux->siguiente;
    }
  if (aux->siguiente != NULL)
    {
      aux2 = aux->siguiente;
      aux->siguiente = aux2->siguiente;
      free (aux2);
    }
  else
    {
      return;
    }

}

int
Buscar (struct LSE **cab, int dato)
{
  int posicion = 0;
  struct LSE *aux = NULL;
  aux = (struct LSE *) malloc (sizeof (struct LSE));
  aux = (*cab);

  if (aux->dato == dato)
    {
      return 0;
    }
  else if (aux->siguiente->dato != dato)
    {
      while (aux->siguiente->dato != dato)
	{
	  aux = aux->siguiente;
	  posicion++;
	}
    }
  else
    {
      return -1;
    }
  return (posicion);
}

int
main ()
{
  struct LSE *Lista1 = NULL;

  IngresarElem (&Lista1, 20);
  IngresarElem (&Lista1, 21);
  IngresarElem (&Lista1, 29);
  mostrarLSE (&Lista1);
  eliminarDato (&Lista1, 24);
  mostrarLSE (&Lista1);
  eliminarDato (&Lista1, 29);
  mostrarLSE (&Lista1);
  return 0;
}
