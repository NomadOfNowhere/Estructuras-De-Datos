/**
 * @file burbuja.c
 * @brief Este archivo contiene el programa Bubble Sort u ordenamiento burbuja.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */

#include <stdio.h>
#include "header.h"

/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo de burbuja.
 * 
 * @param A Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 * @return void
 * 
 * @note El algoritmo de la burbuja consiste en:
 *  \n-Se compara el primer elemento con el segundo elemento. Si el primer elemento es mayor que el segundo, se intercambian.
 *  \n-Se continúa comparando el segundo elemento con el tercer elemento, el tercer elemento con el cuarto, y así sucesivamente hasta que se hayan comparado todos los elementos adyacentes del arreglo.
 *  \n-Si se encontró un elemento que debió ser intercambiado en el paso anterior, se repite el proceso desde el principio. 
 *  \n-En caso de que el arreglo ya se encuentre ordenado, gracias a las modificaciones de la burbuja optimizada, el algoritmo se detiene.
 * @remark Complejidad de tiempo en el peor de los casos: O(n^2)
 */

void BurbujaOptimizada(int *A, int n){       
    int cambios=TRUE;    
    int i=0;
    while(i<=n-2 && cambios != FALSE){     
        cambios=FALSE;
        for(int j=0; j<=(n-2)-i; j++){  
            if(A[j] > A[j+1]){
                int aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
                cambios=TRUE;         
            }
        }
        i=i+1;
    }
}