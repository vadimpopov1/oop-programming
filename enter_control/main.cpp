// Вариант 17. Создайте структуру Вектор с элементами x, y, z - декартовыен координаты. 
// Определить для M заданных векторов длину каждого вектора и найти номер самого длинного вектора

#include <iostream>
#include <cmath>

using namespace std;

struct Vector {
    float x;
    float y;
    float z;
};

float find_len(float x, float y, float z) {
    return sqrt(x*x + y*x + z*z);
}

int main() {
    int vector_count;
    cout << "Enter count of vectors: ";
    cin >> vector_count; 

    Vector vectors[vector_count];
    for (int i = 0; i < vector_count; i++) {
        
        cout << endl << "Enter float coordinates (x, y, z) of vector " << i + 1 << ": ";
        cin >> vectors[i].x >> vectors[i].y >> vectors[i].z;
    }    

    float max_len = 0.0;
    int max_len_id = 0;

    for (int i = 0; i < vector_count; i++) {
        float vector_len = find_len(vectors[i].x, vectors[i].y, vectors[i].z);
        if (vector_len > max_len) {
            max_len = vector_len;
            max_len_id = i + 1;
        }
        cout << endl << "Length of vector " << i + 1 << ": " << vector_len << endl;
    }
    
    cout << endl << "Max vector " << max_len_id << " with lenght " << max_len << endl;
}
