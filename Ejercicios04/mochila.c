/*
----------------------------------------------------------
IPN-ESCOM
Autor: González Joshua
Versión: 1.0
Algoritmos y Estructuras de Datos                  2CM8

   PROBLEMA DE LA MOCHILA ENTERA (0/1)

 * DESCRIPCIÓN:
   Implementación del algoritmo que resuelve el problema
   de la mochila entera (0/1) e imprime el beneficio
   máximo y qué objetos se deben seleccionar.

 * OBSERVACIONES:
   -Para reducir archivos o líneas extras de código redundantes, se
   implementó la solución al problema a y b en el mismo archivo.

   El problema de la mochila consiste en: 
   -Que un ladrón entra a robar objetos en una casa, el ladrón tiene 
   una mochila con cierta capacidad máxima (W) y quiere decidir qué 
   objetos de los n objetos disponibles introducir en su mochila, sin 
   superar la capacidad máxima y eligiendo los objetos que le proporcionen
   el beneficio o la suma máxima. Se deben tomar en cuenta el peso
   de los objetos (w) y el valor de éstos (v).

   -Para resolver este problema se hará uso de la BÚSQUEDA EXHAUSTIVA,
   así se explorarán todas las combinaciones posibles de manera
   recursiva.

   -La idea principal del algoritmo que resuelve el problema es explorar
   dos posibilidades, introducir el elemento actual en la mochila 
   y no introducirlo y avanzar al siguiente elemento, y ver cuál opción
   es la que nos proporciona la suma a máxima. Se repetirán estos
   pasos recursivamente hasta que no se pueda introducir el elemento
   actual, pues supera la capacidad actual de la mochila; o si la capacidad
   de la mochila está llena (igual a 0); o si ya no hay elementos disponibles
   por probar o introducir.

   -Para saber qué objetos se seleccionaron se utilizó el concepto de "máscaras 
   de bits", que en pocas palabras son una secuencia de bits que nos permiten 
   representar algo, en este caso, los objetos que seleccionamos, al utilizar 
   su representación binaria y marcar estos objetos encendiendo el ith-bit. 
   De esta manera no tendremos que utilizar arreglos y la complejidad 
   de tiempo O(n) y memoria O(n) bajaría a O(1), tanto en tiempo como en memoria.

 * INSTRUCCIONES DE COMPILACIÓN:
   Compilado en linux con: gcc mochila.c -o mochila -std=c11
----------------------------------------------------------
*/

// Librerías utilizadas
#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
int max(int a, int b);
int knapsack(int c, int i, int n, int *w, int *v, int *mascara);

/*
   FUNCIÓN MAIN

 * int main(int n_args, char *args[]);
 * DESCRIPCIÓN: Lógica del programa.
  
 * RECIBE: 
   PARÁMETRO int n_args: Número de argumentos que recibirá el programa.
   PARÁMETRO char *args[]: Argumentos que recibirá el programa.

 * RETORNA:
   0: Para indicar que el programa finalizó con éxito.
   1: Si el programa tuvo un error y no finalizó con éxito.
  
 * OBSERVACIONES:
   Esta función principal incluye toda la lógica del programa:
   1. Si el número de argumentos proporcionados al programa es diferente de 3, se imprimirá
      que hubo un error y se terminará el programa con 1.
   2. Se asignarán las variables y reservará memoria dinámica para los arreglos en donde
      se almacenará el peso y valor de los objetos.
   3. En caso de que no se pudiera reservar memoria dinámica, el programa imprimirá
      un mensaje de error y se terminará con 1.
   4. Se leerán los n elementos para los arreglos de pesos y valores de los objetos.
   5. Se llamará a la función recursiva knapsack y se imprimirá el valor que retorne.
   6. Se iterará sobre los bits de la máscara de bits resultante para determinar cuáles
      fueron los objetos que se seleccionaron (1-seleccionado, 0-no seleccionado) y así se 
      imprimirá el índice, peso y valores de los objetos seleccionados.
   7. Se liberará la memoria reservada para los arreglos dinámicos.
   8. Se retornará un 0 indicando que el programa finalizó con éxito.
*/

