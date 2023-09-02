                                                            /*
----------------------------------------------------------
IPN-ESCOM
Alumno: González Joshua
Algoritmos y Estructuras de Datos                  2CM8

Cálculo del GCD (Greatest Common Divisor)

4. Implemente el modelo recursivo para el cálculo del GCD 
(Greatest Common Divisor) (a>=0 && b>=0)

Compilado con: gcc GCD.c -o GCD -std=c17
----------------------------------------------------------
                                                            */

#include <stdio.h>          // Librerías de entrada y salida estándar

// Prototipo de función
int GCD(int a, int b);      

// Función principal del programa
int main(){                 
    int a, b, aux;
    printf("Ingresa los números A y B: ");
    scanf("%d %d", &a, &b);

    aux=a;
    if(b > a) a=b, b=aux;    // a > b para hacer menos llamadas de funciones recursivas
    
    printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));
    return 0;
}

// Función recursiva para calcular el algoritmo de Euclides: GCD(a, b) = GCD(b, a % b)
/*
    Caso base: cuando b == 0 (residuo entre la división de a y b), retorna a (el GCD de los números)
    Caso recursivo: cálcula el GCD llamando a la función recursivamente con a=b, b=el residuo de la
    división entre a y b
*/
int GCD(int a, int b){
    if(!b)                 // Caso base
        return a;     
    return GCD(b, a%b);    // Caso recursivo
                         
}
