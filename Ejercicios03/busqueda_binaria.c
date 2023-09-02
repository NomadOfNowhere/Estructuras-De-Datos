#include <stdio.h>
#include "header.h"
/*
----------------------------------------------------------
IPN-ESCOM
Autor: González Joshua
Versión: 1.0
Algoritmos y Estructuras de Datos                  2CM8

   BÚSQUEDA BINARIA RECURSIVA E ITERATIVA

 * DESCRIPCIÓN:
   Implementaciones del algoritmo de búsqueda binaria iterativa
   y recursiva para encotnrar un elemento en una lista ordenada 
   de elementos.

 * OBSERVACIONES:
   El algoritmo de búsqueda binaria, de forma iterativa y recursiva,
   busca un elemento en una colección ordenada de elementos. 
   -El primer requisito es que el arreglo o lista de elementos 
   se encuentre ordenada, por como funciona el algoritmo, en esta
   implementación se utiliza apoyo del algoritmo de ordenamiento
   quicksort, para ordenar eficiente y rápidamente los elementos,
   hablando en términos de tiempo y memoria.
   -Se utilizan dos punteros, uno para el comienzo del arreglo y otro
   para el final de arreglo.
   -Se divide el arreglo a la mitad, en caso de que el elemento de la mitad 
   sea igual al elemento buscado, se retornará su índice o posición en el 
   arreglo.
   -En caso de que el elemento de la mitad sea menor al elemento buscado,
   el puntero del comienzo del arreglo se asigna a la mitad del arreglo + 1.
   -En caso de que el elemento de la mitad sea mayor al elemento buscado,
   el puntero del final se asigna a la mitad del arreglo - 1.
   -EL proceso se repetirá hasta que el elemento sea encontrado o que los
   punteros del comienzo y final del arreglo apunten al mismo índice o posición
   en el arreglo, lo que significará que sólo queda ese elemento por comparar,
   si es igual, retorna la posición, en caso contrario, retornará un -1,
   indicando que el elemento no fue encontrado.

 * INSTRUCCIONS DE COMPILACIÓN:
   Compilado en linux con: gcc busqueda_binaria.c -c -std=c17
----------------------------------------------------------
*/

/*
   ALGORITMO DE BÚSQUEDA BINARIA ITERATIVA

 * struct par busqueda_binaria_iterativa(int *A, int valor, int inicio, int fin)
 * DESCRIPCIÓN: Implementación del algoritmo de búsqueda binaria iterativa para
   encontrar un elemento en una lista ordenada de elementos.
  
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros.
   PARÁMETRO int valor: El valor o elemento a buscar en la lista.
   PARÁMETRO int inicio: Indice del comienzo de la lista.
   PARÁMETRO int fin: Indice del final de la lista.
  
 * RETORNA:
   struct par datos: Que contiene el índice o posición en el arreglo del elemento (si se encontró) 
   y el número de comparaciones que se realizaron en la búsqueda.
  
 * OBSERVACIONES:
   El algoritmo de búsqueda binaria iterativa consiste en:
   -El primer requisito es que la lista o colección de elementos se tiene que encontrar ordenada.
   -Se inicializa un struct con la variable res (posición en el arreglo del elemento que se busca) 
   en -1 y el número de comparaciones en 0. 
   -Se ejecutará un bucle mientras inicio sea menor o igual a fin.
   -Por cada iteración se incrementa el número de comparaciones realizadas.
   -Se obtendrá la mitad del rango a buscar el elemento del arreglo.
   -Se evalúa...
    1. Si el elemento a buscar es igual al elemento de la mitad del rango actual, se rompe el bucle.
    2. Si el valor a buscar es mayor que el valor de la mitad del rango actual, el rango a buscar 
       se hace más pequeño, es decir: el puntero de inicio se asigna a mitad + 1, reduciendo el rango
       o tamaño sobre el cual buscar.
    3. En caso contrario, si el valor a buscar es mayor, de igual manera el rango a buscar se
       encoge, pero haciendo que el puntero del final sea igual a mitad - 1.
    -Es importante incluir el +1 o -1 al reducir el rango, pues así la búsqueda binaria hará menos comparaciones,
     ya que se excluye el elemento de la mitad, pues no tiene sentido en volver a buscar en la mitad si ya sabemos 
     que ahí no se encuentra el elemento.
    -Se repiten los pasos descritos anteriormente hasta que inicio sea menor o igual a fin.
    -Cuando el bucle termina o se rompe, se retorna el struct con los datos: res (posición en el índice) 
    y el número de comparaciones realizadas.

    Complejidad de tiempo en el peor de los casos: O(log(n))

*/
par busqueda_binaria_iterativa(int *A, int valor, int inicio, int fin) {
    par datos;
    datos.res = -1, datos.comparaciones = 0;
    while(inicio <= fin){
        int mitad = (inicio + fin) >> 1;
        datos.comparaciones++;
        if(valor == A[mitad]) {
            datos.res = mitad;
            break;
        }
        else if(valor > A[mitad])
            inicio = mitad + 1;
        else
            fin = mitad - 1;
    }
    return datos;
}

