                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Raíz de un número X
6. El valor de la raíz de un número X puede calcularse 
empleando la siguiente definición recurrente

Compilado con: gcc RaizX.c -o RaizX -std=c17 -lm
----------------------------------------------------------
                                                            */

#include <stdio.h>    // Librería de entrada y salida estándar
#include <math.h>     // Librería de funciones matemáticas

// Prototipos de función
double raizX(int x, int n);   
double error_porcentual(double a, double b);

// Función principal del programa
int main(){
    printf("* * * Raiz cuadrada de un numero x * * *\n");
    printf("Ingresa el numero 'x' y numero de iteraciones 'n': ");

    // Cálculo aproximado de la raíz cuadrada
    int x, n; scanf("%d %d", &x, &n);
    double valor_exacto = sqrt(x), valor_aprox = raizX(x, n), error = error_porcentual(valor_aprox, valor_exacto);
    
    // Impresión de información
    printf("Raiz cuadrada de %d\n\n", x);
    printf("Valor real:\t\t\t     %.16lf\n\n", valor_exacto);
    printf("Valor aproximado con %d iteraciones: %.16lf\n\n", n, valor_aprox);
    printf("Error porcentual:\t    %.16lf\n", error);
    printf("Porcentaje de aproximacion: %.16lf\n", 100.0-error);
    return 0;
}

// Función recursiva para aproximar el valor de la raíz cuadrada de un número
/*
    Caso base: cuando n == 0, retornamos un 0, para indicar que las llamadas recursivas terminaron
    Caso recursivo: llamamos a la función recursivamente con n-1
*/
double raizX(int x, int n){
    if(!n)   // Caso base
        return 0;                                 
    return 1.0 + ((x - 1) / (1.0 + raizX(x, n-1)));   // Caso recursivo
                                                     
}

/* Función para calcular el error porcentual con la fórmula:
Error porcentual = |Valor aproximado - Valor exacto|
                   --------------------------------- * 100
                   |        Valor exacto           |
*/
double error_porcentual(double valor_aprox, double valor_exacto){
    return (fabs(valor_aprox - valor_exacto)) / valor_exacto * 100;
}