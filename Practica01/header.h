/**
 * @file header.h
 * @brief Este archivo contiene los prototipos de funciones de distintos algoritmos de ordenamiento.
 * @author Los chalanes de Marckess
 * @date 29/03/2023
*/
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

/**
 * @def TRUE
 * @brief Valor verdadero
 * La macro tiene el valor uno para representar verdadero
 */
#define TRUE 1
/**
 * @def FALSE
 * @brief Valor falso
 * La macro tiene el valor cero para representar falso
 */
#define FALSE 0
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo de burbuja optimizada.
 * @param A Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 * @return void
*/
void BurbujaOptimizada(int *A, int n);
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo de selección.
 * @param A Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 * @return void
*/
void Seleccion(int *A, int n);
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo de inserción.
 * @param A Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 * @return void
*/
void Insercion(int *A, int n);
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo Merge Sort.
 * @param A Arreglo de enteros a ordenar.
 * @param p Índice del primer elemento del arreglo.
 * @param r Índice del último elemento del arreglo.
 * @return void
*/
void MergeSort(int *A, int p, int r);
/**
 * @brief Fusiona dos sub-arreglos ordenados en un solo arreglo ordenado.
 * @param A Arreglo de enteros que contiene los dos sub-arreglos a fusionar.
 * @param p Índice del primer elemento del primer sub-arreglo.
 * @param q Índice del último elemento del primer sub-arreglo.
 * @param r Índice del último elemento del segundo sub-arreglo.
 * @return void
*/
void Merge(int *A, int p, int q, int r);
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo Quicksort.
 * @param A Arreglo de enteros a ordenar.
 * @param p Índice del primer elemento del arreglo.
 * @param r Índice del último elemento del arreglo.
 * @return void
*/
void Quicksort(int *A, int p, int r);
/**
 * @brief Escoge un pivote y lo utiliza para particionar el arreglo en dos sub-arreglos.
 * @param A Arreglo de enteros a particionar.
 * @param p Índice del primer elemento del arreglo.
 * @param r Índice del último elemento del arreglo.
 * @return int Índice del pivote.
*/
int Pivot(int *A, int p, int r);
/**
 * @brief Intercambia dos elementos de un arreglo.
 * @param A Arreglo de enteros que contiene los elementos a intercambiar.
 * @param i Índice del primer elemento a intercambiar.
 * @param j Índice del segundo elemento a intercambiar.
 * @return void
*/
void Intercambiar(int *A, int i, int j);
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo Shell Sort.
 * @param A Arreglo de enteros a ordenar.
 * @param n Tamaño del arreglo.
 * @return void
*/
void Shell(int *A, int n);
#endif /* SORTING_ALGORITHMS_H */