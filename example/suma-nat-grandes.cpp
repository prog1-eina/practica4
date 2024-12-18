/*********************************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Miguel Ángel Latre
 * Última revisión: 23 de octubre de 2024
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

#include <climits>
#include <iostream>
#include "naturales-grandes.hpp"
using namespace std;

/*
 * Programa que muestra un desbordamiento al utilizar datos de tipo unsigned de 9 dígitos.
 */
int main() {
    // 1. Declaración e inicialización de variables
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS];
    convertir(UINT_MAX, a);
    convertir(1, b);

    // 2. Cálculo de la suma
    unsigned suma[NUM_DIGITOS];
    bool desborda;
    sumar(a, b, suma, desborda);

    // 3. Determinación de la corrección del resultado
    if (desborda) {
        // 4. «desborda» es «true»: se ha producido un desbordamiento
        cout << "Error: ha desbordado (y no debería)" << endl;
        return 1;
    } else {
        // 5. «desborda» es «false»: se ha calculado el resultado correcto
        // Escritura de resultados
        cout << "Suma de " << UINT_MAX << " y 1: ";
        escribirEnPantalla(suma);
        cout << endl;

        // 6. Devolución de código de salida 0 si ha escrito correctamente 4294967296
        return 0;
    }
}