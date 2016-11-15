#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Pre: r>= 0.0
 * Post: Escribe por pantalla, en una misma línea, el valor del radio [r] y de la
 *       longitud de una circunferencia de radio [r]
 */
void circunferencia (double r) {
    const double PI = 3.1416;
    cout << fixed << setprecision(2) << setw(7) << r << setprecision(3) << setw(16)
		<< 2.0*PI*r << endl;
}

/*
 *  Pre: ---
 *  Post: Escribe por pantalla el radio y la longitud de tres circunferencias
 */
int main() {
   /*
    * Escribe por pantalla el radio y la longitud de tres circunferencias
    */
    cout << setw(7) << "Radio" << setw(20) << "Circunferencia" << endl;
    cout << setw(7) << "=====" << setw(20) << "==============" << endl;
    circunferencia(1.234);
    circunferencia(5.0112);
    circunferencia(11.5178);
    /*
     * El programa termina normalmente devolviendo un valor 0
     */
    return 0;
}
