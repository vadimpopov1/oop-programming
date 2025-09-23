#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Straight {
    private:
        int a;
        int b;

    public:
        Straight(int _a, int _b) {
            a = _a;
            b = _b;
        }
    
        Straight() {
            a = 1;
            b = 0;
        }

    int getA() {
        return a; 
    }
    
    int getB() { 
        return b; 
    }

    void checkParallel(int i, int _aOX, int _bOX) {
        if (a == _aOX) {
            if (b == _bOX) {
                cout << "Прямая под номером " << i << " " << a << "x + " << b << " совпадает с прямой " << _aOX << "x + " << _bOX << endl;
            } else {
                cout << "Прямая под номером " << i << " " << a << "x + " << b << " параллельна с прямой " << _aOX << "x + " << _bOX << endl;
            }
        } else {
            cout << "Прямая под номером " << i << " " << a << "x + " << b << " пересекается с прямой " << _aOX << "x + " << _bOX << endl;
        }
    }
};

int main() {
    srand(time(NULL));

    int _aOX;
    int _bOX;
    int countStraight;

    cout << "Введите количество прямых для генерации: ";
    cin >> countStraight;
    
    cout << "\nВведите коэффиценты a и b для прямой M: ";
    cin >> _aOX >> _bOX;

    int countParalles = 0;
    cout << "\n";

    for (int i = 1; i <= countStraight; i++) {
        Straight line(rand() % 10, rand() % 10);
        line.checkParallel(i, _aOX, _bOX);

        if (line.getA() == _aOX && line.getB() != _bOX) {
            countParalles++;
        }
    }

    cout << "\nКоличество параллельных прямых: " << countParalles << endl;
}   
