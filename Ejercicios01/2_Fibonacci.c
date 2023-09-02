                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Serie de Fibonacci
2. Implemente el modelo recursivo que obtiene el termino n 
de la serie de Fibonacci (n>=1):

Compilado con: gcc Fibonacci.c -o Fibonacci -std=c17
----------------------------------------------------------
                                                            */

#include <stdio.h> // Librería de entrada y salida estándar

// Prototipo de función
int Fib(int n); 

// Función principal del programa
int main(){          
    int n;
    printf("* * * Serie de Fibonacci * * *\n");
    printf("Ingresa el termino de la serie a calcular: ");
    scanf("%d", &n);
    printf("Fib(%d) = %d\n", n, Fib(n));
    return 0;
}

// Función recursiva para calcular la serie de Fibonacci
/*
    Caso base 1: Si n == 0, retorna un 0
    Caso base 2: Si n == 1, retorna un 1
    Caso recursivo: recursión múltiple para calcular los
    dos términos previos de la serie (n-1 y n-2)
*/
int Fib(int n){
    if(!n)                        // Caso base 1
        return 0;                 // Caso base 2
    if(n == 1) 
        return 1;          
    return Fib(n-1) + Fib(n-2);   // Caso recursivo               
}