int main(int n_args, char *args[]){
    // Si el número de argumentos proporcionados es diferente al requerido
    if(n_args != 3) {
        printf("Indique capacidad de la mochila (w) y el numero de objetos (n)");
        printf(" - Ejemplo: [user@equipo]$ %s 20 5\n", args[0]);
        exit(1);
    }

    // Asignación de variables y de memoria dinámica
    int W=atoi(args[1]), n=atoi(args[2]);
    int *w, *v, objetos=0;
    w=malloc(n*sizeof(int)), v=malloc(n*sizeof(int));

    // Si no se pudo reservar memoria dinámica
    if(w == NULL || v == NULL) {
        printf("No se pudo reservar memoria dinamica!\n");
        exit(1);
    }

    // Lectura del PESO de los n objetos
    for(int i=0; i<n; i++)
        scanf("%d", &w[i]);

    // Lectura del VALOR de los n objetos
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);

    // Impresión de la suma máxima
    printf("Suma maxima: %d\n", knapsack(W, 0, n, w, v, &objetos));

    // Impresión del ÍNDICE de los OBJETOS SELECCIONADOS
    printf("Indice de objetos seleccionados:  ");
    for(int i=0; i<n; i++){
        if(objetos & (1 << i))
            printf("%d ", i);
    }

    // Impresión del peso de los objetos seleccionados
    printf("\nPesos de objetos seleccionados:   ");
    for(int i=0; i<n; i++){
        if(objetos & (1 << i))
            printf("%d ", w[i]);
    }

    // Impresión de los valores de los objetos seleccionados
    printf("\nValores de objetos seleccionados: ");
    for(int i=0; i<n; i++){
        if(objetos & (1 << i))
            printf("%d ", v[i]);
    }
    printf("\n");

    // Liberación de memoria reservada
    free(w);
    free(v);
    return 0;
}

/*
   FUNCIÓN MAX

 * int max(int a, int b)
 * DESCRIPCIÓN: Implementación de una función para encontrar el máximo
   de dos elementos.
  
 * RECIBE: 
   PARÁMETRO int a: Primer elemento
   PARÁMETRO int b: Segundo elemento
  
 * RETORNA:
   int a: Si el elemento a es mayor que b.
   int b: Si el elemento b es mayor que a.
  
 * OBSERVACIONES:
   La función de max consiste en:
   -Tomará dos elementos enteros como parámetros, que serán el primer
   y el segundo elemento a comparar y se retornará el que sea mayor.
   -Se usará el operador ternario para compactar un poco las líneas de código:
      -Si a es mayor... se retornará a "a".
      -Si b es mayor... se retornará a "b".

  * COMPLEJIDAD DE TIEMPO: O(1)
*/
int max(int a, int b) {
    return a > b ? a : b;
}


