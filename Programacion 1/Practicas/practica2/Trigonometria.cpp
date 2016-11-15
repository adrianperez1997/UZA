#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
 * Pre:...
 * Post:escribe en pantalla un angulo en radianes, que nosotros previamente hemos introducido en grados, 
 * y calcula el seno, el coseno y la tangente.
 */
 
int main()
{
	double grados, minutos, segundos;
	cout<< "Escriba el valor de un angulo (grados, minutos y segundos): "<<flush;
	cin >> grados >> minutos >> segundos;
	double radianes= (grados+minutos/60+segundos/3600)*M_PI/180;
	cout << "Valor del angulo en radianes: "<< setprecision(4)<<radianes<<endl;
	cout<<"sen "<<setprecision(4)<<radianes<<" = "<<setprecision(5)<< sin(radianes)<<endl;
	cout<<"cos "<<setprecision(4)<<radianes<<" = "<<setprecision(5)<< cos(radianes)<<endl;
	cout<<"tg "<<setprecision(4)<<radianes<<" = "<<setprecision(5)<< tan(radianes)<<endl;
	
}

