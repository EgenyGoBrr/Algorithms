#include <iostream>
#include <string>
#include <vector>

int main() {

    // не работает, если в начале строки стоят пробелы

    int l = 0;
    unsigned int i = 0;
    std::string str;
    std::string str1;
    std::string word;
    std::string longest_word;

    // std::cin >> l;
    std::getline(std::cin, str1);
    std::getline(std::cin, str);

    for (; i < str.size(); i++) {
        if (str[i] == ' ')
            break;
        longest_word.push_back(str[i]);
    }


    for (; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (word.size() > longest_word.size()) {
                longest_word.clear();
                longest_word = word;
                word.clear();
            }    
        }
        else
            word.push_back(str[i]);
    }

    std::cout << longest_word << '\n' << longest_word.size();

    return 0;
}