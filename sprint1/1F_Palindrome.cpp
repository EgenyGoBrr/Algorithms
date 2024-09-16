#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string str;
    std::string str1;
    std::string clear_str;
    std::getline(std::cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i]))
            clear_str.push_back(str[i]);
        if (std::isalpha(str[i]))
            clear_str.push_back((char)tolower(str[i]));
    }

    str1 = clear_str;
    std::reverse(clear_str.begin(), clear_str.end());
    if (str1 == clear_str)
        std::cout << "True";
    else 
        std::cout << "False";
    return 0;
}