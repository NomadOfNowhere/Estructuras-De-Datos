/**
 * @file quickSort.c
 * @brief Este archivo contiene el programa Quick sort u ordenamiento rapido.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */
#include <stdio.h>
#include "header.h"

/**
 * @brief Intercambia dos elementos de un arreglo.
 * @param A Arreglo de enteros que contiene los elementos a intercambiar.
 * @param i Índice del primer elemento a intercambiar.
 * @param j Índice del segundo elemento a intercambiar.
 * @return void
*/

void Intercambiar(int *A, int i, int j) {
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

/**
 * @brief Escoge un pivote y lo utiliza para particionar el arreglo en dos sub-arreglos.
 * @param A Arreglo de enteros a particionar.
 * @param p Índice del primer elemento del arreglo.
 * @param r Índice del último elemento del arreglo.
 * @return int Índice del pivote.
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

/**
 * @brief Implementación del algoritmo de ordenamiento rápido, el cual ordena un arreglo de enteros
 * en forma ascendente. Usando la técnica de divide y vencerás, el algoritmo divide el arreglo y elige un elemento pivote y reordena 
 * los elementos del arreglo de modo que los elementos más pequeños que el pivote 
 * estén a su izquierda, y los elementos más grandes que el pivote estén a su derecha.
 * @param A Apuntador a un arreglo de enteros
 * @param p Comienzo de la indexación del arreglo
 * @param r Final de la indexación del arreglo
 * @return void
 * @note El algoritmo de ordenamiento rápido consiste en:
 * \n -Elegir un elemento pivote del arreglo (el primer elemento).
 * \n -Reordenar los elementos del arreglo de modo que los elementos más pequeños que el pivote estén a su izquierda, y los 
 * elementos más grandes que el pivote estén a su derecha.
 * \n -Recursivamente, aplicar el algoritmo Quicksort a los subarreglos resultantes a la izquierda y a la derecha del pivote.
 * \n -Combinar los subarreglos ordenados en un único arreglo ordenado.
 * @remark Complejidad de tiempo en el peor de los casos: O(n^2), pero en la práctica nunca se llega a esto, logrando así un buen desempeño 
 * de O(nlog(n))
*/

void Quicksort(int *A, int p, int r) {
    if (p < r) {                    
        int j = Pivot(A, p, r);
        Quicksort(A, p, j - 1);
        Quicksort(A, j + 1, r);
    }
}