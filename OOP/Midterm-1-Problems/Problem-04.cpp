#include<iostream>
#include<cstring>

using namespace std;

class Patnik {
private:
    char ime[100];
    int klasa;
    bool velosiped;

public:
    Patnik(const char* i, int k, bool v) : klasa(k), velosiped(v) {
        strncpy(ime, i, 99);
        ime[99] = '\0';
    }

    friend ostream& operator<<(ostream& os, const Patnik& p) {
        os << p.ime << endl << p.klasa << endl << (p.velosiped ? "Da" : "Ne") << endl;
        return os;
    }

    bool hasBicycle() const {
        return velosiped;
    }

    int getClass() const {
        return klasa;
    }
};

class Voz {
private:
    char destinacija[100];
    Patnik* patnici;
    int brojPatnici;
    int maxVelosipedi;
    int brojDovolniVelosipedi;

public:
    Voz(const char* dest, int maxv) : brojPatnici(0), maxVelosipedi(maxv), brojDovolniVelosipedi(0) {
        strncpy(destinacija, dest, 99);
        destinacija[99] = '\0';
        patnici = new Patnik[100];  // Assuming a maximum of 100 passengers
    }

    ~Voz() {
        delete[] patnici;  // Release memory allocated for the array
    }

    Voz& operator+=(const Patnik& p) {
        if (p.getClass() == 1 && brojDovolniVelosipedi < maxVelosipedi) {
            patnici[brojPatnici++] = p;
            if (p.hasBicycle()) {
                brojDovolniVelosipedi++;
            }
        } else if (p.getClass() == 2 && brojDovolniVelosipedi < maxVelosipedi) {
            patnici[brojPatnici++] = p;
            if (p.hasBicycle()) {
                brojDovolniVelosipedi++;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Voz& v) {
        os << v.destinacija << endl;
        for (int i = 0; i < v.brojPatnici; i++) {
            os << v.patnici[i];
        }
        return os;
    }

    void patniciNemaMesto() const {
        int brojPatnici1 = 0;
        int brojPatnici2 = 0;
        int brojNemaMesto1 = 0;
        int brojNemaMesto2 = 0;

        for (int i = 0; i < brojPatnici; i++) {
            if (patnici[i].getClass() == 1) {
                brojPatnici1++;
                if (patnici[i].hasBicycle() && brojNemaMesto1 < maxVelosipedi) {
                    brojNemaMesto1++;
                }
            } else if (patnici[i].getClass() == 2) {
                brojPatnici2++;
                if (patnici[i].hasBicycle() && brojNemaMesto2 < maxVelosipedi) {
                    brojNemaMesto2++;
                }
            }
        }

        cout << "Patnici od 1-va klasa koi nemaat mesto so velosiped: " << brojNemaMesto1 << endl;
        cout << "Patnici od 2-ra klasa koi nemaat mesto so velosiped: " << brojNemaMesto2 << endl;
    }
};

int main() {
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;

    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);

    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        v += p;
    }

    cout << v;
    v.patniciNemaMesto();

    return 0;
}
