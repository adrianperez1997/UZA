/*
 * Fichero de interfaz grupo.cc del módulo grupo
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
int fechaMasAntigua (int tFechas[], int n){
	int masAntigua=tFechas[0];
	int i=1;
	while (i<n){
		if(tFechas[i]< masAntigua){
			masAntigua=tFechas[i];
		}
		i++;
	}
	return masAntigua;
		
	}

/*
 * Pre: n > 0 y tFechas[inicial,n-1] almacena n fechas
 * Post: Devuelve el ínidice de la fecha almacenada en tFechas[inicial,n-1] más antigua
 */
int fechaMasAntigua (int tFechas[], int inicial, int n){
	int iMasAntigua=tFechas[inicial];
	int i=inicial+1;
	while (i<n){
		if(tFechas[i]< tFechas[iMasAntigua]){
			iMasAntigua=i;
		}
		i++;
	}
	return iMasAntigua;
		
}
/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el año que más se repite en el grupo de fechas almacenadas
 *       en tFechas[0,n-1]
 */
int anyoMasRepetido (int tFechas[], int n){
	int repeticiones[n];
	for(int i=0; i<n; ++i){repeticiones[i]=0;}
	for(int i=0; i<n; ++i){
		for(int j=i+1;j<n; ++j){
			if (tFechas[i]/10000==tFechas[j]/10000){++repeticiones[i];}
		}
	}
	int iMaximo=0;
	for(int i=1; i<n; ++i){
		if (repeticiones[i]>repeticiones[iMaximo]){iMaximo=i;}
	}
	return tFechas[iMaximo]/10000;
}

/*
 * Pre:  fecha tiene el formato aaaammdd.
 * Post: Ha devuelto el mes de fecha (mm).
 */
int mes(int fecha) {
	return ((fecha%10000)/100);
}

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el mes, un número del intervalo [1,12], que más se repite en el 
 *       grupo de fechas almacenadas en tFechas[0,n-1]
 */
int mesMasRepetido (int tFechas[], int n){
	int repeticiones[n];
	for(int i=0;i<n; ++i){repeticiones[i]=0;}
	for(int i=0; i<n; ++i){
		for(int j=i+1;j<n; ++j){
			if (mes(tFechas[i])==mes(tFechas[j])){++repeticiones[i];}
		}
	}
	int iMaximo=0;
	for(int i=1; i<n; ++i){
		if (repeticiones[i]>repeticiones[iMaximo]){iMaximo=i;}
	}
	return mes(tFechas[iMaximo]);
}
/*
 * Pre:  fecha tiene el formato aaaammdd.
 * Post: Ha devuelto el dia de fecha (aa).
 */
int dia(int fecha) {
	return fecha%100;
}
/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el día del mes, un valor comprendido en el intervalo [1-31],  
 *       que más se repite en el grupo de fechas almacenadas en tFechas[0,n-1]
 */
int diaMasRepetido (int tFechas[], int n){
	int repeticiones[n];
	for(int i=0;i<n; ++i){repeticiones[i]=0;}
	for(int i=0; i<n; ++i){
		for(int j=i+1;j<n; ++j){
			if (dia(tFechas[i])==dia(tFechas[j])){++repeticiones[i];}
		}
	}
	int iMaximo=0;
	for(int i=1; i<n; ++i){
		if (repeticiones[i]>repeticiones[iMaximo]){iMaximo=i;}
	}
	return dia(tFechas[iMaximo]);
}

/*
 * Pre: n > 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve la fecha que más se repite en el grupo de fechas almacenadas
 *       en tFechas[0,n-1]
 */
int fechaMasRepetida (int tFechas[], int n){
	int repeticiones[n];
	for(int i=0;i<n; ++i){repeticiones[i]=0;}
	for(int i=0; i<n; ++i){
		for(int j=i+1;j<n; ++j){
			if (tFechas[i]==tFechas[j]){++repeticiones[i];}
		}
	}
	int iMaximo=0;
	for(int i=1; i<n; ++i){
		if (repeticiones[i]>repeticiones[iMaximo]){iMaximo=i;}
	}
	return tFechas[iMaximo];
}

