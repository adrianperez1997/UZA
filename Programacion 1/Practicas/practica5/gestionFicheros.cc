/*
 * Fichero gestionFicheros.h de interfaz del módulo gestionFicheros
 */
 #include <iostream>
 #include <fstream>
 #include "gestionFicheros.h"
 #include "../Persona/persona.h"
 using namespace std;
/*
 * En lo que sigue se presenta la sintaxis de cuatro formatos para el
 * almacenamiento en un fichero de los datos de una secuencia de personas
 * que constituyen un grupo. Los datos <dia>, <mes> y <año> definen la fecha
 * nacimiento de la persona y <mujer> define su sexo (mujer si su valor es
 * true [cierto] u hombre si su valor es false [falso])
 *
 * Formato textual T01 para almacenar información de un grupo de personas
 * en un fichero:
 *   <fichero_T01> ::=   { <persona>  fin_línea }
 *   <persona> ::= <dia> <sep> <mes> <sep> <año> <sep> <mujer>
 *   <dia> ::= literal_entero
 *   <mes> ::= literal_entero
 *   <año> ::= literal_entero
 *   <mujer> ::= literal_booleano
 *   <sep> ::= " " { " " }
 *
 * Formato textual T02 para almacenar información de un grupo de personas
 * en un fichero:
 *   <fichero_T02> ::=   { <persona>  fin_línea }
 *   <persona> ::= <dia> <sep> <mes> <sep> <año> <sep> <mujer>
 *   <dia> ::= literal_entero
 *   <mes> ::= literal_entero
 *   <año> ::= literal_entero
 *   <mujer> ::= literal_booleano
 *   <sep> ::= ","
 *
 * Formato binario B01 para almacenar información de un grupo de personas
 * en un fichero:
 *   <fichero_B01> ::=   { <persona> }
 *   <persona> ::= <dia> <mes> <año> <mujer>
 *   <dia> ::= dato_tipo_int
 *   <mes> ::= dato_tipo_int
 *   <año> ::= dato_tipo_int
 *   <mujer> ::= dato_tipo_bool
 *
 * Formato binario B02 para almacenar información de un grupo de personas
 * en un fichero:
 *   <fichero_B02> ::=   { <persona> }
 *   <persona> ::= dato_tipo_persona
 */
 
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *      un grupo de N personas según el formato textual T01.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de 
 *       las personas del grupo
 */

