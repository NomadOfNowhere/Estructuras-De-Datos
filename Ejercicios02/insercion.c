#include <stdio.h>
#include "header.h"

/*
   ALGORITMO DE ORDENAMIENTO POR INSERCIÓN

 * void Insercion(int *A, int n)
 * DESCRIPCIÓN: Implementación del algoritmo de ordenamiento por inserción, el cual ordena un arreglo de enteros
   en forma ascendente. Se recorre el arreglo de elementos y se inserta cada uno en su posición adecuada en el arreglo ordenado
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int n: El tamaño o número de elementos del arreglo
  
 * RETORNA:
   void
  
 * OBSERVACIONES:
   El algoritmo de ordenamiento por inserción consiste en:
   -Se toma el primer elemento del arreglo como el primer elemento del arreglo ordenado.
   -Se toma el siguiente elemento y se compara con todos los elementos del arreglo, desde el valor actual de i hasta el final.
   -Si el elemento es menor que el elemento actual, se desplaza el elemento actual una posición a la derecha.
   -Si el elemento es mayor o igual que el elemento actual, se inserta el elemento en la posición actual.
   -Se repite el proceso para cada elemento de la lista original, insertando cada elemento en su posición adecuada en la lista ordenada.
   
   Complejidad de tiempo en el peor de los casos: O(n^2)
*/

/* Ordenamiento por Inserción */
void Insercion(int *A, int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        int temp = A[i];
        while (j > 0 && temp < A[j - 1]) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}