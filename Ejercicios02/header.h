// Macros y variables del programa
#define TRUE 1
#define FALSE 0
// Prototipos de funciones
void BurbujaOptimizada(int *A, int n);
void Seleccion(int *A, int n);
void Insercion(int *A, int n);
void MergeSort(int *A, int p, int r);
void Merge(int *A, int p, int q, int r);
void Quicksort(int *A, int p, int r);
int Pivot(int *A, int p, int r);
void Intercambiar(int *A, int i, int j);