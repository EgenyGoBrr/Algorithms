#include <iostream>
#include <vector>

int main() {
    int num = 0;
    std::vector<int> answer;

    std::cin >> num;

    if (num == 0){
        std::cout << 0;
        return 0;
    }

    while (num > 0) {
        answer.push_back(num % 2);
        num /= 2;
    }
    
    for (int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i];
    }
    return 0;
}