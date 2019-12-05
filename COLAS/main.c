#include <stdio.h>
#include <stdlib.h>

struct COLA
{
  int dato;
  struct COLA *frente;
  struct COLA *final;
};

void
Formar (struct COLA **cab, int dato)
{
  struct COLA *aux = NULL;
  aux = (struct COLA *) malloc (sizeof (struct COLA));
  if (aux == NULL)
    {
      return;
    }

  struct COLA *aux2 = NULL;
  aux2 = (struct COLA *) malloc (sizeof (struct COLA));
  if ((*cab) == NULL)
    {
      aux->dato = dato;
      (*cab) = aux;
      (*cab)->final = NULL;
      (*cab)->frente = NULL;

    }
  else
    {
      aux = (*cab);
      while (aux->final != NULL)
	{
	  aux = aux->final;
	}
      aux->final = aux2;
      aux2->final = NULL;
      aux2->frente = aux;
      aux2->dato = dato;
    }

}

int
Atender (struct COLA **cab)
{

  if ((*cab) == NULL)
    {
      return 0;
    }

  struct COLA *aux = NULL;
  aux = (struct COLA *) malloc (sizeof (struct COLA));

  if ((*cab)->final == NULL)
    {
      aux = (*cab);
      (*cab) = NULL;
    }
  else
    {
      aux = (*cab);
      (*cab) = (*cab)->final;
    }

  return (aux->dato);
}

void
mostrarCOLA (struct COLA *cab)
{
  struct COLA *aux = NULL;
  aux = (struct COLA *) malloc (sizeof (struct COLA));

  if (cab == NULL)
    {
      printf ("COLA VACIA");
    }
  aux = cab;

  while (aux->final != NULL)
    {
      printf ("%d \n", Atender (&aux));
    }
  if (aux->final == NULL)
    {
      printf ("%d \n", aux->dato);
    }
}

int
main ()
{
  struct COLA *Lista1 = NULL;

  Formar (&Lista1, 20);
  Formar (&Lista1, 21);
  Formar (&Lista1, 29);
  mostrarCOLA (Lista1);
  Atender (&Lista1);
  mostrarCOLA (Lista1);
  Atender (&Lista1);
  mostrarCOLA (Lista1);
  return 0;
}
