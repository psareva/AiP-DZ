#include <iostream>
#include <execution>

void extend(int** ptr_a, size_t k, size_t d, int filler){
    if (k > d) {
        throw std::invalid_argument("k не может быть больше d");
    }
    if (ptr_a == nullptr) {
        throw std::invalid_argument("Указатель ptr_a не может быть равен nullptr");
    }
    if (*ptr_a == nullptr) {
        throw std::invalid_argument("Указатель *ptr_a не может быть равен nullptr");
    }
    int* b = new int[d];
    for (size_t i = 0; i < k; i++){
        b[i] = (*ptr_a)[i];
    }
    for (size_t j = k; j < d; j++){
        b[j] = filler;
    }
    delete[] *ptr_a;
    *ptr_a = b;
}