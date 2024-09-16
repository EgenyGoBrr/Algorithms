#include <iostream>
#include <vector>

int main() {
    std::vector<int> answer;
    int num = 0;
    std::cin >> num;

    int i = 2;

    while (i * i <= num){
        while (num % i == 0)
        {
            answer.push_back(i);
            num /= i;
        }
        i++;        
    }
    if (num > 1) {
        answer.push_back(num);
    }
    
    for (int i = 0; i < answer.size(); i++) 
        std::cout << answer[i] << ' ';

    return 0;
}