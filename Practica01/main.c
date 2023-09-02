/**
 * @file main.c
 * @brief Programa principal que contiene la lógica del programa.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
 */


// Librerías que utiliza el programa
#include <stdio.h>           // Librería de entrada y salida estándar
#include <stdlib.h>          // Librería de utilidades estándar
#include <time.h>            // Librería del tiempo
#include "header.h"

/**
 * @brief Este archivo contiene la lógica del programa
 * @note Instrucciones de compilación:
 *  gcc main.c burbuja.c insercion.c seleccion.c mergeSort.c quickSort.c shell.c -o main -std=c17
 *  (Es necesario pasar todos los archivos como parámetro, ya que se utiliza un puntero a funciones para reducir códgo)
 * @note Instrucciones de ejecución:
 *  Sigue el siguiente formato:
 *      ./main   N     INICIAL_ALGORITMO   IMPRIMIR_ARREGLO_O_TIEMPO?   <   10mil_numeros.txt
 * @note Toma 2 argumentos de entrada:
 *  \n 1. La cantidad de datos que se le quieren pasar al programa
 *  \n  -Por ejemplo: 1000, 5000, 10000
 *  \n 2. Un carácter para elegir el tipo de algoritmo al que se quiere utilizar
 *      \n-BurbujaOptimizada: b
 *      \n-Selección: s
 *      \n-Inserción: i
 *      \n-MergeSort: m
 *      \n-QuickSort: q
 *      \n-Shell: h
 *  \n 3. Si se quiere imprimir...
 *      \n-Sí: 1 - imprime el arreglo
 *      \n-No: 0 - imprime los tiempos
 *  \n Ejemplo, para usar el algoritmo de ordenamiento de burbuja para 1000 datos y que se quiera imprimir su contenido sería:
 *      \n./main 1000 b 1
 *  \n Ejemplo, para usar el algoritmo de mezcla para 10000 datos e imprimir los tiempos que tarda sería:
 *      \n./main 10000 m 0
*/

/**
 * @brief Función principal del programa
 * 
 * @param argc Cantidad de argumentos pasados a la función.
 * @param argv Array de argumentos pasados a la función.
 *
 * @return Un valor entero que indica el éxito o el fracaso del programa.
*/

int main(int n_arg, char *args[]) {

    //Declaración de variables
    int n, f, *A; char opcion, *nombreAlgoritmo;
    // Puntero de funciones que apuntan a NULL
    void (*algoritmoF1)(int*,int)=NULL, (*algoritmoF2)(int*,int,int)=NULL;

    // Si el número de argumentos proporcionada al programa es diferente de lo necesario, se sale del programa
    if(n_arg != 4) {
        printf("Indique el tamanio de n, la inicial del algoritmo de ordenamiento a utilizar y si ");
        printf("desea imprimir el contenido del arreglo ordenado - Ejemplo: [user@equipo]$ %s 1000 b\n", args[0]);
        exit(1);
    }

    // Asignación de variables
    n=atoi(args[1]);
    f=atoi(args[3]);
    opcion=args[2][0];
    A=malloc(n*sizeof(int));

    if(A==NULL){
        printf("No se pudo reservar memoria dinámica para el arreglo\n");
        exit(1);
    }

    // El puntero de función apunta a la función de ordenamiento requerida por el usuario
    if(opcion == 'b') {
        nombreAlgoritmo="de 'Burbuja Optimizada'";
        algoritmoF1 = BurbujaOptimizada;
    }
    else if(opcion == 's') {
        nombreAlgoritmo="por 'Seleccion'";
        algoritmoF1 = Seleccion;
    }
    else if(opcion == 'i') {
        nombreAlgoritmo="por 'Insercion'";
        algoritmoF1 = Insercion;
    }
    else if(opcion == 'm') {
        nombreAlgoritmo="por 'Mezcla'";
        algoritmoF2 = MergeSort;
    }
    else if(opcion == 'q') {
        nombreAlgoritmo="'Rapido'";
        algoritmoF2 = Quicksort;
    }
    else if(opcion == 'h'){
        nombreAlgoritmo="Shell";
        algoritmoF1 = Shell;
    }
    else {
        printf("Indique el tamanio de n y la inicial del algoritmo de ordenamiento a utilizar - Ejemplo: [user@equipo]$ %s 1000 b\n", args[0]);
        exit(1);
    }

    // Se leen los datos necesarios para el programa
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    // MEDICIÓN DEL TIEMPO
    // Variables para la medición de tiempo
    clock_t t_inicio, t_final;
    double t_intervalo;

    // Se llama al puntero de función
    if(algoritmoF1 != NULL) {
        // Inicia medición del tiempo
        t_inicio = clock();
        // Se llama al algoritmo de ordenación
        (*algoritmoF1)(A, n);
    }
    else {
        // Inicia medición del tiempo
        t_inicio = clock();
        // Se llama al algoritmo de ordenación
        (*algoritmoF2)(A, 0, n-1);
    }

    // Termina medición del tiempo
    t_final = clock();

    // Si se desea imprimir el tiempo que tarda en ejecutarse el algoritmo
    if(!f){
        //Cálculo del tiempo y enviar mensaje a salida estandar con la medición
        t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
        printf("Ordenamiento %s para '%d' elementos. ", nombreAlgoritmo, n);
        printf("Tiempo medido: '%.10f' segundos.\n", t_intervalo);
    }

    // Si se desea imprimir el arreglo
    if(f) {
        for(int i=0; i<n; i++) {
            printf("A[%d]: %d\n", i, A[i]);
        }
    }
    free(A);
    return 0;
}