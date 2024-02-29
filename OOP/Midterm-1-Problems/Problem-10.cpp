#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Ucesnik {
private:
    char* name;
    bool gender;
    int age;
public:
    Ucesnik() {
        name = nullptr;
        gender = true;
        age = 0;
    }
    Ucesnik(char* name, bool gender, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->gender = gender;
        this->age = age;
    }
    Ucesnik(const Ucesnik& objekt) {
        name = new char[strlen(objekt.name) + 1];
        strcpy(name, objekt.name);
        gender = objekt.gender;
        age = objekt.age;
    }
    ~Ucesnik() {
        delete[] name;
    }
    Ucesnik& operator=(const Ucesnik &objekt){
        if (this == &objekt) {
            delete[] name;
            name = new char[strlen(objekt.name) + 1];
            strcpy(name, objekt.name);
            gender = objekt.gender;
            age = objekt.age;
        }
        return *this;
    }
    
    char* getName() {
        return name;
    }
    bool getGender() {
        return gender;
    }
    int getAge() {
        return age;
    }
};
class Maraton {
private:
    char location[100];
    int numUcesnici;
    Ucesnik* ucesnici;
public:
    Maraton() {
        location[0] = 0;
        numUcesnici = 0;
        ucesnici = nullptr;
    }
    Maraton(char* location, int numUcesnici,const Ucesnik* ucesnici) {
        strcpy(this->location, location);
        this->numUcesnici = numUcesnici;
        this->ucesnici = new Ucesnik[numUcesnici];
        for (int i = 0; i < numUcesnici; i++) {
            this->ucesnici[i] = ucesnici[i];
        }
    }
    Maraton(const Maraton& object) {
        strcpy(location, object.location);
        numUcesnici = object.numUcesnici;
        ucesnici = new Ucesnik[object.numUcesnici];
        for (int i = 0; i < numUcesnici; i++) {
            ucesnici[i] = object.ucesnici[i];
        }
    }
    ~Maraton() {
        delete[] ucesnici;
    }

    Maraton& operator=(const Maraton& object) {
        if (this == &object) {
            delete[] ucesnici;
            strcpy(location, object.location);
            ucesnici = new Ucesnik[object.numUcesnici];
            for (int i = 0; i < n; i++) {
                ucesnici[i] = object.ucesnici[i];
            }
        }
        return *this;
    }
    Maraton& operator+=(const Ucesnik& object) {
        Ucesnik* temp = new Ucesnik[numUcesnici + 1];
        for (int i = 0; i < numUcesnici; i++) {
            temp[i] = ucesnici[i];
        }
        temp[numUcesnici] = object;
        numUcesnici++;
        delete[] ucesnici;
        ucesnici = temp;
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik** u = new Ucesnik * [n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}
