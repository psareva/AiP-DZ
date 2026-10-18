#include <iostream>
#include <exception>
#include <limits>

int * concat_cols(const int * a, size_t n1, size_t m, const int * b, size_t n2){
    size_t maxx_size_t = std::numeric_limits<size_t>::max();
    if (a == nullptr || b == nullptr){
        throw std::invalid_argument("Указатель a не может быть равен nullptr");
    }
    if (m > (maxx_size_t/(n1+n2))){
        throw std::overflow_error("m не может быть больше max_size_t/(n1+n2)");
    }
    int * c = new int[(n1+n2)*m];
    for (size_t i = 0; i < n1; i++){
        for (size_t j = 0; j < m; j++){
            c[i*m+j] = a[i*m+j];
        }
    }
    for (size_t i = n1; i < n1+n2; i++){
        for (size_t j = 0; j < m; j++){
            c[i*m + j] = b[(i-n1)*m + j];
        }
    }
    return c;
}
