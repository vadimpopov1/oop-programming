#include <iostream>
#include <string>

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

    void outputAnimal() {
        cout << "Название: " << name << "\nВозраст: " << age << "\nАреал обитания: " << areal << "\nТип: " << type << endl;
    }

    string get_Name() {
        return name;
    }

    
    int get_Age() {
        return age;
    }

    string get_Areal() {
        return areal;
    }

    string get_Type() {
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

int main() {
    Animal Cat = Animal("Кот", 3, "Любой", "Кошачии");
    Animal *Dog = new Animal("Собака", 4, "Любой", "Хордовые");
    Cat.outputAnimal();
    cout << "\n";
    Dog->outputAnimal();
    cout << "\n";

    int newAge;

    cout << "Введите новый возраст Кота: ";
    cin >> newAge;
    Cat.set_Age(newAge);
    
    cout << "Введите новый возраст Собаки: ";
    cin >> newAge;
    Dog->set_Age(newAge);

    cout << "\n";

    cout << "Возраст Кота: " << Cat.get_Age() << endl;
    cout << "Возраст Собаки: " << Dog->get_Age() << endl;

    cout << "\n";

    Cat.outputAnimal();
    cout << "\n";
    Dog->outputAnimal();
    cout << "\n";
    
    Cat.set_Name("Слон");
    Cat.set_Age(21);
    Cat.set_Areal("Африка");
    Cat.set_Type("Хордовые");
    Cat.outputAnimal();
}
