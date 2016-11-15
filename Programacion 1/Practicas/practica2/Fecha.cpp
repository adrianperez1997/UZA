#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	char a, a2, a3, a4, m, m2, d, d2;
	
    cout << "Escriba una fecha con formato de 8 cifras [aaaammdd]: " << flush;
	cin >> a; 
	cin >> a2;
	cin >> a3;
	cin >> a4;
	cin >> m;
	cin >> m2;
	cin >> d;
	cin >> d2;
	
	cout << "La fecha escrita es " << d << d2<< "/" << m << m2 << "/" << a << a2 << a3 << a4<< endl;
    return 0;
}
