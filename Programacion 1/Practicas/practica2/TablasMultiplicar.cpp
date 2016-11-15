/*
 * Autores: Miguel Angel Latre y Javier Martinez
 * Ultima revisión: 20 de marzo de 2014
 * Resumen: Programa interactivo que presenta por pantalla las tablas de multiplicar 
 *          seleccionadas por el operador
 */
 
#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  Pre: ---
 *  Post: Presenta por pantalla la tabla de multiplicar del [n]
 *
 *        LA TABLA DEL n
 *        n x 0 = 0
 *        n x 1 = n
 *        n x 2 = ...
 *             ...
 *        n x 9 = ...
 *        n x 10 = ...
 */
void presentarTabla (const int n) {
    /*  Escribe el encabezamiento de la tabla de multiplicar del [n]  */
    cout << endl << "LA TABLA DEL " << n << endl;
     /*  Escribe las 11 lineas de la tabla de multiplicar del [n]  */
     for (int i=0; i<=10; ++i) {
         cout <<  setw(3) <<  n  << " x " <<  setw(2) << i  << " = " 
              <<  setw(3) <<  n*i << endl;
     }
}

/*
 *  Pre: ---
 *  Post: Pregunta reiteradamente al operador qué tabla de multiplicar desea y la escribe
 *        a continuación, salvo que su respuesta sea un 0, en cuyo caso el programa termina.
 */
int main() {
    /*  Plantea la primera pregunta al operador  */
    cout << "Que tabla desea escribir (0 para acabar): " << flush;
    /*  Asigna a [multiplicando] el primer valor entero escrito por el operador  */
    int multiplicando;
    cin  >>  multiplicando;
    /*  Itera hasta que el operador responda con un valor nulo  */
    while (multiplicando!=0) {
        /*  Ordena escribir por pantalla la tabla de multiplicar de [multiplicando]  */
        presentarTabla(multiplicando);
        /*  Plantea una nueva pregunta al operador */
        cout << endl << "Que tabla desea escribir (0 para acabar): " << flush;
        /*  Asigna a [multiplicando] el nuevo valor entero escrito por el operador  */
        cin  >>  multiplicando;
    }
    return 0;
}