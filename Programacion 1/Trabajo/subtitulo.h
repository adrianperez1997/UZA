/*
 * Programadores del módulo: J. Martínez y M.A. Latre
 * Fecha: 27 de octubre de 2015
 */
 
/*
 * Fichero subtitulo.h de interfaz del módulo subtitulo
 */
 
#ifndef SUBTITULO_H

#define SUBTITULO_H

//#include "../ModTiempo/tiempo.h"         // el módulo tiempo
#include "tiempo.h"         // el módulo tiempo

using namespace std;

// Número máximo de líneas del texto de un subtítulo
const int MAX_LINEAS = 3;
// Número máximo de caracteres por línea en un subtítulo         
const int MAX_LONG_LINEA = 80;    

/*
 * Un dato de tipo Subtitulo permite representar un subtítulo con su
 * información asociada (número del subtítulo, su texto, y el tiempo 
 * inicial y final de su proyección)
 */
struct Subtitulo {
   int numero;                // número del subtítulo
   int numLineasTexto;        // su número de líneas
   char texto[MAX_LINEAS][MAX_LONG_LINEA];    // cada una de sus líneas
   Tiempo inicio, fin;        // tiempo del inicio y fin de su proyección
};

/****************************************************************************
 * Función para definir el valor de un dato de tipo Subtitulo
 ****************************************************************************/
				   
/*
 * Pre: num >= 1, nLineas >= 0
 * Post: Devuelve un subtítulo cuyo número es num, cuenta con un texto
 *       con nLineas líneas, iguales a las almacenadas en texto[0,nLineas-1],
 *       el instante del comienzo de su proyección es igual a t_inicio
 *       y el instante del final de su proyección es igual a t_fin
 */
Subtitulo definir (int num, int nLineas, char texto[][MAX_LONG_LINEA],  
                   Tiempo t_inicio, Tiempo t_fin);

/****************************************************************************
 *  Funciones para conocer los detalles de un dato de tipo Subtitulo:
 *  su número, su texto, su comienzo y su final 
 ****************************************************************************/

/*
 * Pre: ---
 * Post: Devuelve el número del subtítulo S
 */
int numero (Subtitulo S);

/*
 * Pre: ---
 * Post: Asigna a nLineas el número de líneas del subtítulo S y a 
 *       texto[0,nLineas-1] el contenido de cada una de esas líneas
 */
void texto (Subtitulo S, int& nLineas, char texto[][MAX_LONG_LINEA]);

/*
 * Pre: ---
 * Post: Devuelve el tiempo del comienzo de la proyección del 
 *       subtítulo S
 */
Tiempo principio (Subtitulo S);
 
/*
 * Pre: ---
 * Post: Devuelve el tiempo del final de la proyección del
 *       subtítulo S
 */
Tiempo fin (Subtitulo S);

#endif