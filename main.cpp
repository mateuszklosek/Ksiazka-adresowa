#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;


struct Adresat {
    int id;
    string imie, nazwisko, tel, email, adres;
};

vector<Adresat> nowy(vector<Adresat> kontakt) {
    string imie, nazwisko, tel, email, adres;
    int numberOfContacts = kontakt.size();
    int lastId;
    Adresat singleContact;
    system("cls");

    if(kontakt.empty()) {
        lastId = 0;
    } else {
        lastId = kontakt[numberOfContacts-1].id;
    }

    cout << "Tworzenie nowego kontaktu: " << endl;
    cout << "Podaj Imie: ";
    cin >> imie;
    cout << "Podaj Nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, tel);
    cout << "Podaj adres email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    singleContact = {lastId + 1, imie, nazwisko, tel, email, adres};
    kontakt.push_back(singleContact);

    cout << kontakt[numberOfContacts].id<<endl;
    cout << kontakt[numberOfContacts].imie<<endl;
    cout << kontakt[numberOfContacts].nazwisko<<endl;
    cout << kontakt[numberOfContacts].tel<<endl;
    cout << kontakt[numberOfContacts].email<<endl;
    cout << kontakt[numberOfContacts].adres<<endl;

    fstream plik;
    plik.open("ksiazka.txt",ios::out | ios::app);

    plik<<lastId+1<<"|";
    plik<<imie<<"|";
    plik<<nazwisko<<"|";
    plik<<tel<<"|";
    plik<<email<<"|";
    plik<<adres<< "|" << endl;

    plik.close();

    cout << "Kontakt " << imie << " " << nazwisko << " zostal dodany pomyslnie!"<< endl;

    Sleep(3000);
    return kontakt;
}

int lista(vector<Adresat> kontakt, char menu) {
    int numberOfContacts = kontakt.size();
    char wybor;

    while(1) {
        if (menu == '4') {
            system("cls");
            for (int i=0; i<numberOfContacts; i++)
                cout << "ID " << kontakt[i].id << " " << "Imie: " << kontakt[i].imie << " " << "Nazwisko: " << kontakt[i].nazwisko << " " << "Nr tel.: " << kontakt[i].tel << " " << "E-mail: " << kontakt[i].email << " " << "Adres: " << kontakt[i].adres << " " << endl;
            cout << "Wcisnij 1 aby wrocic do menu" << endl;
            cin >> wybor;
            if (wybor == '1') {
                return 0;
            }
        }
    }
    return 0;
}

int poImieniu(vector<Adresat> kontakt,char menu) {
    int numberOfContacts = kontakt.size();
    char wybor;
    string imie;
    bool znaleziono = false;

    while(1) {
        if (menu == '2') {
            system("cls");
            cout << "Jakiego imienia szukasz?" << endl;
            cin >> imie;
            for (int i=0; i<numberOfContacts; i++) {
                if (imie == kontakt[i].imie) {
                    cout << "Nr " << kontakt[i].id << " " << "Imie: " << kontakt[i].imie << " " << "Nazwisko: " << kontakt[i].nazwisko << " " << "Nr tel.: " << kontakt[i].tel << " " << "E-mail: " << kontakt[i].email << " " << "Adres: " << kontakt[i].adres << " " << endl;
                    znaleziono = true;
                }
            }
            if (znaleziono == false)
                cout << "Nie znaleziono kontaktu o imieniu: " << imie <<  endl;
            cout << "\n" << "Wcisnij 1 aby wrocic do menu" << endl;
            cin >> wybor;
            if (wybor == '1') {
                return 0;
            }
        }
    }
    return 0;
}

