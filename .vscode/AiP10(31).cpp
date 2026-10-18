#include <iostream>
#include <exception>

int * transpose(const int* a, size_t n, size_t m){
    if (a == nullptr) {
        throw std::invalid_argument("Указатель a не может быть равен nullptr");
    }
    int* trans_matrix = new int[m*n];
    for (size_t i = 0; i < m; i++){
        for (size_t j = 0; j < n; j++){
            trans_matrix[i*n+j] = a[j*m+i];
        }
    }
    return trans_matrix;
}
