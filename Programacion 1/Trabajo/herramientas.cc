
/*
 * Programador del módulo: Adrián Pérez Ortega
 * Fecha: 29 de noviembre de 2015
 */
 /*
  * Fichero herramientas.h de interfaz del módulo herramientas
  */
#include <iostream>
#include <iomanip>
#include "../ModTiempo/tiempo.h"           // el módulo tiempo
//#include "tiempo.h"           // el módulo tiempo
#include "herramientas.h"           // el módulo herramientas
#include <fstream>
#include "../ModSubtitulo/subtitulo.h"
using namespace std;

/****************************************************************************
 * Funciones para trabajar con tablas de datos de tipo Tiempo
 ****************************************************************************/

void permutar (Tiempo& uno, Tiempo& otro){
	Tiempo aux=uno;
	uno=otro;
	otro=aux;
}
/*
 * Pre: n >= 0 y T[0,n-1] almacena los valores de n medidas de tiempo.
 * Post: Los valores de T[0,n-1] han sido permutados de forma que ahora
 *       se encuentran ordenados según medidas de tiempo de duración
 *       igual o creciente. Es decir, el tiempo T[0] es igual o menor
 *       que el tiempo T[1], ..., y el tiempo T[n-2] es menor o igual
 *       que el tiempo T[n-1]
 */
void ordenar (Tiempo T[], const int n){
	int iMin;
	for(int i=0; i<n; i++){
		iMin=i;
		for(int j=i+1; j<n; j++){
			if(esMenor(T[j],T[iMin])){
			iMin=j;
			}
		}
		permutar(T[iMin], T[i]);
	}
}

/*
 * Pre: El tiempo t es inferior a 100 horas
 * Post: Escribe por pantalla una secuencia de 12 caracteres (y sin 
 *       acabar la línea) en la que presenta el tiempo definido por t 
 *       con el siguiente formato:
 *       hh:mm:ss,mmm
 *       Un ejemplo:
 *       07:30:00,055
 */

void mostrar (const Tiempo t){
	cout<<setfill('0')<<setw(2)<<hora(t)<<":"<<setfill('0')<<setw(2)<<minuto(t)<<":"<<setfill('0')<<setw(2)<<segundo(t)<<","<<setfill('0')<<setw(3)<<milesima(t);
	}

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
void mostrar (const Tiempo T[], const int n){
	int i=0;
	while (i<n){
		cout<<setfill('0')<<setw(2)<<i+1<<". "<<setfill('0')<<setw(2)<<hora(T[i])<<":"<<setfill('0')
		<<setw(2)<<minuto(T[i])<<":"<<setfill('0')<<setw(2)<<segundo(T[i])<<","<<setfill('0')<<setw(3)
		<<milesima(T[i])<<endl;
		i++;
	}
}
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
int contarSubtitulos (const char nombreFichero[]){
	int subtitulos=0;
	ifstream f;
	f.open(nombreFichero);
	const int MAX=128;
	char linea[MAX];
	if(f.is_open()){
		while(!f.eof()){
			f.getline(linea,MAX);
			if ((int)linea[0]==0){
				f.getline(linea,MAX);
				if ((int)linea[0]!=0){subtitulos++;}
			}
		}
		subtitulos++;
		f.close();
	}
	else if(!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombreFichero<<endl;
		subtitulos=-1;
	}
	return subtitulos;
}

/*
 * Pre: El fichero nombreFichero almacena subtítulos en formato 'subrip'
 * Post: Almacena en la tabla S, a partir del elemento S[0], todos los
 *       subtitulos del  fichero nombreFichero en el mismo orden en
 *       que estaban en el fichero
 */
void leerSubtitulos (const char nombreFichero[], Subtitulo S[]){
	ifstream f;
	f.open(nombreFichero);
	const int MAX=128;
	char linea[MAX], subtitulo[MAX];
	if(f.is_open()){
		while(!f.eof()){
			f.getline(linea,MAX);
			f.getline(linea,MAX);
			f.getline(linea,MAX);
			for(int i=0;(int)linea!=0;i++){
				//S[i]=linea;
				f.getline(linea,MAX);
			}
		}
		f.close();
	}
	else if(!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombreFichero<<endl;
	}
}

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
void mostrar (Subtitulo S){
	int nLineas;
	char subtitulos[nLineas][MAX_LONG_LINEA];
	cout<<numero(S)<<". ";
	mostrar(principio(S));
	cout<<" - ";
	mostrar(fin(S));
	texto(S, nLineas, subtitulos);
	for(int i=0; i<nLineas; i++){
		cout<<subtitulos[i];
	}
}

/*
 * Pre: TS[0,total-1] almacena un número de subtitulos igual a total,
 *      total >= 0, i >= 1 y j <= total
 * Post: Presenta por pantalla un listado de los subtítulos almacenados
 *       en TS que van desde el i-ésimo hasta el j-ésimo, siendo TS[0]
 *       el primero, TS[1] el segundo y así sucesivamente. Dos subtitulos 
 *       consecutivos se separan mediante una línea en blanco.
 */
void mostrar (const Subtitulo TS[], const int total, int i, int j);