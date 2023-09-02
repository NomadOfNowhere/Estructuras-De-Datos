#include <stdio.h>
#include "header.h"

/*
   ALGORITMO DE ORDENAMIENTO RÁPIDO

 * void QuickSort(int *A, int p, int r)
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
  
 * OBSERVACIONES:
   El algoritmo de ordenamiento rápido consiste en:
   -Elegir un elemento pivote del arreglo (el primer elemento).
   -Reordenar los elementos del arreglo de modo que los elementos más pequeños que el pivote estén a su izquierda, y los 
   elementos más grandes que el pivote estén a su derecha.
   -Recursivamente, aplicar el algoritmo Quicksort a los subarreglos resultantes a la izquierda y a la derecha del pivote.
   -Combinar los subarreglos ordenados en un único arreglo ordenado.

   Complejidad de tiempo en el peor de los casos: O(n^2), pero en la práctica nunca se llega a esto, logrando así un buen desempeño
   de O(nlog(n))
*/

void Intercambiar(int *A, int i, int j) {
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

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

void Quicksort(int *A, int p, int r) {
    if (p < r) {
        int j = Pivot(A, p, r);
        Quicksort(A, p, j - 1);
        Quicksort(A, j + 1, r);
    }
}