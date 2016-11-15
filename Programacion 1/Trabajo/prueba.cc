#include <iostream>
//#include <string.h>
#include "tiempo.h"

#include "../ModHerramientas/herramientas.h"
//#include "herramientas.h"
#include "../ModSubtitulo/subtitulo.h"
using namespace std;
int main(){
	Tiempo nuevo=definir(7833);
	Tiempo otro=definir(7894);
	mostrar(nuevo);
	mostrar(otro);
	permutar(nuevo,otro);
		mostrar(nuevo);
	mostrar(otro);

	cout<<"*********"<<"\n";
	Tiempo tiempos[4];
	tiempos[0]=definir(1111);
	tiempos[1]=definir(5555);
	tiempos[2]=definir(1111);
	tiempos[3]=definir(3333);
	mostrar(tiempos,4);
	ordenar(tiempos,4);
	cout<<"ORDENADO:\n";
	mostrar(tiempos,4);
	cout<<"*********"<<"\n";
	cout<<"Convertido:   "<<hora(nuevo)<<":"<<minuto(nuevo)<<":"<<segundo(nuevo)<<","<<milesima(nuevo)<<"\n";
	cout<<"El segundo:   "<<hora(otro)<<":"<<minuto(otro)<<":"<<segundo(otro)<<","<<milesima(otro)<<"\n";
	otro=restar(nuevo,otro);
	cout<<"La resta:   "<<hora(otro)<<":"<<minuto(otro)<<":"<<segundo(otro)<<","<<milesima(otro)<<"\n";
	otro=sumar(nuevo,otro);
	cout<<"La suma:   "<<hora(otro)<<":"<<minuto(otro)<<":"<<segundo(otro)<<","<<milesima(otro)<<"\n";
	if (esMenor(nuevo,otro)){cout<<"El menor es nuevo"<<"\n";};
	nuevo=sumar(nuevo,otro);
	if (esMayor(nuevo,otro)){cout<<"Ahora, el mayor es nuevo"<<"\n";};
	nuevo=otro;
	if (sonIguales(nuevo,otro)){cout<<"Ahora, son los dos iguales"<<"\n";};
    cout<<"*****SUBTITULOS****"<<"\n";
	char textillo[3][MAX_LONG_LINEA]={"hola","caracola","roja"};
	//char tt[];
//	tt="Hola                                                                          ";
 //   textillo[1]="caracola                                                                      ";
	Subtitulo titulillo=definir(55,3,textillo,nuevo,otro);
    cout<<numero(titulillo)<<"::"<<titulillo.numLineasTexto<<"::"<<titulillo.texto[2]<<"::\n";
	mostrar(principio(titulillo));
	mostrar(fin(titulillo));
	int cuantastiene;
	char quepone[3][MAX_LONG_LINEA];
	texto(titulillo,cuantastiene,quepone);
	cout<<cuantastiene<<"::"<<quepone[1]<<"::\n";
	
	cout<<endl;
    cout<<"*******************"<<"\n";
    cout<<"*****FICHEROS******"<<"\n";
    cout<<"*******************"<<"\n";
	const int DIM = 999;
	Subtitulo Subtitulos[DIM];
	int num_s;                // número del subtítulo
    int numLineas_s;        // su número de líneas
    char texto_s[MAX_LINEAS][MAX_LONG_LINEA];    // cada una de sus líneas
    Tiempo inicio_s, fin_s;        // tiempo del inicio y fin de su proyección
    int CuantosSubtitulos=0;
	CuantosSubtitulos=contarSubtitulos("../../Datos/sub01.srt");
	Subtitulo prueba[DIM];
	//leerSubtitulos("../../Datos/sub01.srt", prueba);
	cout<<"Hay un total de "<<CuantosSubtitulos<<" Subtitulos en el archivo";
	mostrar(titulillo);
}