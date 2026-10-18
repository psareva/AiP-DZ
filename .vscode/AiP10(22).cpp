#include <iostream>
#include <exception>
#include <limits>

int * add_col(const int* a, size_t n, size_t m, int filler){
    int maxx_int = std::numeric_limits<int>::max();
    if (a == nullptr) {
        throw std::invalid_argument("Указатель ptr_a не может быть равен nullptr");
    }
    if (n > (maxx_int/(m+1))){
        throw std::overflow_error("n не может быть больше max_int/(m+1)");
    }
    int* b = new int[n*(m+1)];
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            b[i*(m+1)+j] = a[i*m+j];
        }
    }
    for (size_t i = 0; i < n; i++){
        b[m*i + (m+1)] = filler;
    }
    return b;
}