#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	double euros;
	cout << "Escriba una cantidad de dinero en euros: " << flush;
	cin >> euros;
	const double CAMBIO = 166.3860;
	
	cout << "Son " << int (euros + 0.005) << " euros y " << int (100.0*(euros - int (euros + 0.005))+0.5)
	<< " centimos que equivalen a " << int (euros*CAMBIO + 0.5) << " pesetas"<< endl;
	
  return 0;
}
