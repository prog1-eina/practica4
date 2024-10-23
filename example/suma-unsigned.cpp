/*********************************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Miguel Ángel Latre
 * Última revisión: 24 de octubre de 2024
 * Resumen: Ejemplo de desbordamiento al utilizando datos de tipo «unsigned» de 9 dígitos.
 *          El fichero «suma-nat-grandes.cpp» contiene el mismo algoritmo donde se evita el 
 *          desbordamiento utilizando la biblioteca «naturales-grandes».
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           make suma-unsigned
 *       o ejecutando la tarea "Compilar programa «suma-unsigned»" de VSC.
 *
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/suma-unsigned
 *       o ejecutar la tarea "Ejecutar programa «suma-unsigned»" de VSC.
\*********************************************************************************************/

#include <iostream>
using namespace std;

/*
 * Programa que muestra un desbordamiento al utilizar datos de tipo unsigned de 9 dígitos.
 */
int main() {
    // 1. Declaración e inicialización de variables
    unsigned a = 4294967295;     // Máximo unsigned representable: 2³² - 1
    unsigned b = 1;

    // 2. Cálculo de la suma
    unsigned suma = a + b;

    // 3. Escritura de resultados
    cout << "Suma de 4294967295 y 1: " << suma << endl;

    // 4. Devolución de código de salida 1: sabemos que ha escrito 0 en lugar de 4294967296
    return 1;
}