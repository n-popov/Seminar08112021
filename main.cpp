#include <iostream>
#include <vector>

struct Vector {
    Vector(unsigned new_size) { // Конструктор
        size = new_size;
        capacity = new_size;
        data = new int[size];
        for(auto i = 0u; i < size; data[i++] = 0);
    }

    ~Vector() { // Деструктор
        std::cout << "Deleting data and freeing memory" << std::endl;
        delete[] data;
    }

    void reallocate(unsigned new_capacity) { // Перевыделение памяти
        int* new_data = new int[new_capacity];
        for(auto i = 0u; i < std::min(size, new_capacity); i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    void resize(unsigned new_size) { // resize как у вектора
        reallocate(new_size);
        for(auto i = std::min(size, new_size); i < new_size; i++) {
            data[i] = 0;
        }
        size = new_size;
    }

    void push_back(int element) { // push_back как у вектора
        if (capacity > size) data[size++] = element;
        else {
            capacity = size * 2;
            reallocate(capacity);
            data[size++] = element;
        }
    }

    int& operator[](unsigned index) {
        return data[index];
    }

    unsigned size;
    unsigned capacity;
    int* data;
};


// Пример функции, в которой используется void*
// для передачи данных произвольного типа
auto function(void* pointer_to_something, bool is_number) {
    if (is_number) {
        int x = *((int*)(pointer_to_something));
        std::cout << x;
    }
    else {
        char x = *((char*)(pointer_to_something));
        std::cout << x;
    }
}

void increase_by_two(int& x) {
    x += 2;
}

int main() {
//    size_t N;
//    std::cin >> N; // Задаём размер
//
//    Vector numbers(N); // Создаём вектор заданного размера
//    std::cout << numbers.size << ' ' << numbers.capacity << std::endl; // Выводим размер и ёмкость
//    for(auto i = 0u; i < numbers.size; std::cout << numbers[i++] << ' '); // Выводим элементы вектора
//    std::cout << std::endl;
//    std::cin >> N;
//    numbers.resize(N); // Тест resize
//    for(auto i = 0u; i < N; std::cout << numbers[i++] << ' ');
//    std::cout << std::endl;
//    int element;
//    for(auto i = 0; i < 2; i++) {
//        std::cin >> element;
//        numbers.push_back(element); // Тест push_back
//    }
//    numbers[0] = 100;
//    std::cout << numbers.size << ' ' << numbers.capacity << std::endl;
//    for(auto i = 0u; i < numbers.size; std::cout << numbers[i++] << ' ');
//    std::cout << std::endl;

    int y = 6;
    char c = 't';
    function((void*)(&y), true);
    function((void*)(&c), false);


}
