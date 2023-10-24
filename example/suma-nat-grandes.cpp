/*********************************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Miguel Ángel Latre
 * Ultima revisión: 24 de octubre de 2024
 * Resumen: Ejemplo de funcionamiento por encima de 9 dígitos con la biblioteca
 *          «naturales-grandes».
 *          El fichero «suma-unsigned.cpp» contiene el mismo algoritmo donde se produce un 
 *          desbordamiento al utilizar el tipo «unsigned».
 * Nota: El código de este programa está repartido en varios módulos. 
 *       Para compilarlo, hay que ejecutar el comando
 *           make suma-nat-grandes
 *       o ejecutar la tarea "Compilar programa «suma-nat-grandes»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/suma-nat-grandes
 *       o ejecutar la tarea "Ejecutar programa «suma-nat-grandes»" de VSC.
\*********************************************************************************************/

#include <iostream>
#include "naturales-grandes.hpp"
using namespace std;

/*
 * Programa que muestra un desbordamiento al utilizar datos de tipo unsigned de 9 dígitos.
 */
int main() {
    // 1. Declaración e inicialización de variables
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS];
    convertir(4294967295, a);
    convertir(1, b);

    // 2. Cálculo de la suma
    unsigned suma[NUM_DIGITOS];
    sumar(a, b, suma);

    // 3. Escritura de resultados
    cout << "Suma de 4294967295 y 1: ";
    escribirEnPantalla(suma);
    cout << endl;

    // 4. Devolución de código de salida 0: ha escrito correctamente 4294967296
    return 0;
}