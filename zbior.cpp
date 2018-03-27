//metody klasy zbior
#include "zbior.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior::Zbior()					//konstruktor domyslny
{
    licznosc=0;
    int i;
    for (i=0;i<MAX;i++)
	liczby[i]=0.0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior::~Zbior()					//destruktor
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zbior::dodaj_element(const double & liczba) //dodanie elementu do zbioru
{
    if (licznosc<MAX)				//sprawdzenie, czy zbior nie jest pelny
    {
	int i;					//zmienna do obslugi petli
        for (i=0;i<licznosc;i++)
	    if (liczby[i]==liczba)		//sprawdzenie, czy liczba juz nalezy do zbioru
		{
		std::cout << "Liczba " << liczba << " juz nalezy do zbioru.\n";
		return false;
		}
	liczby[licznosc++]=liczba;		//dodanie nowej liczby
	//std::cout << "Dodano nowa liczbe do zbioru.\n";
        return true;
    }
    else
    {
	std::cout << "Zbior jest pelny.\n";
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zbior::usun_element(double & liczba)	//usuniecie elementu ze zbioru
{
    int i,j;					//zmienne do obslugi petli
    if (licznosc>0)				//sprawdzenie, czy zbior nie jest pusty
    {
        for (i=0;i<licznosc;i++)
	    if (liczby[i]==liczba)		//sprawdzenie, czy element, ktory chcemy usunac, nalezy do zbioru
		{
		    for (j=(i+1);j<licznosc;j++) //przestawienie liczb na prawo od usuwanej liczy o jedna pozycje w lewo
			liczby[j-1]=liczby[j];
		    liczby[licznosc-1]=0.0;	//wyzerowanie pozycji, ktora nie nalezy juz do zbioru
		    licznosc--;			//zmniejszenie licznosci zbioru o 1
		    //std::cout << "Liczba " << liczba << " usunieta.\n";
		    return true;
		}
	std::cout << "Liczba " << liczba << " nie nalezy do zbioru.\n";
	return false;
    }
    std::cout << "Zbior jest pusty\n";
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zbior::czy_nalezy(double & liczba)		//sprawdzenie, czy element nalezy do zbioru
{
    int i;					//zmienna do obslugi petli
    for (i=0;i<licznosc;i++)
        if (liczby[i]==liczba)			//poszukiwanie danej liczby w zbiorze
	return true;
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Zbior::liczba_elementow()			//liczba elementow zbioru
{
    return licznosc;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator+(const Zbior & B)		//suma zbiorow
{
    int i,j;					//zmienne do obslugi petli
    int k;
    Zbior C;					//utworzenie zbioru C
    bool koniec;				//jesli 'true', to operacja jest przerywana				
    koniec=false;				//(przekroczono max dopuszczalny rozmiar zbioru)

    for (i=0;i<licznosc;i++)			//skopiowanie wszystkich elementow zbioru, dla ktorego wywolywana jest metoda,
	C.liczby[i]=liczby[i];			//do zbioru C
    C.licznosc = licznosc;			//ustalenie poczatkowej licznosci zbioru C


    for (i=0;i<B.licznosc;i++)			//teraz sprawdzamy, ktore elementu zbioru B (parametr metody) nie wystepuja
    {						//jeszcze w zbiorze C
	k=0;
        for (j=0;j<licznosc;j++)
	    if (B.liczby[i]!=C.liczby[j])	//dla kazdego elementu ze zbioru B sprawdzamy, czy nie nalezy juz on do zbioru C:
	        k++;				//w tym celu porownujemy kazdy element zbioru B z poczatkowymi elementami zbioru C
      						//(jest ich 'licznosc') i zwiekszmay indeks 'k' o jeden, jesli ten element 
						//jest rozny od sprawdzanego elementu zbioru C
	if (k==licznosc)			//jesli element nie nalezy do C, to go dodajemy
	{    					//w przeciwnym przypadku element nie jest dodawany do zbioru C
	    C.liczby[C.licznosc]=B.liczby[i];
	    C.licznosc++;
	    if (C.licznosc>=MAX)
		{
		    koniec=true;		//jesli przekroczono max dopuszczalny rozmiar zbioru
		    break;
		}
	}
    }

    if (koniec==true) std::cout << "Przekroczono max dozwolony rozmiar zbioru.\n";
    return C;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator+=(const Zbior & B)	//suma zbiorow z nadpisaniem
{
    int i,j;					//zmienne do obslugi petli
    int k;
    int licznosc_pocz;				//poczatkowa liczba elementow zbioru dla ktorego wywolano metode
    licznosc_pocz=licznosc;			//zbior dla ktorego wywolano metode (ozn. Z_wyw)
    bool koniec1;				//jesli 'true', to operacja jest przerywana			
    koniec1=false;				//(przekroczono max dopuszczalny rozmiar zbioru)

    for (i=0;i<B.licznosc;i++)			//sprawdzenie, ktore elementu zbioru B (parametr metody) nie wystepuja
    {						//jeszcze w zbiorze Z_wyw
	k=0;
        for (j=0;j<licznosc_pocz;j++)
	    if (B.liczby[i]!=liczby[j])		//dla kazdego elementu ze zbioru B sprawdzamy, czy nie nalezy juz on do zbioru Z_wyw:
	        k++;				//w tym celu porownujemy kazdy element zbioru B z poczatkowymi elementami zbioru Z_wyw
      						//(jest ich 'licznosc_pocz') i zwiekszmay indeks 'k' o jeden, jesli ten element 
						//jest rozny od sprawdzanego elementu zbioru Z_wyw;
	if (k==licznosc_pocz)			//jesli element nie nalezy do Z_wyw, to go dodajemy
	{    					//w przeciwnym przypadku element nie jest dodawany do zbioru Z_wyw
	    liczby[licznosc]=B.liczby[i];
	    licznosc++;
	    if (licznosc>=MAX)
	    {
	        koniec1=true;			//jesli przekroczono max dopuszczalny rozmiar zbioru
	        break;
	    }
	}
    }
    if (koniec1==true) std::cout << "Przekroczono max dozwolony rozmiar zbioru.\n";
    return *this;				//zwrocenie zmodyfikowanego zbioru Z_wyw
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator-(const Zbior & B)		//roznica zbiorow
{
    int i,j;					//zmienne do obslugi petli
    Zbior C;

    for (i=0;i<licznosc;i++)			//skopiowanie wszystkich elementow zbioru, dla ktorego wywolywana jest metoda,
	C.liczby[i]=liczby[i];			//do zbioru C
    C.licznosc = licznosc;			//ustalenie poczatkowej licznosci zbioru C


    for (i=0;i<B.licznosc;i++)			//teraz sprawdzamy, ktore elementu zbioru B (parametr metody) wystepuja w zbiorze C
    {
        for (j=0;j<C.licznosc;j++)
	    if (B.liczby[i]==C.liczby[j])	//dla kazdego elementu ze zbioru B sprawdzamy, czy nalezy on do zbioru C;
	        {
		C.usun_element(C.liczby[j]);	//jesli nalezy, do go usuwamy
      		break;				//i przechodzimy do sprawdzenia dla kolejnego elementu zbioru B
		}
    }
    return C;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator-=(const Zbior & B)	//roznica zbiorow z nadpisaniem
{
    int i,j;					//zmienne do obslugi petli

    for (i=0;i<B.licznosc;i++)			//sprawdzamy, ktore elementu zbioru B (parametr metody) wystepuja w zbiorze,
    {						//dla ktorego wywolano metode
        for (j=0;j<licznosc;j++)
	    if (B.liczby[i]==liczby[j])		//dla kazdego elementu ze zbioru B sprawdzamy, czy nalezy on do zbioru,
	        {				//dla ktorego wywolano metode;
		usun_element(liczby[j]);	//jesli nalezy, do go usuwamy
      		break;				//i przechodzimy do sprawdzenia dla kolejnego elementu zbioru B
		}
    }
    return *this;				//zwrocenie zmodyfikowanego zbioru
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator*(const Zbior & B)		//przeciecie zbiorow
{
    int i,j;					//zmienne do obslugi petli
    Zbior C;

    for (i=0;i<licznosc;i++)			//poszukiwanie elementow wspolnych dla obu zbiorow
	for (j=0;j<B.licznosc;j++)
	    {
		if (liczby[i]==B.liczby[j])	//jesli znaleziono, to ten element dodajemy do zbioru C
		    {
			C.liczby[C.licznosc]=liczby[i];
			C.licznosc++;
			break;
		    }
	    }
   
    return C;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Zbior Zbior::operator*=(const Zbior & B)	//przeciecie zbiorow z nadpisaniem
{
    int i,j;					//zmienne do obslugi petli
    Zbior C;					//obiekt tymczasowy, bedzie przechowywal czesc wspolna zbiorow

    for (i=0;i<licznosc;i++)			//poszukiwanie elementow wspolnych dla obu zbiorow
	for (j=0;j<B.licznosc;j++)
	    {
		if (liczby[i]==B.liczby[j])
		    {
			C.liczby[C.licznosc]=liczby[i];
			C.licznosc++;
			break;
		    }
	    }

    for (i=0;i<licznosc;i++)			//przypisanie wartosci poczatkowych zbiorowi, dla ktorego wywolano metode
	{
	    liczby[i]=0.0;
	    licznosc=0;
	}

    for (i=0;i<C.licznosc;i++)			//przypisanie temu zbiorowi elementow ze zbioru tymczasowego C
	{
	    liczby[i]=C.liczby[i];
	    licznosc=C.licznosc;
	}

    return *this;				//zwrocenie zmodyfikowanego zbioru
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zbior::operator==(const Zbior & B)		//rownosc zbiorow
{
    if (licznosc!=B.licznosc)			//jesli zbiory maja rozna liczbe elementow to nie sa sobie rowne
	{
	    std::cout << "Zbiory nie sa rowne.\n";
	    return false;
	}

    int i,j;					//zmienne do obslugi petli
    int dopasowane;				//ile elementow z danego zbioru udalo sie sparowac z elemntami z drugiego zbioru
    dopasowane=0;

    for (i=0;i<licznosc;i++)
	for (j=0;j<B.licznosc;j++)
		if (liczby[i]==B.liczby[j])
			dopasowane++;

    if (dopasowane==licznosc)			//zbiory beda sobie rowne, jesli kazdemu elementowi z jednego zbioru uda sie
	{					//przyporzadkowac pare z drugiego zbioru
	    std::cout << "Zbiory sa sobie rowne.\n";				
	    return true;
	}
    else
	{
	std::cout << "Zbiory nie sa rowne.\n";
	return false;	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Zbior::operator!=(const Zbior & B)		//rozlacznosc zbiorow
{
    int i,j;					//zmienne do obslugi petli

    for (i=0;i<licznosc;i++)
	for (j=0;j<B.licznosc;j++)
		if (liczby[i]==B.liczby[j])	//jesli uda sie znalezc dwa takie same elementy w dwoch zbiorach, to na pewno
		{				//nie sa one rozlaczne
		    std::cout << "Zbiory nie sa rozlaczne.\n";    
		    return false;		
		}

    std::cout << "Zbiory sa rozlaczne.\n";
    return true;				//w przeciwnym przypadku zbiory sa rozlaczne
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os,const Zbior & B)	//drukowanie zbioru
{
    int i;					//zmienna do obslugi petli

    if (B.licznosc!=0)				//jesli zbior jest niepusty
    {
	os << "{"; 
	for (i=0;i<(B.licznosc-1);i++)
	    os << B.liczby[i] << ", ";
        os << B.liczby[B.licznosc-1] << "}\n";
    }
    else
	os << "{}\n";				//jesli zbior jest pusty

    return os;
}