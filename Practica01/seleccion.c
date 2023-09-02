/**
 * @file seleccion.c
 * @brief Este archivo contiene el programa Selection sort u ordenamiento por selección.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */
#include <stdio.h>
#include "header.h"
/**
 * @brief Implementación del algoritmo de ordenamiento por selección, el cual ordena un arreglo de enteros 
 * en forma ascendente. Consiste en encontrar el elemento mínimo del arreglo y colocarlo en su posición correcta en el arreglo ordenado
 * @param A Apuntador a un arreglo de enteros
 * @param n El tamaño o número de elementos del arreglo
 * @return void
 * @note El algoritmo de ordenamiento por selección consiste en:
 * \n Consiste en encontrar el elemento mínimo del arreglo y colocarlo en su posición correcta en el arreglo ordenado. Este proceso se repite para el 
 * segundo elemento más pequeño, el tercer elemento más pequeño y así sucesivamente hasta que todo el arreglo se encuentre ordenado.
 * \n-Se encuentra el elemento mínimo del arreglo y se intercambia con el primer elemento.
 * \n-Se encuentra el elemento mínimo del arreglo que comienza en la segunda posición y se intercambia con el segundo elemento.\
 * \n-Se continúa el proceso para cada elemento restante del arreglo, encontrando el elemento mínimo y colocándolo en su posición 
 * correcta en la lista ordenada.
 * @remark Complejidad de tiempo en el peor de los casos: O(n^2)
*/

void Seleccion(int *A, int n) {        
    for (int k = 0; k <= n - 2; k++) {     
        int p = k;                        
        for (int i = k + 1; i <= n - 1; i++) { 
            if (A[i] < A[p])           
                p = i;
        }
        int temp = A[p];            
        A[p] = A[k];
        A[k] = temp;
    }
}