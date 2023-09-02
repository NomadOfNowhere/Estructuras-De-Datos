                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Factorial de un número
1. Implemente el modelo recursivo del factorial (n>=0).

Compilado con: gcc Factorial.c -o Factorial -std=c17
----------------------------------------------------------
                                                            */

#include <stdio.h>        // Librería de entrada y salida estándar

// Prototipo de función
long long n_factorial(long long n);    

// Función principal del programa
int main(){      
    int n; 
    printf("* * * Factorial de un numero * * *\n");
    printf("Ingresa el valor de n: ");
    scanf("%d", &n);
    printf("Factorial de %d es: %lld\n", n, n_factorial(n));
    return 0;
}

// Función recursiva para calcular el factorial de un número
/*
    Caso base: cuando n == 0, retorna un 1
    Caso recursivo: si n >= 1, llama a la función con 
    n - 1 y retorna el resultado multiplicado por n
*/
long long n_factorial(long long n){
    if(!n) return 1;                            // Caso base             
    if(n >= 1) return n_factorial(n - 1) * n;   // Caso recursivo
                                                
}