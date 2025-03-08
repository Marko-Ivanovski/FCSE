#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class StockRecord {
private:
    char ID[13];
    char companyName[51];
    double purchasePrice;
    double currentPrice;
    int numberOfShares;

public:
    StockRecord(const char* id, const char* name, double price, int shares)
        : purchasePrice(price), currentPrice(price), numberOfShares(shares) {
        strncpy(ID, id, 12);
        ID[12] = '\0';
        strncpy(companyName, name, 50);
        companyName[50] = '\0';
    }

    void setNewPrice(double c) {
        currentPrice = c;
    }

    double value() const {
        return numberOfShares * currentPrice;
    }

    double profit() const {
        return numberOfShares * (currentPrice - purchasePrice);
    }

    friend ostream& operator<<(ostream& os, const StockRecord& sr) {
        os << sr.companyName << " " << sr.numberOfShares << " "
           << sr.purchasePrice << " " << sr.currentPrice << " " << sr.profit();
        return os;
    }
};
class Client {
private:
    char clientName[61];
    int clientID;
    StockRecord* portfolio;
    int portfolioSize;

public:
    Client(const char* name, int id) : clientID(id), portfolioSize(0) {
        strncpy(clientName, name, 60);
        clientName[60] = '\0';
        portfolio = new StockRecord[10]; // Assuming a maximum of 10 StockRecord objects
    }

    ~Client() {
        delete[] portfolio; // Release memory allocated for the array
    }

    double totalValue() const {
        double total = 0.0;
        for (int i = 0; i < portfolioSize; ++i) {
            total += portfolio[i].value();
        }
        return total;
    }

    void operator+=(const StockRecord& sr) {
        if (portfolioSize < 10) { // Ensure array bounds are not exceeded
            portfolio[portfolioSize++] = sr;
        }
    }

    friend ostream& operator<<(ostream& os, const Client& client) {
        os << client.clientID << " " << fixed << setprecision(2) << client.totalValue() << endl;
        for (int i = 0; i < client.portfolioSize; ++i) {
            os << client.portfolio[i] << endl;
        }
        return os;
    }
};

int main() {
    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[13], company[51];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr << endl;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[13], companyName[51], clientName[61];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;
}