int poNazwisku(vector<Adresat> kontakt,char menu) {
    int numberOfContacts = kontakt.size();
    char wybor;
    string nazwisko;
    bool znaleziono1 = false;

    while(1) {
        if (menu == '3') {
            system("cls");
            cout << "Jakiego nazwiska szukasz?" << endl;
            cin >> nazwisko;
            for (int i=0; i<numberOfContacts; i++) {
                if (nazwisko == kontakt[i].nazwisko) {
                    cout << "Nr " << kontakt[i].id << " " << "Imie: " << kontakt[i].imie << " " << "Nazwisko: " << kontakt[i].nazwisko << " " << "Nr tel.: " << kontakt[i].tel << " " << "E-mail: " << kontakt[i].email << " " << "Adres: " << kontakt[i].adres << " " << endl;
                    znaleziono1 = true;
                }
            }
            if (znaleziono1 == false)
                cout << "Nie znaleziono kontaktu o nazwisku: " << nazwisko <<  endl;
            cout << "\n" << "Wcisnij 1 aby wrocic do menu" << endl;
            cin >> wybor;
            if (wybor == '1') {
                return 0;
            }
        }
    }
    return 0;
}

vector<Adresat> usun(vector<Adresat> kontakt) {
    int numberOfContacts = kontakt.size(), id, kontakt_do_usuniecia;
    char decyzja;
    bool sprawdzenie = false;
    system("cls");

    if(kontakt.empty()) {
        cout << "Baza kontaktow jest pusta!" <<endl;
    } else {
        cout << "Podaj id kontaktu ktory chcesz usunac" << endl;
        cin >> id;
        for (int i=0; i<numberOfContacts; i++) {
            if (id == kontakt[i].id) {
                kontakt_do_usuniecia = i;
                sprawdzenie = true;
            }
        }
        if (sprawdzenie == false) {
            cout << "Nie ma kontaktu o takim ID!";
            Sleep(2000);
            return kontakt;
        }
        cout << "Czy napewno chcesz usunac kontakt: " << kontakt[kontakt_do_usuniecia].imie << " " << kontakt[kontakt_do_usuniecia].nazwisko << " o numerze ID " << kontakt[kontakt_do_usuniecia].id << " ?" << endl;
        cout << "Jesli tak, wcisnij t"<<endl;
        cout << "Jesli nie, wcisnij n"<<endl;
        cin >> decyzja;


        if (decyzja == 't') {
            kontakt.erase(kontakt.begin()+kontakt_do_usuniecia);
            cout << "Kontakt od numerze ID " << id << " zostal usuniety!" <<endl;

            fstream plik;
            plik.open("ksiazka.txt",ios::out | ios::trunc);
            numberOfContacts = kontakt.size();
            for (int i = 0; i < numberOfContacts; i++) {
                plik<<kontakt[i].id<<"|";
                plik<<kontakt[i].imie<<"|";
                plik<<kontakt[i].nazwisko<<"|";
                plik<<kontakt[i].tel<<"|";
                plik<<kontakt[i].email<<"|";
                plik<<kontakt[i].adres<<"|"<<endl;
            }
            plik.close();
        }
    }
    Sleep(2000);
    return kontakt;
}

