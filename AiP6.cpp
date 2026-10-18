#include <iostream>

int* prost(int* m, size_t n, size_t& count){
    int* ans = new int[n];
    if (n<1){
        throw "Число, ниже 1";
    }
    for (size_t j = 0; j < n; j++) {
        bool flag = true;
        if (m[j] == 1){
            flag = false;
        }
        for (size_t k = 2; k < m[j]; k++){
            if (m[j]%k == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            ans[count] = m[j];
            count++;
        }
    }
    return ans;
}

int main(){
    size_t n = 0;
    std::cin >> n;
    int* m = new int[n];
    for (size_t i = 0; i < n; i++) {
        m[i] = i + 1;       
    }
    size_t count = 0;
    int* z = prost(m, n, count);
    for (size_t l = 0; l < n; l++) {
        std::cout << z[l] << std::endl;    
    }
    std::cout << count << std::endl;
    return 0;
}