/*
 * Pre: n >= 0 y tFechas[0,n-1] almacena n fechas
 * Post: Devuelve el número de fechas almacenadas en tFechas[0,n-1] que
 *       coinciden con la fecha dia/mes/anyo
 */
int cuantos (int tFechas[], int n, int dia, int mes, int anyo){
	int fecha= dia+mes*100+anyo*10000;
	int j=0;
	for (int i=0; i<n; i++){
		if (fecha==tFechas[i]){
			++j;
		}
	}
	return j;
}

/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *    Funciones que trabajan con tablas de sexos                               *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

/*
 * Pre: n >= 0, tSexo[0,n-1] almacena el sexo de un grupo de personas
 * Post: Devuelve el número de datos de tSexo[0,n-1] que corresponden a hombres
 */
int hombres (bool tSexo[], int n){
	int j=0;
	for (int i=0; i<n; i++){
		if (tSexo[i]==false){
			++j;
		}
	}
	return j;
}

/*
 * Pre: n >= 0, tSexo[0,n-1] almacena el sexo de un grupo de personas
 * Post: Devuelve el número de datos de tSexo[0,n-1] que corresponden a mujeres
 */
int mujeres (bool tSexo[], int n){
	int j=0;
	for (int i=0; i<n; i++){
		if (tSexo[i]){
			++j;
		}
	}
	return j;
}

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
int contar (int tFechas[], bool tSexo[], int n, int desde, int hasta, bool hombres, bool mujeres){
	int NH=0;
	int NM=0;
	for (int i=0; i<n; i++){
		if(tFechas[i]>=desde && tFechas[i]<=hasta){
			if (tSexo[i]==true){
				NM++;
			}
			else if (tSexo[i]==false){
				NH++;
			}
		}
	}
	if (hombres==true&&mujeres==true){
		return NH+NM;
	}
	else if (hombres==true&&mujeres==false){
		return NH;
	}
	else if (mujeres==true&&hombres==false){
		return NM;
	}
	else if (hombres==false && mujeres==false){
		return 0;
	}
}
	
			
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
                  int& numero){
	int NH=0;
	int NM=0;
	for (int i=0; i<n; i++){
		if (tSexo[i]){
			NM++;
		}
		else if (tSexo[i]==false){
			NH++;
		}
	}
	int i=0;
	int j=0;
	if (sexo){
		numero=NM;
		tSeleccion[numero];
		while(i<NM){
			if (tSexo[i]){
				tSeleccion[j]=tSexo[i];
				j++;
			}
			i++;
		}		
	}
	else if (sexo==false){
		numero=NH;
		tSeleccion[numero];
		while(i<NH){
			if (tSexo[i]){
				tSeleccion[j]=tSexo[i];
				j++;
			}
			i++;
		}		
	}
				  }

	

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
void distribuir (int tFechas[], bool tSexo[], int n) {
	int i=0;
	bool tAlmacenMuj[n];
	bool tAlmacenHom[n];
	int tAlmacenFechasH[n];
	int tAlmacenFechasM[n];
	int j=0;
	int h=0;
	while(i<n){
		if (tSexo[i]){
			tAlmacenMuj[j]=tSexo[i];
			tAlmacenFechasM[j]=tFechas[i];
			j++;
		}
		else if (tSexo[i]==false){
			tAlmacenHom[h]=tSexo[i];
			tAlmacenFechasH[h]=tFechas[i];
			h++;
		}
		i++;
	}
	for(int i=0; i<=j; i++){
		tSexo[i]=tAlmacenMuj[i];
		tFechas[i]=tAlmacenFechasM[i];
	}
	while(i<(h+j)){
		tSexo[i]=tAlmacenHom[i-j];
		tFechas[i]=tAlmacenFechasH[i-j];
		i++;
	}
	
}

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
void ordenar (int tFechas[], bool tSexo[], int n){
	int i=0;
	int fechasOrdenadas[n];
	while(i<n){
		int indiceMenor = fechaMasAntigua(tFechas, i, n);
		tFechas[i]=0;
		i++;
	}
	return fechasOrdenadas[];
	
}
