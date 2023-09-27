/******************************************************************************\
 * Programación 1. Práctica 4
 * Autor: Miguel Ángel Latre Abadía
 * Ultima revisión: 2 de noviembre de 2022
 * Resumen: Fichero de implementación «naturales-grandes-test.cpp» de un módulo
 *          denominado «naturales-grandes-test» para hacer de pruebas de las 
 *          funciones definidas en el módulo «naturales-grandes» de la 4.ª 
 *          práctica.
\******************************************************************************/

#include <iostream>
#include <string>
#include "testing-prog1.hpp"
#include "naturales-grandes.hpp"
using namespace std;

/******************************************************************************\
 * Funciones para probar las funciones nuevas de la biblioteca «calculos» 
 *                                                                        
 * (Para escribir estas funciones, no se han utilizado conceptos de C++    
 * que no se hayan visto en la asignatura, excepto en las función de conversión 
 * de cadena de caracteres a «natural grande» y viceversa, cuyos fundamentos se
 * verán en el tema 10 sobre cadenas de caracteres)                                
 ******************************************************************************/

/* 
 * Constante con la que se inicializan las NUM_DIGITOS componentes de un vector que
 * representa números grandes, con el objetivo de maximizar las posibilidades de
 * localizar errores. El valor elegido provoca que cuando «numeroGrande» sea 
 * convertido a «string», los valores no inicializados por la función objeto de
 * pruebas se muestren con el carácter '?'
 */
const unsigned VALOR_INDEFINIDO = '?' - '0';


/*
 * Pre:  «numero» almacena la representación de un número natural. Sea «n» el 
 *       número de dígitos de «numero». La componente numero[0] representa las  
 *       unidades de «numero», la componente numero[1] las decenas de «numero» 
 *       y así, sucesivamente, la componente numero[s-1] representa el dígito 
 *       más significativo de «numero». Las componentes de índices superiores
 *       almacenan el valor 0.
 * Post: Devuelve una cadena de caracteres que representa el número natural
 *       representado por «numero» (sin ceros a la izquierda).
 */
string convertirAString(const unsigned numero[]) {
    int i = NUM_DIGITOS - 1;
    while (i >= 0 && numero[i] == 0) {
        i--;
    }
    if (i < 0) {
        return "0";
    } else {
        string resultado = "";
        resultado.reserve(NUM_DIGITOS);
        while (i >= 0) {
            if (numero[i] <= 9 || numero[i] == VALOR_INDEFINIDO) {
                resultado += numero[i] + '0';
            } else {
                resultado += '(' + to_string(numero[i]) + ')';
            }
            i--;
        }
        return resultado;
    }
}


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo).
 * Post: Tras ejecutar este procedimiento, «numeroGrande» contiene la secuencia
 *       de dígitos equivalente a la de número «numero». Sea «n» el número de
 *       dígitos de «numero». La componente numeroGrande[0] almacena las 
 *       unidades de «numero», la componente numeroGrande[1], las decenas de 
 *       «numero» y así, sucesivamente, la componente numeroGrande[n-1] almacena  
 *       el dígito más significativo de «numero». Las componentes de índices 
 *       superiores almacenan el valor 0
 */
void convertirDeString(const string numeroStr, unsigned numeroGrande[]) {
    for(unsigned i = 0; i < numeroStr.length(); i++) {
        numeroGrande[numeroStr.length() - i - 1] = numeroStr.at(i) - '0';
    }
    for (unsigned i = numeroStr.length(); i < NUM_DIGITOS; i++) {
        numeroGrande[i] = 0;
    }
}


/*
 * Pre:  El vector «testigo» tiene «NUM_DIGITOS» componentes.
 * Post: Devuelve «true» si y solo si las «NUM_DIGITOS» componentes del vector
 *       «testigo» almacenan el valor de la constante «VALOR_INDEFINIDO».
 */
bool comprobarTestigo(const unsigned testigo[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++) {
        if (testigo[i] != VALOR_INDEFINIDO) {
            return false;
        }
    }
    return true;
}


/*
 * Pre:  En la línea actual de la pantalla se ha escrito un texto anunciando que
 *       se ha realizado una prueba de una determinada función con unos
 *       determinados argumentos.
 * Post: Si los valores de «valorEsperado» y «valorCalculado» son iguales y todas las
 *       componentes de los vectores «testigo1» y «testigo2» almacenan el valor de la
 *       constante «VALOR_INDEFINIDO», completa un mensaje de la pantalla informando
 *       de que la prueba es correcta. En el caso de que alguna componente de los
 *       vectores «testigo1» y «testigo2» almacene un valor distinto al de la 
 *       constante «VALOR_INDEFINIDO», completa el mensaje de la pantalla indicando
 *       que, pese a que el valor calculado por la función objeto de pruebas sea
 *       correcto, esta ha modificado memoria fuera de los límites del vector.
 *       En el caso de que los valores de «valorEsperado» y «valorCalculado» no sean
 *       iguales, completa el mensaje de la pantalla indicando que la prueba
 *       realizada es incorrecta e informa también de los valores de «valorEsperado»
 *       y «valorCalculado».
 */
void escribirResultadoPrueba(const string valorEsperado, const string valorCalculado,
                             const unsigned testigo1[], const unsigned testigo2[]) {
    if (valorEsperado == valorCalculado) {
        if (comprobarTestigo(testigo1) && comprobarTestigo(testigo2)) {
            cout << "correcta." << endl;
        } else {
            cout << "incorrecta: el valor calculado es el correcto, pero ha "
                 << "modificado memoria fuera de los límites del vector. " << endl;
        }
    } else {
        escribirResultadoPrueba(valorEsperado, valorCalculado);
    }
}


