#include <iostream>
using namespace std;
/*
*Numero m ´ aximo de elementos en una secuencia (un valor positivo ) ´
*/
const int MAX =120; // Definir su valor segun necesidades (siempre MAX ´ > 0)
/*
*Un dato definido a partir del tipo generico Secuencia representa una secuencia ´
* de elementos de tipo T
*/
template <typename T>
struct Secuencia {
// El valor de numDatos define el numero K de elementos de la secuencia [d ´ 1, d 2, ..., d K]
// con K >= 0 y K <= MAX
int numDatos;
// Los elementos de la secuencia [d 1, d 2, ..., d K] se almacenan de forma contigua
// en el vector datos :
// d 1 se almacena en datos[0]
// d 2 se almacena en datos[1]
// ...
// y, finalmente , d K se almacena en datos[K−1]
T datos [MAX];
};




/*
* Pre: cierto
* Post : S.numDatos = 1 AND S.datos[0] = elemento
*/
template <typename T>
void unitaria (Secuencia<T>& S, const T elemento) {
	//1 = 1 AND elemento = elemento => cierto
	S.numDatos=1;
	//S.numDatos = 1 AND elemento = elemento
	S.datos[0]=elemento;
	//S.numDatos = 1 AND S.datos[0] = elemento
}

/*
* Pre: S.numDatos = K AND K >= 0 AND K < MAX AND
* (PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
* Post : S.numDatos = K + 1 AND S.datos[K] = ultimo AND
* (PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
*/
template <typename T>
void insertarUltimo (Secuencia<T>& S, const T ultimo) {
	//S.numDatos = K AND
	//(PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])=>
	//Pre: S.numDatos = K AND K >= 0 AND K < MAX AND
	//(PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
	
	//S.numDatos + 1 = K + 1 AND
	//(PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
	S.numDatos=S.numDatos+1;
	//S.numDatos = K + 1 AND ultimo = ultimo AND
	//(PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
	S.datos[S.numDatos-1]=ultimo;
	//S.numDatos = K + 1 AND S.datos[K] = ultimo AND
	//(PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
}

/*
* Pre: S.numDatos = K AND K >=1 AND K <= MAX AND
* (PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
* Post : S.numDatos = K − 1 AND
* (PT alfa EN [2,K]. S. datos[ alfa − 2] = Do[alfa])
*/
template <typename T>
void retirarPrimero (Secuencia<T>& S) {
	
	//S.numDatos = K AND K >=1 AND K <= MAX AND
	//(PT alfa EN [1,K]. S.datos[ alfa − 1] = Do[alfa]) =>
	eliminar(S,1);
	// S.numDatos = K − 1 AND
	//(PT alfa EN [1,i]. S.datos[ alfa − 1] = Do[alfa]) AND
	//(PT alfa EN [i+1,K]. S.datos[ alfa − 2] = Do[alfa])
	//AND i=1 =>
	
	// S.numDatos = K − 1 AND
	//(PT alfa EN [1,1]. S.datos[ alfa − 1] = Do[alfa]) AND
	//(PT alfa EN [2,K]. S.datos[ alfa − 2] = Do[alfa]) =>
	
	//Post : S.numDatos = K − 1 AND
	//(PT alfa EN [2,K]. S. datos[ alfa − 2] = Do[alfa])
}

