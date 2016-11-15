/*
 *  Fichero calculos.cc de implementación del módulo calculos
 */

/*
 *  Pre: ---
 *  Post: Devuelve el número de cifras de [n] cuando este número se escribe en base 10
 */
int numCifras (int n) {
    int cuenta = 1;            // lleva la cuenta de las cifras identificadas
    n = n/10;                  // elimina la cifra menos significativa de [n]
    while (n!=0) {
        /*
         *  El valor de <cuenta> es igual al de cifras identificadas en [n]
         */
        cuenta = cuenta + 1;     // contabiliza la cifra menos significativa de [n]
	n = n / 10;              // y la elimina de [n]
    }
    return cuenta;
}

/*
 *  Pre: ---
 *  Post: Devuelve la suma de las cifras de [n] cuando éste se escribe en base 10
 */
int sumaCifras (int n) {
    if (n<0) { n = -n; }
    int suma = 0;                 // suma de las cifras eliminadas de [n] (inicialmente 0)
    while (n!=0) {
        suma = suma + n % 10;     // suma la cifra menos significativa de [n]
        n = n / 10;               // y la elimina de [n]
    }
    return suma;
}

/*
 *  Pre: i>=1
 *  Post: Devuelve la i-esima cifra menos significatica de [n] cuando éste se escribe en
 *        base 10
 */
int cifra (int n, int i) {
    if (n<0) {
        n = -n;
    }
    for (int exp = 1; exp<i; ++exp) {
        n = n / 10;    // elimina la cifra menos significativa de [n]
    }
    return n % 10;
}

/*
 *  Pre: ---
 *  Post: Devuelve el número que escrito en base 10 es la imagen especular de [n] cuando
 *        éste se escribe también en base 10.
 */
int imagen (int n) {
    /*
     *  Si [n] es negativo lo cambia de signo
     */
    bool negativo = n<0;
    if (n<0) {
        n = -n;
    }
    /*
     *  Calcula la cifra más significativa de la imagen de [n]
     */
    int suImagen = n%10;
    n = n/10;
    while (n!=0) {
        /*
         *  Incorpora en cada iteración una cifra a [suImagen] y  elimina la menos
         *  significativa de [n]
         */
        suImagen = 10 * suImagen + n % 10;  n = n / 10;
    }
    /*
     *  Si [n] era inicialmente negativo devuelve el valor de [suImagen]
     *  cambiado de signo
     */
    if (negativo) {
        return -suImagen;
    }
    else {
        return suImagen;
    }
}

/*
 *  Pre: n>=0
 *  Post: Devuelve el factorial de [n]
 */
int factorial (int n) {
    int r = 1;                         //  r = 0! 
    for (int i = 2; i<=n; ++i) {
        r = i * r;                     //  r = i! 
    }
    return r;
}

/*
 *  Pre: ---
 *  Post: Devuelve [true] si y sólo si [n] es un número primo
 */
bool esPrimo (int n) {
    if (n==2) {
        return true;      // [n] es igual a 2, luego es primo
    }
    else if (n<2 || n%2==0) {
        return false;     // es menor que 2 o divisible por 2
    }
    else {
        /*
         * Se buscan posibles divisores impares de [n]
         */
        int divisor = 3;              // Primer divisor impar a probar
        bool loParece = true;
        while (loParece && divisor*divisor<=n) {
            loParece = n%divisor>0;  divisor = divisor + 2;
        }
        return loParece;
    }
}

/*
 *  Pre: a!=0 ó b!=0
 *  Post: Devuelve el máximo común divisor de [a] y [b]
 */
int mcd (int a, int b) {
    if(a<0) { a = -a; }
    if(b<0) { b = -b; }
    /*
     
     * Aplica el algoritmo de Euclides para el calculo del m.c.d. de [a] y [b]
     */
    while (b!=0) {
        int resto = a % b;
        a = b;  b = resto;
    }
    return a;
}
int cifraMasSignificativa (int n){
	if(n<0){
		n=-n;
	}
	while(n>=10){
		n=n/10;
	}
	return n;
}

/*
 *  Pre: ---
 *  Post: Devuelve la cifra de mayor valor de n cuando n se escribe en 
 *        base 10
 */
int cifraMayor (int n){
	int maximo=0;
	while(n!=0){
		if(n%10>maximo){
			maximo=n%10;
			n=n/10;
		}
		else{
			n=n/10;
		}
	}
	return maximo;
}

/*
 *  Pre: ---
 *  Post: Devuelve un entero cuyas cifras de unidades y decenas, en base 10, 
 *        coinciden con las unidades de n en base 10, sus dos siguiente  
 *        cifras, centenas y millares, en base 10, coinciden con las decenas 
 *        de n, en base 10, y así sucesivamente. Ejemplos:
 *           duplicarCifras(5) = 55
 *           duplicarCifras(-5) = -55
 *           duplicarCifras(7809) = 77880099
 *           duplicarCifras(-7809) = -77880099
 *           duplicarCifras(1002) = 11000022
 *           duplicarCifras(-1002) = -11000022
 */
int duplicarCifras (int n){
	int cifras=11;
	int duplicado=0;
	while(n!=0){
		duplicado=duplicado+n%10*cifras;
		n=n/10;
		cifras=cifras*100;
	}
	return duplicado;
}

/*
 * Pre: n>0
 * Post: Devuelve un entero que al ser escrito en base 10 presenta las cifras 
 *       no nulas de [n] y en el mismo orden y, entre cada par de cifras no 
 *       nulas  consecutivas, el número devuelto presenta un cero. Ejemplos:
 *         cerificar(7) = 7
 *         cerificar(17) = 107
 *         cerificar(113) = 10103
 *         cerificar(170) = 107
 *         cerificar(1203) = 10203
 *         cerificar(1000203) = 10203
 *         cerificar(912000) = 90102
 *         cerificar(91002000) = 90102
 */
int cerificar (int n){
	int cerificada=0;
	int i=1;
	while(n/10!=0){
		if (n%10!=0){
			cerificada=cerificada+(n%10)*i;
			i=i*100;
		}
		n=n/10;
	}
	cerificada=cerificada+(n%10)*i;
	return cerificada;
}


