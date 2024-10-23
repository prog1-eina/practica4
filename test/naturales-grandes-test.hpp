/*********************************************************************************
 * Programación 1. Práctica 4
 * Autor: Miguel Ángel Latre Abadía
 * Última revisión: 2 de noviembre de 2022
 * Resumen: Fichero de interfaz «naturales-grandes-test.hpp» de un módulo
 *          denominado «naturales-grandes-test» para hacer de pruebas de las
 *          funciones definidas en el módulo «naturales-grandes» de la 4.ª
 *          práctica.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <string>
using namespace std;

/*
 * Pre:  «valorEsperado» es una cadena de caracteres que contiene la 
 *       representación decimal de un número natural (sin signo).
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «convertir», invocada con el vector que representa el valor como número
 *       grande del argumento «n», calcula el valor correcto «valorEsperado».
 *       En caso afirmativo, si este procedimiento detecta que la función «convertir»
 *       ha modificado memoria fuera de los límites del vector que se le ha pasado
 *       como argumento, informa de ello también.
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «convertir».
 */
void probarConvertir(const unsigned n, const string valorEsperado);

/*
 * Pre:  «aStr», «bStr» y «valorEsperado» son cadenas de caracteres que contiene 
 *       la representación decimal de números naturales (sin signo).
 *       «valorEsperado», en particular, representa la suma de «aStr» y «bStr».
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «sumar», invocada con los vectores que representan los valores como
 *       números grandes de los argumentos «aStr» y «bStr», calcula el valor
 *       correcto «valorEsperado».
 *       En caso afirmativo, si este procedimiento detecta que la función «sumar»
 *       ha modificado memoria fuera de los límites de los vectores que se le han
 *       pasado como argumentos, informa de ello también.
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «sumar».
 */
void probarSumar(const string aStr, const string bStr, 
                 const string valorEsperado);

/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el valor 
 *       numérico representado por la secuencia «numero».
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «valor», invocada con el vector que representa el valor como número
 *       grande del argumento «numero», devuelve el valor correcto
 *       «valorEsperado». 
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «valor».
 */
void probarValor(const string numero, const unsigned valorEsperado);

/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es la
 *       representación de «numero», pero con sus cifras en orden inverso.
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «calcularImagen», invocada con el vector que representa el valor como
 *       número grande del argumento «numero», calcula el valor correcto
 *       «valorEsperado». 
 *       En caso afirmativo, si este procedimiento detecta que la función
 *       «calcularImagen» ha modificado memoria fuera de los límites del vector que
 *       se le ha pasado como argumento, informa de ello también.
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «calcularImagen».
 */
void probarCalcularImagen(const string numero, const string valorEsperado);

/*
 * Pre:  «numero» almacena una cadena de caracteres con la secuencia de
 *       dígitos de un número natural. «valorEsperado» indica si la secuencia
 *       «numero» corresponde a un número capicúa («true») o no («false»).
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «esCapicua», invocada con el vector que representa el valor como número
 *       grande del argumento «numero», devuelve el valor correcto
 *       «valorEsperado». 
 *       En caso afirmativo, si este procedimiento detecta que la función «esCapicua»
 *       ha modificado memoria fuera de los límites del vector que se le ha pasado
 *       como argumento, informa de ello también.
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «esCapicua».
 */
void probarEsCapicua(const string numero, const bool valorEsperado);

/*
 * Pre:  «numeroStr» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo).
 * Post: Escribe un mensaje en pantalla informando acerca de si el procedimiento
 *       «copiar», invocada con el vector que representa el valor como número
 *       grande del argumento «numeroStr», realiza una copia correcta de su
 *       argumento de entrada.
 *       En caso afirmativo, si este procedimiento detecta que la función «copiar»
 *       ha modificado memoria fuera de los límites de los vectores que se le han
 *       pasado como argumento, informa de ello también.
 *       En caso negativo, informa acerca del valor incorrecto que calcula la función
 *       «copiar».
 */
void probarCopiar(const string numeroStr);

/*
 * Pre:  «aStr» y «bStr» son cadenas de caracteres que contienen la  
 *       representación decimal de dos números naturales (sin signo). 
 *       «valorEsperado» es igual a true si «aStr» y «bStr» es la representación
 *       del mismo número y false en caso contrario.
 * Post: Escribe un mensaje en pantalla informando acerca de si la función
 *       «sonIguales», invocada con los argumentos «aStr» y «bStr», devuelve el
 *       valor correcto «valorEsperado». En caso negativo, informa también
 *       acerca del valor incorrecto que devuelve la función.
 */
void probarSonIguales(const string aStr, const string bStr, 
                      const bool valorEsperado);

/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el número
 *       de cifras de «numero».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «numCifras», invocada con el vector que representa el valor como número
 *       grande del argumento «numero», ha calculado el valor correcto
 *       «valorEsperado». En caso negativo, ha informado también acerca del
 *       valor incorrecto que devuelve la función.
 */
void probarNumCifras(const string numero, const unsigned valorEsperado);
