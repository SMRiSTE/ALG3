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

int* append_to_dynamic_array(int* arr, int* logical_size, int* actual_size) {
    print_dynamic_array(arr, *logical_size, *actual_size);
    if (*logical_size < *actual_size) {
        *logical_size += 1;
        int num;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> num;
        if (num == 0) {
            std::exit(0);
        }
        arr[*logical_size - 1] = num;
        return arr;
    }
    else if (*logical_size == *actual_size) {
        *logical_size += 1;
        int* new_arr = new int[*actual_size * 2];
        for (int i = 0; i < *actual_size - 1; i++) {
            new_arr[i] = arr[i];
        }
        *actual_size *= 2;
        delete[] arr;
        arr = new_arr;
        int num;
        std::cout << "Введите элемент для добавления: ";
        std::cin >> num;
        arr[*logical_size - 2] = num;
        return new_arr;
    }
    else {
        std::cerr << "Ошибка: логический размер не может быть больше фактического размера!" << std::endl;
        return arr;
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
    append_to_dynamic_array(arr, &logical_size, &actual_size);
    delete[] arr;
}