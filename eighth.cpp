#include <iostream>
#include <vector>

int* reallocate(int* data, unsigned old_size, unsigned new_size) {
    int* new_data = new int[new_size];
    for(auto i = 0u; i < old_size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    return new_data;
}

void read_array(unsigned int** data, unsigned int* n) {
    auto size = 1u;
    auto capacity = size;
    *data = new unsigned[size];
    unsigned temporary;
    for(;std::cin >> temporary;) {
        if (size < capacity) {

        }
    }

}

int main() {
    int* data = new int[5];
    for(auto i = 0; i < 5; i++) {data[i] = i;}
    data = reallocate(data, 5, 7);
    for(auto i = 0; i < 7; i++) {std::cout << data[i] << ' ';}
    std::cout << std::endl;
}
