/**
 * @file mergeSort.c
 * @brief Este archivo contiene el programa Merge sort u ordenamiento por mezcla.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * @brief Implementación del algoritmo de ordenamiento por mezcla, el cual ordena un arreglo de enteros
 * en forma ascendente. Usando la técnica de divide y vencerás, divide el arreglo en tamaños más pequeños, hasta que
 * su tamaño sea 0 o 1, ya que así el arreglo se encontrará ordenado, para posteriormente llamar a la función merge y 
 * mezclar los subarreglos ordenados con el arreglo original.
 * 
 * @param A Apuntador a un arreglo de enteros
 * @param p Comienzo de la indexación del arreglo
 * @param r Final de la indexación del arreglo
 * @return void
 * @note El algoritmo de ordenamiento por mezcla consiste en:
 * \n-Si la longitud del arreglo es 0 o 1, entonces el arreglo ya se encuentra ordenado. En otro caso:
 * \n-Dividir el arreglo desordenado en dos subarreglos de aproximadamente la mitad del tamaño.
 * \n-Ordenar cada subarreglo recursivamente aplicando el ordenamiento por mezcla.
 * \n-Mezclar los dos subarreglo en un solo arreglo ordenado.
 * @remark Complejidad de tiempo en el peor de los casos: O(log(n))
*/

void MergeSort(int *A, int p, int r) { 
    if (p < r) {
        int q = (p + r) / 2;       
        MergeSort(A, p, q);         
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}
/**
 * @brief Función para mezclar los arreglos ordenados con el arreglo original
 * 
 * @param A Apuntador a un arreglo de enteros
 * @param q Mitad del arreglo
 * @param p Comienzo de la indexación del arreglo
 * @param r Final de la indexación del arreglo
 * @return void
 * @note -El procedimiento combina dos subarreglos del arreglo A en un único subarreglo ordenado.
  \n-Divide el arreglo en dos mitades de tamaño p o q y q+1 a r.
  \n-Ordena recursivamente las dos mitades utilizando el algoritmo merge sort
  \n-Combina las dos mitades ordenadas en un sólo arreglo ordenado utilizando el procedimiento merge
  \n-Este procesidimiento implementa la operación básica de Merge de dos subarreglos en un sólo arreglo ordenado. 
 *@remark La complejidad de tiempo de este procedimiento es O(N)
*/
void Merge(int *A, int p, int q, int r)    
{
    int l = r - p + 1, i = p, j = q + 1;   
    int *C = malloc(l * sizeof(int));    
    if (C == NULL) {
        exit(1);
    }
    for (int k = 0; k < l; k++) { 
        if (i <= q && j <= r) { 
            if (A[i] < A[j]) {
                C[k] = A[i];
                i++;
            }
            else {             
                C[k] = A[j];
                j++;
            }
        }
        else if (i <= q) {    
            C[k] = A[i];     
            i++;
        }
        else {             
            C[k] = A[j];   
            j++;
        }
    }
    int k = p;
    for (int i = 0; i < l; i++) { 
        A[k] = C[i];
        k++;
    }
    free(C);       
}