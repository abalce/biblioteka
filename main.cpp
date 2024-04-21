#include"bib.h"

int main()
{
    Powiesc d(7,"Dostojewski","Zbrodnia i Kara","Znak");
    d.wyswietl();

    Historyczna h(21,"ZZ Z","tak",1895);

    h.wyswietl();

    Naukowa n(54,"Neil deGrasse Tyson","Kosmiczne zachwyty","astronomia");

    Czytelnik Jakub(6,"kubus","puchatek");

    Jakub.wypozycz(&d);
    Jakub.wypozycz(&h);
    Jakub.wypozycz(&n);

    Jakub.usunNaukowe();

    cout<<Jakub<<endl;




    return 0;
}
