#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;


struct Adresat {
    int id, UserId;
    string imie, nazwisko, tel, email, adres;
};

struct Uzytkownik {
    int id;
    string nazwa, haslo;
};

Adresat konwersja_danych_z_pliku(string linia) {
    Adresat singleContact;
    string daneKontaktu[7];
    int liczba_zmiennej=0, pozycja = 0, licznik = 0, dlugosc_lini, id, UserId;

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
    UserId = atoi(daneKontaktu[1].c_str());
    singleContact = {id, UserId, daneKontaktu[2], daneKontaktu[3], daneKontaktu[4], daneKontaktu[5], daneKontaktu[6]};
    return singleContact;
}

Uzytkownik konwersja_danych_z_pliku_uzytkownicy(string linia) {
    Uzytkownik singleUser;
    string daneUzytkownika[3];
    int liczba_zmiennej=0, pozycja = 0, licznik = 0, dlugosc_lini, UserId;

    dlugosc_lini = linia.length();
    for (int i=0; i<dlugosc_lini-1; i++) {

        if (linia[i] == '|') {
            daneUzytkownika[liczba_zmiennej] = linia.substr(pozycja,licznik);
            liczba_zmiennej++;
            pozycja = i+1;
            licznik = 0;
        } else {
            licznik ++;
        }
    }
    daneUzytkownika[liczba_zmiennej] = linia.substr(pozycja,licznik);
    UserId = atoi(daneUzytkownika[0].c_str());
    singleUser = {UserId, daneUzytkownika[1], daneUzytkownika[2]};
    return singleUser;
}

vector<Adresat> nowy(vector<Adresat> kontakt, int UserId) {
    string imie, nazwisko, tel, email, adres, linia;
    int numberOfContacts = kontakt.size();
    int lastId;
    fstream plik;
    Adresat singleContact;
    system("cls");

    plik.open("ksiazka.txt", ios::in);
    while (getline(plik, linia)) {
        singleContact = konwersja_danych_z_pliku(linia);
        lastId = singleContact.id;
    }
    plik.close();

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

    singleContact = {lastId + 1, UserId, imie, nazwisko, tel, email, adres};
    kontakt.push_back(singleContact);


    plik.open("ksiazka.txt",ios::out | ios::app);

    plik<<lastId+1<<"|";
    plik<<UserId<<"|";
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
    Adresat singleContact;
    char decyzja;
    string linia;
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
        cout << "Kontakt o numerze ID " << id << " zostal usuniety!" <<endl;
        numberOfContacts = kontakt.size();
        fstream plik1;
        fstream plik2;
        plik1.open("ksiazka_tymczasowa.txt",ios::out);
        plik2.open("ksiazka.txt",ios::in);
        while (getline(plik2, linia)) {
            singleContact = konwersja_danych_z_pliku(linia);
            if (singleContact.id != id) {
                plik1<<linia<<endl;
            }
        }
        plik1.close();
        plik2.close();
        remove( "ksiazka.txt");
        rename( "ksiazka_tymczasowa.txt", "ksiazka.txt" );
    }
    Sleep(2000);
    return kontakt;
}

vector<Adresat> edytuj(vector<Adresat> kontakt, int UserId) {
    string imie, nazwisko, tel, email, adres, linia;
    int numberOfContacts = kontakt.size(), id, kontakt_do_edycji;
    char decyzja, wybor;
    bool sprawdzenie = false;
    system("cls");
    Adresat singleContact;

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
        fstream plik1;
        fstream plik2;
        plik1.open("ksiazka_tymczasowa.txt",ios::out);
        plik2.open("ksiazka.txt",ios::in);
        while (getline(plik2, linia)) {
            singleContact = konwersja_danych_z_pliku(linia);
            if (singleContact.id == id) {
             plik1<<kontakt[kontakt_do_edycji].id<<"|";
             plik1<<kontakt[kontakt_do_edycji].UserId<<"|";
             plik1<<kontakt[kontakt_do_edycji].imie<<"|";
             plik1<<kontakt[kontakt_do_edycji].nazwisko<<"|";
             plik1<<kontakt[kontakt_do_edycji].tel<<"|";
             plik1<<kontakt[kontakt_do_edycji].email<<"|";
             plik1<<kontakt[kontakt_do_edycji].adres<<"|"<<endl;
            } else {
            plik1<<linia<<endl;
            }
        }
        plik1.close();
        plik2.close();
        remove( "ksiazka.txt");
        rename( "ksiazka_tymczasowa.txt", "ksiazka.txt" );
    }
    Sleep(2000);
    return kontakt;
}

