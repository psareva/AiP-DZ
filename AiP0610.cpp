#include <iostream>
#include <exception>
#include <limits>

int* f_schit(size_t n){
    int* m = new int[n];
    int a = 0;
    for (int i = 0; i<n; i++){
        std::cin >> a;
        if (std::cin.fail()){
            delete[] m;
            throw std::logic_error("err");
        }
        m[i] = a;
    }
    return m;
}


int summ(int* m, size_t n){
    int sm = 0;
    int maxx = std::numeric_limits<int>::max();
    int minn = std::numeric_limits<int>::max();
    for (size_t j = 0; j < n; j++){
        if ((m[j] > maxx-sm) || (m[j] < minn-sm)){
            throw std::overflow_error("z");
        }
        sm += m[j];
    }
    return sm;
}

int vivod(int* m, size_t n, int sm){
    for (size_t k = 0; k < n; k++){
        std::cout << m[k];
    }
    std::cout << sm << sm/n;
    return 1;
}

int main(){
    int count = 0;
    std::cin >> count;
    size_t n = count;
    try{
        int* m = f_schit(n);
        int sm = summ(m, n);
        vivod(m, n, sm);
    }
    catch(const std::logic_error& e){
        std::cerr << "Код ошибки 1";
        return 1;
    }
    catch(const std::bad_alloc& e){
        std::cerr << "Код ошибки 2";
        return 2;
    }
    catch(const std::overflow_error& e){
        std::cerr << "Код ошибки 2";
        return 2;
    }
    catch(const std::exception& e){
        std::cerr << "Код ошибки 3";
        return 3;
    }
    

    
}