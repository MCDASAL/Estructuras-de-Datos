#include <stdio.h>
#include <stdlib.h>

struct LCSE
{
  int dato;
  struct LCSE *siguiente;
};

//Ingresa por el inicio
void
IngresarElem (struct LCSE **cab, int dato)
{
  struct LCSE *aux = NULL;
  aux = (struct LCSE *) malloc (sizeof (struct LCSE));

  if (aux == NULL)
    {
      return;
    }
  if (*cab == NULL)
    {
      aux->dato = dato;
      (*cab) = aux;
      (*cab)->siguiente = (*cab);
    }
  else if ((*cab)->siguiente == (*cab))
    {
      aux->dato = dato;
      aux->siguiente = (*cab);
      (*cab)->siguiente = aux;
      (*cab) = aux;
    }
  else
    {
      struct LCSE *aux2 = NULL;
      aux2 = (struct LCSE *) malloc (sizeof (struct LCSE));

      if (aux2 == NULL)
	{
	  return;
	}

      aux2 = (*cab);
      while (aux2->siguiente != (*cab))
	{
	  aux2 = aux2->siguiente;
	}

      aux->dato = dato;
      aux->siguiente = (*cab);
      aux2->siguiente = aux;
      (*cab) = aux;

    }

}

void
mostrarLCSE (struct LCSE *cab)
{
  struct LCSE *aux = NULL;
  aux = (struct LCSE *) malloc (sizeof (struct LCSE));

  if (aux == NULL)
    {
      return;
    }

  aux = cab;

  while (aux->siguiente != cab)
    {
      printf ("%d \n", aux->dato);
      aux = aux->siguiente;
    }
  if (aux->siguiente == cab && aux != cab)
    {
      printf ("%d \n", aux->dato);
    }
}

void
eliminarDato (struct LCSE **cab, int dato)
{

  if ((*cab) == NULL)
    {
      return;
    }

  struct LCSE *aux = NULL;
  struct LCSE *aux2 = NULL;
  aux = (struct LCSE *) malloc (sizeof (struct LCSE));
  aux2 = (struct LCSE *) malloc (sizeof (struct LCSE));

  if ((*cab)->dato == dato)
    {
      aux = (*cab);
      aux2 = (*cab);
      while (aux2->siguiente != (*cab))
	{
	  aux2 = aux2->siguiente;
	}
      (*cab) = (*cab)->siguiente;
      aux2->siguiente = (*cab);
      free (aux);
    }
  else if ((*cab)->dato != dato)
    {
      aux = (*cab);
      while (aux->siguiente != (*cab) && aux->siguiente->dato != dato)
	{
	  aux = aux->siguiente;
	}
      if (aux->siguiente != (*cab))
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
}

int
main ()
{
  struct LCSE *Lista1 = NULL;

  IngresarElem (&Lista1, 20);
  IngresarElem (&Lista1, 21);
  IngresarElem (&Lista1, 25);
  mostrarLCSE (Lista1);
  eliminarDato (&Lista1, 24);
  mostrarLCSE (Lista1);
  eliminarDato (&Lista1, 25);
  mostrarLCSE (Lista1);
  return 0;
}
