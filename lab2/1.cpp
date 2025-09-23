#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

class EquilateralTriangle {
    protected:
        float side_length;
        // bool print_message;

    public:
        // EquilateralTriangle(float _side_length, bool _print_message = true) : side_length(_side_length), print_message(_print_message) {
        //     if (print_message) {
        //         cout << "[SUCCESS] Создан треугольник с длиной стороны: " << side_length << endl;
        //     }
        // }

        EquilateralTriangle(float _side_length) : side_length(_side_length) {
            // cout << "[SUCCESS] Создан треугольник с длиной стороны: " << side_length << endl;
        }

        float getHeight() {
            return (sqrt(3) * side_length) / 2;
        }

        float getBisector() {
            return (sqrt(3) * side_length) / 2;
        }

        float getPerimeter() {
            return 3 * side_length;
        }

        float getSquare() {
            return (sqrt(3) * pow(side_length, 2)) / 4; 
        }

        void getTriangleInfo() {
            cout << "Длина стороны треугольника: " << side_length << endl
                 << "Высота: " << getHeight() << endl
                 << "Биссектриса: " << getBisector() << endl
                 << "Периметр: " << getPerimeter() << endl
                 << "Площадь: " << getSquare() << endl;
        }
};

class EquilateralPyramid : public EquilateralTriangle {
    public: 
        EquilateralPyramid(float _side_length) : EquilateralTriangle(_side_length) {
        }

        float getVolume() {
            return (sqrt(3)/4) * pow(side_length, 2);
        }

        void getPyramidInfo() {
            cout << "Длина стороны пирамиды: " << side_length << endl
                 << "Объем: " << getVolume() << endl;
        }
};

int main() {
    srand(time(NULL));

    int countTrigangles;
    int countPyramides;

    cout << "Введите количество треугольников для генерации: ";
    cin >> countTrigangles;

    cout << "Введите колиество пирамид для генерации: ";
    cin >> countPyramides;

    float triangles[countTrigangles];
    float sumAvgTriangles;

    float pyramides[countPyramides];
    float maxPyramide = 0.0;

    for (int i = 0; i < countTrigangles; i++) {
        EquilateralTriangle triangle(1.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 9.0));
        triangle.getTriangleInfo();
        triangles[i] = triangle.getSquare();
        sumAvgTriangles += triangle.getSquare();
        cout << endl;
    }  
    
    cout << endl;

    for (int i = 0; i < countPyramides; i++) {
        EquilateralPyramid pyramide(1.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 9.0));
        pyramide.getPyramidInfo();
        pyramides[i] = pyramide.getSquare();
        cout << endl;
    }

    sumAvgTriangles /= countTrigangles;

    int countTrianglesAvg = 0;
    
    for (int i = 0; i < countTrigangles; i++) {
        if (triangles[i] >= sumAvgTriangles) {
            countTrianglesAvg += 1;
        }
    }

    cout << endl << "Найдено " << countTrianglesAvg << " треугольника(ов) у которых площадь больше средней (" << sumAvgTriangles << ").\n";

    for (int i = 0; i < countPyramides - 1; i++) {
        if (pyramides[i] >= maxPyramide) {
            maxPyramide = pyramides[i];
        }
    }
    cout << endl << "Максимальный объем пирамиды равен: " << maxPyramide << endl;
}
