#!/bin/bash

# /*----------------------------------------------------------
#   IPN-ESCOM
#   Autor: González Joshua
#   Algoritmos y Estructuras de Datos                  2CM8
#
#   script.sh
#
#   DESCRIPCIÓN:
#   Script de bash para automatizar pruebas
#
#   OBSERVACIONES:
#   Este script de bash automatiza las pruebas con los diferentes
#   tipos de algoritmos de búsqueda, N totales y valores a buscar.
#   Los pasos que realiza son los siguientes:
#   1. Compila el programa principal.
#   2. Crea un archivo de texto para almacenar los resultados.
#   3. Almacena en un arreglo los distintos argumentos que puede tomar
#   el programa principal.
#   4. Se itera sobre los arreglos y se llama al programa principal
#   haciendo que tome los distintos argumentos, lea los datos requeridos
#   de un archivo de texto y escriba la salida en el archivo de texto creado
#   anteriormente.
#   5. Al termino de cada bucle escribe un salto de línea en el archivo.
#
#   Ejecutado en linux con: ./script.sh
#----------------------------------------------------------*/

# Compilación del programa
gcc main.c busqueda_lineal.c busqueda_binaria.c quickSort.c -o main -std=c17

# Creación de un archivo para almacenar los resultados obtenidos
touch resultados.txt

# Arreglo de elementos que se leerán como argumentos para el programa, contienen el número de elementos totales, los elementos a buscar
# y las iniciales de los algoritmos (para ejecutar los algoritmos requeridos)
N_total=(5000000 10000000)
valores_a_buscar=(322486 14700764 3128036 6337399 61396 10393545 2147445644 1295390003 450057883 187645041 
1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 0)
iniciales_algoritmos=("l d" "l o" "b i" "b r")

# Bucle que toma los valores de los arreglos
for n in "${N_total[@]}"                            # Itera con los valores de N
do
    for busquedas in "${iniciales_algoritmos[@]}"   # Itera con las iniciales de los algoritmos
    do
        for valor in "${valores_a_buscar[@]}"       # Itera con los valores a buscar
        do
            # Llama al ejecutable main con los distintos valores asignados, lee datos de un archivo de texto y
            # escribe la salida en un archivo de texto creado al comienzo
            ./main $n $busquedas $valor < numeros10millones.txt >> resultados.txt
        done
    # Imprime un salto de línea en el archivo destino
    echo '' >> resultados.txt
    done
done


