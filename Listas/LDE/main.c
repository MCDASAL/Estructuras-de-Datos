#include <stdio.h>
#include <stdlib.h>

struct LDE
{
  int dato;
  struct LDE *siguiente;
  struct LDE *anterior;
};

//Ingresa por el inicio
void
IngresarElem (struct LDE **cab, int dato)
{
  struct LDE *aux = NULL;
  aux = (struct LDE *) malloc (sizeof (struct LDE));
  if (aux == NULL)
    {
      return;
    }
  if (*cab == NULL)
    {
      (*cab) = aux;
      (*cab)->siguiente = NULL;
      (*cab)->anterior = NULL;
      aux->dato = dato;
    }
  else
    {
      aux->dato = dato;
      aux->siguiente = (*cab);
      (*cab) = aux;
      (*cab)->anterior = NULL;
    }
}

//Ingresar por el final
void
IngElemFinal (struct LDE **cab, int dato)
{
  struct LDE *aux = NULL;
  aux = (struct LDE *) malloc (sizeof (struct LDE));
  if (aux == NULL)
    {
      return;
    }
  aux = (*cab);
  while (aux->siguiente != NULL)
    {
      aux = aux->siguiente;
    }

  struct LDE *aux1 = NULL;
  aux1 = (struct LDE *) malloc (sizeof (struct LDE));
  if ((*cab) == NULL)
    {
      (*cab) = aux1;
      (*cab)->siguiente = NULL;
      (*cab)->anterior = NULL;
      aux1->dato = dato;
    }
  else
    {
      aux->siguiente = aux1;
      aux1->siguiente = NULL;
      aux1->anterior = aux;
      aux1->dato = dato;
    }

}

//Mostrar normal
void
mostrarLDE (struct LDE *cab)
{
  while (cab != NULL)
    {
      printf ("%d \n", cab->dato);
      cab = cab->siguiente;
    }
}

//Mostrar Inversa
void
mInversaLDE (struct LDE *cab)
{
  struct LDE *aux = NULL;
  aux = (struct LDE *) malloc (sizeof (struct LDE));
  aux = cab;
  while (aux->siguiente != NULL)
    {
      aux = aux->siguiente;
    }
  while (aux->anterior != NULL)
    {
      printf ("%d \n", aux->dato);
      aux = aux->anterior;
    }
}

//Eliminar por dato
void
EliminarElem (struct LDE **cab, int dato)
{
  struct LDE *aux = NULL;
  aux = (struct LDE *) malloc (sizeof (struct LDE));
  if (aux == NULL)
    {
      return;
    }
  aux = (*cab);

  while (aux->dato != dato)
    {
      aux = aux->siguiente;
    }

  if (aux->siguiente == NULL)
    {
      aux->anterior->siguiente = NULL;
      free (aux);
    }
  else if (aux->siguiente == NULL && aux->anterior == NULL)
    {
      (*cab) = NULL;
      free (*cab);
    }
  else if (aux->siguiente != NULL && aux->anterior == NULL)
    {
      aux->siguiente->anterior = NULL;
      free (aux);
    }
  else if (aux->siguiente != NULL && aux->anterior != NULL)
    {
      aux->siguiente->anterior = aux->anterior;
      aux->anterior->siguiente = aux->siguiente;
      free (aux);
    }
}
