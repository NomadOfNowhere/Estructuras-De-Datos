/*----------------------------------------------------------
  IPN-ESCOM
  Autor: González Joshua
  Versión: 1.0
  Algoritmos y Estructuras de Datos                  2CM8

  main.c

  * DESCRIPCIÓN
    Lógica del programa

  * OBSERVACIONES
    Este archivo contiene toda la lógica del programa, es la
    función principal, se le pasarán por argumentos los
    parámetros al programa y así el usuario podrá ingresar el
    tamaño de la colección de elementos (N); si quiere ocupar
    búsqueda lineal o binaria; el "tipo" de búsqueda, es decir:
    si quiere que la búsqueda lineal sea desordenada/ordenada o
    si la búsqueda binaria es iterativa o recursiva; y el elemento
    que se busca.
  
  * INSTRUCCIONES DE COMPILACIÓN
    Compilado en linux con: gcc main.c busqueda_lineal.c busqueda_binaria.c quickSort.c -o main -std=c17
----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
* EJEMPLO DE UTILIZACIÓN DEL PROGRAMA
  ./main tamaño_de_N busqueda tipo_de_la_busqueda valor_a_buscar

* Ejemplo para búsqueda lineal en una colección desordenada
  ./main 10000000 l d 322486

* Ejemplo para búsqueda lineal en una colección ordenada
  ./main 10000000 l o 322486

* Ejemplo para búsqueda binaria iterativa
  ./main 10000000 b i 322486

* Ejemplo para búsqueda binaria recursiva
  ./main 10000000 b r 322486

 * int main(int n_arg, char *args[])
 * DESCRIPCIÓN: Lógica del programa
  
 * RECIBE:
   PARÁMETRO int n_arg: Número de argumentos que recibirá el programa.
   PARÁMETRO char *args[]: Argumentos que recibirá el programa.
  
 * RETORNA:
   0: Para indicar que el programa finalizó con éxito.
   1: Si el programa tuvo un error y no finalizó con éxito.
  
 * OBSERVACIONES:
   Esta función principal incluye toda la lógica del programa.
   1. Si el número de argumentos proporcionados al programa es diferentes de 5, imprimirá
      que hubo un error.
   2. Se asignarán las variables y reservará memoria dinámica para un arreglo.
   3. En caso de que no se pudo reservar memoria dinámica, el programa imprimirá
      un mensaje de error y se terminará con -1.
   4. Se leerán los elementos para el arreglo.
   5. Si el tipo de búsqueda requiere que la colección de elementos se encuentre ordenada, 
      entonces se ordenará con la ayuda del algoritmo quicksort.
   6. Se llamará a la función del tipo de búsqueda requerido dependiendo de los argumentos
      que se le proporcionaron al programa, en caso de que se hayan introducido argumentos
      invalidos, entonces el programa imprimirá un mensaje de error y se terminará con -1.
   7. Se evaluará el valor de res:
      1. Si es diferente de -1, entonces significa que se encontró el elemento en la colección
         y se imprimirá su posición en el arreglo y las comparaciones que se realizaron.
      2. En caso contrario, si no se encontró, se imprimirá el número de comparaciones realizadas.
   8. Por último, se liberará la memoria reservada para el arreglo dinámico.
*/

int main(int n_arg, char *args[]){
    int n, valor, *A; char busqueda, tipo, *nombre; par datos;
    // Si el número de argumentos proporcionado al programa es diferente de los requeridos, se sale del programa
    if(n_arg != 5) {
        printf("Indique el tamanio de n, la inicial del algoritmo de ordenamiento a utilizar y si");
        printf("desea imprimir el contenido del arreglo ordenado - Ejemplo: [user@equipo]$ %s 1000 b\n", args[0]);
        exit(1);
    }

    // Asignación de variables
    n = atoi(args[1]);
    busqueda = args[2][0];
    tipo = args[3][0];
    valor = atoi(args[4]);
    A=malloc(n * sizeof(int));

    // Si no se pudo reservar memoria dinámica
    if(A == NULL) {
        printf("No se pudo reservar memoria dinámica\n");
        exit(1);
    }

    // Lectura de elementos
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    // Se ordena el arreglo de elementos en caso de que la colección necesite encontrarse ordenada
    if(busqueda == 'b' || tipo == 'o')
        Quicksort(A, 0, n-1);

    // Se llama al algoritmo de búsqueda requerido
    if (busqueda == 'l' && tipo == 'd') {
        nombre = "Busqueda lineal en una lista desordenada";
        datos = busqueda_lineal_desordenada(A, n, valor);
    }
    else if (busqueda == 'l' && tipo == 'o') {
        nombre = "Busqueda lineal en una lista ordenada";
        datos = busqueda_lineal_ordenada(A, n, valor);
    }
    else if (busqueda == 'b' && tipo == 'i') {
        nombre = "Busqueda binaria iterativa en una lista ordenada";
        datos = busqueda_binaria_iterativa(A, valor, 0, n-1);
    }
    else if (busqueda == 'b' && tipo == 'r') {
        nombre = "Busqueda binaria recursiva en una lista ordenada";
        datos = busqueda_binaria_recursiva(A, valor, 0, n-1, 0);
    }
    // Si los argumentos introducidos al programa fueron incorrectos
    else {
        printf("Indique el tamanio de n, la inicial de la busqueda, inicial del tipo de la busqueda y el valor a buscaro - Ejemplo: [user@equipo]$ %s 1000 b i 3\n", args[0]);
        exit(1);
    }
    // Si se encontró el elemento en la colección, se imprime su posición en el arreglo y las comparaciones que se realizaron
    if(datos.res != -1) {
        printf("%s de %d elementos: ", nombre, n);
        printf("Elemento [%d] encontrado en la posicion A[%d] - con %d comparaciones realizadas\n", valor, datos.res, datos.comparaciones);
    }  
    // Si no se encontró, se imprime el número de comparaciones realizadas
    else {
        printf("%s de %d elementos: ", nombre, n);
        printf("Elemento [%d] NO encontrado - con %d comparaciones realizadas.\n", valor, datos.comparaciones);
    }
    free(A);   // Se libera la memoria reservada para el arreglo dinámico
    return 0;
}