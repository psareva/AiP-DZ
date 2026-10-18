#include <iostream>
#include <exception>
#include <limits>


int * add_row(const int* a, size_t n, size_t m, int filler){
    int maxx_int = std::numeric_limits<int>::max();
    if (a == nullptr) {
        throw std::invalid_argument("Указатель ptr_a не может быть равен nullptr");
    }
    if (m > (maxx_int/(n+1))){
        throw std::overflow_error("m не может быть больше max_int/(n+1)");
    }
    int* b = new int[(n+1)*m];
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            b[i*m+j] = a[i*m+j];
        }
    }
    for (size_t j = 0; j < m; j++){
        b[n*m+j] = filler;
    }
    return b;
}