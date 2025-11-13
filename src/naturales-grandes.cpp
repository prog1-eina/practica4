/*********************************************************************************************\
 * Programación 1. Práctica 4
 * Autores: ------------- ¡PON AQUÍ TU NOMBRE! -------------
 * Última revisión: 
 * Resumen: Fichero de implementación «naturales-grandes.cpp» de un módulo denominado
 *          «naturales-grandes» para trabajar con números naturales de gran magnitud en la
 *          4ª práctica.
\*********************************************************************************************/

#include "naturales-grandes.hpp"

/*
 * Pre:  «original» almacena la representación de un número natural. La
 *       componente original[0] representa las unidades de «original», la
 *       componente original[1] las decenas de «original» y así, sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo de cada uno almacenan el valor 0.
 *       «original» y «copia» tienen «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «copia» almacena una representación
 *       idéntica a la del número natural correspondiente a la de «original».
 */
void copiar(const unsigned original[], unsigned copia[]) {
    // Por completar
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales.
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así
 *       sucesivamente. Las componentes de índices superiores a los
 *       correspondientes a los dígitos más significativos almacenan el
 *       valor 0. Las componentes de índices superiores almacenan el valor 0.
 *       «a» y «b» tienen «NUM_DIGITOS» componentes.
 * Post: Devuelve el valor booleano «true» si «a» y «b» representan el mismo
 *       número natural y «false» en caso contrario.
 */
bool sonIguales(const unsigned a[], const unsigned b[]) {
    // Por completar
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así, sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0.
 *       «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Devuelve el número de cifras de «natural» cuando se escribe en base 10
 *       sin ceros a la izquierda.
 */
unsigned numCifras(const unsigned natural[]) {
    // Por completar
}


/*
 * Pre:  «natural» almacena la representación de un número natural grande. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así, sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0.
 *       «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, se ha escrito en la pantalla el
 *       número natural representado por «natural» (sin ceros a la izquierda).
 */
void escribirEnPantalla(const unsigned natural[]) {
    // Por completar
}


/*
 * Pre:  «naturalGrande» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «naturalGrande» contiene la
 *       secuencia de dígitos equivalente a «numero». La componente
 *       naturalGrande[0] almacena las unidades de «numero», la componente
 *       naturalGrande[1], las decenas de «numero» y así sucesivamente. Las
 *       componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0.
 */
void convertir(const unsigned numero, unsigned naturalGrande[]) {
    // Por completar
}


/*
 * Pre:  «naturalGrande» almacena los dígitos de un número natural lo
 *       suficientemente pequeño como para ser representado por un dato de tipo
 *       «unsigned». En la componente naturalGrande[0] se almacena el dígito
 *       que representa las unidades de ese número, en la componente
 *       naturalGrande[1], las decenas y así sucesivamente. Las componentes de
 *       índices superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «naturalGrande» tiene «NUM_DIGITOS»
 *       componentes.
 * Post: Devuelve el valor numérico del natural almacenado en «naturalGrande».
 */
unsigned valor(const unsigned naturalGrande[]) {
    // Por completar
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales. 
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así
 *       sucesivamente. Las componentes de índices superiores a los
 *       correspondientes a los dígitos más significativos almacenan el
 *       valor 0.
 *       Los vectores «a», «b» y «suma» tienen «NUM_DIGITOS» componentes.
 * Post: Si la suma de los naturales representados por «a» y «b» tiene
 *       «NUM_DIGITOS» o menos, tras ejecutarse este procedimiento, «suma»
 *       almacena la representación del número natural equivalente a la suma de
 *       los naturales representados por «a» y «b» y el valor de
 *       «desbordamiento» es «false». En el caso contrario, el valor de «suma»
 *       no está definido y el valor de «desbordamiento» es «true». 
 */
void sumar(const unsigned a[], const unsigned b[],
           unsigned suma[], bool &desbordamiento) {
    // Por completar
}


/*
 * Pre:  «a» almacena la representación de un número natural. La componente
 *       a[0] representa las unidades del natural «a», la componente a[1], las
 *       decenas y así sucesivamente. Las componentes de índices superiores a
 *       los correspondientes a los dígitos más significativos almacenan el
 *       valor 0.
 *       Los vectores «a» y «producto» tienen «NUM_DIGITOS» componentes.
 * Post: Si el producto de los naturales representados por «a» y el valor de
 *       «b» tiene «NUM_DIGITOS» o menos, tras ejecutarse este procedimiento,
 *       «producto» almacena la representación del número natural equivalente
 *       al producto de los naturales representados por «a» y el valor de «b» y
 *       el valor de «desbordamiento» es «false». En el caso contrario, el
 *       valor de «producto» no está definido y el valor de «desbordamiento»
 *       es «true».
 */
void multiplicar(const unsigned a[], const unsigned b,
                 unsigned producto[], bool &desbordamiento) {
    // Por completar
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0.
 *       «natural» e «imagen» tienen «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar este procedimiento, «imagen» almacena la representación
 *       del número natural correspondiente a la imagen especular de «natural».
 */
void calcularImagen(const unsigned natural[], unsigned imagen[]) {
    // Por completar
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0.
 *       «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Devuelve «true» si y solo si «natural» es un número capicúa.
 */
bool esCapicua(const unsigned natural[]) {
    // Por completar
}
