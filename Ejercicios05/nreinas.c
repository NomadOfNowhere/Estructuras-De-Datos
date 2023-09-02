/* ----------------------------------------------------------
IPN-ESCOM
Autor: González Joshua
Versión: 1.0
Algoritmos y Estructuras de Datos                  2CM8

   PROBLEMA DE LAS N-REINAS

 * DESCRIPCIÓN:
   Implementación del algoritmo que resuelve el problema
   de las N-reinas utilizando una búsqueda exhaustiva y
   backtracking.

 * OBSERVACIONES:
   El problema de las N-reinas consiste en: 
   1. Colocar n reinas en un tablero de ajedrez de tamaño n*n de forma la reinas no se amenacen según las normas del ajedrez. 
   2. Se busca encontrar una solución o todas las soluciones posibles.
   3. Este problema puede resolverse utilizando un esquema de backtracking.
   4. Las restricciones para este problema consisten en que dos reinas no pueden colocarse en la misma fila, 
      ni en la misma columna ni en la misma diagonal, es entonces cuando ocurre el backtracking y se prueba con otra
      combinación.

 * INSTRUCCIONES DE COMPILACIÓN:
   Compilado en linux con: gcc nreinas.c -o nreinas -std=c11
----------------------------------------------------------
*/

// Librerías utilizadas
#include <stdio.h>
#include <stdlib.h>

// Declaración de constantes
#define true 1
#define false 0

// Prototipos de funciones
void NReinas(int n);
int nReinasBacktracking(int **tablero, int columna, int n);
int validarPosicion(int **tablero, int fila, int columna, int n);
void imprimir(int **tablero, int n);

/*
   FUNCIÓN MAIN

 * int main(int n_args, char *args[]);
 * DESCRIPCIÓN: LLama a la función NReinas.
  
 * RECIBE: 
   PARÁMETRO int n_args: Número de argumentos que recibirá el programa.
   PARÁMETRO char *args[]: Argumentos que recibirá el programa.

 * RETORNA:
   0: Para indicar que el programa finalizó con éxito.
   1: Si el programa tuvo un error y no finalizó con éxito.
  
 * OBSERVACIONES:
   Esta función principal llama a las funciones para resolver el problema de las n-reinas:
   1. Si el número de argumentos proporcionados al programa es diferente de 2, se imprimirá
      que hubo un error y se terminará el programa con 1.
   2. Se asignará el número de reinas que se intentará colocar o tamaño del tablero n x n con los 
      parámetros proporcionados al programa.
   3. Se llamará a la función que resuelve el problema de las n-reinas
   4. Se retornará un 0 indicando que el programa finalizó con éxito.
*/
int main(int n_args, char *args[]){
    // Si el número de argumentos proporcionados es diferente al requerido
    if(n_args != 2) {
        printf("Ingresa el tamanio del tablero - Ejemplo[$user] %s 8\n", args[0]);
        exit(1);
    }
    // Asignación del tamaño del tablero
    int n=atoi(args[1]);
    // Se llama a la función para resolver el problema de las n-reinas
    NReinas(n);
    return 0;
}

/*
   FUNCIÓN NREINAS

 * int NReinas(int n);
 * DESCRIPCIÓN: Esta función es la encargada de inicializar la matriz bidimensional de tamaño
   n x n donde se intentará colocar las n reinas y se verificará si existe una solución
   llamando a las funciones auxiliares
  
 * RECIBE: 
   PARÁMETRO int n: Número de reinas que se intentarán colocar o el tamaño de la matriz n x n.

 * RETORNA:
   void
  
 * OBSERVACIONES:
   Esta función toma como entrada un número entero n que indica el número de reinas que se deben 
   colocar en un tablero de tamaño n x n:
   1. Se reserva memoria dinámica para una arreglo bidimensional. Primero se reserva memoria dinámica
      para un arreglo de n punteros enteros, después se itera sobre el arreglo y se asigna memoria
      dinámica para cada fila.
   2. Se inicializa el arreglo bidimensional con ceros.
   3. Se llama a la función auxiliar nReinasBacktracking(tablero, columna, n) con el tablero vacío y la
      columna inicial 0 para verificar si existe una solución.
   4. Si existe una solución se imprimirá el tablero final o de la solución, en caso contrario se 
      imprimirá que no existe solución.
   5. Se libera la memoria dinámica utilizada por la matriz bidimensional, para ello se iterará sobre
      cada fila de la matriz y liberará su memoria, para posteriormente liberar la memoria utilizada
      por el doble puntero.
*/

void NReinas(int n){
    // Reserva de memoria dinámica
    int **tablero = malloc(n * sizeof(int*)); 
    for(int i=0; i<n; i++)
        tablero[i] = malloc(n * sizeof(int));

    // Inicialización del arreglo en 0's
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tablero[i][j] = 0;
        }
    }
    // Verificamos si existe una solución
    if(nReinasBacktracking(tablero, 0, n)) {
        printf("La solucion es:\n");
        imprimir(tablero, n);
    }
    else 
        printf("No se encontro solucion!\n");

    // Liberamos memoria reservada
    for(int i=0; i<n; i++)
        free(tablero[i]);
    free(tablero);
}


