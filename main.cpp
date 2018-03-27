//testowanie klasy Zbior

#include<iostream>
#include "zbior.h"

int main()
{
    using namespace std;
    Zbior A,B,C,D,E,F,G,H;

    A.dodaj_element(1.1);
    A.dodaj_element(0.1);
    A.dodaj_element(11.41);
    A.dodaj_element(-41.1);
    A.dodaj_element(333.551);
    A.dodaj_element(0.0);
    A.dodaj_element(55.451);
    A.dodaj_element(9.0);
    A.dodaj_element(-999.88);

    B.dodaj_element(34.55);
    B.dodaj_element(-67.88);
    B.dodaj_element(9.0);
    B.dodaj_element(-41.1);
    B.dodaj_element(55.665);
    B.dodaj_element(-100.0);
    B.dodaj_element(333.551);
    B.dodaj_element(1.1);
    B.dodaj_element(-2.2);
    B.dodaj_element(0.0);
    B.dodaj_element(404.4);
    B.dodaj_element(-87.8);

    cout << "A= " << A << endl << "B= " << B << endl << endl;


    cout << "Suma zbiorow A i B:" << endl;
    C=A+B;
    cout << "C=A+B" << endl << "C= " << C << endl << endl;


    cout << "Suma zbiorow A i B z nadpisaniem zawartosci:" << endl; 
    A+=B;
    cout << "A+=B" << endl << "A= " << A << endl << endl;


    cout << "Roznica zbiorow A i B:" << endl;
    D=A-B;
    cout << "D=A-B" << endl << "D= " << D << endl << endl;


    cout << "Roznica zbiorow A i B z nadpisaniem zawartosci:" << endl;
    A-=B;
    cout << "A-=B" << endl << "A= " << A << endl << endl;


    cout << "Przeciecie zbiorow A i B:" << endl;
    E=A*B;
    cout << "E=A+B" << endl << "E= " << E << endl << endl;


    cout << "Przeciecie zbiorow A i B z nadpisaniem zawartosci:" << endl;
    A*=B;
    cout << "A*=B" << endl << "A= " << A << endl << endl;


    cout << "Rownosc zbiorow A i B:" << endl;
    A==B;


    cout << "Rozlacznosc zbiorow A i B:" << endl;
    A!=B;



    F.dodaj_element(34.55);
    F.dodaj_element(21.33);
    F.dodaj_element(0.0);
    F.dodaj_element(-0.99);

    G.dodaj_element(0.0);
    G.dodaj_element(34.55);
    G.dodaj_element(-0.99);
    G.dodaj_element(21.33);

    H.dodaj_element(43.54);
    H.dodaj_element(-12.34);
    H.dodaj_element(456.0099);
    H.dodaj_element(-0.0313);


    cout << "Rownosc zbiorow F i G" << endl;
    F==G;
    cout << endl;

    cout << "Rownosc zbiorow F i H" << endl;
    F==H;
    cout << endl;

    cout << "Rozlacznosc zbiorow F i G" << endl;
    F!=G;
    cout << endl;

    cout << "Rozlacznosc zbiorow F i H" << endl;
    F!=H;
    cout << endl;



    return 0;
}