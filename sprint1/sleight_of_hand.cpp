// https://contest.yandex.ru/contest/22450/run-report/116689629/
#include <iostream>
#include <vector>

#define FIELD_SIZE_I 4
#define FIELD_SIZE_J 4

int main() {
    int k = 0;
    int score = 0;
    char num;
    std::vector<int> digit_counter(10);

    std::cin >> k;
    k *= 2;

    for (int i = 0; i < FIELD_SIZE_I; i++) {
        for (int j = 0; j < FIELD_SIZE_J; j++) {
            std::cin >> num;

            if (num != '.') {
                digit_counter[num - '0']++;
            }
        }
    }

    for (int i = 0; i < digit_counter.size(); i++) {
        if (k >= digit_counter[i] && digit_counter[i] != 0)
            score++;
    }
    std::cout << score;

    return 0;
}