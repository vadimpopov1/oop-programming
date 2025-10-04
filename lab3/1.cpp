#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Tea {
    protected:
        string type;
        string pack;
        string manufacturer;
        float price;
        long int count;

    public:
        Tea(string _type, string _pack, string _manufacturer, float _price, long int _count) {     
            type = _type;
            pack = _pack;
            manufacturer = _manufacturer;
            price = _price;
            count = _count;
        }

        Tea() = default;
    
    string getType() {
        return type;
    }

    string getPack() {
        return pack;
    }

    string getManufacturer() {
        return manufacturer;
    }

    float getPrice() {
        return price;
    }

    long int getCount() {
        return count;
    }

    float getSum() {
        return price * count;
    }

    void saveToBin(ofstream &out) {
        size_t len = type.size();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(type.c_str(), len);

        len = pack.size();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(pack.c_str(), len);

        len = manufacturer.size();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(manufacturer.c_str(), len);

        out.write(reinterpret_cast<char*>(&price), sizeof(price));
        out.write(reinterpret_cast<char*>(&count), sizeof(count));
    }

    void loadFromBin(ifstream &in) {
        size_t len;
        
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        type.resize(len);
        in.read(&type[0], len);

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        pack.resize(len);
        in.read(&pack[0], len);

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        manufacturer.resize(len);
        in.read(&manufacturer[0], len);

        in.read(reinterpret_cast<char*>(&price), sizeof(price));
        in.read(reinterpret_cast<char*>(&count), sizeof(count));
    }
};

void saveToBinFile(Tea* teas[], int count, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    out.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (int i = 0; i < count; i++) {
        teas[i]->saveToBin(out);
    }

    out.close();
}

int loadFromBinFile(Tea* teas[], const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return 0;
    }

    int count;
    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    for (int i = 0; i < count; i++) {
        teas[i] = new Tea();
        teas[i]->loadFromBin(in);
    }

    in.close();
    return count;
}

void getParametr(string type, int counter) {
    size_t size = type.length() / 2;
    cout << "│  " << type;
    for (int i = (9 - size); i > -1; i--) {
        cout << " ";
    }
    if (counter % 6 == 0) {
        cout << "│"<<  endl;
    }
}

void clearMemory(int count, Tea* teas[]) {
    for (int j = 0; j < count; j++) {
        delete teas[j];
    }
}

void printTable(Tea* teas[], int count) {
    cout << "                        Таблица: Закупка чая                            " << endl
         << "┌────────────┬────────────┬───────────────┬──────────────┬─────────────┬────────────────┐" << endl
         << "│  Тип чая   │  Упаковка  │ Производитель │     Цена     │ Количество  │     Сумма      │" << endl
         << "├────────────┼────────────┼───────────────┼──────────────┼─────────────┼────────────────┤" << endl;

    long int counter = 0;
    float summ = 0;

    for (int i = 0; i < count; i++) {
        getParametr(teas[i]->getType(), 1);
        getParametr(teas[i]->getPack(), 2);
        getParametr(teas[i]->getManufacturer(), 3);
        getParametr(to_string(teas[i]->getPrice()).substr(0, 4), 4);
        getParametr(to_string(teas[i]->getCount()), 5);
        getParametr(to_string(teas[i]->getSum()).substr(0, 8), 6);
        counter += teas[i]->getCount();
        summ += teas[i]->getSum();
    }

    cout << "├────────────┼────────────┼───────────────┼──────────────┼─────────────┼────────────────┤" << endl;
    cout << "│   Всего    │            │               │              ";
    getParametr("\b " + to_string(counter), 5);
    getParametr(to_string(summ).substr(0, 8), 6);
    cout << "└────────────┴────────────┴───────────────┴──────────────┴─────────────┴────────────────┘" << endl;
}

int main() {
    Tea* teas[100];
    int i = 0;

    ifstream in("info.txt");
    if (in.is_open()) {
        string type, pack, manufacturer, priceStr, countStr;
        while (getline(in, type) && 
               getline(in, pack) && 
               getline(in, manufacturer) && 
               getline(in, priceStr) && 
               getline(in, countStr)) {
                float price = stof(priceStr);
                long int count = stol(countStr);
            teas[i] = new Tea(type, pack, manufacturer, price, count);
            i++;
        }
    }

    printTable(teas, i);
    saveToBinFile(teas, i, "teas.bin");
    clearMemory(i, teas);

    Tea* loadedTeas[100];
    int loadedCount = loadFromBinFile(loadedTeas, "teas.bin");

    cout << endl;
    printTable(loadedTeas, loadedCount);
    clearMemory(loadedCount, loadedTeas);
}

// reinterpret_cast - оператор приведения типов, который преобразует значение одного указателя или ссылки в значение другого,
// совершенно другого типа, сохраняя при этом исходную битовую комбинацию данных.
