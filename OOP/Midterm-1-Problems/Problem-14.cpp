#include <iostream>
#include <cstring>

enum Tip { LINUX, UNIX, WINDOWS };

class OperativenSistem {
private:
    char* ime;
    float verzija;
    Tip tip;
    float golemina;

public:
    OperativenSistem() : ime(nullptr), verzija(0.0), tip(LINUX), golemina(0.0) {}
    
    OperativenSistem(const char* i, float v, Tip t, float g) : verzija(v), tip(t), golemina(g) {
        ime = new char[strlen(i) + 1];
        strcpy(ime, i);
    }

    OperativenSistem(const OperativenSistem& other) : verzija(other.verzija), tip(other.tip), golemina(other.golemina) {
        ime = new char[strlen(other.ime) + 1];
        strcpy(ime, other.ime);
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    OperativenSistem& operator=(const OperativenSistem& other) {
        if (this != &other) {
            delete[] ime;
            ime = new char[strlen(other.ime) + 1];
            strcpy(ime, other.ime);
            verzija = other.verzija;
            tip = other.tip;
            golemina = other.golemina;
        }
        return *this;
    }

    void pecati() const {
        cout << "Ime: " << ime << ", Verzija: " << verzija << ", Tip: " << tip << ", Golemina: " << golemina << "GB" << endl;
    }

    bool ednakviSe(const OperativenSistem& os) const {
        return (strcmp(ime, os.ime) == 0) && (verzija == os.verzija) && (tip == os.tip) && (golemina == os.golemina);
    }

    int sporediVerzija(const OperativenSistem& os) const {
        if (verzija == os.verzija) return 0;
        return (verzija < os.verzija) ? -1 : 1;
    }

    bool istaFamilija(const OperativenSistem& sporedba) const {
        return (strcmp(ime, sporedba.ime) == 0) && (tip == sporedba.tip);
    }
};

class Repozitorium {
private:
    char ime[20];
    OperativenSistem* operativniSistemi;
    int brojOperativniSistemi;

public:
    Repozitorium(const char* i) : brojOperativniSistemi(0) {
        strncpy(ime, i, 19);
        ime[19] = '\0';
        operativniSistemi = nullptr;
    }

    ~Repozitorium() {
        delete[] operativniSistemi;
    }

    void pecatiOperativniSistemi() const {
        cout << "=====Operativni Sistemi vo Repozitoriumot=====" << endl;
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            operativniSistemi[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem& operativenSistem) {
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            if (this->operativniSistemi[i].ednakviSe(operativenSistem)) {
                for (int j = i; j < brojOperativniSistemi - 1; ++j) {
                    this->operativniSistemi[j] = this->operativniSistemi[j + 1];
                }
                --brojOperativniSistemi;
                return;
            }
        }
    }

    void dodadi(const OperativenSistem& nov) {
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            if (this->operativniSistemi[i].istaFamilija(nov) && this->operativniSistemi[i].sporediVerzija(nov) == -1) {
                this->operativniSistemi[i] = nov;
                return;
            }
        }

        OperativenSistem* temp = new OperativenSistem[brojOperativniSistemi + 1];
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            temp[i] = operativniSistemi[i];
        }
        temp[brojOperativniSistemi] = nov;

        delete[] operativniSistemi;
        operativniSistemi = temp;
        ++brojOperativniSistemi;
    }
};

int main() {
    using namespace std;

    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();

    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);

    cout << "=====Brisenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();

    return 0;
}
