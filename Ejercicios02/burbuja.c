#include <stdio.h>
#include "header.h"
/*
   ALGORITMO DE ORDENAMIENTO BURBUJA

 * void BurbujaOptimizada(int *A, int n)
 * DESCRIPCIÓN: Implementación del algoritmo de ordenamiento burbuja optimizada, el cual ordena un arreglo de enteros
   en forma ascendente y se detiene si el arreglo ya se encuentra ordenado
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int n: El tamaño o número de elementos del arreglo
  
 * RETORNA:
   void
  
 * OBSERVACIONES:
   El algoritmo de la burbuja consiste en:
   -Se compara el primer elemento con el segundo elemento. Si el primer elemento es mayor que el segundo, se intercambian.
   -Se continúa comparando el segundo elemento con el tercer elemento, el tercer elemento con el cuarto, y así sucesivamente 
    hasta que se hayan comparado todos los elementos adyacentes del arreglo.
   -Si se encontró un elemento que debió ser intercambiado en el paso anterior, se repite el proceso desde el principio. 
   -En caso de que el arreglo ya se encuentre ordenado, gracias a las modificaciones de la burbuja optimizada, el algoritmo se detiene.

   Complejidad de tiempo en el peor de los casos: O(n^2)

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