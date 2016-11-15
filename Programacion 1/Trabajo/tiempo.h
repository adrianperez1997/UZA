
/*
 * Programador del módulo: Adrián Pérez Ortega
 * Fecha: 29 de noviembre de 2015
 */
/*
 * Fichero tiempo.c de interfaz del módulo tiempo
 */

#ifndef TIEMPO_H

#define TIEMPO_H

/*
 * Un dato de tipo Tiempo permite representar una medida de tiempo,
 * no negativa, con una precisión de una milésima de segundo
 */
struct Tiempo {
	int horas;
	int minutos;
	int segundos;
	int milesimas;
};

/****************************************************************************
 * Funciones para definir el valor de un dato de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: seg >= 0
 * Post: Devuelve una medida de tiempo de seg segundos
 */
Tiempo definir (int seg);

/*
 * Pre: seg >= 0, mil_seg >= 0 y mil_seg <= 999
 * Post: Devuelve una medida de tiempo de seg segundos y mil_seg milesimas
 *       de segundo
 */
Tiempo definir (int seg, int mil_seg);

/****************************************************************************
 *  Funciones para conocer la descomposición de un dato de tipo Tiempo
 *  en horas, minutos, segundos y milésimas de segundo
 ****************************************************************************/

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de horas h de la medida de tiempo t
 */
int hora (Tiempo t);

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de minutos m de la medida de tiempo t
 */
int minuto (Tiempo t);

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de segundos s de la medida de tiempo t
 */
int segundo (Tiempo t);

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de milésimas de segundos mil de la medida de tiempo t
 */
int milesima (Tiempo t);

/****************************************************************************
 *  Funciones para comparar dos datos de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo si el tiempo t1 es más corto que el tiempo t2
 */
bool esMenor (Tiempo t1, Tiempo t2);

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo si el tiempo t1 es más largo que el tiempo t2
 */
bool esMayor (Tiempo t1, Tiempo t2);

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo el valor del tiempo t1 es igual al del
 *       tiempo t2
 */
bool sonIguales (Tiempo t1, Tiempo t2);

/****************************************************************************
 * Funciones para operar aritméticamente con un par de datos de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo.
 * Post: Devuelve un tiempo igual a la suma de los tiempos t1 y t2
 */
Tiempo sumar (Tiempo t1, Tiempo t2);

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo. El valor
 *      de t1 es igual o superior al de t2.
 * Post: Devuelve un tiempo igual a la diferencia del tiempo t1 menos el
 *       tiempo t2
 */
Tiempo restar (Tiempo t1, Tiempo t2);

#endif