#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Animal {
    private:
        string name;
        int age;
        string areal;
        string type;

    public:
        Animal(string _name, int _age, string _areal, string _type) {
            name = _name;
            age = _age;
            areal = _areal;
            type = _type;
        }        

        Animal() {
            name = "Кот";
            age = 2;
            areal = "Любой";
            type = "Кошачьи";
        }

    void outputAnimal() {
        cout << "Название: " << name << "\nВозраст: " << age << "\nАреал обитания: " << areal << "\nТип: " << type << endl;
    }


    string get_Name() const {
        return name;
    }

    int get_Age() const {
        return age;
    }

    string get_Areal() const {
        return areal;
    }

    string get_Type() const {
        return type;
    }

    void set_Name(string _name) {
        name = _name;
    }

    void set_Age(int _age) {
        age = _age;
    }

    void set_Areal(string _areal) {
        areal = _areal;
    }

    void set_Type(string _type) {
        type = _type;
    }
};

bool compareAnimals(const Animal& a1, const Animal& a2) {
    if (a1.get_Age() != a2.get_Age()) 
        return a1.get_Age() < a2.get_Age();

    return a1.get_Name() < a2.get_Name();
}

int main() {
    int n;
    cout << "Введие размер вектора (N): ";
    cin >> n;
    cout << endl;

    vector<Animal> animals(n);
    
    Animal listOfAnimals[] = {
        Animal("Собака", 4, "Любой", "Хордовые"),
        Animal("Попугай", 2, "Тропики", "Птицы"),
        Animal("Хомяк", 1, "Любой", "Грызуны"),
        Animal("Рыбка", 2, "Вода", "Рыбы"),
    };

    for (int i = 0; i < n; i++) {
        animals.push_back(listOfAnimals[i]);
    }

    if (animals.empty()) {
        cout << "Вектор пуст! Программа остановлена." << endl;
    } else {
        sort(animals.begin(), animals.end(), compareAnimals);

        for (int i = 0; i < animals.size(); i++) {
            animals[i].outputAnimal();
            cout << endl;
        }

        Animal newAnimal("Черепаха", 2, "Пустыня", "Рептилии");

        sort(animals.begin(), animals.end(), compareAnimals);
        auto pos = lower_bound(animals.begin(), animals.end(), newAnimal, compareAnimals);
        // lower_bound - не меньше переданного upper_bound - больше заданного.
        // auto - динамическое присваивание.
        animals.insert(pos, newAnimal);

        cout << "****************************************\n          Добавили черепаху: \n\n" << endl;
        for (int i = 0; i < animals.size(); i++) {
            animals[i].outputAnimal();
            cout << endl;
        }
    }
}
