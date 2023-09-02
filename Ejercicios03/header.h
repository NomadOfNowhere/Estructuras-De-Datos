#ifndef HEADER_H
#define HEADER_H
/*----------------------------------------------------------
  IPN-ESCOM
  Autor: González Joshua
  Versión: 1.0
  Algoritmos y Estructuras de Datos                  2CM8

  header.h

  * DESCRIPCIÓN:
    Librería para los archivos o algoritmos utilizados en el programa

  * OBSERVACIONES:
    Este archivo de encabezado contiene las definiciones de tipos
    de datos y prototipos de funciones utilizados en los algoritmos.
    -Se define un tipo de dato struct llamado "par" para almacenar
    la posición en el arreglo del elemento a buscar y el número de 
    comparaciones que se realizaron.
    -Se declaran los prototipos de funciones para los archivos o algoritmos
    utilizados.

  * INSTRUCCIONES DE COMPILACIÓN:
    Compilado en linux con: gcc header.h -c -std=c17
----------------------------------------------------------*/

/*** Definiciones de tipos de datos ***/
/* Definicion de un tipo de dato struct llamado par, para almacenar y retornar
   la posición o índice en el arreglo del elemento a buscar y las comparaciones 
   que se necesitaron realizar */
typedef struct par{ 
    int res, comparaciones;
} par;

/*** Prototipos de funciones ***/
par busqueda_lineal_desordenada(int *A, int n, int valor);
par busqueda_lineal_ordenada(int *A, int n, int valor);
par busqueda_binaria_iterativa(int *A, int valor, int inicio, int fin);
par busqueda_binaria_recursiva(int *A, int valor, int inicio, int fin, int comparacion);
void Intercambiar(int *A, int i, int j);
int Pivot(int *A, int p, int r);
void Quicksort(int *A, int p, int r);

#endif