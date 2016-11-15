
/*
 * Programador del módulo: Adrián Pérez Ortega
 * Fecha: 29 de noviembre de 2015
 */

/*
 * Fichero tiempo.cc de interfaz del módulo tiempo
 */

#include "tiempo.h"

/****************************************************************************
 * Funciones para definir el valor de un dato de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: seg >= 0
 * Post: Devuelve una medida de tiempo de seg segundos
 */
Tiempo definir (int seg){
	int s=seg;
	int h=0,m=0;
	int mil=0;
	while (s>59){
		s=s-60;
		m++;
		while(m>59){
			m=m-60;
			h++;			
		}
	}
	Tiempo nuevo={h,m,s,mil};
	return nuevo;
}

/*
 * Pre: seg >= 0, mil_seg >= 0 y mil_seg <= 999
 * Post: Devuelve una medida de tiempo de seg segundos y mil_seg milesimas
 *       de segundo
 */
Tiempo definir (int seg, int mil_seg){
	int s=seg;
	int h=0,m=0;
	while (s>59){
		s=s-60;
		m++;
		while(m>59){
			m=m-60;
			h++;			
		}
	}
	Tiempo nuevo={h,m,s,mil_seg};	
	return nuevo;
}

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
int hora (Tiempo t){
	return t.horas;
}

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de minutos m de la medida de tiempo t
 */
int minuto (Tiempo t){
	return t.minutos;
}

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de segundos s de la medida de tiempo t
 */
int segundo (Tiempo t){
	return t.segundos;
}

/*
 * Pre: t define una medida de tiempo no negativa con precisión de una milésima
 *      de segundo.
 *      Podemos imaginar a t equivalente a <h:m:s:mil>, donde h son horas (igual
 *      o mayor que 0), m son minutos (entre 0 y 59), s son segundos (entre 0 y 
 *      59) y mil son milésimas de segundo (entre 0 y 999)
 * Post: Devuelve el número de milésimas de segundos mil de la medida de tiempo t
 */
int milesima (Tiempo t){
	return t.milesimas;
}

/****************************************************************************
 *  Funciones para comparar dos datos de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo si el tiempo t1 es más corto que el tiempo t2
 */
bool esMenor (Tiempo t1, Tiempo t2){
	bool resultado=false;
	if (hora(t1)<hora(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)<minuto(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)==minuto(t2) && segundo(t1)<segundo(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)==minuto(t2) && segundo(t1)==segundo(t2) && milesima(t1)<milesima(t2)){
			resultado=true;
	}
	return resultado;
}

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo si el tiempo t1 es más largo que el tiempo t2
 */
bool esMayor (Tiempo t1, Tiempo t2){
	bool resultado=false;
	if (hora(t1)>hora(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)>minuto(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)==minuto(t2) && segundo(t1)>segundo(t2)){
			resultado=true;
	}
	else if (hora(t1)==hora(t2) && minuto(t1)==minuto(t2) && segundo(t1)==segundo(t2) && milesima(t1)>milesima(t2)){
			resultado=true;
	}
	return resultado;
}

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo
 * Post: Devuelve true si y sólo el valor del tiempo t1 es igual al del
 *       tiempo t2
 */
bool sonIguales (Tiempo t1, Tiempo t2){
	bool resultado=false;
	if (!esMayor(t1,t2) && !esMenor(t1,t2)){
		resultado=true;
	}
	return resultado;
}

/****************************************************************************
 * Funciones para operar aritméticamente con un par de datos de tipo Tiempo
 ****************************************************************************/

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo.
 * Post: Devuelve un tiempo igual a la suma de los tiempos t1 y t2
 */
Tiempo sumar (Tiempo t1, Tiempo t2){
	int h=0, m=0, s=0;
	int mil=milesima(t1)+milesima(t2);
	if (mil>999){
		mil-=1000;
		s++;
	}
	s=s+segundo(t1)+segundo(t2);
	while (s>59){
		s-=60;
		m++;		
	}
	m=m+minuto(t1)+minuto(t2);
	while (m>59){
		m-=60;
		h++;
	}
	h=h+hora(t1)+hora(t2);
	Tiempo nuevo={h,m,s,mil};
	return nuevo;
}

/*
 * Pre: t1 y t2 definen dos medidas de tiempo con precisión de una milésima
 *      de segundo, iguales o superiores a 0 milésimas de segundo. El valor
 *      de t1 es igual o superior al de t2.
 * Post: Devuelve un tiempo igual a la diferencia del tiempo t1 menos el
 *       tiempo t2
 */
Tiempo restar (Tiempo t1, Tiempo t2){
	int milesimasT=milesima(t1)-milesima(t2)+(segundo(t1)-segundo(t2))*1000+(minuto(t1)-minuto(t2))*60000+(hora(t1)-hora(t2))*3600000;
	int s=0, m=0, h=0;
	while(milesimasT>999){
		milesimasT-=1000;
		s++;
	}
	while(s>59){
		s-=60;
		m++;
	}
	while(m>59){
		m-=60;
		h++;
	}
	int mil=milesimasT;
	Tiempo nuevo={h,m,s,mil};
	return nuevo;
}
