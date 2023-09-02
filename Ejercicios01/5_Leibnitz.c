                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Serie de Leibnitz
5. En 1674 el alemán G. Leibnitz da una serie que nos permite 
calcular el valor de PI, utilice esta en un programa en el 
que el usuario de un valor de n sobre esta para determinar 
una a aproximación de PI.

Compilado con: gcc Leibnitz.c -o Leibnitz -std=c17 -lm
----------------------------------------------------------
                                                            */

#include <stdio.h>        // Librería de entrada y salida estándar
#include <math.h>         // Librería para operaciones matemáticas

// Prototipo de función
double leibnitz(int n);   

// Función principal del programa
int main(){               
    int n;
    printf("* * * Formula de Leibniz para aproximar el valor de PI * * *\n");
    printf("Ingresa el numero de iteraciones: ");
    scanf("%d", &n);
    printf("Valor aproximado de PI con %d interaciones: %.16lf\n", n, leibnitz(n) * 4);  // Multiplicamos el valor obtenido por 4
    return 0;
}

// Función recursiva para aproximar el valor de PI después de n llamadas de funciones o iteraciones
/*
    Caso base: Si n == 0, retorna un 1 (simplificando la sumatoria cuando n es igual a 0)
    Caso recursivo: llama a la función recursivamente con n - 1
*/
double leibnitz(int n){
    if(!n)        // Caso base
        return 1;         
    return (pow(-1, n) / (2 * n + 1)) + leibnitz(n - 1);   // Caso recursivo
}