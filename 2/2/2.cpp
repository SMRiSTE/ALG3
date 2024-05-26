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
    std::cout << std::endl;
}

void append_to_dynamic_array(int* &arr, int &logical_size, int &actual_size, int num) {
    if (logical_size < actual_size) {
        logical_size += 1;
        arr[logical_size - 1] = num;
    }
    else if (logical_size == actual_size) {
        int* new_arr = new int[2 * actual_size];
        for (int i = 0; i < logical_size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[logical_size] = num;

        logical_size++;
        actual_size *= 2;

        delete[] arr;
        arr = new_arr;
    }
    else {
        std::cerr << "Ошибка: логический размер не может быть больше фактического размера!" << std::endl;
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
    std::cout<<actual_size;

    int num;
    for (int i = 0; i < logical_size; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> num;
        arr[i] = num;
    }
    print_dynamic_array(arr, logical_size, actual_size);

    while (true) {
        std::cout << "Введите элемент для добавления: ";
        std::cin >> num;
        if (num == 0) {
            std::cout << "Спасибо! Ваш массив: ";
            for (int i = 0; i < actual_size; i++) {
                if (i < logical_size) {
                    std::cout << arr[i] << " ";
                }
                else {
                    std::cout << "_ ";
                }
            }
            std::exit(0);
        }
        else {
            append_to_dynamic_array(arr, logical_size, actual_size, num);
            print_dynamic_array(arr, logical_size, actual_size);
        }
    }
    delete[] arr;
}