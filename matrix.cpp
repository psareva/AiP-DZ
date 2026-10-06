#include <iostream>
#include <exception>

int** matrix_input(size_t m, size_t n);
int** matrix_transpose(int** matrix, size_t m, size_t n);
int matrix_output(int** trans_matrix, size_t n, size_t m);

int** matrix_input(size_t m, size_t n){
    int** matrix = new int*[m];
    for (size_t i = 0; i < m; i++){
        matrix[i] = new int[n];
    }
    for (size_t i = 0; i < m; i++){
        for (size_t j = 0; j < n; j++){
            std::cin >> matrix[i][j];
            if (std::cin.fail()){
                for (size_t k; k < m; k++){
                    delete[] matrix[k];
                }
                delete[] matrix;
                throw std::logic_error("Ошибка ввода");
            }
        }    
    }
        return matrix;
}

int** matrix_transpose(int** matrix, size_t m, size_t n){
    int** trans_matrix = new int*[n];
    for (size_t i = 0; i < n; i++){
        trans_matrix[i] = new int[m];
    }
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            trans_matrix[i][j] = matrix[j][i];
        }
    }
    return trans_matrix;
}

int matrix_output(int** trans_matrix, size_t n, size_t m){
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            std::cout << trans_matrix[i][j];
        }
    }
    return 1;
}

int main(){
    int m_i = 0, n_i = 0;
    std::cin >> m_i >> n_i;
    if (std::cin.fail() || (m_i <= 0) || (n_i <= 0)){
        std::cerr << "Код ошибки 1";
        return 1;
    }
    size_t m = m_i, n = n_i;
    try{
        int** matrix = matrix_input(m, n);
        int** trans_matrix = matrix_transpose(matrix, m, n);
        matrix_output(trans_matrix, n, m);
    }
    catch(const std::logic_error& e){
        std::cerr << "Код ошибки 1";
        return 1;
    }
    catch(const std::bad_alloc& e){
        std::cerr << "Код ошибки 2";
        return 2;
    }
    catch(const std::exception& e){
        std::cerr << "Код оошибки 0";
        return 0;
    }
}