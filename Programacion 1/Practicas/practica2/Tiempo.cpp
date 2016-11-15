#include <iostream>
using namespace std;
int main()
{
   double segundos0;
   cout << "Duracion en segundos: " << flush;
   cin >> segundos0;
   segundos0=int(segundos0 + 0.5);
   int dias, horas, minutos, segundos;
   
   dias=segundos0 / 86400;
   horas=(segundos0 - dias*86400) / 3600;  
   minutos=(segundos0- ((horas * 3600)+(dias*86400))) / 60;  
   segundos=(segundos0-((horas * 3600)+(dias*86400)+(minutos*60))); 
  cout << "Este tiempo equivale a " << dias << " dias "<<horas
  <<" horas "<<minutos<<" minutos y "<< segundos << " segundos"<< endl;
}
