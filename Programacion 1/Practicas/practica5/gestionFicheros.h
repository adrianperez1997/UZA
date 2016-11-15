/*
 * Fichero gestionFicheros.h de interfaz del módulo gestionFicheros
 */

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
			  int& numDatos);
							 
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *      un grupo de N personas según el formato textual T02.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoT02 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos);
						  
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *     un grupo de N personas según el formato binario B01.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoB01 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos);
					
/*
 * Pre: [nombre] define el nombre de un fichero que almacena información de
 *      un grupo de N personas según el formato binario B02.
 * Post: Ha asignado a numDatos el valor N y a tFechas[0,numDatos-1] y a 
 *       tSexo[0,numDatos-1] la información correspondiente a cada una de las 
 *       personas del grupo
 */
void leerDatosFormatoB02 (const char nombre[], int tFechas[], bool tSexo[],
			  int& numDatos);
				
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      un grupo de personas según el formato T01.
 * Post: Ha almacenado en el fichero [nombre] con formato textual T01 la información 
 *       sobre un grupo de numPersonas personas definida en tFechas[0,numPersonas-1] 
 *       y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoT01 (const char nombre[], int tFechas[], bool tSexo[],
			     int numPersonas);
	
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato textual T02.
 * Post: Ha almacenado en el fichero [nombre] con formato textual T02 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoT02 (const char nombre[], int tFechas[], bool tSexo[],
                             int numPersonas);
							 
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato binario B01.
 * Post: Ha almacenado en el fichero [nombre] con formato binario B01 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoB01 (const char nombre[], int tFechas[], bool tSexo[],
		             int numPersonas);
							 
/*
 * Pre: [nombre] define el nombre de un fichero destinado a almacenar información de
 *      personas según el formato binario B02.
 * Post: Ha almacenado en el fichero [nombre] con formato binario B02 la información sobre
 *       numPersonas personas definida en tFechas[0,numPersonas-1] y tSexo[0,numPersonas-1]
 */
void guardarDatosFormatoB02 (const char nombre[], int tFechas[], bool tSexo[],
			     int numPersonas);