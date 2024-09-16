#include <iostream>

int main() {
    bool answer = false;
    int num = 0;
    int i = 4;
    std::cin >> num;

    while (i <= num) {
        if (i == num) {
            answer = true;
            break;
        }
        i *= 4;
    }
    
    if (answer || num == 1)
        std::cout << "True";
    else
        std::cout << "False";
    return 0;
}