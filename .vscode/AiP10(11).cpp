#include <iostream>
#include <exception>

int* extend(const int* a, size_t k, size_t d, int filler){
    if (k > d) {
        throw std::invalid_argument("k не может быть больше d");
    }
    if (a == nullptr) {
        throw std::invalid_argument("Указатель a не может быть равен nullptr");
    }
    int* b = new int[d];
    for (size_t i = 0; i < k; i++) {
        b[i] = a[i];     
    }
    for (size_t j = k; j < d; j++) {
        b[j] = filler;    
    }
    return b;
}

int main() {
    size_t k = 5, d = 7;
    int filler = 1;
    const int* a = new int[k];
    int* b = extend(a, k, d, filler);
    for (size_t i = 0; i < d; i++) {
        std::cout << b[i] << " ";
    }
}