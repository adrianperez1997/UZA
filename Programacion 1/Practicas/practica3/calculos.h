/*
 *  Fichero calculos.h de intefaz del módulo calculos
 */

/*
 *  Pre: ---
 *  Post: Devuelve el número de cifras de [n] cuando este número se escribe en base 10
 */
int numCifras (int n);

/*
 *  Pre: ---
 *  Post: Devuelve la suma de las cifras de [n] cuando éste se escribe en base 10
 */
int sumaCifras (int n);

/*
 *  Pre: i>=1
 *  Post: Devuelve la i-esima cifra menos significatica de [n] cuando éste se escribe en
 *        base 10
 */
int cifra (int n, int i);

/*
 *  Pre: ---
 *  Post: Devuelve el número que escrito en base 10 es la imagen especular de [n] cuando
 *        éste se escribe también en base 10.
 */
int imagen (int n);

/*
 *  Pre: n>=0
 *  Post: Devuelve el factorial de [n]
 */
int factorial (int n);

/*
 *  Pre: ---
 *  Post: Devuelve [true] si y sólo si [n] es un número primo
 */
bool esPrimo (int n);

/*
 *  Pre: a!=0 ó b!=0
 *  Post: Devuelve el máximo común divisor de [a] y [b]
 */
int mcd (int a, int b);
int cifraMasSignificativa(int n);
int cifraMayor(int n);
int duplicarCifras(int n);
int cerificar(int n);