/*
   ALGORITMO DE BÚSQUEDA BINARIA RECURSIVA

 * struct par busqueda_binaria_recursiva(int *A, int valor, int inicio, int fin)
 * DESCRIPCIÓN: Implementación del algoritmo de búsqueda binaria iterativa para
   encontrar un elemento en una lista ordenada de elementos.
  
 * RECIBE: 
   PARÁMETRO int *A: Apuntador a un arreglo de enteros.
   PARÁMETRO int valor: El valor o elemento a buscar en la lista.
   PARÁMETRO int inicio: Indice del comienzo de la lista.
   PARÁMETRO int fin: Indice del final de la lista.
   PARÁMETRO int comparacion: Número de comparaciones realizadas.
  
 * RETORNA:
   struct par datos: Que contiene el índice o posición en el arreglo del elemento (si se encontró) 
   y el número de comparaciones que se realizaron en la búsqueda.
  
 * OBSERVACIONES:
   El algoritmo de búsqueda binaria recursiva consiste en:
   -El primer requisito es que la lista o colección de elementos se tiene que encontrar ordenada.
   -Se evalúa...
      1. Caso base 1: Si "inicio es mayor a fin", significa que ya se buscó en el arreglo y elemento que
         se buscaba no fue encontrado, entonces:
          -Se crea un struct llamado datos, para almacenar la posición del índice (res) y el número de
          comparaciones. Como no se encontró el elemento, res va a ser igual a -1.
          -Se retornan los datos
      2. En caso contrario...
         -Se obtiene la mitad del rango a buscar del arreglo, dividiendo el rango actual (suma del puntero
          de inicio + puntero del final y se divide entre 2).
         -Se evalúa...
           1. Caso base 2: Si elemento a buscar es igual al elemento de la mitad del rango actual, significa que 
              encontramos el elemento que buscábamos, entonces:
              -Se crea un struct llamado datos para almacenar la posición o índice en el arreglo
               del elemento que buscábamos y el número de comparaciones que se realizaron.
              -Se retornan los datos
           2. Paso recursivo 1: Si el elemento que buscamos es mayor al elemento de la mitad del rango actual, 
              entonces se reducirá el rango: llamando a la función recursiva con el puntero del inicio=mitad + 1,
              el puntero del final=final y con el número de comparaciones + 1, para indicar que se realizó
              otra comparación. Se retornará el valor que devuelva la función.
           3. Paso recursivo 2: En caso contrario, si el elemento que buscamos es menor al elemento de la mitad 
              del rango actual, entonces se reducirá el rango: llamando a la función recursiva con el puntero 
              del inicio=inicio, el puntero del final=mitad-1 y con el número de comparaciones + 1, para indicar 
              que se realizó otra comparación. Se retornará el valor que devuelva la función recursiva.
    
    Complejidad de tiempo en el peor de los casos: O(log(n))
*/
par busqueda_binaria_recursiva(int *A, int valor, int inicio, int fin, int comparacion) {
    if(inicio > fin) {
        par datos;
        datos.res = -1, datos.comparaciones = comparacion;
        return datos;
    }
    else {
        int mitad = (inicio + fin) >> 1;
        if(valor == A[mitad]) {
            par datos;
            datos.res = mitad, datos.comparaciones = comparacion + 1;
            return datos;
        }
        else if (valor > A[mitad])
            return busqueda_binaria_recursiva(A, valor, mitad + 1, fin, comparacion + 1);
        else
            return busqueda_binaria_recursiva(A, valor, inicio, mitad - 1, comparacion + 1);
    }
}