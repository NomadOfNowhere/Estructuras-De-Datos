                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Combinatoria (Coeficiente binomial)
3. Implemente el modelo recursivo de la combinatoria (k>=0 && n>=k):

Compilado con: gcc Combinatoria.c -o Combinatoria -std=c17
----------------------------------------------------------
                                                            */

#include <stdio.h>    // Librería de entrada y salida estándar

// Prototipo de función
long long combinatoria(int n, int k);  

// Función principal del programa
int main() {           
    int n, k; 
    printf("* * * Combinatoria * * *\n");
    printf("Ingresa el valor de n y k: ");
    scanf("%d %d", &n, &k);
    printf("Coeficiente binomial C(%d, %d) = %lld\n", n, k, combinatoria(n, k));
    return 0;
}

// Función recursiva para calcular el coeficiente binomial (combinatoria)
/*
    Caso base 1: Si k == 0 ó k == n retorna un 1
    Caso recursivo: recursión múltiple para calcular el coeficiente binomial 
    (n - 1, k -1) y (n - 1, k)
    Caso base 2: Si n < 0 ó n < k, retorna un 0
*/
long long combinatoria(int n, int k) { 
    if(k == 0 || k == n)   // Caso base 1
        return 1;                   
    if(k > 0 && n > k)     // Caso recursivo
        return combinatoria(n - 1, k - 1) + combinatoria(n - 1, k);                                                                            
    else 
        return 0;          // Caso base 2
}