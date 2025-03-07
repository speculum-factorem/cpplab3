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
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % 200 - 100) + (rand() % 100) / 100.0; // Генерация чисел от -100.0 до 100.0
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

    // Находим индексы минимального и максимального по модулю элементов
    size_t minIndex = 0, maxIndex = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (abs(arr[i]) < abs(arr[minIndex])) minIndex = i;
        if (abs(arr[i]) > abs(arr[maxIndex])) maxIndex = i;
    }

    // Определяем начальный и конечный индексы
    size_t start = min(minIndex, maxIndex);
    size_t end = max(minIndex, maxIndex);

    // Если start и end совпадают, возвращаем 0
    if (start == end) return 0;

    // Вычисляем произведение элементов между start и end
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
    // Получаем размер массива от пользователя
    int size = getArraySize();

    // Генерируем массив случайных чисел
    vector<double> arr = generateRandomArray(size);

    // Выводим исходный массив
    cout << "Исходный массив: ";
    for (double x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Вычисляем сумму положительных элементов
    double sumPos = sumPositiveElements(arr);
    cout << "Сумма положительных элементов: " << sumPos << endl;

    // Находим произведение элементов между минимальным и максимальным по модулю
    double product = productBetweenMinMax(arr);
    cout << "Произведение элементов между минимальным и максимальным по модулю: " << product << endl;

    // Сортируем массив по убыванию
    sortArrayDescending(arr);

    // Выводим отсортированный массив
    cout << "Массив, упорядоченный по убыванию: ";
    for (double x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}