/*----------------------------------------------------------
  IPN-ESCOM
  Autor: González Joshua
  Versión: 1.0
  Algoritmos y Estructuras de Datos                  2CM8

  ALGORITMO DE ORDENAMIENTO RÁPIDO

  * DESCRIPCIÓN: Implementación del algoritmo de ordenamiento rápido, el cual ordena un arreglo de enteros
    en forma ascendente. Usando la técnica de divide y vencerás, el algoritmo divide el arreglo y elige un elemento pivote y reordena 
    los elementos del arreglo de modo que los elementos más pequeños que el pivote 
    estén a su izquierda, y los elementos más grandes que el pivote estén a su derecha.
  
 * OBSERVACIONES:
   El algoritmo de ordenamiento rápido consiste en:
   -Elegir un elemento pivote del arreglo (el primer elemento).
   -Reordenar los elementos del arreglo de modo que los elementos más pequeños que el pivote estén a su izquierda, y los 
   elementos más grandes que el pivote estén a su derecha.
   -Recursivamente, aplicar el algoritmo Quicksort a los subarreglos resultantes a la izquierda y a la derecha del pivote.
   -Combinar los subarreglos ordenados en un único arreglo ordenado.

   Complejidad de tiempo en el peor de los casos: O(n^2), pero en la práctica nunca se llega a esto, logrando así un buen desempeño
   de O(nlog(n))

  Compilado con: gcc quickSort.c -c -std=c17
----------------------------------------------------------*/

#include <stdio.h>
#include "header.h"

/*
  void intercambiar(int *A, int p, int r)
 * DESCRIPCIÓN: Función para intercambiar elementos
  
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int i: Posición del primer elemento en el arreglo
   PARÁMETRO int j: Posición del segundo elemento en el arreglo
  
 * RETORNA:
   void

 * OBSERVACIONES:
   Esta función sirve para intercambiar los elementos de 2 posiciones
   del arreglo.
   -Se inicializa una variable temporal para guardar el valor del elemento
    en la posición j del arreglo.
   -Se asigna a la posición j del arreglo el valor de la posición i.
   -Se asigna a la posición i del arreglo el valor de la variable temporal.
*/

void Intercambiar(int *A, int i, int j) {
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

/*
  void Pivot(int *A, int p, int r)
  * DESCRIPCIÓN: Función que elige un elemento como pivote
    y lo utiliza para particionar el arreglo en dos subarreglos.
  
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int p: Posición del primer elemento en el arreglo
   PARÁMETRO int r: Posición del último elemento en el arreglo
  
 * RETORNA:
   int j: Posición o índice del pivote en el arreglo.

 * OBSERVACIONES:
   Esta función sirve para elegir un elemento como pivote y particionar
   el arreglo en dos subarreglos, dependiendo de si los elementos son
   mayores o menores que éste.
   -Se elige como pivote el primer elemento.
   -Con ayuda de bucles while y un if se hacen intercambios de tal manera 
   que los elementos que son menores que el pivote queden a su izquierda y 
   que los elementos que son mayores queden a la derecha del pivote.
   -Se retorna la posición en el arreglo del pivote.
*/

int Pivot(int *A, int p, int r) {
    int piv = A[p], i = p + 1, j = r;
    while (i <= j) {
        while (A[i] <= piv && i <= r)
            i++;
        while (A[j] > piv)
            j--;
        if (i < j)
            Intercambiar(A, i, j);
    }
    Intercambiar(A, p, j);
    return j;
}

/*
  void QuickSort(int *A, int p, int r)
  * DESCRIPCIÓN: Implementación del algoritmo de ordenamiento rápido, el cual ordena un arreglo de enteros
    en forma ascendente. Usando la técnica de divide y vencerás, el algoritmo divide el arreglo y elige un elemento pivote y reordena 
    los elementos del arreglo de modo que los elementos más pequeños que el pivote 
    estén a su izquierda, y los elementos más grandes que el pivote estén a su derecha.
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int p: Comienzo de la indexación del arreglo
   PARÁMETRO int r: Final de la indexación del arreglo
  
 * RETORNA:
   void

 * OBSERVACIONES
   -Si la posición o índice en el arreglo de p es menor a r, entonces:
     -Se elije un pivote
     -Recursivamente, aplicar el algoritmo Quicksort a los subarreglos resultantes 
     a la izquierda y a la derecha del pivote.
*/
void Quicksort(int *A, int p, int r) {
    if (p < r) {
        int j = Pivot(A, p, r);
        Quicksort(A, p, j - 1);
        Quicksort(A, j + 1, r);
    }
}