/*
 * Pre:  En la línea actual de la pantalla se ha escrito un texto anunciando que
 *       se ha realizado una prueba de una determinada función con unos
 *       determinados argumentos.
 * Post: Si los valores de «valorEsperado» y «valorCalculado» son iguales y todas las
 *       componentes de los vectores «testigo1» y «testigo2» almacenan el valor de la
 *       constante «VALOR_INDEFINIDO», completa un mensaje de la pantalla informando
 *       de que la prueba es correcta. En el caso de que alguna componente de los
 *       vectores «testigo1» y «testigo2» almacene un valor distinto al de la 
 *       constante «VALOR_INDEFINIDO», completa el mensaje de la pantalla indicando
 *       que, pese a que el valor calculado por la función objeto de pruebas sea
 *       correcto, esta ha modificado memoria fuera de los límites del vector.
 *       En el caso de que los valores de «valorEsperado» y «valorCalculado» no sean
 *       iguales, completa el mensaje de la pantalla indicando que la prueba
 *       realizada es incorrecta e informa también de los valores de «valorEsperado»
 *       y «valorCalculado».
 */
void escribirResultadoPrueba(const bool valorEsperado, const bool valorCalculado,
                             const unsigned testigo1[], const unsigned testigo2[]) {
    if (valorEsperado == valorCalculado) {
        if (comprobarTestigo(testigo1) && comprobarTestigo(testigo2)) {
            cout << "correcta." << endl;
        } else {
            cout << "incorrecta: el valor calculado es el correcto, pero ha "
                 << "modificado memoria fuera de los límites del vector. " << endl;
        }
    } else {
        escribirResultadoPrueba(valorEsperado, valorCalculado);
    }
}


/*
 * Pre:  ---
 * Post: Inicializa las NUM_DIGITOS componentes de «numeroGrande» con un valor
 *       conocido para maximizar las posibilidades de localizar errores.
 *       El valor elegido provoca que cuando «numeroGrande» sea convertido a
 *       «string», los valores no inicializados por la función objeto de pruebas
 *       se muestren con el carácter '?'
 */
void inicializar(unsigned numeroGrande[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++) {
        numeroGrande[i] = VALOR_INDEFINIDO;
    }
}


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
void probarConvertir(const unsigned n, const string valorEsperado) {
    cout << "Prueba convertir (" << n << ", unsigned[]) ";
    unsigned testigo1[NUM_DIGITOS], valorCalculado[NUM_DIGITOS], testigo2[NUM_DIGITOS];
    inicializar(valorCalculado);
    inicializar(testigo1);
    inicializar(testigo2);
    convertir(n, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado), testigo1, testigo2);
}


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
                 const string valorEsperado) {
    cout << "Prueba sumar (" << aStr << ", " << bStr << ", unsigned[]) ";
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS], testigo1[NUM_DIGITOS], 
             valorCalculado[NUM_DIGITOS], testigo2[NUM_DIGITOS];
    convertirDeString(aStr, a);
    convertirDeString(bStr, b);
    inicializar(valorCalculado);
    inicializar(testigo1);
    inicializar(testigo2);
    sumar(a, b, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado), testigo1, testigo2);
}


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
void probarValor(const string numero, const unsigned valorEsperado) {
   cout << "Prueba valor(" << numero << ") ";
   unsigned numeroGrande[NUM_DIGITOS];
   convertirDeString(numero, numeroGrande);
   unsigned valorDevuelto = valor(numeroGrande);
   escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


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
void probarCalcularImagen(const string numero, const string valorEsperado) {
    cout << "Prueba calcularImagen (" << numero << ", unsigned[]) ";
    unsigned numeroGrande[NUM_DIGITOS], testigo1[NUM_DIGITOS], 
             valorCalculado[NUM_DIGITOS], testigo2[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    inicializar(valorCalculado);
    inicializar(testigo1);
    inicializar(testigo2);
    calcularImagen(numeroGrande, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado), testigo1, testigo2);
}


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
void probarEsCapicua(const string numero, const bool valorEsperado) {
    cout << "Prueba esCapicua (" << numero << ") ";
    unsigned testigo1[NUM_DIGITOS], numeroGrande[NUM_DIGITOS], testigo2[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    inicializar(testigo1);
    inicializar(testigo2);
    bool valorCalculado = esCapicua(numeroGrande);
    escribirResultadoPrueba(valorEsperado, valorCalculado, testigo1, testigo2);
}


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
void probarCopiar(const string numeroStr) {
    cout << "Prueba copiar (" << numeroStr << ", unsigned[]) ";
    unsigned numeroGrande[NUM_DIGITOS], testigo1[NUM_DIGITOS], 
             valorCalculado[NUM_DIGITOS], testigo2[NUM_DIGITOS];
    convertirDeString(numeroStr, numeroGrande);
    inicializar(valorCalculado);
    inicializar(testigo1);
    inicializar(testigo2);
    copiar(numeroGrande, valorCalculado);
    escribirResultadoPrueba(convertirAString(numeroGrande),
                            convertirAString(valorCalculado), testigo1, testigo2);
}


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
                      const bool valorEsperado) {
    cout << "Prueba sonIguales (" << aStr << ", " << bStr << ") ";
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS];
    convertirDeString(aStr, a);
    convertirDeString(bStr, b);
    bool valorCalculado = sonIguales(a, b);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
}


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
void probarNumCifras(const string numero, const unsigned valorEsperado) {
    cout << "Prueba numCifras (" << numero << ") ";
    unsigned numeroGrande[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    unsigned valorCalculado = numCifras(numeroGrande);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
}
