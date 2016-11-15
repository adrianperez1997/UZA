/*
 * Fichero calculadoraEnteros.cc que almacena el módulo principal del programa
 */

#include <iostream>
#include "calculos.h"

using namespace std;

/*
 *  Pre: ---
 *  Post: Presenta el menu de opciones disponibles
 */
void presentarMenu () {
    cout << "\nMENU DE OPERACIONES\n===================" << endl;
    cout << "0 - Finalizar" << endl;
    cout << "1 - Calcular el numero de cifras de un entero" << endl;
    cout << "2 - Sumar las cifras de un entero" << endl;
    cout << "3 - Extraer una cifra de un entero" << endl;
    cout << "4 - Calcular la imagen especular de un entero" << endl;
    cout << "5 - Comprobar si un entero es primo" << endl << endl;
}

/*
 *  Pre: ---
 *  Post: Ejecuta las acciones asociadas a la orden cuyo código es [operación]
 */
void ejecutarOrden (int operacion) {
   if (operacion >= 1 && operacion <= 5) {
      /*
       * Se va a ejcutar una operación válida. En primer lugar se pide al operador
       * que defina un número entero
       */
      int numero;
      cout << "Escriba un numero entero : " << flush;
      cin >> numero;
      if (operacion==1) {
         /*  Informa del número de cifras de [numero]  */
         cout << "El numero " << numero << " tiene " << numCifras(numero)
              << " cifras" << endl;
      }
      else if (operacion==2) {
         /*  Informa de la suma de las cifras de [numero]  */
         cout << "Las cifras de " << numero << " suman " << sumaCifras(numero) << endl;
      }
      else if (operacion==3) {
         /*  El operador debe definir la posición de una cifra de [número]  */
         int posicion;
         cout << "Seleccione la posicion de una cifra: " << flush;
         cin >> posicion;
         /*  Informa del valor de la cifra ubicada en [posición] de [numero]  */
         cout << "La cifra situada en la posicion " << posicion << " del numero "
              <<  numero << " es " << cifra(numero, posicion) << endl;
      }
      else if (operacion==4) {
         /*  Informa del valor de la imagen especular de [numero]  */
         cout << "El numero imagen especular del " << numero << " es el " 
              << imagen(numero) << endl;
      }
      else if (operacion==5) {
         /*  Informa si [numero] es un número primo o no lo es  */
         cout << "El numero " << numero;
         if (!esPrimo(numero)) {  cout << " no";   }
            cout << " es primo" << endl;
         }
   }
   else {
      /*  El código de operación no es válido  */
      cout << "Opción desconocida" << endl;
   }
}

/*
 *  Plantea al operador de forma reiterada un menú con varias opciones, lee
 *  la respuesta del operador y presenta los resultados de ejecutar la opción
 *  elegida. Concluye cuando el operador selecciona la opción [0]
 */
int main () {
    /*
     *  Presenta por primera vez el menú de opciones y lee la respuesta del operador
     */
    presentarMenu();
    int operacion;
    cout << "Seleccione una operacion [0-5]: " << flush;
    cin >> operacion;
    /*
     *  Itera hasta que el valor de [opcion] sea igual a 0
     */
     while (operacion!=0) {
          /*
           * Ejecuta la última operación seleccionada
           */
          ejecutarOrden(operacion);
          /*
           *  Presenta de nuevo el menú de opciones
           */
          presentarMenu();
          /*
           *  Lee la respuesta del operador
           */
          cout << "\nSeleccione una operacion [0-5]: " << flush;
          cin >> operacion;
     }
}