/*
* Pre: S.numDatos = K AND K >=1 AND K <= MAX AND
* (PT alfa EN [1,K]. S.datos[ alfa − 1] = Do[alfa])
* AND i>0 AND i<=K
* Post : S.numDatos = K − 1 AND
* (PT alfa EN [1,i]. S.datos[ alfa − 1] = Do[alfa]) AND
* (PT alfa EN [i+1,K]. S.datos[ alfa − 2] = Do[alfa])
*/
template <typename T>
void eliminar (Secuencia<T>& S, int i) {
	
	//Pre: S.numDatos = K AND K >=1 AND K <= MAX AND
	//(PT alfa EN [1,K]. S.datos[ alfa − 1] = Do[alfa])
	//AND i>0 AND i<=K
	
	//Dom(i<S.numDatos)=>cierto
	if(i<S.numDatos){
		//S.numDatos = K AND K >=1 AND K <= MAX AND
		//(PT alfa EN [1,K]. S.datos[ alfa − 1] = Do[alfa])
		//AND i>0 AND i<K
		S.datos[i-1]=S.datos[i];
		eliminar(S,i+1);
		//S.numDatos = K − 1 AND
		//(PT alfa EN [1,i+1]. S.datos[ alfa − 1] = Do[alfa]) AND
		//(PT alfa EN [i+2,K]. S.datos[ alfa − 2] = Do[alfa])
		i=i-1;
		//S.numDatos = K − 1 AND
		//(PT alfa EN [1,i]. S.datos[ alfa − 1] = Do[alfa]) AND
		//(PT alfa EN [i+1,K]. S.datos[ alfa − 2] = Do[alfa])
	}
	
	else{
		//S.numDatos = K 
		//(PT alfa EN [1,i]. S.datos[ alfa − 1] = Do[alfa]) AND
		//(PT alfa EN [i+1,K]. S.datos[ alfa − 2] = Do[alfa])
		S.numDatos=S.numDatos-1;
		//S.numDatos = K − 1 AND
		//(PT alfa EN [1,i]. S.datos[ alfa − 1] = Do[alfa]) AND
		//(PT alfa EN [i+1,K]. S.datos[ alfa − 2] = Do[alfa])
	}
}

/*
* Pre: S.numDatos = K AND K >= 0 AND K <= MAX AND
* (PT alfa EN [1,K]. S. datos[ alfa − 1] = Do[alfa])
* Post : S.numDatos = K AND (K > 0 −> S.datos[0] = Do[K]) AND
* (PT alfa EN [1,K−1]. S.datos[ alfa ] = Do[alfa])
*/
template <typename T> 
void rotarDerecha (Secuencia<T>& S) {
	//Dom(S.numDatos>0)=>cierto
	if (S.numDatos>0){
		T aux=S.datos[S.numDatos-1];
		int i=S.numDatos-1;
		//S.numDatos = K AND i = K-1 AND K > 0 AND aux = Do[K]
		//PT alfa EN [i+1,K−1]. S.datos[alfa] = Do[alfa]
		while (i>0){
			//INV:S.numDatos = K AND i < K AND i > 0 AND aux = Do[K]
			//	  PT alfa EN [i+1,K−1]. S.datos[alfa] = Do[alfa]
			S.datos[i]=S.datos[i-1];
			i=i-1;
			//S.numDatos = K AND i < K AND i >= 0 AND aux = Do[K]
			//PT alfa EN [i,K−1]. S.datos[alfa] = Do[alfa]
		}
		//S.numDatos = K AND K >= 0 AND i = 0 AND aux = Do[K]
		//PT alfa EN [1,K−1]. S.datos[alfa] = Do[alfa]
		S.datos[0]=aux;
		//S.numDatos = K AND K >= 0 AND i = 0 AND S.datos[0] = Do[K]
		//PT alfa EN [1,K−1]. S.datos[alfa] = Do[alfa] =>
		//Post : S.numDatos = K AND (K > 0 −> S.datos[0] = Do[K]) AND
		//(PT alfa EN [1,K−1]. S.datos[ alfa ] = Do[alfa])
	}
}

/*
* Pre: S.numDatos = K AND K >= 0 AND K <= MAX
* Post : longitud (S) = K
*/
template <typename T>
int longitud (const Secuencia<T> S) {
	//S.numDatos = K AND K >= 0 AND K <= MAX =>
	//S.numDatos = K
	return S.numDatos;
	//longitud (S) = K
}




void mostrar(const Secuencia<int> S){
	
	int i=0;
	while(i!=S.numDatos){
		cout<<S.datos[i]<<endl;
		i++;
	}
	
}
int main(){
	
	Secuencia <int> prueba;
	unitaria(prueba,1);
	
	insertarUltimo(prueba,2);
	insertarUltimo(prueba,3);
	insertarUltimo(prueba,4);
	insertarUltimo(prueba,5);
	insertarUltimo(prueba,6);
	insertarUltimo(prueba,7);
	insertarUltimo(prueba,8);
	insertarUltimo(prueba,9);
	insertarUltimo(prueba,10);
	
	mostrar(prueba);
	cout<<endl<<endl;
	rotarDerecha(prueba);
	mostrar(prueba);
	cout<<longitud(prueba);
}