#include <stdio.h>
#include "header.h"
/*
----------------------------------------------------------
IPN-ESCOM
Autor: González Joshua
Versión: 1.0
Algoritmos y Estructuras de Datos                  2CM8

   BÚSQUEDA LINEAL O SECUENCIAL EN UNA COLECCIÓN DESORDENADA
   U ORDENADA

 * DESCRIPCIÓN:
   Implementaciones del algoritmo de búsqueda lineal o secuencial
   en una lista desordenada y ordenada de elementos

 * OBSERVACIONES:
   EL algoritmo de búsqueda lineal o secuencial consiste en recorrer un arreglo
   o lista desordenada u ordenada, de izquierda a derecha, buscando un elemento,
   en caso de que se encuentre, el algoritmo termina y retorna la posición
   del elemento en el arreglo. 
   -En caso de que se trate de una lista desordenada, se recorrerá el arreglo
   y se detendrá una vez que se encuentre el elemento o que se llegue al final de
   la lista.
   -En caso de que se trate de una lista ordenada, se recorrerá el arreglo
   y se detendrá una vez que se encuentre el elemento o que el siguiente elemento
   en la lista sea mayor al elemento que buscamos, pues al estar ordenada, sabemos
   que después de ese elemento no tiene sentido seguir buscando.

 * INSTRUCCIONS DE COMPILACIÓN:
   Compilado en linux con: gcc busqueda_lineal.c -c -std=c17
----------------------------------------------------------
*/

/*
   ALGORITMO DE BÚSQUEDA LINEAL PARA UNA COLECCIÓN DESORDENADA

 * struct par busqueda_lineal_desordenada(int *A, int n, int valor)
 * DESCRIPCIÓN: Implementación del algoritmo de búsqueda lineal o secuencial en una lista desordenada, el cual recorrerá
   el arreglo o lista buscando un elemento y se detendrá hasta que encuentre dicho valor

 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros.
   PARÁMETRO int n: El tamaño o número de elementos del arreglo.
   PARÁMETRO int valor: El valor o elemento a buscar en la lista.
  
 * RETORNA:
   struct par datos: Que contiene el índice o posición en el arreglo del elemento (si se encontró) 
   y el número de comparaciones que se realizaron en la búsqueda.
  
 * OBSERVACIONES:
   El algoritmo de búsqueda lineal o secuencial en una lista desordenada consiste en:
   -Se inicializa un struct con la variable res en -1 y el número de comparaciones en 0.
   -Se recorre la lista, de izquierda a derecha, desde 0 hasta i<=n-1
   -Por cada iteración se incrementa el número de comparaciones realizadas
   -Se compara el elemento actual de la lista con el valor buscado, en caso de que sean iguales, se almacenará
   el índice o posición del valor en el arreglo en la variable res y se terminará el bucle
   -Se retorna el struct con los datos: res (posición en el índice) y el número de comparaciones realizadas

   Complejidad de tiempo en el peor de los casos: O(n)

*/
par busqueda_lineal_desordenada(int *A, int n, int valor) {
    par datos;
    datos.res = -1, datos.comparaciones = 0;
    for (int i = 0; i <= n - 1; i++) {
        datos.comparaciones++;
        if (A[i] == valor) {
            datos.res = i;
            break;
        }
    }
    return datos;
}


/*
 * ALGORITMO DE BÚSQUEDA LINEAL EN UNA COLECCIÓN ORDENADA

 * struct par busqueda_lineal_ordenada(int *A, int n, int valor)

 * DESCRIPCIÓN: Implementación del algoritmo de búsqueda lineal o secuencial en una lista ordenada de elementos,
   el cual recorrerá el arreglo o lista buscando un elemento y se detendrá hasta que encuentre dicho valor o
   que el siguiente elemento de la lista sea mayor al elemento que se busca.
 
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros
   PARÁMETRO int n: El tamaño o número de elementos del arreglo
   PARÁMETRO int valor: El valor o elemento a buscar en la lista
  
 * RETORNA:
 * struct par datos: Que contiene el índice posición en el earreglo del elemento (si se encontró) 
   y el número de comparaciones que se realizaron
  
 * OBSERVACIONES:
   El algoritmo de búsqueda lineal o secuencial en una lista ordenada consiste en:
   -Se inicializa un struct con la variable res en -1 y el número de comparaciones en 1, ya que por lo menos
   es necesario realizar una comparación para evaluar la condición del bucle.
   -Se recorre la lista ordenada, de izquierda a derecha, desde 0 hasta i<=n-1 y se cumpla que el siguiente valor
   de la lista es menor o igual al elemento que se busca, en caso contrario, el bucle no se ejecutará.
   -Se compara el elemento actual de la lista con el valor buscado, en caso de que sean iguales, se almacenará
   el índice o posición del valor en el arreglo en la variable res y se terminará el bucle.
   -Por cada iteración se incrementa el número de comparaciones realizadas.
   -Se retorna el struct con los datos: res (posición en el índice) y el número de comparaciones realizadas.

   Complejidad de tiempo en el peor de los casos: O(n)

*/
par busqueda_lineal_ordenada(int *A, int n, int valor) {
    par datos;
    datos.res = -1, datos.comparaciones = 1;
    for(int i = 0; i <= n - 1 && A[i] <= valor; i++){
        if(A[i] == valor) {
            datos.res = i;
            break;
        }
        datos.comparaciones++;
    }
    return datos;
}
