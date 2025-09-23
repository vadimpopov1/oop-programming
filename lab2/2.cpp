#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

class Pharmacy {
    protected:
        string name;
        long int phone_number;
        string address;
        string opening_hours;
    
    public:
        Pharmacy(string _name, long int _phone_number, string _address, string _opening_hours) : name(_name), phone_number(_phone_number), address(_address), opening_hours(_opening_hours) {
        }

        Pharmacy() {
            name = "Аптека";
            phone_number = 89999999999;
            address = "Ленина 89";
            opening_hours = "9:00 - 20:00";
        }

        void setName(string _name) {
            name = _name;
        }

        string getName() {
            return name;
        }

        void setPhoneNumber(int _phone_number) {
            phone_number = _phone_number;
        }

        int getPhoneNumber() {
            return phone_number;
        }

        void setAddress(string _address) {
            address = _address;
        }

        string getAddress() {
            return address;
        }

        void setOpeningHours(string _opening_hours) {
            opening_hours = _opening_hours;
        }

        string getOpeningHours() {
            return opening_hours;
        }

        void getPharmacyInfo() {
            cout << "Название: " << name << endl
            << "Номер телефона: " << phone_number << endl
            << "Адрес: " << address << endl
            << "Часы работы: " << opening_hours << endl
            << "Владелец: Государство" << endl;
        }
}; 

class PrivatePharmacy : public Pharmacy {
    private:
        string ownerFIO;
    
    public:
        PrivatePharmacy(string _name, long int _phone_number, string _address, string _opening_hours, string _ownerFIO) : Pharmacy(_name, _phone_number, _address, _opening_hours) {
            ownerFIO = _ownerFIO;
        }

        PrivatePharmacy() : Pharmacy("Аптека", 89999999999, "Ленина 89", "9:00 - 20:00") {
            ownerFIO = "Иванов Иван Иваныч";
        }

        void setOwnerFIO(string _ownerFIO) {
            ownerFIO = _ownerFIO;
        }

        string getOwnerFIO() {
            return ownerFIO;
        }

        void getPrivatePharmacyInfo() {
            getPharmacyInfo();
            cout << "Владелец: " << ownerFIO << endl << endl;
        }
};

int main() {
    int countPharmacy;
    int countPrivatePharmacy;

    cout << "Введите количество аптек для создания: ";
    cin >> countPharmacy;

    cout << "Введите колиество частных аптек для создания: ";
    cin >> countPrivatePharmacy;

    Pharmacy* pharmacy = new Pharmacy[countPharmacy];
    PrivatePharmacy* privatepharmacy = new PrivatePharmacy[countPrivatePharmacy];

    for (int i = 0; i < countPharmacy; i++) {
        string _name;
        long int _phone_number;
        string _address; 
        string _opening_hours;

        cout << "Название аптеки (строка): ";
        cin.ignore();
        getline(cin, _name);
        cout << "Телефон аптеки (число): ";
        cin >> _phone_number;
        cout << "Адрес аптеки (строка): ";
        cin.ignore();
        getline(cin, _address);
        cout << "Часы работы аптеки (строка): ";
        getline(cin, _opening_hours);      

        pharmacy[i] = Pharmacy(_name, _phone_number, _address, _opening_hours);
        cout << endl;
    }

    for (int i = 0; i < countPrivatePharmacy; i++) {
        string _name;
        long int _phone_number;
        string _address; 
        string _opening_hours;
        string _ownerFIO;

        cout << "Название частной аптеки (строка): ";
        cin.ignore();
        getline(cin, _name);
        cout << "Телефон частной аптеки (число): ";
        cin >> _phone_number;
        cout << "Адрес частной аптеки (строка): ";
        cin.ignore();
        getline(cin, _address);
        cout << "Часы работы частной аптеки (строка): ";
        getline(cin, _opening_hours); 
        cout << "ФИО владельца частной аптеки (строка): ";    
        getline(cin, _ownerFIO);  
        
        privatepharmacy[i] = PrivatePharmacy(_name, _phone_number, _address, _opening_hours, _ownerFIO);
        cout << endl;
    }

    for (int i = 0; i < countPharmacy; i++) {
        pharmacy[i].getPharmacyInfo();
        cout << endl;
    }
    
    for (int i = 0; i < countPrivatePharmacy; i++) {
        privatepharmacy[i].getPrivatePharmacyInfo();
        cout << endl;
    }

    delete[] pharmacy;
    delete[] privatepharmacy;
}
