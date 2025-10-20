#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class ToolShop {
    private:
        string name;
        string address;
        string opening_hours;
        string tools_type;
        int layout;

    public:
        ToolShop(string _name, string _address, string _openning_hours, string _tools_type, int _layout) {
            name = _name;
            address = _address;
            opening_hours = _openning_hours;
            tools_type = _tools_type;
            layout = _layout;
        }

        ToolShop() {
            name = "Инструментальный";
            address = "Ленина 42";
            opening_hours = "10:00 - 19:00";
            tools_type = "ручные";
            layout = 100;
        }

        string get_Name() {
            return name;
        }

        string get_Address() {
            return address;
        }

        string get_OpenningHours() {
            return opening_hours;
        }

        string get_ToolsType() {
            return tools_type;
        }

        int get_Layout() const {
            return layout;
        }

        void set_Name(string _name) {
            name = _name;
        }

        void set_Address(string _address) {
            address = _address;
        }

        void set_OpenningHours(string _opening_hours) {
            opening_hours = _opening_hours;
        }

        void set_ToolsType(string _tools_type) {
            tools_type = _tools_type;
        }

        void set_Layout(int _layout) {
            layout = _layout;
        }

        void getToolShopInfo() {
            cout << "Название: " << get_Name() << endl
            << "Адрес: " << get_Address() << endl
            << "Часы работы: " << get_OpenningHours() << endl
            << "Тип инструментов: " << get_ToolsType() << endl
            << "Площадь магазина: " << get_Layout() << " м²" << endl;
        }

        void saveToFile(const string& filename) {
            ofstream out(filename, ios::app);
            if (out.is_open()) {
                out << endl;
                out << name << endl;
                out << address << endl;
                out << opening_hours << endl;
                out << tools_type << endl;
                out << layout << endl;
                out.close();
            }
        }
};

bool compareToolShops(const ToolShop* a1, const ToolShop* a2) {
    return a1->get_Layout() < a2->get_Layout();
}

int main() {
    int N;
    cout << "Введите количество магазинов для чтения из файла. (Доступно 100 магазинов): ";
    cin >> N;

    ToolShop* toolshops[500];
    vector<ToolShop*> sortByLayout;
    int i = 0;

    ifstream in("instrument.txt");
    if (in.is_open()) {
        string _name, _address, _openning_hours, _tools_type, layout;
        
        for (i = 0; i < N; i++) {
            if (!getline(in, _name) ||
                !getline(in, _address) ||
                !getline(in, _openning_hours) ||
                !getline(in, _tools_type) ||
                !getline(in, layout)) {
                break;
            }
            
            int _layout = stoi(layout);

            toolshops[i] = new ToolShop(_name, _address, _openning_hours, _tools_type, _layout);

            if (_layout >= 200) {
                sortByLayout.push_back(toolshops[i]);
            }

            toolshops[i]->getToolShopInfo();
            cout << endl;
        }
    }
    in.close();

    if (sortByLayout.size() == 0) {
        cout << "Магазинов с площадью 200 м² и более не найдено!" << endl;
    } else {
        cout << "Найдено " << sortByLayout.size() << " магазина(ов) с площадью больше чем 200 м²!" << endl << endl << "**** Найденные магазины в отсортированном виде ****" << endl << endl;
        
        sort(sortByLayout.begin(), sortByLayout.end(), compareToolShops);
        for (int i = 0; i < sortByLayout.size(); i++) {
            sortByLayout[i]->getToolShopInfo();
            cout << endl;
        }

        string _name, _address, _opening_hours, _tools_type;
        int _layout;

        cout << "Название магазина (строка): ";
        cin.ignore();
        getline(cin, _name);
        cout << "Адрес (строка): ";     
        getline(cin, _address);
        cout << "Часы работы (строка): ";
        getline(cin, _opening_hours);
        cout << "Тип товара (строка): ";
        getline(cin, _tools_type);
        cout << "Площадь (число): ";
        cin >> _layout;
        cin.ignore();

        ToolShop* newToolShop = new ToolShop(_name, _address, _opening_hours, _tools_type, _layout);
        newToolShop->saveToFile("instrument.txt");
        cout << endl;

        sort(sortByLayout.begin(), sortByLayout.end(), compareToolShops);
        auto pos = lower_bound(sortByLayout.begin(), sortByLayout.end(), newToolShop, compareToolShops);
        sortByLayout.insert(pos, newToolShop);

        cout << "**** Обновленный вектор со вставкой нового элемента ****" << endl << endl;
        for (int i = 0; i < sortByLayout.size(); i++) {
            sortByLayout[i]->getToolShopInfo();
            cout << endl;
        }
    }
};