/*
 * Programadores del módulo: J. Martínez y M.A. Latre
 * Fecha: 27 de octubre de 2015
 */
 
/*
 * Fichero subtitulo.h de interfaz del módulo subtitulo
 */
 
#include <iostream>
#include "subtitulo.h"
//#include "../ModTiempo/tiempo.h"         // el módulo tiempo
#include "tiempo.h"         // el módulo tiempo

using namespace std;
 


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
                   Tiempo t_inicio, Tiempo t_fin){
   Subtitulo nuevo;
   nuevo.numero=num;
   nuevo.numLineasTexto=nLineas;
   for(int i=0;i<MAX_LINEAS;i++){
	   for(int j=0;j<MAX_LONG_LINEA;j++){
            nuevo.texto[i][j]=texto[i][j];
			}
		};
   nuevo.inicio=t_inicio;
   nuevo.fin=t_fin;
   return nuevo;
}

/****************************************************************************
 *  Funciones para conocer los detalles de un dato de tipo Subtitulo:
 *  su número, su texto, su comienzo y su final 
 ****************************************************************************/

/*
 * Pre: ---
 * Post: Devuelve el número del subtítulo S
 */
int numero (Subtitulo S) {
	return S.numero;
}

/*
 * Pre: ---
 * Post: Asigna a nLineas el número de líneas del subtítulo S y a 
 *       texto[0,nLineas-1] el contenido de cada una de esas líneas
 */
void texto (Subtitulo S, int& nLineas, char texto[][MAX_LONG_LINEA]){
	nLineas= S.numLineasTexto;
    for(int i=0;i<nLineas;i++){
	   for(int j=0;j<MAX_LONG_LINEA;j++){
            texto[i][j]=S.texto[i][j];
			}
		};
}

/*
 * Pre: ---
 * Post: Devuelve el tiempo del comienzo de la proyección del 
 *       subtítulo S
 */
Tiempo principio (Subtitulo S){
	return S.inicio;
}
 
/*
 * Pre: ---
 * Post: Devuelve el tiempo del final de la proyección del
 *       subtítulo S
 */
Tiempo fin (Subtitulo S){
	return S.fin;
}