vector<Adresat> edytuj(vector<Adresat> kontakt) {
    string imie, nazwisko, tel, email, adres;
    int numberOfContacts = kontakt.size(), id, kontakt_do_edycji;
    char decyzja, wybor;
    bool sprawdzenie = false;
    system("cls");

    if(kontakt.empty()) {
        cout << "Baza kontaktow jest pusta!" <<endl;
    } else {
        cout << "Podaj id kontaktu ktory chcesz edytowac" << endl;
        cin >> id;
        for (int i=0; i<numberOfContacts; i++) {
            if (id == kontakt[i].id) {
                kontakt_do_edycji = i;
                sprawdzenie = true;
            }
        }
        if (sprawdzenie == false) {
            cout << "Nie ma kontaktu o takim ID!";
            Sleep(2000);
            return kontakt;
        }
        cout << "Wybierz ktora dane chcesz edytowac" << endl;
        cout << "1 - imie" << endl;
        cout << "2 - nazwisko" << endl;
        cout << "3 - numer telefonu" << endl;
        cout << "4 - email" << endl;
        cout << "5 - adres" << endl;
        cout << "6 - powrot do menu" << endl;
        cin >> wybor;

        if (wybor == '1') {
            cout << "Podaj nowe imie: ";
            cin >> imie;
            kontakt[kontakt_do_edycji].imie = imie;
            cout << "Udalo sie!" << endl;
        } else if (wybor == '2') {
            cout << "Podaj nowe nazwisko: ";
            cin >> nazwisko;
            kontakt[kontakt_do_edycji].nazwisko = nazwisko;
            cout << "Udalo sie!" << endl;
        } else if (wybor == '3') {
            cout << "Podaj nowy numer telefonu: ";
            cin.sync();
            getline(cin, tel);
            kontakt[kontakt_do_edycji].tel = tel;
            cout << "Udalo sie!" << endl;
        } else if (wybor == '4') {
            cout << "Podaj nowy email: ";
            cin >> email;
            kontakt[kontakt_do_edycji].email = email;
            cout << "Udalo sie!" << endl;
        } else if (wybor == '5') {
            cout << "Podaj nowy adres: ";
            cin.sync();
            getline(cin, adres);
            kontakt[kontakt_do_edycji].adres = adres;
            cout << "Udalo sie!" << endl;
        } else if (wybor == '6') {
            return kontakt;
        }
        fstream plik;
        plik.open("ksiazka.txt",ios::out | ios::trunc);
        numberOfContacts = kontakt.size();
        for (int i = 0; i < numberOfContacts; i++) {
            plik<<kontakt[i].id<<"|";
            plik<<kontakt[i].imie<<"|";
            plik<<kontakt[i].nazwisko<<"|";
            plik<<kontakt[i].tel<<"|";
            plik<<kontakt[i].email<<"|";
            plik<<kontakt[i].adres<<"|"<<endl;
        }
        plik.close();
    }
    Sleep(2000);
    return kontakt;
}


Adresat konwersja_danych_z_pliku(string linia) {
    Adresat singleContact;
    string daneKontaktu[6];
    int liczba_zmiennej=0, pozycja = 0, licznik = 0, dlugosc_lini, id;

    dlugosc_lini = linia.length();
    for (int i=0; i<dlugosc_lini-1; i++) {

        if (linia[i] == '|') {
            daneKontaktu[liczba_zmiennej] = linia.substr(pozycja,licznik);
            liczba_zmiennej++;
            pozycja = i+1;
            licznik = 0;
        } else {
            licznik ++;
        }
    }
    daneKontaktu[liczba_zmiennej] = linia.substr(pozycja,licznik);
    id = atoi(daneKontaktu[0].c_str());
    singleContact = {id, daneKontaktu[1], daneKontaktu[2], daneKontaktu[3], daneKontaktu[4], daneKontaktu[5]};
    return singleContact;
}

int main() {

    vector<Adresat> kontakt;
    int menu = 0;
    string linia;
    int dlugosc_linii;
    char wybor, wybor1;
    string imie, nazwisko, tel, email, adres;
    int id;
    Adresat singleContact;

    fstream plik;
    plik.open("ksiazka.txt", ios::in);

    if(plik.good()== false) cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, linia)) {
        singleContact = konwersja_danych_z_pliku(linia);
        kontakt.push_back(singleContact);
    }

    plik.close();

    while(1) {
        if (menu == 0) {
            system("cls");
            cout << "1. Dodaj kontakt" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "9. Zakonczenie programu" << endl;
            cin >> wybor;

            if (wybor == '1') {
                kontakt = nowy(kontakt);
            } else if (wybor == '2') {
                menu = poImieniu(kontakt, wybor);
            } else if (wybor == '3') {
                menu = poNazwisku(kontakt, wybor);
            } else if (wybor == '4') {
                menu = lista(kontakt, wybor);
            } else if (wybor == '5') {
                kontakt = usun(kontakt);
            } else if (wybor == '6') {
                kontakt = edytuj(kontakt);
            } else if (wybor == '9') {
                exit(0);
            }
        }
    }

    return 0;
}
