// https://contest.yandex.ru/contest/22450/run-report/116689293/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    unsigned int n = 0;
    std::vector<int> street;
    std::vector<int> index_of_zero;
    std::vector<int> answer;

    std::cin >> n;

    for (unsigned int i = 0; i < n; i++) {
        int t = 0;
        std::cin >> t;
        street.push_back(t);
        if (t == 0)
            index_of_zero.push_back(i);
    }

    for (unsigned int i = 0; i < street.size(); i++) {
        if (street[i] == 0) {
            answer.push_back(0);
            continue;
        }

        int min = abs(i - index_of_zero[0]);
        int t = 0;
        for (unsigned int j = 1; j < index_of_zero.size(); j++) {
            t = abs(i - index_of_zero[j]);
            // при использовании std::min() задача не проходит ограничение по времени
            min = t < min ? t : min;
        }
        answer.push_back(min);
    }

    for (unsigned int i = 0; i < answer.size(); i++) {   
        std::cout << answer[i] << ' ';
    }
    return 0;
}