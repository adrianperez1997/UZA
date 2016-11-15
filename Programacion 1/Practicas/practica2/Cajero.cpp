#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
  int billete10=0;
  int billete20=0;
  int billete50=0;
  int cantidad;
  cout << "Cantidad a retirar en euros [positiva y multiplo de 10]: " << flush;
  cin >> cantidad;
  
  while (cantidad>=50){
	  billete50++;
	  cantidad=cantidad-50;
  }
  while (cantidad>=20){
	  billete20++;
	  cantidad=cantidad-20;
  }
while (cantidad>=10){
	  billete10++;
	  cantidad=cantidad-10;
}	 
cout << "Billetes" << setw(20) << "Euros"<< endl;
cout << "============================"<<endl;
cout << setw(5) << billete10 << setw(20) << "10"<<endl; 
cout << setw(5) << billete20 << setw(20) << "20"<<endl; 
cout << setw(5) << billete50 << setw(20) << "50"<<endl; 
    return 0;
}
