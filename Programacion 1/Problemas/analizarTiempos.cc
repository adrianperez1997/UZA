/*
 * Autor del programa: Adrian Perez Ortega
 * Fecha: 8 de noviembre de 2015
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Pre:
 * Post: lee y evalua si los tiempos estan escritos sintacticamente correctos, si no es asi, especifica el error
 * 		y valido toma el valor false, ademas las variables h, m, seg y milesima quedan indefinidas. Si es correcto valido toma el valor true. 		
 */
void leer (int& h, int& m, int& seg, int& milesima, bool& valido) {
	valido=true;
	char dosPuntos=':';
	char coma=',';
	cout<<"Escriba un tiempo [horas:minuto:segundo,milesima]: "<<flush;
	
	cin>>h>>dosPuntos;								//El programa lee el primer entero y el caracter que le sigue
	if(dosPuntos!=':'){
		cout<<"Error sintactico: Tras las horas debe escribirse el caracter ':'"<<endl;
		valido=false;
	}
	else{
		cin>>m>>dosPuntos;							//Continua leyendo el siguiente entero y el siguiente caracter
		if(dosPuntos!=':'){
			cout<<"Error sintactico: Tras el minuto debe escribirse el caracter ':'"<<endl;
			valido=false;
		}
		else{
			cin>>seg>>coma;							//Repite lo mismo con los siguientes
			if(coma!=','){
				cout<<"Error sintactico: Tras el segundo debe escribirse el caracter ','"<<endl;
				valido=false;
			}
			else{
				cin>>milesima;						//Por ultimo recoge las milesimas
			}
		}
	}
}

/*
 * Pre: las h, m, seg y milesimas son variables enteras.
 * Post: h>0 , 0<m<60 , 0<seg<60 , 0<milesima<1000. Si alguna de estas condiciones no se cumple devuelve false y especifica el error.
 */
bool verificado (int h, int m, int seg, int milesima) {
	bool resultado=true;
	if (h<0){
		cout<<"Error semantico: las horas no pueden ser negativas"<<endl;
		resultado=false;
	}
	if (m<0||m>59){	
		cout<<"Error semantico: el minuto esta fuera del intervalo [0,59]"<<endl;
		resultado=false;
	}
	if (seg<0||seg>59){
		cout<<"Error semantico: el segundo esta fuera del intervalo [0,59]"<<endl;
		resultado=false;
	}
	if (milesima<0||milesima>999){
		cout<<"Error semantico: la milesima esta fuera del intervalo [0,999]"<<endl;
		resultado=false;
	}
	return resultado;
}

/*
 * Pre: h>=0, m>=0, m<=59, seg>=0, seg<=59, milesima>=0 y milesima<=999
 * Post: Escribe por pantalla una línea informando de la corrección de una medida de tiempo
 *       definida por los valores de los parámetros H, m, s y milesima con el siguiente
 *       formato (la medida del tiempo se representa con 12 caracteres en total):
 *          El tiempo escrito es correcto: hh:mm:ss,mmm
 *       Ejemplo:
 *          El tiempo escrito es correcto: 33:00:24,000
 *       Otro ejemplo:
 *          El tiempo escrito es correcto: 00:52:00,150
 */
void presentar (int h, int m, int seg, int milesima) {
	cout<<"El tiempo es correcto: ";
	//Añade ceros delante del entero si es menor que 10
	if (h<10){
		cout<<'0';
	}
	cout<<h<<':';
	if (m<10){
		cout<<'0';
	}
	cout<<m<<':';
	if (seg<10){
		cout<<'0';
	}
	cout<<seg<<',';
	//Se hacen dos comprobaciones para saber si las milesimas tienen una, dos o tres cifras
	if (milesima<100){
		cout<<'0';
		if (milesima<10){
			cout<<'0';
		}
	}
	cout<<milesima;
}

int main ( ) {
    const int NUM_PRUEBAS = 3;       // Número de datos (tiempos) a analizar
    for (int i = 1; i <= NUM_PRUEBAS; ++i) {
        // En cada iteración analiza la corrección sintáctica y semántica
        // de un tiempo facilitado interactivamente por el operador
        int  h, m, seg, milesima;
        bool datoValido;
        // Pide al operador que escriba un tiempo y lo analiza sintácticamente.
        // Asigna a datoValido un valor true si y sólo si no hay errores
        // sintácticos y, en tal caso, asigna a h, m, seg y milesima los
        // valores que les corresponden
        leer(h, m, seg, milesima, datoValido);
        if (datoValido) {
            // Tras superar el análisis sintáctico, analiza la validez de los
            // valores de los datos h, m, seg y milesima
            if (verificado(h, m, seg, milesima)) {
                // Tras superar el análisis semántico, escribe por pantalla una línea
                // informando de la corrección del tiempo con el siguiente formato
                // (emplea 12 caracteres para escribir el tiempo analizado):
                //    El tiempo escrito es correcto: hh:mm:ss,mmm
                // Ejemplo:
                //    El tiempo escrito es correcto: 03:40:00,005
                presentar(h, m, seg, milesima);
            }
        }
        cout << endl;    // línea en blanco de separación
    }
    return 0;
}