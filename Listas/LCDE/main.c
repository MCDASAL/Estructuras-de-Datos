#include <stdio.h>
#include <stdlib.h>

struct LCDE
{
  int dato;
  struct LCDE *sig;
  struct LCDE *ant;
};

//Ingresa por el inicio
void
IngresarElem (struct LCDE **cab, int dato)
{
  struct LCDE *aux = NULL;
  aux = (struct LCDE *) malloc (sizeof (struct LCDE));

  if (aux == NULL)
    {
      return;
    }
  if (*cab == NULL)
    {
      aux->dato = dato;
      (*cab) = aux;
      (*cab)->sig = (*cab);
      (*cab)->ant = (*cab);
    }
  else if ((*cab)->sig == (*cab))
    {
      aux->dato = dato;
      aux->sig = (*cab);
      aux->ant = (*cab);
      (*cab)->sig = aux;
      (*cab)->ant = aux;
      (*cab) = aux;
    }
  else
    {

      aux->dato = dato;
      aux->sig = (*cab);
      aux->ant = (*cab)->ant;
      (*cab)->ant->sig = aux;
      (*cab)->ant = aux;
      (*cab) = aux;

    }

}

//Mostrar hacia delante
void
FmostrarLCDE (struct LCDE *cab)
{
  struct LCDE *aux = NULL;
  aux = (struct LCDE *) malloc (sizeof (struct LCDE));

  if (aux == NULL)
    {
      return;
    }

  aux = cab;

  while (aux->sig != cab)
    {
      printf ("%d \n", aux->dato);
      aux = aux->sig;
    }
  if (aux->sig == cab && aux != cab)
    {
      printf ("%d \n", aux->dato);
    }
}

//Mostrar hacia atras
void
BmostrarLCDE (struct LCDE *cab)
{
  struct LCDE *aux = NULL;
  aux = (struct LCDE *) malloc (sizeof (struct LCDE));

  if (aux == NULL)
    {
      return;
    }

  aux = cab;

  while (aux->ant != cab)
    {
      printf ("%d \n", aux->dato);
      aux = aux->ant;
    }
  if (aux->ant == cab && aux != cab)
    {
      printf ("%d \n", aux->dato);
    }
}

void
eliminarDato (struct LCDE **cab, int dato)
{

  if ((*cab) == NULL)
    {
      return;
    }

  struct LCDE *aux = NULL;
  struct LCDE *aux2 = NULL;
  aux = (struct LCDE *) malloc (sizeof (struct LCDE));
  aux2 = (struct LCDE *) malloc (sizeof (struct LCDE));

  if ((*cab)->dato == dato && (*cab)->sig != (*cab))
    {
      aux = (*cab);
      (*cab)->ant->sig = (*cab)->sig;
      (*cab)->sig->ant = (*cab)->ant;
      (*cab) = (*cab)->sig;
      free (aux);
    }
  else if ((*cab)->dato == dato && (*cab)->sig == (*cab))
    {
      aux = (*cab);
      (*cab) = NULL;
      free (aux);
    }
  else if ((*cab)->dato != dato)
    {
      aux = (*cab);
      while (aux->sig != (*cab) && aux->sig->dato != dato)
	{
	  aux = aux->sig;
	}
      if (aux->sig != (*cab))
	{
	  aux2 = aux->sig;
	  aux->sig = aux2->sig;
	  aux2->sig->ant = aux;
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
  struct LCDE *Lista1 = NULL;

  IngresarElem (&Lista1, 20);
  IngresarElem (&Lista1, 21);
  IngresarElem (&Lista1, 25);
  FmostrarLCDE (Lista1);
  eliminarDato (&Lista1, 24);
  FmostrarLCDE (Lista1);
  eliminarDato (&Lista1, 25);
  BmostrarLCDE (Lista1);
  return 0;
}