/*
   ALGORITMO DE LA MOCHILA ENTERA (0/1)

 * int knapsack(int c, int i, int n, int *w, int *v, int *mascara)
 * DESCRIPCIÓN: Implementación del algoritmo que resuelve el problema
   de la mochila entera (0/1), imprime la suma máxima y los objetos
   que se seleccionaron.
  
 * RECIBE: 
   PARÁMETRO int c: Capacidad actual de la mochila.
   PARÁMETRO int i: Índice actual.
   PARÁMETRO int n: El tamaño o número de elementos del arreglo.
   PARÁMETRO int *w: Apuntador a un arreglo de enteros (pesos de los objetos).
   PARÁMETRO int *v: Apuntador a un arreglo de enteros (valores de los objetos).
   PARÁMETRO int *mascara: Apuntador a un entero.
  
 * RETORNA:
   int v3: Que contiene el valor de la suma máxima de los valores de los
   objetos seleccionados.
  
 * OBSERVACIONES:
   El algoritmo de la mochila entera (0/1) consiste en:
   
   OBTENCIÓN DEL BENEFICIO MÁXIMO:
   1. Caso base:
   Si c==0 o i==n, se retornará un 0, pues ya se utilizó la capacidad máxima de la 
   mochila o se llegó al final de arreglo.

   2. Caso recursivo 1:
   -Si el peso del elemento actual (w[i]) es mayor a la capacidad actual de la mochila, entonces 
   éste elemento no se considerará, por lo que la función se llamará recursivamente con la
   capacidad actual e i+1, para indicar que se probará seleccionando el siguiente elemento.

   3. Caso recursivo 2: Se harán dos llamadas de funciones recursivas, una al incluir el elemento actual y 
   otra al NO incluirlo, además su valor se almacenará en una variable entera:

       v1: Se le asignará la suma del valor del elemento actual y el que retorne la función recursiva al incluir 
           el elemento actual, por lo que la función se llamará recursivamente restándole a la capacidad actual 
           la capacidad del elemento actual y con i+1, para indicar que se probará seleccionando el siguiente elemento.

       v2: Almacenará el valor que retorna la función recursiva al NO incluir el elemento actual, por lo que
           la función se llamará recursivamente con la capacidad actual e i+1, para indicar que se probará
           seleccionando el siguiente elemento.

   4. Se llamará a la función max para evaluar cuál valor es el máximo entre las dos variables v1 y v2.

   5. Se retornará la suma que proporcione el beneficio máximo.

   Complejidad de tiempo de este procedimiento: O(2^n)

 * SELECCIÓN DE OBJETOS EN EL PROBLEMA DE LA MOCHILA:
   Para saber qué objetos se seleccionaron se utilizó el concepto de "máscaras de bits", que en 
   pocas palabras son una secuencia de bits que nos permiten representar algo, en este caso, los 
   objetos que seleccionamos, al utilizar su representación binaria y marcar estos objetos encendiendo 
   el ith-bit. De esta manera no tendremos que utilizar arreglos, por lo que la complejidad de tiempo 
   O(n) y memoria O(n) de este procedimiento bajaría a O(1), tanto en tiempo como en memoria.

   1. Al principio de cada llamada recursiva se declararán dos variables enteras llamadas mascaras 1 y 2, 
   en donde almacenaremos los objetos que se seleccionan.

   2. Cuando se llame a una función se pasará por referencia a las variables de mascaras, para actualizar
   su valor.

   3. Caso recursivo 1:
      a) Cuando la única opción es NO incluir el elemento actual..
         Al ser la única opción, la función recursiva simplemente tomará como parámetro el valor 
         actual de la mascara original (mascara).

   4. Casos recursivos 2:
      a) Cuando se incluye el elemento actual...
         Se utilizará un corrimiento de bits a la izquierda para prender el ith-bit e indicar que se
         seleccionará este elemento y se llamará a la función recursiva con este parámetro.

      b) Cuando NO se incluye el elemento actual...
         La función recursiva tomará como parámetro el valor actual de mascara2.

   5. Se evaluará cual variable que almacena el valor de las llamadas recursivas posee el máximo, pero
      se utilizará el operador ternario para reducir un poco las líneas de código, y se le aplicará
      la operación de bit "|" de esta variable a mascara para actualizar su valor.
      a) Si "v1 == v3", se seleccionará la combinación de elementos de mascara1.
      b) En caso contrario, si "v2 == v3", se seleccionará la combinación de elementos de mascara2.

    Complejidad de tiempo de este procedimiento: O(1)

  * COMPLEJIDAD DE TIEMPO TOTAL DE ESTA FUNCIÓN: O(2^n)
*/

int knapsack(int c, int i, int n, int *w, int *v, int *mascara){
    if(c == 0 || i == n) 
        return 0;
    if(w[i] > c)
        return knapsack(c, i+1, n, w, v, mascara);

    int mascara1 = 0, mascara2 = 0;
    mascara1 = (1 << i);

    int v1 = v[i] + knapsack(c-w[i], i+1, n, w, v, &mascara1);
    int v2 = knapsack(c, i+1, n, w, v, &mascara2);
    int v3 = max(v1, v2);
    
    *mascara |= (v1 == v3) ? mascara1 : mascara2;
    return v3;
}
