
/*
 * Programador del módulo: Adrián Pérez Ortega
 * Fecha: 29 de noviembre de 2015
 */
 /*
  * Fichero herramientas.h de interfaz del módulo herramientas
  */

#ifndef HERRAMIENTAS_H

#define HERRAMIENTAS_H

#include "../ModTiempo/tiempo.h"               // el módulo tiempo
#include "../ModSubtitulo/subtitulo.h"         // el módulo subtitulo

/****************************************************************************
 * Funciones para trabajar con tablas de datos de tipo Tiempo
 ****************************************************************************/

void permutar (Tiempo& uno, Tiempo& otro);
/*
 * Pre: n >= 0 y T[0,n-1] almacena los valores de n medidas de tiempo.
 * Post: Los valores de T[0,n-1] han sido permutados de forma que ahora
 *       se encuentran ordenados según medidas de tiempo de duración
 *       igual o creciente. Es decir, el tiempo T[0] es igual o menor
 *       que el tiempo T[1], ..., y el tiempo T[n-2] es menor o igual
 *       que el tiempo T[n-1]
 */
void ordenar (Tiempo T[], const int n);

/*
 * Pre: El tiempo t es inferior a 100 horas
 * Post: Escribe por pantalla una secuencia de 12 caracteres (y sin 
 *       acabar la línea) en la que presenta el tiempo definido por t 
 *       con el siguiente formato:
 *       hh:mm:ss,mmm
 *       Un ejemplo:
 *       07:30:00,055
 */
void mostrar (const Tiempo t);

/*
 * Pre: Los tiempos almacenados en T[0,n-1] son inferiores a 100 horas
 * Post: Escribe por pantalla n líneas en las que presenta los valores de 
 *       los tiempos almacenados en T[0,n-1] con el siguiente formato  
 *       (cadauno de los tiempos ocupa 12 caracteres):
 *       01. 03:12:00,500
 *       02. 12:45;30,000
 *       03. 00:01:00,450
 *            ....
 */
void mostrar (const Tiempo T[], const int n);



/****************************************************************************
 * Funciones para trabajar con datos de tipo Subtitulo y con ficheros que 
 * almacenan subtítulos en formato 'subrip'
 ****************************************************************************/

/*
 * Pre: El fichero nombreFichero almacena subtítulos en formato 'subrip'
 * Post: Si el fichero nombreFichero es accesible y puede leerse, entonces 
 *       devuelve el número de subtítulos que almacena, en caso contrario 
 *       devuelve un número negativo
 */
int contarSubtitulos (const char nombreFichero[]);

/*
 * Pre: El fichero nombreFichero almacena subtítulos en formato 'subrip'
 * Post: Almacena en la tabla S, a partir del elemento S[0], todos los
 *       subtitulos del  fichero nombreFichero en el mismo orden en
 *       que estaban en el fichero
 */
void leerSubtitulos (const char nombreFichero[], Subtitulo S[]);

/*
 * Pre: ---
 * Post: Presenta por pantalla el subtítulo S. En una primera línea su
 *       número, tiempo de comienzo y de finalización. En líneas sucesivas 
 *       su texto. El formato empleado es el siguiente:
 * 
 *       183. 01:53:08,000 - 01:53:07,500
 *       Primera linea del texto del subtitulo
 *       Siguiente linea del texto del subtitulo
 *           .   .   .
 *       Ultima linea del texto del subtitulo
 */
void mostrar (Subtitulo S);

/*
 * Pre: TS[0,total-1] almacena un número de subtitulos igual a total,
 *      total >= 0, i >= 1 y j <= total
 * Post: Presenta por pantalla un listado de los subtítulos almacenados
 *       en TS que van desde el i-ésimo hasta el j-ésimo, siendo TS[0]
 *       el primero, TS[1] el segundo y así sucesivamente. Dos subtitulos 
 *       consecutivos se separan mediante una línea en blanco.
 */
void mostrar (const Subtitulo TS[], const int total, int i, int j);

#endif