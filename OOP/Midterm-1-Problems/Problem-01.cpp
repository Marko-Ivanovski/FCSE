#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

enum tip{POP, RAP, ROK};

class Pesna {
private:
	char* ime;
	int minuti;
	tip tips;
public:
	Pesna() {
		ime = nullptr;
		minuti = 0;
		tips = POP;
	}

	Pesna(char* ime, int minuti, tip tip) {

		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		this->minuti = minuti;
		this->tips = tip;
	}

	Pesna(const Pesna& object) {
    ime = nullptr;
		ime = new char[strlen(object.ime) + 1];
		strcpy(ime, object.ime);
		minuti = object.minuti;
		tips = object.tips;
	}

	Pesna& operator=(const Pesna& object) {
		if (this != &object) {
			delete[] ime;
			ime = new char[strlen(object.ime) + 1];
			strcpy(ime, object.ime);
			minuti = object.minuti;
			tips = object.tips;
		}
		return *this;
	}

	~Pesna() {
		delete [] ime;
	}

	char* getIme() {
		return ime;
	}
	int getMinuti() {
		return minuti;
	}
	tip getTip() {
		return tips;
	}

	void pecati() {
		cout << "\"" << getIme() << "\"" << "-" << getMinuti() <<"min" << endl;
	}
};
class CD {
private:
	Pesna pesni[10];
	int broj;
	int maxMinuti;
public:

	CD(int i) {
		broj = 0;
		maxMinuti = i;
	}

	CD(Pesna *pesni, int br, int maxMinuti) {
        broj = br;
        this->maxMinuti = maxMinuti;
        for (int i = 0; i < broj; i++) {
            this->pesni[i] = pesni[i];
        }
	}

	CD(const CD& object) {
        broj = object.broj;
        maxMinuti = object.maxMinuti;
        for (int i = 0; i < broj; i++) {
            pesni[i] = object.pesni[i];
        }
	}

	~CD(){}

	Pesna getPesna(int index) {
		return pesni[index];
	}
	int getBroj() {
		return broj;
	}
	int getMaxMinuti() {
		return maxMinuti;
	}

 	void dodadiPesna(Pesna &p) {               //void dodadi/add == operator +=
        if (broj < 10){
            if  (maxMinuti >= p.getMinuti()){
                pesni[broj] = p;
                broj++;
                maxMinuti -=p.getMinuti();
            }
        }
	}

	void pecatiPesniPoTip(tip t) {
		for (int i = 0; i < broj; i++) {
			if (pesni[i].getTip() == t) {
				pesni[i].pecati();
			}
		}
	}
};

int main() {
	// se testira zadacata modularno
	int testCase;
	cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if (testCase == 1) {
		cout << "===== Testiranje na klasata Pesna ======" << endl;
		cin >> ime;
		cin >> minuti;
		cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
		Pesna p(ime, minuti, (tip)kojtip);
		p.pecati();
	}
	else if (testCase == 2) {
		cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ime;
			cin >> minuti;
			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
			Pesna p(ime, minuti, (tip)kojtip);
			omileno.dodadiPesna(p);
		}
		for (int i = 0; i < n; i++)
			(omileno.getPesna(i)).pecati();
	}
	else if (testCase == 3) {
		cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ime;
			cin >> minuti;
			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
			Pesna p(ime, minuti, (tip)kojtip);
			omileno.dodadiPesna(p);
		}
		for (int i = 0; i < omileno.getBroj(); i++)
			(omileno.getPesna(i)).pecati();
	}
	else if (testCase == 4) {
		cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ime;
			cin >> minuti;
			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
			Pesna p(ime, minuti, (tip)kojtip);
			omileno.dodadiPesna(p);
		}
		cin >> kojtip;
		omileno.pecatiPesniPoTip((tip)kojtip);

	}
	else if (testCase == 5) {
		cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ime;
			cin >> minuti;
			cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
			Pesna p(ime, minuti, (tip)kojtip);
			omileno.dodadiPesna(p);
		}
		cin >> kojtip;
		omileno.pecatiPesniPoTip((tip)kojtip);

	}

	return 0;
}
