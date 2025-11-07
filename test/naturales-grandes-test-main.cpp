/******************************************************************************
 * Programación 1. Práctica 4
 * Autores: Miguel Ángel Latre
 * Última revisión: 23 de octubre de 2024
 * Resumen: Programa de pruebas del módulo «naturales-grandes» de la 4.ª 
 *          práctica.
 * Nota: Para facilitar la escritura de este programa de pruebas, los números
 *       grandes se han expresado como cadenas de caracteres. Las funciones 
 *       «convertirAString» y «convertirDeString» del módulo 
 *       «naturales-grandes-test» convierten estas cadenas de caracteres a los
 *       vectores de enteros sin signo que se utilizan en el módulo
 *       «naturales-grandes».
 *****************************************************************************/

#include <iostream>
#include "naturales-grandes-test.hpp"
#include "testing-prog1.hpp"
using namespace std;


/* 
 * Programa que prueba las funciones de la biblioteca «naturales-grandes»
 */
int main() {
    bool todoOk = true;

    probarCopiar("0", todoOk);
    probarCopiar("1", todoOk);
    probarCopiar("123", todoOk);
    probarCopiar("123456789012345678901234567890123456789012345678901234567890",
                 todoOk);
    probarCopiar(milNueves(), todoOk);

    probarSonIguales("0", "0", true, todoOk);
    probarSonIguales("0", "1", false, todoOk);
    probarSonIguales("1", "0", false, todoOk);
    probarSonIguales("4444", "4444", true, todoOk);
    probarSonIguales("1444", "4444", false, todoOk);
    probarSonIguales("4444", "1444", false, todoOk);
    probarSonIguales("4144", "4444", false, todoOk);
    probarSonIguales("4414", "4444", false, todoOk);
    probarSonIguales("4441", "4444", false, todoOk);
    probarSonIguales("1234567890", "1234567890", true, todoOk);
    probarSonIguales("12345678901234567890", "1234567890", false, todoOk);
    probarSonIguales("1234567890", "12345678901234567890", false, todoOk);
    probarSonIguales("1234567890123456789012345678901234567890", 
                     "1234567890123456789012345678901234567890", true, todoOk);
    probarSonIguales("123456789012345678901234567890123456789012345678901234567890", 
                     "1234567890123456789012345678901234567890", false,
                     todoOk);
    probarSonIguales("1234567890123456789012345678901234567890", 
                     "123456789012345678901234567890123456789012345678901234567890",
                     false, todoOk);
    probarSonIguales(milNueves(), milNueves(), true, todoOk);
    probarSonIguales(milNueves(), "999999999999999999999999", false, todoOk);
    probarSonIguales("999999999999999999999999", milNueves(), false, todoOk);

    probarNumCifras("0", 1, todoOk);
    probarNumCifras("1", 1, todoOk);
    probarNumCifras("9", 1, todoOk);
    probarNumCifras("10", 2, todoOk);
    probarNumCifras("99", 2, todoOk);
    probarNumCifras("100", 3, todoOk);
    probarNumCifras("123456789", 9, todoOk);
    probarNumCifras("123456789012345678901234567890", 30, todoOk);
    probarNumCifras("12345678901234567890123456789012345678901234567890", 50,
                    todoOk);
    probarNumCifras(milNueves(), 1000, todoOk);

    probarConvertir(0, "0", todoOk);
    probarConvertir(1, "1", todoOk);
    probarConvertir(902, "902", todoOk);
    probarConvertir(10015, "10015", todoOk);
    probarConvertir(27043573, "27043573", todoOk);
    probarConvertir(4294967295, "4294967295", todoOk);

    probarValor("0", 0, todoOk);
    probarValor("7", 7, todoOk);
    probarValor("18", 18, todoOk);
    probarValor("903", 903, todoOk);
    probarValor("100670", 100670, todoOk);
    probarValor("123456789", 123456789, todoOk);
    probarValor("4294967295", 4294967295, todoOk);

    // Elemento neutro
    probarSumar("0", "0", "0", false, todoOk);
    probarSumar("132", "0", "132", false, todoOk);
    probarSumar("0", "132", "132", false, todoOk);
    probarSumar("0", "335", "335", false, todoOk);
    probarSumar("335", "0", "335", false, todoOk);
    // Sumas sin llevar
    probarSumar("802", "100", "902", false, todoOk);
    probarSumar("100", "802", "902", false, todoOk);
    probarSumar("802", "10", "812", false, todoOk);
    probarSumar("10", "802", "812", false, todoOk);
    // Con acarreo
    probarSumar("8", "8", "16", false, todoOk);
    probarSumar("108", "108", "216", false, todoOk);
    probarSumar("189", "21", "210", false, todoOk);
    probarSumar("21", "189", "210", false, todoOk);
    probarSumar("9999", "1", "10000", false, todoOk);
    probarSumar("1", "9999", "10000", false, todoOk);
    // De más de 20 dígitos
    // (no representables como unsigned ni como unsigned long long)
    probarSumar("123412345678901234567890", "10", "123412345678901234567900",
                false, todoOk);
    probarSumar("10", "123412345678901234567890", "123412345678901234567900",
                false, todoOk);
    probarSumar("999999999999999999999999", "1", "1000000000000000000000000",
                false, todoOk);
    probarSumar("1", "999999999999999999999999", "1000000000000000000000000",
                false, todoOk);
    // Con desbordamiento
    probarSumar(milNueves(), "1",
                "No importa la suma porque hay desbordamiento", true, todoOk);
    probarSumar("1", milNueves(),
                "No importa la suma porque hay desbordamiento", true, todoOk);
    // Sin desbordamiento
    probarSumar(milNueves(), "0", milNueves(), false, todoOk);
    probarSumar("0", milNueves(), milNueves(), false, todoOk);

    // Multiplicaciones por 0
    probarMultiplicar("0", 0, "0", false, todoOk);
    probarMultiplicar("42", 0, "0", false, todoOk);
    probarMultiplicar("0", 42, "0", false, todoOk);
    // Elemento neutro
    probarMultiplicar("1", 1, "1", false, todoOk);
    probarMultiplicar("132", 1, "132", false, todoOk);
    probarMultiplicar("1", 132, "132", false, todoOk);
    // Multiplicaciones sin llevar
    probarMultiplicar("2", 3, "6", false, todoOk);
    probarMultiplicar("3", 2, "6", false, todoOk);
    probarMultiplicar("99", 9, "891", false, todoOk);
    probarMultiplicar("9", 99, "891", false, todoOk);
    probarMultiplicar("402", 2, "804", false, todoOk);
    probarMultiplicar("1001", 9, "9009", false, todoOk);
    // Con acarreo
    probarMultiplicar("3", 4, "12", false, todoOk);
    probarMultiplicar("4", 3, "12", false, todoOk);
    probarMultiplicar("3", 10, "30", false, todoOk);
    probarMultiplicar("10", 3, "30", false, todoOk);
    probarMultiplicar("12", 12, "144", false, todoOk);
    probarMultiplicar("14", 16, "224", false, todoOk);
    probarMultiplicar("16", 14, "224", false, todoOk);
    probarMultiplicar("9365", 8742, "81868830", false, todoOk);
    probarMultiplicar("8742", 9365, "81868830", false, todoOk);
    probarMultiplicar("2", 402, "804", false, todoOk);
    probarMultiplicar("9", 1001, "9009", false, todoOk);
    // De más de 20 dígitos (no representables como unsigned ni como
    // unsigned long long)
    probarMultiplicar("123412345678901234567890", 10,
                      "1234123456789012345678900", false, todoOk);
    probarMultiplicar("999999999999999999999999", 1,
                      "999999999999999999999999", false, todoOk);
    probarMultiplicar("12341234567890123456", 12345678,
                      "15241383936t691200560112896", false, todoOk);
    // Con desbordamiento
    probarMultiplicar(milNueves(), 2,
                      "No importa el producto porque hay desbordamiento", true,
                      todoOk);
    // Sin desbordamiento
    probarMultiplicar(milNueves(), 1, milNueves(), false, todoOk);
    probarMultiplicar(milNueves(), 0, "0", false, todoOk);

    probarCalcularImagen("0", "0", todoOk);
    probarCalcularImagen("1", "1", todoOk);
    probarCalcularImagen("18", "81", todoOk);
    probarCalcularImagen("903", "309", todoOk);
    probarCalcularImagen("92719", "91729", todoOk);
    probarCalcularImagen("123456789", "987654321", todoOk);
    probarCalcularImagen("1030507090", "907050301", todoOk);
    probarCalcularImagen("123412345678901234567890", "98765432109876543214321",
                         todoOk);
    probarCalcularImagen(milNueves(), milNueves(), todoOk);

    probarEsCapicua("0", true, todoOk);
    probarEsCapicua("1", true, todoOk);
    probarEsCapicua("10", false, todoOk);
    probarEsCapicua("11", true, todoOk);
    probarEsCapicua("100", false, todoOk);
    probarEsCapicua("101", true, todoOk);
    probarEsCapicua("91718", false, todoOk);
    probarEsCapicua("91719", true, todoOk);
    probarEsCapicua("92719", false, todoOk);
    probarEsCapicua("12341234567890123456789", false, todoOk);
    probarEsCapicua("123412345678909876543214321", true, todoOk);
    probarEsCapicua(milNueves(), true, todoOk);
    
    escribirMensajeFinal(todoOk);
    if (todoOk) {
        return 0;
    } else {
        return 1;
    }
}
