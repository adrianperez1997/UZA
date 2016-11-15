/*
 * Fichero de interfaz grupo.h del módulo grupo
 */
 
/*
 * Este módulo facilita una colección de funciones para trabajar con la 
 * información asociada a un grupo de personas. De cada persona interesan
 * únicamente dos datos: su fecha de nacimiento y su sexo.
 * La represención de la información de un grupo de personas se gestiona 
 * mediante dos tablas, una tabla de datos de tipo [int] que almacena las 
 * fechas de nacimiento de cada persona y una tabla de tipo [bool] que
 * codifica el sexo de cada persona: true (cierto) si es mujer y false 
 * (falso) si es hombre.
 * Los datos de una persona determinada se almacenan en elementos de las
 * tablas de fechas de nacimientos y de sexo que tienen índices idénticos.
 */
  
/*
 * Codificación de fechas: Las fechas a la que se hace referencia en este módulo 
 * se representan como datos enteros que, si se escriben en base decimal, constan
 * de 8 cifras, aaaammdd, donde las cuatro más significativas, aaaa, representan
 * el año, las dos cifras que les siguen, mm, representan el mes, y las dos cifras 
 * menos significativas, dd, representan el día del mes. Ejemplos de fechas: 
 * 20150101 y 20151231, que representan el primer y último dia del año 2015.
 * 
 * Codificación del sexo de una persona: mediante un dato booleano; si su valor es 
 * cierto (true) denota una mujer y si su valor es falso (false) denota un hombre.
 */
 
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *    Funciones que trabajan con tablas de fechas                              *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve la fecha almacenada en tFechas[0,n-1] más antigua
 */
int fechaMasAntigua (int tFechas[], int n);

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el año que más se repite en el grupo de fechas almacenadas
 *       en tFechas[0,n-1]
 */
int anyoMasRepetido (int tFechas[], int n);

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el mes, un número del intervalo [1,12], que más se repite en el 
 *       grupo de fechas almacenadas en tFechas[0,n-1]
 */
int mesMasRepetido (int tFechas[], int n);

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el día del mes, un valor comprendido en el intervalo [1-31],  
 *       que más se repite en el grupo de fechas almacenadas en tFechas[0,n-1]
 */
int diaMasRepetido (int tFechas[], int n);

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve la fecha que más se repite en el grupo de fechas almacenadas
 *       en tFechas[0,n-1]
 */
int fechaMasRepetida (int tFechas[], int n);

/*
 * Pre: n >= 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el número de fechas almacenadas en tFechas[0,n-1] que
 *       coinciden con la fecha dia/mes/anyo
 */
int cuantos (int tFechas[], int n, int dia, int mes, int anyo);

/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *    Funciones que trabajan con tablas de sexos                               *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

/*
 * Pre: n >= 0, tSexo[0,n-1] almacena el sexo de un grupo de personas
 * Post: Devuelve el número de datos de tSexo[0,n-1] que corresponden a hombres
 */
int hombres (bool tSexo[], int n);

/*
 * Pre: n >= 0, tSexo[0,n-1] almacena el sexo de un grupo de personas
 * Post: Devuelve el número de datos de tSexo[0,n-1] que corresponden a mujeres
 */
int mujeres (bool tSexo[], int n);

/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *     Funciones que gestionan dos tablas que almacenan las fechas de          *
 *     nacimiento y el sexo de un grupo de personas                            *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

/*
 * Pre: n >= 0, tFechas[0,n-1] almacena las fechas de nacimiento de un grupo de 
 *      personas y tSexo[i] almacena el sexo de la persona de ese grupo cuya fecha 
 *      de nacimiento es tFechas[i]. Sean NH y NM el número de hombres y mujeres 
 *      del grupo, respectivamente, nacidos en el intervalo de fechas [desde,hasta]
 * Post: Si los parámetros hombres y mujeres son ambos cierto (true) entonces 
 *       devuelve NH+NM, si sólo hombres es cierto (true) entonces devuelve NH; 
 *       si sólo mujeres es cierto (true) entonces devuelve NM; y si ambos son
 *       falso (false) devuelve 0
 */
int contar (int tFechas[], bool tSexo[], int n, int desde, int hasta, 
            bool hombres, bool mujeres);
			
/*
 * Pre: n >= 0, tFechas[0,n-1] almacena las fechas de nacimiento de un grupo de 
 *      personas y tSexo[i] almacena el sexo de la persona de ese grupo cuya fecha 
 *      de nacimiento es tFechas[i].
 *      Sean NH y NM el número de hombres y mujeres del grupo
 * Post: Si el parámetro sexo es cierto (true) entonces numero toma el valor MH y
 *       almacena en tSeleccion[0,numero-1] las fechas de nacimiento de las MH mujeres 
 *       del grupo y si el parámetro sexo es falso (false) entonces numero toma el 
 *       valor NH y almacena en tSeleccion[0,numero-1] las fechas de nacimiento 
 *       de los NH hombres del grupo
 */
void seleccionar (int tFechas[], bool tSexo[], int n, bool sexo, int tSeleccion[], 
                  int& numero);

/*
 * Pre: n >= 0, tFechas[0,n-1] almacena las fechas de nacimiento de un grupo de 
 *      personas y tSexo[i] almacena el sexo de la persona de ese grupo cuya fecha 
 *      de nacimiento es tFechas[i].
 *      Sean NH y NM el número de hombres y mujeres del grupo
 * Post: Permuta los datos de tFechas[0,n-1] y de tSexo[0,n-1] de forma que los
 *       datos tFechas[0,NM-1] y de tSexo[0,NM-1] correspondan a las NM mujeres 
 *       del grupo y los datos tFechas[NM,n-1] y de tSexo[NM,n-1] correspondan 
 *       a los NH hombres del grupo, manteniendo la propiedad de que tSexo[i] almacena
 *       el sexo de la persona de ese grupo cuya fecha de nacimiento es tFechas[i].
 */
void distribuir (int tFechas[], bool tSexo[], int n);

/*
 * Pre: n >= 0, tFechas[0,n-1] almacena las fechas de nacimiento de un grupo de 
 *      personas y tSexo[i] almacena el sexo de la persona de ese grupo cuya fecha 
 *      de nacimiento es tFechas[i]. 
 *      Sean NH y NM el número de hombres y mujeres del grupo
 * Post: Permuta los datos de tFechas[0,n-1] y de tSexo[0,n-1] de forma que queden
 *       ordenados según la edad, es decir, tFechas[0] y tSexo[0] almacenarán la 
 *       información de la persona más veterana del grupo y tFechas[n-1] y tSexo[n-1]
 *       los de la más joven, manteniendo la propiedad de que tSexo[i] almacena el
 *       sexo de la persona de ese grupo cuya fecha de nacimiento es tFechas[i].
 */
void ordenar (int tFechas[], bool tSexo[], int n);