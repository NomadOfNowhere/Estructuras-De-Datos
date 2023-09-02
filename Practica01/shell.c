/**
 * @file shell.c
 * @brief Este archivo contiene el programa Shell sort.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */
#include <stdio.h>
#include "header.h"
/**
 * @brief Implementación del algoritmo de ordenamiento shell, el cual ordena los elementos lejanos unos de otros y luego ir reduciendo esa distancia hasta llegar a ordenar adyacentes. 
 * Esto se logra con una serie de divisiones sucesivas de la lista en subgrupos más pequeños que se ordenan 
 * internamente mediante el algoritmo de inserción
 * @param A Apuntador a un arreglo de enteros
 * @param n El tamaño o número de elementos del arreglo
 * @return void
 * @note El algoritmo de ordenamiento shell consiste en:
 * \n-Se divide el arreglo a la mitad
 * \n-Se inicializa la variable b=1 porque por lo menos hay 1 intercambio de elementos en el intervalo actual
 * \n-Se recorre el arreglo desde i=k hasta i<=n-1
 * \n-Se compara si A[i-k]>A[i], en caso de que sí, intercambian posiciones y se incrementa el valor de la variable b
 * \n-Si no hay ningún intercambio en todo el arreglo, b=0, por lo que el bucle interno se detiene
 * \n-Se divide el arreglo a la mitad y se repite el proceso hasta que k>=1
 * @remark Complejidad de tiempo en el peor de los casos: O(n^2), en el mejor de los casos: O(nlog(n))
*/

void Shell(int *A, int n)  
{
    int k = n / 2;         
    while (k >= 1) 
    {
        int b = 1;
        while (b != 0)     
        {
            b = 0;
            for (int i = k; i <= n - 1; i++)    
            {
                if (A[i - k] > A[i])    
                {
                    int temp = A[i];
                    A[i] = A[i - k];
                    A[i - k] = temp;
                    b = b + 1;
                }
            }
        }
        k = k / 2;   
    }
}