/*
   FUNCIÓN NREINASBACKTRACKING

 * int nReinasBacktracking(int **tablero, int columna, int n);
 * DESCRIPCIÓN: Es la función recursiva que implementa el algoritmo de backtracking
   para resolver el problema de las N reinas.
  
 * RECIBE: 
   PARÁMETRO int **tablero: Doble puntero a una matriz bidimensional.
   PARÁMETRO int columna: Posición de la columna actual.
   PARÁMETRO int n: Número de reinas que se intentarán colocar o el tamaño de la matriz n x n.

 * RETORNA:
   true: Si se colocaron todas las reinas en el tablero o si fue posible colocar una
   en la siguiente columna.
   false: Si no hay solución para el problema.
  
 * OBSERVACIONES:
   Es la función recursiva que implementa el algoritmo de backtracking para resolver 
   el problema de las N reinas.
   1. La función recibe como entrada el tablero actual, la columna actual y el número total de reinas n.
   2. La función verifica si se han colocado todas las reinas en el tablero (es decir, si columna >= n), y si es así,
      devolverá true.
   3. En caso contrario, intentará colocar una reina en cada fila posible de la columna actual, y se llamará recursivamente 
      a la función con la siguiente columna. Si se encuentra una solución, se devuelve tru. Si n ose encuentra ninguna solución 
      se restaura el tablero y se devuelve false.
*/
int nReinasBacktracking(int **tablero, int columna, int n) {
    // Impresión de cada configuración del tablero que se prueba
    imprimir(tablero, n);

    // Se verifica si se se colocaron todas las reinas en el tablero
    if(columna >= n)
        return true;
    // En caso contrario, intenta colocar una reina en cada fila posible de la columna actual
    // llama recursivamente a la función con la siguiente columna
    for(int fila=0; fila<n; fila++) {
        if(validarPosicion(tablero, fila, columna, n)) {
            tablero[fila][columna] = 1;
            if(nReinasBacktracking(tablero, columna+1, n))
                return true;
            printf("Backtrack!\n\n");
            tablero[fila][columna] = 0;
        }
    }
    return false;
}

/*
   FUNCIÓN NREINASBACKTRACKING

 * int validarPosicion(int **tablero, int fila, int columna, int n);
 * DESCRIPCIÓN: 
  
 * RECIBE: 
   PARÁMETRO int **tablero: Doble puntero a una matriz bidimensional.
   PARÁMETRO int fila: Entero con la posición de la fila actual.
   PARÁMETRO int columna: Entero con la posición de la columna actual.
   PARÁMETRO int n: Número de reinas que se intentarán colocar o el tamaño de la matriz n x n.

 * RETORNA:
   true: Si es seguro colocar una reina.
   false: Si no es posible colocar una reina.
  
 * OBSERVACIONES:
   Verifica si es seguro colocar una reina en la posición (fila, columna) del tablero actual.
   Para hacerlo, se verifica:
   1. Que no haya otras reinas en las misma fila.
   2. Que no haya otras reinas en la diagonal superior izquierda.
   3. Que no haya otras reinas en la diagonal inferior izquierda.
   a) En caso de que se cumple una de las condiciones anteriores, se retornará false, ya que no
      es posible colocar una reina en la posición actual.
   b) En caso de que se llegue hasta el final sin que se cumpla una de las condiciones, se retornará
      true, indicando que fue posible colocar una reina en la posición actual.
*/

int validarPosicion(int **tablero, int fila, int columna, int n) {
    // Misma fila
    for(int i=0; i<=columna-1; i++) {
        if(tablero[fila][i])
            return false;
    }
    // Diagonal superior izquierda
    for(int i=fila, j=columna; i>=0 && j>=0; i--, j--) {
        if(tablero[i][j])
            return false;
    }
    // Diagonal inferior izquierda
    for(int i=fila, j=columna; i<n && j>=0; i++, j--) {
        if(tablero[i][j])
            return false;
    }
    return true;
}

/*
   FUNCIÓN IMPRIMIR

 * void imprimir(int **tablero, int n);
 * DESCRIPCIÓN: Imprime el tablero con las reinas colocadas.
  
 * RECIBE: 
   PARÁMETRO int **tablero: Doble puntero a una matriz bidimensional.
   PARÁMETRO int n: Número de reinas que se intentarán colocar o el tamaño de la matriz n x n.

 * RETORNA:
   void
  
 * OBSERVACIONES:
   Esta función sirve para imprimir el tablero de tamaño n x n. 
   Se imprimirá una "R" si hay una reina en fila y columna actual, en caso contrarió
   se imprimirá un "-".
*/
void imprimir(int **tablero, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(tablero[i][j])
                printf("R ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}