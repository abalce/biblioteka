#ifndef BIB
#define BIB

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Ksiazka
{
private:
    int id;
    string autor;
    string tytul;
public:
    Ksiazka(int id, string autor, string tytul) : id(id), autor(autor), tytul(tytul) {}
    virtual ~Ksiazka() = default;
    virtual void wyswietl() const =0;
    int getid() const {return id;}
    string getautor() const {return autor;}
    string gettytul() const {return tytul;}
};

class Powiesc : public Ksiazka
{
private:
    string wydawca;
public:
    Powiesc(int id, string autor, string tytul, string wydawca) : Ksiazka(id,autor,tytul), wydawca(wydawca) {}
    ~Powiesc() {cout<<"\n ~Powiesc";}
    void wyswietl() const override
    {
        cout<<"id: "<<getid()<<"\nAutor: "<<getautor()<<" Tytul: "<<gettytul()<<"\nwydawca: "<<wydawca<<endl;
    }
};

class Historyczna : public Ksiazka
{
private:
    int rok;
public:
    Historyczna(int id, string autor, string tytul, int rok) : Ksiazka(id,autor,tytul), rok(rok) {}
    ~Historyczna() {cout<<"\n ~Historyczna";}
    void wyswietl() const override
    {
        cout<<"id: "<<getid()<<"\nAutor: "<<getautor()<<" Tytul: "<<gettytul()<<"\nrok: "<<rok<<endl;
    }
};

class Naukowa : public Ksiazka
{
private:
    string dziedzina;
public:
    Naukowa(int id, string autor, string tytul, string dziedzina) : Ksiazka(id, autor, tytul), dziedzina(dziedzina) {}
    ~Naukowa() {cout<<"\n ~Naukowa";}
    void wyswietl() const override
    {
       cout<<"id: "<<getid()<<"\nAutor: "<<getautor()<<" Tytul: "<<gettytul()<<"\ndziedzina: "<<dziedzina<<endl;
    }
};


/// czytelnik

class Czytelnik
{
private:
    int nr;
    string imie;
    string nazwisko;
    vector<Ksiazka*>lista;
public:
    Czytelnik(int nr,string imie, string nazwisko) :nr(nr), imie(imie), nazwisko(nazwisko) {}
    ~Czytelnik() = default;

    void wypozycz(Ksiazka* ksiazka)
    {
        lista.push_back(ksiazka);
        cout<<"\nKsiazka wypozyczona przez czytelnika o numerze: "<<nr<<endl;
    }

    friend ostream& operator<<(ostream& os, const Czytelnik& czytelnik)
    {
        os<<"\nCzytelnik o numerze: "<<czytelnik.nr<<"\nImie: "<<czytelnik.imie<<"\nNazwisko: "<<czytelnik.nazwisko<<endl;
        os<<"\n\nWypozyczone ksiazki:"<<endl;
        for(const auto* ksiazka : czytelnik.lista)
        {
            ksiazka->wyswietl();
        }
        return os;
    }


    void operator-=(int indeks)
    {
        lista.erase(lista.begin()+indeks);
    }

    void usunNaukowe()
{
    for (auto it = lista.begin(); it != lista.end(); )
    {
        if (dynamic_cast<Naukowa*>(*it) != nullptr)
        {
            it = lista.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

};
#endif // BIB
