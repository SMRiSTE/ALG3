#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int logical_size, actual_size;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Логический размер массива не может превышать его фактический размер";
        return 0;
    }

    int* arr = new int[actual_size];

    int num;
    for (int i = 0; i < logical_size; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> num;
        arr[i] = num;
    }
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
}