void leerDatosFormatoT01 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos){
	ifstream f;
	f.open(nombre);
	const int MAX=128;
	char linea[MAX];
	numDatos=0;
	int dia, mes, anyo;
	bool mujer;
	if (f.is_open()){
		f>>dia>>mes>>anyo>>boolalpha>>mujer;
		while(!f.eof()){
			f.getline(linea,MAX);
			tFechas[numDatos]=dia+mes*100+anyo*10000;
			tSexo[numDatos]=mujer;
			numDatos++;
			f>>dia>>mes>>anyo>>boolalpha>>mujer;
		}
		f.close();
	}
	else if (!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombre<<endl;
	}

}
	
							 
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *      un grupo de N personas según el formato textual T02.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoT02 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos){
	ifstream f;
	f.open(nombre);
	const int MAX=128;
	char linea[MAX];
	numDatos=0;
	int dia, mes, anyo;
	char coma=',';
	bool mujer;
	if (f.is_open()){
		f>>dia>>coma>>mes>>coma>>anyo>>coma>>boolalpha>>mujer;
		while(!f.eof()){
			f.getline(linea,MAX);
			tFechas[numDatos]=dia+mes*100+anyo*10000;
			tSexo[numDatos]=mujer;
			numDatos++;
			f>>dia>>coma>>mes>>coma>>anyo>>coma>>boolalpha>>mujer;
		}
		f.close();
	}
	else if (!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombre<<endl;
	}
}
						  
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *     un grupo de N personas según el formato binario B01.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoB01 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos){
	ifstream f;
	f.open(nombre,ios::binary);
	if(f.is_open()){
		int dia, mes, anyo;
		bool mujer;
		f.read(reinterpret_cast<char*>(&dia),sizeof(dia));
		f.read(reinterpret_cast<char*>(&mes),sizeof(mes));
		f.read(reinterpret_cast<char*>(&anyo),sizeof(anyo));
		f.read(reinterpret_cast<char*>(&mujer),sizeof(mujer));
		while(!f.eof()){
			tFechas[numDatos]=dia+mes*100+anyo*10000;
			tSexo[numDatos]=mujer;
			numDatos++;
			f.read(reinterpret_cast<char*>(&dia),sizeof(dia));
			f.read(reinterpret_cast<char*>(&mes),sizeof(mes));
			f.read(reinterpret_cast<char*>(&anyo),sizeof(anyo));
			f.read(reinterpret_cast<char*>(&mujer),sizeof(mujer));
		}
	
	}
	else if (!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombre<<endl;
	}
}
					
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *      un grupo de N personas según el formato binario B02.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoB02 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos){
	ifstream f;
	f.open(nombre,ios::binary);
	if(f.is_open()){
		Persona p;
		f.read(reinterpret_cast<char*>(&p),sizeof(p));
		while(!f.eof()){
			tFechas[numDatos]=nacido(p);
			tSexo[numDatos]=esMujer(p);
			numDatos++;
			f.read(reinterpret_cast<char*>(&p),sizeof(p));
		}
	
	}
	else if (!f.is_open()){
		cerr<<"Error al abrir el fichero "<<nombre<<endl;
	}
}
				
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      un grupo de personas según el formato T01.
 * Post: Ha almacenado en el fichero [nombre] con formato textual T01 la información 
 *       sobre un grupo de numPersonas personas definida en tFechas[0,numPersonas-1] 
 *       y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoT01 (const char nombre[], int tFechas[], bool tSexo[],
			     int numPersonas){
	ofstream f (nombre);
	const char separador=' ';
	for(int i=0; i<numPersonas; i++){
		f<<tFechas[i]%100<<separador<<(tFechas[i]/100)%100<<separador
		 <<tFechas[i]/10000<<separador<<boolalpha<<tSexo[i]<<endl;
	}
}
	
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato textual T02.
 * Post: Ha almacenado en el fichero [nombre] con formato textual T02 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoT02 (const char nombre[], int tFechas[], bool tSexo[],
                             int numPersonas){
	ofstream f (nombre);
	const char separador=',';
	for(int i=0; i<numPersonas; i++){
		f<<tFechas[i]%100<<separador<<(tFechas[i]/100)%100<<separador
		 <<tFechas[i]/10000<<separador<<boolalpha<<tSexo[i]<<endl;
	}
}
							 
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato binario B01.
 * Post: Ha almacenado en el fichero [nombre] con formato binario B01 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoB01 (const char nombre[], int tFechas[], bool tSexo[],
		             int numPersonas){
	ofstream f;
	f.open(nombre, ios::binary);
	for(int i=0; i<numPersonas; i++){
		int dia=tFechas[i]%100;
		int mes=(tFechas[i]/100)%100;
		int anyo=tFechas[i]/10000;
		bool mujer=tSexo[i];
		f.write(reinterpret_cast<char*>(&dia),sizeof(dia));
		f.write(reinterpret_cast<char*>(&mes),sizeof(mes));
		f.write(reinterpret_cast<char*>(&anyo),sizeof(anyo));
		f.write(reinterpret_cast<char*>(&mujer),sizeof(mujer));
	}
	f.close();
}
							 
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato binario B02.
 * Post: Ha almacenado en el fichero [nombre] con formato binario B02 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoB02 (const char nombre[], int tFechas[], bool tSexo[],
			     int numPersonas){
	ofstream f;
	f.open(nombre, ios::binary);
	for(int i=0; i<numPersonas; i++){
		Persona p=definirPersona(tFechas[i],tSexo[i]);
		f.write(reinterpret_cast<char*>(&p),sizeof(p));

	}
	f.close();
}
