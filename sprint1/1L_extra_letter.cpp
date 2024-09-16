#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::string t;

    std::getline(std::cin, s);
    std::getline(std::cin, t);

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++) {
        if (s[i] != t[i]) {
            std::cout << t[i];
            break;
        }
    }

    return 0;
}