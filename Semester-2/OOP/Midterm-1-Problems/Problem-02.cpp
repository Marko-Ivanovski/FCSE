#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class List {
private:
    int* array;
    int num;
public:
    List(int i) {
        array = nullptr;
        num = i;
    }
    List(int num, int* array) {
        this->num = num;
        this->array = new int[(num)+1];
        for (int i = 0; i < num; i++) {
            this->array[i] = array[i];
        }
    }
    List(const List& object) {
        num = object.num;
        array = new int[(object.num)+1];
        for (int i = 0; i < num; i++) {
            array[i] = object.array[i];
        }
    }
    List() {}
    List& operator=(const List& object) {
        if (this != &object) {
            delete[] array;
            num = object.num;
            array = new int[(object.num) + 1];
            for (int i = 0; i < num; i++) {
                array[i] = object.array[i];
            }
        }
        return *this;
    }

    int* getArray() {
        return array;
    }
    int getNum() {
        return num;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += array[i];
        }
        return sum;
    }
    double average() {
        double avg = 1;
        avg = sum() / num;
        return avg;
    }
    void pecati() {
        cout << num << ":";
        for (int i = 0; i < num; i++) {
                cout << array[i];
        }
        cout << "sum: " << sum();
        cout << "average: " << average();
    }
};
class ListContainer {
private:
    List* lists;
    int numLists;
    int numOfTries;
public:
    ListContainer() {
        lists = nullptr;
        numLists = 0;
        numOfTries = 0;
    }
    ListContainer(int numLists, List* lists, int numOfTries) {
        this->numLists = numLists;
        this->lists = new List[numLists];
        for (int i = 0; i < numLists; i++) {
            this->lists[i] = lists[i];
        }
        this->numOfTries = numOfTries;
    }
    ListContainer(const ListContainer& object) {
        numLists = object.numLists;
        lists = new List[object.numLists];
        for (int i = 0; i < numLists; i++) {
            lists[i] = object.lists[i];
        }
        numOfTries = object.numOfTries;
    }
    ~ListContainer() {}

    ListContainer& operator=(const ListContainer& object) {
        if (this != &object) {
            delete[] lists;
            numLists = object.numLists;
            lists = new List[numLists];
            for (int i = 0; i < numLists; i++) {
                lists[i] = object.lists[i];
            }
            numOfTries = object.numOfTries;
        }
        return *this;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < numLists; i++) {
            sum +=lists[i].sum();
        }
        return sum;
    }
    double average() {
        double avg=1;
        avg = sum() / numLists;
        return avg;
    }
    void addNewList(List l) {
        List* temp = new List[numLists + 1];
        for (int i = 0; i < numLists; i++) {
            temp[i] = lists[i];
        }
        temp[numLists] = *lists;
        delete[] lists;
        lists = temp;
        numLists++;

    }
    void print() {
        for (int i = 0; i < numLists; i++) {
            cout << "List number: " << i + 1 << " ";
            lists[i].pecati();
        }

    }
};

int main() {
    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(n, niza);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}
