#include <iostream>
#include <exception>

int * concat_rows(const int * a, size_t n, size_t m1, const int * b, size_t m2){
    size_t maxx_size_t = std::numeric_limits<size_t>::max();
    if (a == nullptr || b == nullptr) {
        throw std::invalid_argument("Указатель a не может быть равен nullptr");
    }
    if (n > (maxx_size_t/(m1+m2))){
        throw std::overflow_error("n не может быть больше max_size_t/(m1+m2)");
    }
    int* c = new int[n*(m1+m2)];
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m1; j++){
            c[i*(m1+m2) + j] = a[i*m1+j];
        }
        for (size_t k = m1; k < m1+m2; k++){
            c[i*(m1+m2) + k] = b[i*m2 + (k-m1)];
        }
    }
    return c;
}