//klasa reprezentujaca zbior liczb rzeczywistych

#include<iostream>
using std::ostream;



class Zbior
{
private:
    static const int MAX = 1000;
    double liczby[MAX];
    int licznosc;
public:
    Zbior();
    ~Zbior();
    bool dodaj_element(const double & liczba);
    bool usun_element(double & liczba);
    bool czy_nalezy(double & liczba);
    int liczba_elementow();
    Zbior operator+(const Zbior & B);
    Zbior operator+=(const Zbior & B);
    Zbior operator-(const Zbior & B);
    Zbior operator-=(const Zbior & B);
    Zbior operator*(const Zbior & B);
    Zbior operator*=(const Zbior & B);
    bool operator==(const Zbior & B);
    bool operator!=(const Zbior & B);
    friend ostream & operator<<(ostream & os,const Zbior & A);
};
