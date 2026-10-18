#include <iostream>
#include <exception>

void add_col(int ** a, size_t n, size_t m, int filler){
    if (a == nullptr || *a == nullptr){
        throw std::invalid_argument("Указатель a и указатель *a не может быть равен nullptr");
    }
    for (size_t i = 0; i < n; i++){
        int* b = new int[m + 1];
        for (size_t j = 0; j < m; j++){
            b[j] = a[i][j];
        }
        b[m] = filler;
        delete[] a[m];
        a[i] = b;
    }
}
