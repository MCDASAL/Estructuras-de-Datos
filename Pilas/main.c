#include <stdio.h>
#include <stdlib.h>

struct PILA
{
  int dato;
  struct PILA *sig;
};

//Ingresa por el inicio
void
Push (struct PILA **cab, int dato)
{
  struct PILA *aux = NULL;
  aux = (struct PILA *) malloc (sizeof (struct PILA));
  if (aux == NULL)
    {
      return;
    }
  if (*cab == NULL)
    {
      (*cab) = aux;
      (*cab)->sig = NULL;
      aux->dato = dato;
    }
  else
    {
      aux->dato = dato;
      aux->sig = (*cab);
      (*cab) = aux;
    }
}

int
Pop (struct PILA **cab)
{

  if ((*cab) == NULL)
    {
      return 0;
    }

  struct PILA *aux = NULL;
  aux = (struct PILA *) malloc (sizeof (struct PILA));

  if ((*cab)->sig == NULL)
    {
      aux = (*cab);
      (*cab) = NULL;
    }
  else
    {
      aux = (*cab);
      (*cab) = (*cab)->sig;
    }

  return (aux->dato);
}

void
mostrarPILA (struct PILA *cab)
{
  struct PILA *aux = NULL;
  aux = (struct PILA *) malloc (sizeof (struct PILA));
  if (cab == NULL)
    {
      printf ("PILA VACIA");
    }

  while (cab != NULL)
    {
      Push (&aux, Pop (&cab));
    }
    while (aux != NULL)
    {
      printf ("%d \n", Pop (&aux));
    }
}

int
main ()
{
  struct PILA *PILA = NULL;

  Push (&PILA, 20);
  Push (&PILA, 21);
  Push (&PILA, 29);
  mostrarPILA (PILA);
  Pop (&PILA);
  mostrarPILA (PILA);
  Pop (&PILA);
  mostrarPILA (PILA);
  return 0;
}
