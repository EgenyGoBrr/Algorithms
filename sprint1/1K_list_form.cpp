#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int len = 0;
    std::vector<int> x;
    int k = 0;
    std::vector<int> list_k;
    unsigned long long int a = 0;

    std::cin >> len;
    for (int i = len - 1; i >= 0; i--) {
        std::cin >> k;
        x.push_back(k);
    }
    k = 0;
    std::cin >> k;
    
    do {
        list_k.push_back(k % 10);
        k /= 10;
    }while (k > 0);

    int ks = list_k.size();
    int xs = x.size();

    int size = ks < xs ? ks : xs;
    int t = 0;
    for (int i = 1; i <= size; i++) {
        t = x[xs - i] + list_k[ks - i];
        std::cout << x[xs - i] << " + " << list_k[ks - i] << " = " << t << '\n';
        if (t >= 10) {
            x[xs - i] = t % 10;
            x[xs - i - 1] += t / 10;
        }
        else {
            x[xs - i] = t;
        }
        std::cout << "\tx[" << xs - i << "] = " << x[xs - i] << '\n';
        std::cout << "\tk[" << ks - i << "] = " << list_k[ks - i] << '\n';
    }

    for (int i = 0; i < xs; i++) { 
        std::cout << x[i] << ' ';
    }
    

    return 0;
}