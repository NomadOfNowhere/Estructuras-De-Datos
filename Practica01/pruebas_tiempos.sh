#!/bin/bash
# Este script de bash contiene instrucciones para automatizar las pruebas del programa

# Compilación del programa
gcc main.c burbuja.c insercion.c seleccion.c mergeSort.c quickSort.c shell.c -o main -std=c17

# Creación de un archivo para almacenar los resultados obtenidos
touch tiempo.txt

# Arreglo de elementos que se leerán como argumentos para el programa, contienen las iniciales de los algoritmos
# de ordenamiento (para ejecutar los algoritmos requeridos) y el número de elementos totales que se ordenarán
#iniciales_algoritmos=("b" "i" "s" "m" "q" "h")
iniciales_algoritmos=("m" "q" "h")
N_totales=(500 1000 5000 10000 50000 100000 200000 500000 750000 1000000)

for algoritmo in "${iniciales_algoritmos[@]}"             # Itera sobre las iniciales de los algoritmos
do
	for n in "${N_totales[@]}"                            # Itera sobre los valores de n
	do
		# Llama al ejecutable main con los distintos valores asignados, lee datos de un archivo de texto y
        # escribe la salida en un archivo de texto creado al comienzo
		./main $n $algoritmo 0 < numeros1M.txt >> tiempo.txt
	done
	# Imprime un salto de línea en el archivo destino
    echo '' >> tiempo.txt
done