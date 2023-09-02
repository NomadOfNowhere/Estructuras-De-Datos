/**
 * @file insercion.c
 * @brief Este archivo contiene el programa Insertion Sort u ordenamiento por inserción.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */

#include <stdio.h>
#include "header.h"

/**
 * @brief Implementación del algoritmo de ordenamiento por inserción.
 * 
 * @param A Apuntador a un arreglo de enteros
 * @param n: El tamaño o número de elementos del arreglo
 * @return void
 * @note El algoritmo de ordenamiento por inserción consiste en:
 *  \n-Se toma el primer elemento del arreglo como el primer elemento del arreglo ordenado.
 *  \n-Se toma el siguiente elemento y se compara con todos los elementos del arreglo, desde el valor actual de i hasta el final.
 *  \n-Si el elemento es menor que el elemento actual, se desplaza el elemento actual una posición a la derecha.
 *  \n-Si el elemento es mayor o igual que el elemento actual, se inserta el elemento en la posición actual.
 *  \n-Se repite el proceso para cada elemento de la lista original, insertando cada elemento en su posición adecuada en la lista ordenada.
 * @remark Complejidad de tiempo en el peor de los casos: O(n^2)
*/

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