#include <iostream>
#include <vector>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
#include <algorithm> // для sort()
#include <cmath>    // для abs()
#include <limits>   // для numeric_limits

using namespace std;

// Функция для получения размера массива от пользователя
int getArraySize() {
    int size;
    while (true) {
        cout << "Введите размер массива (положительное целое число): ";
        cin >> size;
        if (cin.fail() || size <= 0) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Ошибка ввода. Пожалуйста, введите положительное целое число." << endl;
        } else {
            break;
        }
    }
    return size;
}

// Функция для генерации массива случайных вещественных чисел
vector<double> generateRandomArray(int size) {
    vector<double> arr(size);
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % 200 - 100) + (rand() % 100) / 100.0;
    }
    return arr;
}

// Функция для вычисления суммы положительных элементов
double sumPositiveElements(const vector<double>& arr) {
    double sum = 0;
    for (double x : arr) {
        if (x > 0) {
            sum += x;
        }
    }
    return sum;
}

// Функция для нахождения произведения элементов между минимальным и максимальным по модулю
double productBetweenMinMax(const vector<double>& arr) {
    if (arr.empty()) return 0;

    size_t minIndex = 0, maxIndex = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (abs(arr[i]) < abs(arr[minIndex])) minIndex = i;
        if (abs(arr[i]) > abs(arr[maxIndex])) maxIndex = i;
    }

    size_t start = min(minIndex, maxIndex);
    size_t end = max(minIndex, maxIndex);

    if (start == end) return 0;

    double product = 1;
    for (size_t i = start + 1; i < end; ++i) {
        product *= arr[i];
    }

    return product;
}

// Функция для сортировки массива по убыванию
void sortArrayDescending(vector<double>& arr) {
    sort(arr.begin(), arr.end(), greater<double>());
}

int main() {
    int size = getArraySize();

    vector<double> arr = generateRandomArray(size);

    cout << "Исходный массив: ";
    for (double x : arr) {
        cout << x << " ";
    }
    cout << endl;

    double sumPos = sumPositiveElements(arr);
    cout << "Сумма положительных элементов: " << sumPos << endl;

    double product = productBetweenMinMax(arr);
    cout << "Произведение элементов между минимальным и максимальным по модулю: " << product << endl;

    sortArrayDescending(arr);

    cout << "Массив, упорядоченный по убыванию: ";
    for (double x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}