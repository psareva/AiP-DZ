#include <iostream>
#include <exception>

int** matrix_input(size_t m, size_t n);
int** matrix_transpose(int** matrix, size_t m, size_t n);
void matrix_output(int** trans_matrix, size_t n, size_t m);

int main() 
{
    int m_i = 0, n_i = 0;
    std::cin >> m_i >> n_i;
    if (std::cin.fail() || (m_i <= 0) || (n_i <= 0)) {
        std::cerr << "Код ошибки 1";
        return 1;
    }
    size_t m = size_t(m_i), n = size_t(n_i);
    try {
        int** matrix = matrix_input(m, n);
        int** trans_matrix = matrix_transpose(matrix, m, n);
        matrix_output(trans_matrix, n, m);
        for (size_t i = 0; i < m; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        for (size_t i = 0; i < n; i++) {
            delete[] trans_matrix[i];
        }
        delete[] trans_matrix;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Код ошибки 1";
        return 1;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Код ошибки 2";
        return 2;
    }
    catch (const std::exception& e) {
        std::cerr << "Код оошибки 0";
        return 0;
    }
}

int** matrix_input(size_t m, size_t n)
{
    int** matrix = new int*[m];
    for (size_t i = 0; i < m; i++) {
        try {
            matrix[i] = new int[n];
        }
        catch (const std::bad_alloc& e) {
            for (size_t k; k < i; k++) {
                delete[] matrix[k];
            }
            delete[] matrix;
            throw;
        }
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
            if (std::cin.fail()) {
                for (size_t k; k < m; k++) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                throw std::logic_error("Ошибка ввода");
            }
        }    
    }
        return matrix;
}

int** matrix_transpose(int** matrix, size_t m, size_t n)
{
    int** trans_matrix = new int*[n];
    for (size_t i = 0; i < n; i++){
        try {
            trans_matrix[i] = new int[m];
        }
        catch (const std::bad_alloc& e) {
            for (size_t k; k < i; k++) {
                delete[] trans_matrix[k];
            }
            delete[] trans_matrix;
            for (size_t j; j < m; j++) {
                delete[] matrix[j];
            }
            delete[] matrix;
            throw;
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            trans_matrix[i][j] = matrix[j][i];
        }
    }
    return trans_matrix;
}

void matrix_output(int** matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}