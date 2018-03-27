//testowanie klasy zbior
#include<iostream>
#include<cctype>
#include "zbior.h"

int main()
{
   using namespace std;
   Zbior A,B,C,D,E;
   double liczba;
   char ch;
   cout << "d-nowa, p-usuwanie, k-koniec,c-czy nalezy,l-licznosc,w-drukuj\n";
	cout << F;

while (cin >> ch && toupper(ch)!='K')
{

    switch (ch)
    {
	case 'e':
	   cout << "podaj liczbe dla zbioru B\n";
	   cin >> liczba;
	   B.dodaj_element(liczba);
	   break;
       case 'd':
           cout << "podaj nowa liczbe\n";
           cin >> liczba;
           A.dodaj_element(liczba);
           break;

       case 'p':
	   cout << "podaj liczbe do usuniecia\n";
	   cin >> liczba;
           A.usun_element(liczba);
           cout << "Liczba " << liczba << " usunieta\n";
           break;
	case 'c':
	   cout << "Wprowadz liczbe do sprawdzenia\n";
	   cin >> liczba;
	   if (A.czy_nalezy(liczba)) 
		cout << "Liczba " << liczba << " nalezy do zbioru A\n";
	   else
		cout << "Liczba " << liczba << " nie nalezy do zbioru A\n";
	   break;
	case 'l':
	   cout << "Licznosc zbioru A: " << A.liczba_elementow() << endl;
	   break;
	case 'w':
	   cout << A;
	   break;
	case 'q':
	   cout << B;
	   break;
	case '1':
	   C=A+B;
	   cout << "C suma:\n";
	   cout << C << "Licznosc zbioru C: " << C.liczba_elementow() << endl;
	   break;
	case '2':
	   A+=B;
	   cout << "Zbior A+=B: " << A << "Licznosc zbioru A: " << A.liczba_elementow() << endl;
	   break;
	case '3':
	   D=A-B;
	   cout << "D roznica:\n";
	   cout << D << "Licznosc zbioru D: " << D.liczba_elementow() << endl;
	   break;
	case '4':
	   A-=B;
	   cout << "Zbior A-=B: " << A << "Licznosc zbioru A: " << A.liczba_elementow() << endl;
	   break;
	case '5':
	   E=A*B;
	   cout << "Zbior E=A*B: " << E << "Licznosc zbioru E: " << E.liczba_elementow() << endl;
	   break;
	case '6':
	   A*=B;
	   cout << "Zbior A*=B: " << A << "Licznosc zbioru A: " << A.liczba_elementow() << endl;
	   break;
	case '7':
	    A==B;
	    break;
	case '8':
	    A!=B;
	    break;
    }

cout << "d-nowa, p-usuwanie, k-koniec,c-czy nalezy,l-licznosc,w-drukuj\n";

}

   cout << "Koniec testow\n";
   return 0;
}