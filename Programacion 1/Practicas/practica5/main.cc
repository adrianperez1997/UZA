#include <iostream>
#include "gestionFicheros.h"
 #include "../Persona/persona.h"
using namespace std;


int main(){
	const int DIM = 999;
	int fechas[DIM], fechas2[DIM], fechas3[DIM], fechas4[DIM];
	bool sexos[DIM], sexos2[DIM], sexos3[DIM], sexos4[DIM];
	int datos, datos2, datos3, datos4;
	char c;
	cout<<"Hay 4 tipos de archivos, los 4 guardan informacion sobre personas (fecha de nacimiento y sexo)"<<endl
	<<"En el fichero gestionFicheros.cc explica como guarda la informacion cada uno"<<endl
	<<"Hagamos unas pruebas, en la carpeta Datos del proyecto tienes los 2 primeros archivos:"<<endl;
	leerDatosFormatoT01("../../Datos/personas01_T01.txt", fechas, sexos, datos);
	leerDatosFormatoT02("../../Datos/personas02_T02.txt", fechas2, sexos2, datos2);
	cout<<"introduce 's' para seguir"<<endl;
	cin>>c;
	cout<<"_____________________________________________________________"<<endl<<"PRIMER ARCHIVO"<<endl<<endl;
	for (int i = 0; i < datos; i++) {
		cout << (i+1) << ' ' << fechas[i] << ' ' << boolalpha << sexos[i] << endl;
	}
	cout<<"_____________________________________________________________"<<endl<<"SEGUNDO ARCHIVO"<<endl<<endl;
	for (int i = 0; i < datos2; i++) {
		cout << (i+1) << ' ' << fechas2[i] << ' ' << boolalpha << sexos2[i] << endl;
	}
	cout<<endl<<endl<<"Ahora guardaremos el archivo T01 en formato B01 y B02. Luego leeremos el archivo B02 para comprobar que es el mismo"<<endl
	<<"Ademas puedes comprobar que en la carpeta se crean los archivos"<<endl;
	cout<<"introduce 's' para seguir"<<endl;
	cin>>c;
	
	guardarDatosFormatoB01("../../Datos/personas03_B01.txt", fechas, sexos, datos);
	guardarDatosFormatoB02("../../Datos/personas04_B02.txt", fechas2, sexos2, datos2);
	leerDatosFormatoB02("../../Datos/personas04_B02.txt", fechas3, sexos3, datos3);
	for (int i = 0; i < datos3; i++) {
		cout << (i+1) << ' ' << fechas3[i] << ' ' << boolalpha << sexos3[i] << endl;
	}
	cout<<"Este mismo archivo se puede volver a guardar en formato T01 y leerlos otra vez"<<endl;
	cout<<"introduce 's' para seguir"<<endl;
	cin>>c;
	
	guardarDatosFormatoT01("../../Datos/personas05_T01.txt", fechas3, sexos3, datos3);
	leerDatosFormatoT01("../../Datos/personas05_T01.txt", fechas4, sexos4, datos4);
	for (int i = 0; i < datos4; i++) {
		cout << (i+1) << ' ' << fechas4[i] << ' ' << boolalpha << sexos4[i] << endl;
	}
}
