#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Pre: r>=0.0
 * Post: Escribe por pantalla en una línea el valor del radio y del área de un
 *       círculo de radio [r]
 */
void circulo (double r) {
    const double PI = 3.1416;
    cout  << "El area de un circulo de radio " << fixed << setprecision(2) << r
          << " es igual a " << PI*r*r << endl;
}

/*
 *  Pre: ---
 *  Post: Pregunta al operador por el [Radio del circulo: ] y le informa en la
 *        línea siguiente del valor del radio y del área del círculo
 */
int main() {
    /*
     * Pregunta al operador y almacena su respuesta en r
     */
    double r;
    cout << "Radio del circulo: " << flush;
    cin >> r;
    /*
     * Presenta por pantalla los datos del círculo de radio r
     */
    circulo(r);
    /*
     * Concluye normalmente y devuelve un 0
     */
    return 0;
}