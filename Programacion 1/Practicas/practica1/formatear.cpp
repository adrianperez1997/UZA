#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * Pre: desde<=hasta
 * Post: Presenta por pantalla una tabla con una línea por cada uno de los valores
 *       del intervalo [desde,hasta]. En cada línea se muestra un valor, su cuadrado
 *       y su cubo
 */
void mostrarPotencias (int desde, int hasta) {
    cout  << setw(3) << "x" << setw(20) <<  "x^2" << setw(20) << "x^3" << endl;
	cout << "===========================================" << endl;
    for (int x = desde; x<=hasta; x = x + 1) {
        cout << setw(3) << x << setw(20) << x*x << setw(20) << x*x*x << endl;
    }
	cout << endl;
}

/*
 * Pre: desde<=hasta
 * Post: Presenta por pantalla una tabla con una línea por cada uno de los valores
 *       de los ángulos, expresados en grados: desde, desde + 5, desde + 10, etc,. que
 *       sean inferiores o iguales a hasta. En cada línea  se muestra el valor del ángulo
 *       en grados y en radianes y los valores de sus funciones seno y coseno.
 */
void mostrarAngulos (int desde, int hasta) {
    const double PI = 3.1415926;
    cout << setw(3) << "grados" << setw(17) << "radianes"  << setw(20) <<  "seno" << setw(20) <<  "coseno" << endl;
	cout << "===============================================================" <<endl;
	cout << fixed;
    for (double x = desde; x<=hasta; x = x + 5.0) {
        double radianes = PI * x / 180.0;
        cout << setw(3) <<  setprecision(0) << x << setw(20) << setprecision(8) << radianes << setw(20) << sin(radianes) << setw(20) << cos(radianes) << endl;
    }
}

/*
 *  Pre: ---
 *  Post: Presenta por pantalla una tabla de potencias (en cada línea un valor, 
 *        su cuadrado y su cubo) y una tabla de ángulos (en cada línea un ángulo
 *        en grados, en radianes,su seno y su coseno)
 */
int main() {
    /* Presenta la tabla de potencias de los enteros comprendidos entre 5 y 15 */
    mostrarPotencias(5,15);
    /* Presenta una tabla con los ángulos comprendidos entre 0 y 180 grados */
    mostrarAngulos(0,180);
    return 0;
}