vector<Uzytkownik> rejestracja(vector<Uzytkownik> profil_uzytkownika) {
    string login, haslo;
    system("cls");
    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;
    Uzytkownik singleUser;
    int i = 0, UsersCount = profil_uzytkownika.size(), UserId;
    UserId = UsersCount + 1;
    while (i < UsersCount) {
        if (profil_uzytkownika[i].nazwa == login ) {
            cout << "Login zajety! Wybierz inny!"<< endl;
            i = 0;
            cin >> login;
        } else {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;
    singleUser = {UserId, login, haslo};
    profil_uzytkownika.push_back(singleUser);

    cout << "Konto zalozone pomyslnie!" << endl;

    fstream plik;
    plik.open("uzytkownicy.txt",ios::out | ios::app);
    plik<<UserId<<"|";
    plik<<login<<"|";
    plik<<haslo<<"|"<<endl;
    plik.close();
    Sleep(2000);
    return profil_uzytkownika;
}

int logowanie(vector<Uzytkownik> profil_uzytkownika) {
    string login, haslo;
    int UserId;
    system("cls");
    cout << "Podaj login: ";
    cin >> login;
    int i = 0, UsersCount = profil_uzytkownika.size();
    while (i < UsersCount) {
        if (profil_uzytkownika[i].nazwa == login) {
            for (int proby = 0; proby < 3; proby++) {
                cout << "Podaj haslo. Pozostalo prob " << 3-proby << ": ";
                cin >> haslo;
                if (profil_uzytkownika[i].haslo == haslo) {
                    UserId = profil_uzytkownika[i].id;
                    cout << "Zalogowales sie!" << endl;
                    Sleep(2000);
                    return profil_uzytkownika[i].id;
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba" <<endl;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownikow z takim loginem" << endl;
    Sleep(2000);
    return 0;

}

vector<Uzytkownik> zmianaHasla(vector<Uzytkownik> profil_uzytkownika, int idZalogowanegoUzytkownika) {
    string haslo;
    int UsersCount = profil_uzytkownika.size();
    system("cls");
    cout << "Podaj nowe haslo: ";
    cin >> haslo;
    for (int i=0; i < UsersCount; i++) {
        if (profil_uzytkownika[i].id == idZalogowanegoUzytkownika) {
            profil_uzytkownika[i].haslo = haslo;
            cout << "Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }
    }
    fstream plik;
    plik.open("uzytkownicy.txt",ios::out | ios::trunc);
    for (int i = 0; i < UsersCount; i++) {
        plik<<profil_uzytkownika[i].id<<"|";
        plik<<profil_uzytkownika[i].nazwa<<"|";
        plik<<profil_uzytkownika[i].haslo<<"|"<<endl;
    }
    plik.close();
    return profil_uzytkownika;
}


int main() {

    vector<Adresat> kontakt;
    vector<Uzytkownik> profil_uzytkownika;
    int menu = 0, idZalogowanegoUzytkownika = 0, id, dlugosc_linii, IdAdresata;
    char wybor, wybor1;
    string linia1, linia2, imie, nazwisko, tel, email, adres, IdAdresataString;
    Adresat singleContact;
    Uzytkownik singleUser;

    fstream plik2;
    plik2.open("uzytkownicy.txt", ios::in);

    while (getline(plik2, linia1)) {
        singleUser = konwersja_danych_z_pliku_uzytkownicy(linia1);
        profil_uzytkownika.push_back(singleUser);
    }

    plik2.close();

    while(1) {
        if (idZalogowanegoUzytkownika == 0) {
            system("cls");
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakonczenie programu" << endl;
            cin >> wybor;

            if (wybor == '1') {
                profil_uzytkownika = rejestracja(profil_uzytkownika);
            } else if (wybor == '2') {
                idZalogowanegoUzytkownika = 1;
                idZalogowanegoUzytkownika = logowanie(profil_uzytkownika);
            } else if (wybor == '9') {
                exit(0);
            }
        } else {
            system("cls");

            fstream plik;
            plik.open("ksiazka.txt", ios::in);

            while (getline(plik, linia2)) {
                singleContact = konwersja_danych_z_pliku(linia2);
                if (singleContact.UserId == idZalogowanegoUzytkownika) {
                    kontakt.push_back(singleContact);
                }
            }
            plik.close();

            while(idZalogowanegoUzytkownika != 0) {
                if (menu == 0) {
                    system("cls");
                    cout << "1. Dodaj kontakt" << endl;
                    cout << "2. Wyszukaj po imieniu" << endl;
                    cout << "3. Wyszukaj po nazwisku" << endl;
                    cout << "4. Wyswietl wszystkich adresatow" << endl;
                    cout << "5. Usun adresata" << endl;
                    cout << "6. Edytuj adresata" << endl;
                    cout << "7. Zmien haslo" << endl;
                    cout << "9. Wylogowanie" << endl;
                    cin >> wybor1;

                    if (wybor1 == '1') {
                        kontakt = nowy(kontakt, idZalogowanegoUzytkownika);
                    } else if (wybor1 == '2') {
                        menu = poImieniu(kontakt, wybor1);
                    } else if (wybor1 == '3') {
                        menu = poNazwisku(kontakt, wybor1);
                    } else if (wybor1 == '4') {
                        menu = lista(kontakt, wybor1);
                    } else if (wybor1 == '5') {
                        kontakt = usun(kontakt);
                    } else if (wybor1 == '6') {
                        kontakt = edytuj(kontakt,idZalogowanegoUzytkownika);
                    } else if (wybor1 == '7') {
                        profil_uzytkownika = zmianaHasla(profil_uzytkownika, idZalogowanegoUzytkownika);
                    } else if (wybor1 == '9') {
                        kontakt.erase (kontakt.begin(),kontakt.end());
                        idZalogowanegoUzytkownika = 0;
                    }
                }
            }
        }
    }
    return 0;
}
