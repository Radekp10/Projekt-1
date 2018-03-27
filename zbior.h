//klasa reprezentujaca zbior liczb rzeczywistych

#include<iostream>
using std::ostream;



class Zbior
{
private:
    static const int MAX = 1000;				//max dopuszczalny rozmiar zbioru
    double liczby[MAX];							//tablica liczb rzeczywistych
    int licznosc;								//liczba elementow zbioru
public:
    Zbior();									//konstruktor
    ~Zbior();									//destruktor
    bool dodaj_element(const double liczba);	//dodawanie elementu do zbioru
    bool usun_element(const double liczba);		//usuwanie elementu ze zbioru
    bool czy_nalezy(const double liczba);		//sprawdzenie, czy element nalezy do zbioru
    int liczba_elementow();						//okreslenie liczby elementow zbioru
    Zbior operator+(const Zbior & B);			//suma zbiorow
    Zbior operator+=(const Zbior & B);			
    Zbior operator-(const Zbior & B);			//roznica zbiorow
    Zbior operator-=(const Zbior & B);
    Zbior operator*(const Zbior & B);			//przeciecie zbiorow
    Zbior operator*=(const Zbior & B);
    bool operator==(const Zbior & B);			//rownosc zbiorow
    bool operator!=(const Zbior & B);			//rozlacznosc zbiorow
    friend ostream & operator<<(ostream & os,const Zbior & A);	//drukowanie zbioru
};
