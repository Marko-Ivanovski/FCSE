#include<iostream>
#include<cstring>
using namespace std;

class Zichara {
private:
    char* mesto;
    int cenaDnevnakarta;

public:
    Zichara(const char* m, int cena) : cenaDnevnakarta(cena) {
        mesto = new char[strlen(m) + 1];
        strcpy(mesto, m);
    }

    ~Zichara() {
        delete[] mesto;
    }

    const char* getMesto() const {
        return mesto;
    }

    int getCenaDnevnakarta() const {
        return cenaDnevnakarta;
    }

    friend ostream& operator<<(ostream& os, const Zichara& z) {
        os << "Zichara na " << z.mesto << " so dnevnakarta od " << z.cenaDnevnakarta << " denari";
        return os;
    }
};

class PlaninarskiDom {
private:
    char ime[16];
    int ceni[2];
    char klasa;
    bool daliZichara;
    Zichara* zichara;

public:
    PlaninarskiDom(const char* i, int c[2], char k) : klasa(k), daliZichara(false), zichara(nullptr) {
        strncpy(ime, i, 15);
        ime[15] = '\0';
        for (int j = 0; j < 2; ++j) {
            ceni[j] = c[j];
        }
    }

    PlaninarskiDom(const char* i, int c[2], char k, const Zichara& z) : klasa(k), daliZichara(true), zichara(nullptr) {
        strncpy(ime, i, 15);
        ime[15] = '\0';
        for (int j = 0; j < 2; ++j) {
            ceni[j] = c[j];
        }
        zichara = new Zichara(z);
    }

    ~PlaninarskiDom() {
        delete zichara;
    }

    PlaninarskiDom& operator=(const PlaninarskiDom& pd) {
        if (this != &pd) {
            strncpy(ime, pd.ime, 15);
            ime[15] = '\0';
            for (int i = 0; i < 2; ++i) {
                ceni[i] = pd.ceni[i];
            }
            klasa = pd.klasa;
            daliZichara = pd.daliZichara;
            delete zichara;
            if (pd.daliZichara) {
                zichara = new Zichara(*pd.zichara);
            } else {
                zichara = nullptr;
            }
        }
        return *this;
    }

    void setZichara(const Zichara& z) {
        delete zichara;
        zichara = new Zichara(z);
        daliZichara = true;
    }

    void operator--() {
        if (klasa > 'A') {
            klasa--;
        }
    }

    friend ostream& operator<<(ostream& os, const PlaninarskiDom& pd) {
        os << pd.ime << " klasa:" << pd.klasa;
        if (pd.daliZichara) {
            os << " so " << *pd.zichara;
        }
        os << endl;
        return os;
    }

    bool operator<=(char c) const {
        return klasa <= c;
    }

    void presmetajDnevenPrestoj(int den, int mesec, int& cena) const {
        if (den < 1 || den > 31 || mesec < 1 || mesec > 12) {
            throw 1;  // Invalid day or month
        }

        int sezona;
        if (mesec >= 4 && mesec <= 9) {
            sezona = 0;  // Summer season
        } else {
            sezona = 1;  // Winter season
        }

        cena = ceni[sezona];
        if (daliZichara) {
            cena += zichara->getCenaDnevnakarta();
        }
    }
};
int main(){

   PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

   //во следниот дел се вчитуваат информации за планинарскиот дом
   char imePlaninarskiDom[15],mestoZichara[30],klasa;
   int ceni[12];
   int dnevnakartaZichara;
   bool daliZichara;
   cin>>imePlaninarskiDom;
   for (int i=0;i<2;i++) cin>>ceni[i];
   cin>>klasa;
   cin>>daliZichara;

   //во следниот дел се внесуваат информации и за жичарата ако постои
   if (daliZichara) {
      cin>>mestoZichara>>dnevnakartaZichara;
      PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
      Zichara r(mestoZichara,dnevnakartaZichara);
      pom.setZichara(r);
      p=pom;
   }
   else{
      PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
      p=*pok;
   }

   //се намалува класата на планинарскиот дом за 2
   --p;
   --p;

   int cena;
   int den,mesec;
   cin>>den>>mesec;
   try{
   p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
   cout<<"Informacii za PlaninarskiDomot:"<<endl;
   cout<<p;
   if (p<='D') 
       cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";
       
   cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
   }
   catch (int){
      cout<<"Mesecot ili denot e greshno vnesen!";
   }
}
